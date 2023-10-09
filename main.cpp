#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include "raylib/raylib.h"
#include "vectorlib.h"
#include "physics.cpp"

#define GRAVITY 10

// Config
int fpsCap = 60;
int BORDER_TYPE = 1; // Which border to choose (0 - Circle, 1 - Rectangle)
bool enableSweepAndPrune = true;
int subSteps = 6;
int screenWidth = 1200;
int screenHeight = 750;
int spawnRate = 5; // The lower the faster
bool enableLogging = false;

FILE* logFile = nullptr; // Declare logFile globally

void logResults(FILE* logFile, int const &ballCount, int const &frames, int const &collisionsToCheck) {
    // Construct text
    std::string string = std::to_string(ballCount) + ";" + std::to_string(frames) + ";" + std::to_string(collisionsToCheck) + "\n";
    const char* text = string.c_str();

    // Write the formatted log message to the file
    fprintf(logFile, text);
}

void calculateNextFrame(std::vector<Element> &elements, float deltaTime, FILE* logFile) {
    float dt = deltaTime / subSteps;

    // Loging variables
    int collisionCheckCount = 0;
    int lastCollisionCheckCount = 0;

    for(int i = 0; i<subSteps; i++) {
        // Calculate physics
        for (Element &element : elements) {
            element.accelerate(Vec2D(0.0f, GRAVITY));
        }
        for (Element &element : elements) {
            element.updatePosition(dt);
        }
        if (enableSweepAndPrune) {
            std::vector<std::pair<int, int>> pairs = sweepAlongX(elements);
            for (int i = 0; i<pairs.size(); i++) {
                elements[pairs[i].first].caluculateCollisions(elements[pairs[i].second]);
            }
        } else {
            for (Element &element : elements) {
                for (Element &element2 : elements) {
                    collisionCheckCount++;
                    element.caluculateCollisions(element2);
                }
            }
        }
        for (Element &element : elements) {
            element.applyConstraints(BORDER_TYPE, screenWidth, screenHeight);
        }
    }
    for (Element &element : elements) {
        DrawCircle(element.pos.x, element.pos.y, element.radius, WHITE);
    }

    if (enableLogging) {
        if (lastCollisionCheckCount != collisionCheckCount) {
            // Log to file
            logResults(logFile, elements.size(), GetFPS(), collisionCheckCount);
        }
    }
}

int main(int, char**){
    if (enableLogging) {
        // Check if folder ./Logs exists
        std::filesystem::path folderPath = "./Logs";

        // Check if the subfolder exists; if not, create it
        if (!std::filesystem::exists(folderPath) || !std::filesystem::is_directory(folderPath)) {
            std::filesystem::create_directories(folderPath);
        }

        // Open logFile
        // Check if there's already a file with log
        if (std::ifstream("./Logs/log.csv")) {
            bool newNameFound = false;
            while (!newNameFound) {
                std::string randomNumber = std::to_string(rand() % 99);
                std::string newFileName = "./Logs/" + randomNumber + "-log.csv";
                if (!std::ifstream(newFileName.c_str())) {
                    newNameFound = true;
                    std::rename("./Logs/log.csv", newFileName.c_str());
                    std::rename("./Logs/config.txt", ("./Logs/" + randomNumber + "-config.txt").c_str());
                }
            }
        }
        logFile = fopen("./Logs/log.csv", "a");
        fprintf(logFile, "NoB; FPS; CoC\n");

        // Log config
        FILE* configFile = fopen("./Logs/config.txt", "a");
        // Construct text
        std::string string = "// Config:\nfpsCap: " + std::to_string(fpsCap) + "\nBorder Type: " + std::to_string(BORDER_TYPE) + "\nSweep and Prune Algo enabled: " + (enableSweepAndPrune ? "true" : "false") + "\nSubsteps: " + std::to_string(subSteps) + "\nScreen width: " + std::to_string(screenWidth) + "\nScreen height: " + std::to_string(screenHeight) + "\nSpawn every n frames: " + std::to_string(spawnRate); 
        const char* text = string.c_str();

        // Write the formatted log message to the file
        fprintf(configFile, text);
        fclose(configFile);
    }

    // Raylib setup
    InitWindow(screenWidth, screenHeight, "Physics Simulation");
    SetTargetFPS(fpsCap);
    SetExitKey(KEY_ESCAPE);
    
    // Control when window should be open
    bool isRunning = true;

    // Add elements to render
    Element standardBall = Element (1, 7, Vec2D(600, 300), Vec2D(200, 1000), Vec2D(400, 250));
    std::vector <Element> elements {};
    std::vector <Element *> xAxis {};
    int spawnCounter = 1;
    int degreeCounter = 100;

    while(!WindowShouldClose()) {
        if (IsKeyReleased(KEY_SPACE)) {
            isRunning = !isRunning;
        }

        if (isRunning) {
            if (spawnCounter % spawnRate == 0) {
                elements.push_back(standardBall);
            }
            standardBall = generateStandardBall(standardBall, degreeCounter);
            spawnCounter++;
            degreeCounter += 20;

            BeginDrawing();
            ClearBackground(DARKGRAY);

            // Render background
            if (BORDER_TYPE == 0) {
                DrawCircle(0.5 * screenWidth, 0.5 * screenHeight, 0.45 * screenHeight, BLACK);
            } else if (BORDER_TYPE == 1) {
                DrawRectangle(0.05 * screenWidth, 0.05 * screenHeight, 0.9 * screenWidth, 0.9 * screenHeight, BLACK);
            }
            
            // Render FPS Info
            DrawFPS(0, 0);
            // Render Ball count
            DrawText(("Ball Count: " + std::to_string(elements.size())).c_str(), 0, 20, 20, WHITE);

            // Get deltaTime
            float deltaTime = GetFrameTime() * 8;

            calculateNextFrame(elements, deltaTime, logFile);
        }

        EndDrawing();
    }

    // Close the log file
    fclose(logFile);

    CloseWindow();

    return 0;
}