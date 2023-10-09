#include "vectorlib.h"
#include <vector>
#include <algorithm>
#include <utility>

// Define elements
class Element {
    public:
        float mass;
        int radius;
        Vec2D pos;
        Vec2D lastPos;
        Vec2D acc;

        Vec2D middlePoint;

        Element(float newMass, int newRad, Vec2D newPos, Vec2D newAcc, Vec2D newMiddle) : mass(newMass), radius(newRad), pos(newPos), lastPos(newPos), acc(newAcc), middlePoint(newMiddle) {}

        void updatePosition(double const &dt) {
            const Vec2D vel = pos - lastPos;
            // Save current position
            lastPos = pos;
            // Perform Verlet integration
            pos = pos + (vel + acc * dt * dt);
            // Reset acceleration
            acc = Vec2D();
        }

        void accelerate(const Vec2D &newAcc) {
            acc += newAcc;
        }

        void applyConstraints(int type, int const &scWi, int const &scHe) {
            if (type == 0) {
                if ((pos - middlePoint).length() + radius > 0.45 * scHe) {
                    pos -= pos.getAngleTo(middlePoint) * ((pos - middlePoint).length() + radius - 0.45 * scHe);
                }
            } else if (type == 1) {
                if (pos.x - radius < 0.05 * scWi) {
                    pos.x = 0.05 * scWi + radius;
                }
                if (pos.x + radius > 0.95 * scWi) {
                    pos.x = 0.95 * scWi - radius;
                }
                if (pos.y - radius < 0.05 * scHe) {
                    pos.y = 0.05 * scHe + radius;
                }
                if (pos.y + radius > 0.95 * scHe) {
                    pos.y = 0.95 * scHe - radius;
                }
            }
        }

        void caluculateCollisions(Element &el) {
            if (this != &el && (pos - el.pos).length() < radius + el.radius) {
                Vec2D axis = pos.getAngleTo(el.pos);
                float overlap = radius + el.radius - (pos - el.pos).length();
                // float massRatio = mass / el.mass;
                // pos += axis * (0.5 / massRatio * overlap);
                pos += axis * 0.5 * overlap;
                // el.pos -= axis * (0.5 * massRatio * overlap);
                el.pos -= axis * 0.5 * overlap;
            }
        }
};

std::vector<std::pair<int, int>> sweepAlongX(std::vector <Element> &elements) {

    std::vector<std::pair<int, int>> returnVec = {};

    std::sort(elements.begin(), elements.end(), [](Element &el, Element &el2) -> bool {
        return (el.pos.x - el.radius) < (el2.pos.x - el2.radius);
    });

    for (int i = 0; i<elements.size(); i++) {

        for (int e = i + 1; e<elements.size(); e++) {

            Element &firstEl = elements[i];
            Element &secondEl = elements[e];
            
            if ((firstEl.pos.x + firstEl.radius) < (secondEl.pos.x - secondEl.radius)) {
                break;
            } else {
                returnVec.push_back(std::make_pair(i, e));
            }
        }
    }
    return returnVec;
}

std::vector<std::pair<int, int>> sweepAlongY(std::vector<std::pair<int, int>> pairs, std::vector<Element> &elements) {

    std::vector<std::pair<int, int>> returnVec = {};

    for (int i = 0; i<pairs.size(); i++) {
        Element &el = elements[pairs[i].first];
        Element &el2 = elements[pairs[i].second];

        if ((el.pos.y + el.radius) >= (el2.pos.y - el2.radius)) {
            returnVec.push_back(pairs[i]);
        }
    }
    return returnVec;
}

// Function for calculating the initial acceleration of a ball for a counter
Element generateStandardBall(Element const &standardBall, int &degreeCounter) {
    if (degreeCounter < 1000) {
        Element returnBall = Element (standardBall.mass, standardBall.radius, standardBall.pos, Vec2D((degreeCounter - 500) * 30, 10000), standardBall.middlePoint);
        return returnBall;
    } else if (degreeCounter >= 1000 && degreeCounter < 2000) {
        Element returnBall = Element (standardBall.mass, standardBall.radius, standardBall.pos, Vec2D((500 - (degreeCounter - 1000)) * 30, 10000), standardBall.middlePoint);
        return returnBall;
    } else {
        degreeCounter = 0;
        return generateStandardBall(standardBall, degreeCounter);
    }
}