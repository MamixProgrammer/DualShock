#include <string>

#include <raylib.h>
#include <iostream>
#include <vector>

#define RAYGUI_IMPLEMENTATION

#include "extras/raygui.h"

void playDialogue(std::vector<std::string> what, Vector2 textPosition, int time, int phraseLength) {
    int dialogueIndex = time / phraseLength;
    DrawText(what[dialogueIndex].c_str(), textPosition.x, textPosition.y, 22, WHITE);
}


int main() {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int move = 0, jump = 1, tntTimer = 5, scene2 = 0, PlayerAnimation = 1, Dx = 0, Dy = 120, PlayerAnimationOld = 1, Size = 140,timer2=0;
    InitWindow(screenWidth, screenHeight, "raylib [core] example");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------
    Vector2 ballCenter = {200, 280};
    Vector2 wallPosition = {655, 0};
    Vector2 wallSize = {300, screenHeight};
    Vector2 ballCenterGreen = {180, 320};
    Vector2 ballCenterBlue = {220, 320};
    Vector2 ballCenterRed = {240, 320};
    float yBallSpeed = 0, ap = 0, app = 1;
    float xBallSpeed = 0, scene = 0, cheats = 0;
    float radius = 50, carx = -50, time = 0, doorV = 0;
    Texture2D texture = LoadTexture("car.png");
    Texture2D back = LoadTexture("city2_long.png");
    Texture2D door = LoadTexture("door.png");
    Texture2D door2 = LoadTexture("door2.png");
    Texture2D house = LoadTexture("house.png");
    Texture2D TNT = LoadTexture("TNT.png");
    Texture2D off = LoadTexture("hgf.png");
    Texture2D on = LoadTexture("on.png");
    Texture2D BOOM = LoadTexture("BOOM.png");
    Texture2D houseOpen = LoadTexture("HouseOpen.png");
    Texture2D door3 = LoadTexture("Door3.png");
    Texture2D Player = LoadTexture("FG.png");
    float sceneHeight = back.height / 2;
    float sceneWidth = 250, tnt = 0, timer = 1,TO_BE_CONTINUED=0;
    Color ballColor = RED;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_LEFT)) {
            xBallSpeed = -3;
            PlayerAnimation = -2;
            PlayerAnimationOld = -1;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            xBallSpeed = 3;
            PlayerAnimation = 2;
            PlayerAnimationOld = 1;
        }
        if (IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_LEFT)) {
            if (PlayerAnimationOld == -1) {
                PlayerAnimation = 1;
            }
            if (PlayerAnimationOld == 1) {
                PlayerAnimation = -1;
            }
        }
        if (ballCenter.y <= radius && scene != 4) {
            if (cheats == 0) {
                yBallSpeed = 0;
                ballCenter.y = radius;
            }
            if (scene == 2) {
                scene = 3;
                ballCenter.y = 400;
            }

        }

        if (ballCenter.y + radius >= screenHeight - 80 && scene != 3) {
            yBallSpeed = 0;
            ballCenter.y = screenHeight - radius - 80;
            jump = 1;
            if (scene == 4) {
                scene = 4.5;
            }
        } else {
            yBallSpeed += 0.2;
        }


        if (scene == 2 && cheats == 0 && CheckCollisionCircleRec
                (ballCenter, radius,
                 {
                         wallPosition.x,
                         wallPosition.y,
                         wallSize.x,
                         wallSize.y
                 }
                )) {
            yBallSpeed = 0;
            xBallSpeed = -5;
            jump = 1;
        }

        if (cheats == 0 && (scene == 2 || scene2 == 3) && CheckCollisionCircleRec
                (ballCenter, radius,
                 {
                         -50,
                         0,
                         50,
                         450
                 }
                )) {
            if (!IsKeyPressed(KEY_RIGHT)) {
                xBallSpeed = 0;
                ballCenter.x = 50;
            }
            if (scene2 == 3) {
                scene2 = 4;
            }

        }
        if(jump==1) {
            if (PlayerAnimation == 1) {
                Dx = 60;
                Dy = 120;
            }

            if (PlayerAnimation == -1) {
                Dx = 0;
                Dy = 120;

            }
            if (PlayerAnimation == 2) {
                timer2++;
                if (timer2 == 10) {
                    Dx += 60;
                    timer2 = 0;
                }
                Dy = 60;

            }
            if (PlayerAnimation == -2) {

                timer2++;
                Dy = 0;
                if (timer2 == 10) {
                    Dx += 60;
                    timer2 = 0;
                }

            }
        }
        else{
            if(PlayerAnimationOld==1){
                Dy=60;
                Dx=120;
            }
            else{
                Dy=0;
                Dx=120;
            }
        }
            if ((scene == 4 || scene == 4.5 || scene == 5 || scene == 5.5) && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             50,
                             0,
                             50,
                             450
                     }
                    )) {
                if (!IsKeyPressed(KEY_RIGHT)) {
                    xBallSpeed = 0;
                    ballCenter.x = 150;
                    PlayerAnimation = 1;
                    if (scene == 5) {
                        scene = 5.5;

                    }
                    if (scene == 5.5) {
                        doorV++;

                    }
                }

            }
            if (CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             800,
                             0,
                             50,
                             450
                     }
                    )) {
                if (tnt == 100 && scene2 == 0) {
                    scene2 = 2;
                }
                if (!IsKeyPressed(KEY_LEFT)) {
                    xBallSpeed = 0;
                    ballCenter.x = 750;
                    PlayerAnimation = -1;
                }

            }
            if ((scene == 4 || scene == 4.5 || scene == 5 || scene == 5.5) && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             0,
                             50,
                             650,
                             10
                     }
                    )) {
                yBallSpeed = 0;

                jump = 1;
            }
            if (scene == 3 && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             wallPosition.x,
                             wallPosition.y + 180,
                             10,
                             wallSize.y
                     }
                    )) {
                yBallSpeed = 0;
                xBallSpeed = -5;
                jump = 1;
            }
            if (scene == 3 && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             0,
                             700,
                             600,
                             10
                     }
                    )) {
                scene = 2;
                ballCenter.x = ballCenterRed.x;
                ballCenter.y = ballCenterRed.y;
            }
            if (tnt == 5 && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             0,
                             200,
                             230,
                             300
                     }
                    )) {
                scene = 4;
                tnt = 0;
                doorV = 0;
                ballCenter.y = 20;
            }
            if (scene == 3 && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             wallPosition.x,
                             wallPosition.y + 175,
                             wallSize.x,
                             10
                     }
                    )) {
                yBallSpeed = 0;

                jump = 1;
            }
            if (scene == 3 && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             wallPosition.x,
                             wallPosition.y,
                             wallSize.x,
                             50
                     }
                    )) {
                yBallSpeed = 1;

            }
            if (cheats == 1) {
                jump = 1;
                move = 1;
            }
            if (IsKeyPressed(KEY_UP) && jump == 1) {
                yBallSpeed = -5;
                jump = 0;
            }
            if (IsKeyPressed(KEY_G)) {
                cheats = 1;
            }

            if (scene == 0)move = 0;//сцена 1
            if (scene == 1)move = 0;//сцена 2
            if (scene == 1.5)move = 0;//сцена 3
            if (scene == 2)move = 1;//поле 1 дверь
            if (scene == 3)move = 1;//поле 2 труба
            if (scene == 4)move = 1;//поле 3 дом
            if (scene == 4.5)move = 1;//сцена 4 дом
            if (scene == 5)move = 1;// подземка
            if (scene == 6)move = 1;//поле 4 р
            if (tnt == 7)move = 1;

            xBallSpeed *= 0.95;
            ballCenter.y += yBallSpeed;
            ballCenter.x += xBallSpeed;


            //background:
            if (scene == 0) {
                DrawTexturePro(back,
                               {0, back.height / 2, sceneWidth, sceneHeight},
                               {0, 0, screenWidth, screenHeight},
                               {0, 0},
                               0, WHITE);
            }
            if (scene == 1 || scene == 2 || scene == 1.5) {
                DrawTexturePro(back,
                               {250, back.height / 2, sceneWidth, sceneHeight},
                               {0, 0, screenWidth, screenHeight},
                               {0, 0},
                               0, WHITE);
                DrawTexturePro(door,
                               {0, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {1030, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {0, 0},
                               90, WHITE);
            }
            if (scene2 == 4 || scene2 == 5) {
                DrawTexturePro(texture,
                               {0, 0, (float) texture.width, (float) texture.height},
                               {carx, 225, (float) 300, (float) 200},
                               {0, 0},
                               0, WHITE);
                DrawTexturePro(back,
                               {250, back.height / 2, sceneWidth, sceneHeight},
                               {0, 0, screenWidth, screenHeight},
                               {0, 0},
                               0, WHITE);
                DrawTexturePro(door3,
                               {0, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {1030, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {0, 0},
                               90, WHITE);
                TO_BE_CONTINUED=1;
            }
            if (scene == 4 || scene == 4.5 || scene == 5 || scene == 5.5) {
                DrawTexturePro(house,
                               {0, 0, 800, 450},
                               {0, 0, screenWidth, screenHeight},
                               {0, 0},
                               0, WHITE);

            }
            if (scene2 != 4 && scene2 != 5) {
                if (7 == tnt || tnt == 100) {
                    DrawTexturePro(houseOpen,
                                   {0, 0, 800, 450},
                                   {0, 0, screenWidth, screenHeight},
                                   {0, 0},
                                   0, WHITE);
                    ballCenterRed.x = ballCenter.x;
                    ballCenterRed.y = ballCenter.y;
                }
            }
            if (ballCenterGreen.x < 400 && tnt == 7) {
                ballCenterGreen.x += 1.2;
                ballCenterBlue.x++;

            }

            if (scene == 3) {
                DrawTexturePro(back,
                               {250, back.height / 4, sceneWidth, sceneHeight},
                               {0, 0, screenWidth, screenHeight},
                               {0, 0},
                               0, WHITE);
                DrawTexturePro(door2,
                               {0, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {1030, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {0, 0},
                               90, WHITE);
            }

            BeginDrawing();

            if (scene == 1.5 || scene == 2 || tnt == 7 || tnt == 100 || scene == 6) {
                if (scene == 1.5) {
                    move = 0;
                    DrawCircleV(ballCenterRed, radius, ballColor);
                }

                DrawCircleV(ballCenterGreen, radius, DARKGREEN);
                DrawCircleV(ballCenterBlue, radius, DARKBLUE);
            }
            if (move == 1) {
                DrawTexturePro(Player,
                               {static_cast<float>(Dx), static_cast<float>(Dy), 60, 60},
                               {ballCenter.x - 80, ballCenter.y - 80, static_cast<float>(Size),
                                static_cast<float>(Size)},
                               {0, 0},
                               0, WHITE);
            }
            ClearBackground(GRAY);
            if (scene != 3) {
                DrawRectangle(0, 370, 800, 80, BLACK);
            }
            if (scene == 1 && carx > 600)carx = -200;
            if (scene == 0 || scene == 1 || scene == 2 || scene == 1.5) {
                DrawTexturePro(texture,
                               {0, 0, (float) texture.width, (float) texture.height},
                               {carx, 225, (float) 300, (float) 200},
                               {0, 0},
                               0, WHITE);
            }
            if (carx <= screenWidth - 100 && scene == 0) {
                carx += 1.5;
            }
            if (carx >= screenWidth - 100 && scene == 0) {
                scene++;
            }
            if (cheats == 1) {
                if (IsKeyPressed(KEY_U)) {
                    scene++;
                }
                DrawCircleV(ballCenter, radius, WHITE);
                DrawText("CHEATS ON", 350, 50, 30, GREEN);
            }
            if (scene2 == 2) {
                int phraseLength = 200;

                playDialogue(
                        std::vector<std::string>{"Wait.", "", "the door is clothed", ""},
                        {150, 400},
                        time,
                        phraseLength);
                playDialogue(
                        std::vector<std::string>{"", "", "", "I'll go to the car, look for more dynamite.",
                                                 "If you don't want to wait, you can try to hack it."},
                        {70, 400},
                        time,
                        phraseLength);
                time = (int) (++time) % (phraseLength * 4);
                if (time == 0) {
                    scene2 = 3;
                }
            }
            if (ballCenterGreen.x >= 400 && tnt == 7) {

                int phraseLength = 150;

                playDialogue(
                        std::vector<std::string>{"You : No car here!", "Do you see that black car?", "", "", "", "",
                                                 "You: I like the situation better",
                                                 "Well, they couldn't take it like that and dissolve in the air"},
                        {150, 400},
                        time,
                        phraseLength);

                playDialogue(
                        std::vector<std::string>{"", "", "", "Victor: Maybe not that garage?", "",
                                                 "Victor: Yes, we are wasting time.", "", ""},
                        {150, 400},
                        time,
                        phraseLength);
                playDialogue(
                        std::vector<std::string>{"", "", "Charlie: I don't understand...", "",
                                                 "Charlie: No. Green door. The same one.", "", "", ""},
                        {70, 400},
                        time,
                        phraseLength);
                time = (int) (++time) % (phraseLength * 8);
                if (time == 0) {
                    tnt = 100;
                    ballCenter = ballCenterRed;
                }
            }
            if (carx < 50 && scene == 1) {
                carx += 0.6;
            }
            if (scene == 1 && carx > 600)carx = -200;
            if (carx > 50 && scene == 1) {
                scene = 1.5;
            }
            if (scene == 1 || scene == 2 || scene == 1.5) {
                DrawTexturePro(door,
                               {0, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {1030, 0, static_cast<float>(door.width), static_cast<float>(door.height)},
                               {0, 0},
                               90, WHITE);
            }
            if (scene == 1.5 && ballCenterRed.x < 550) {
                ballCenterBlue.x++;
                ballCenterRed.x += 1.5;
                ballCenterGreen.x += 0.7;
            }
            if (scene == 5.5 && tnt == 0) {
                DrawText("placing bomb", 50, 375, 22, GREEN);
                DrawRectangle(doorV, 400, 5, 20, RED);
                ballCenter.x = 150;
                if (doorV == 600)tnt = 1;
            }
            if (scene == 5.5) {
                if (tnt == 0) {
                    DrawTexturePro(TNT,
                                   {0, 0, (float) TNT.width, (float) TNT.height},
                                   {ballCenter.x, ballCenter.y, 50, 50},
                                   {0, 0},
                                   0, WHITE);
                }
                if (tnt == 1) {
                    DrawTexturePro(TNT,
                                   {0, 0, (float) TNT.width, (float) TNT.height},
                                   {75, 250, 75, 75},
                                   {0, 0},
                                   0, WHITE);

                    timer++;
                    if (timer > 0 && timer < 50)DrawText("00:05", 50, 375, 22, RED);
                    if (timer > 50 && timer < 100)DrawText("00:04", 50, 375, 22, RED);
                    if (timer > 100 && timer < 150)DrawText("00:03", 50, 375, 22, RED);
                    if (timer > 150 && timer < 200)DrawText("00:02", 50, 375, 22, RED);
                    if (timer > 200 && timer < 250)DrawText("00:01", 50, 375, 22, RED);
                    if (timer > 250 && timer < 300)DrawText("00:00", 50, 375, 22, RED);
                    if (timer == 300) {
                        tnt = 5;
                        timer = 0;
                    }

                }
                if (tnt == 5) {
                    if (timer < 50) {
                        DrawTexturePro(BOOM,
                                       {0, 0, (float) BOOM.width, (float) BOOM.height},
                                       {-100, 125, 400, 300},
                                       {0, 0},
                                       0, WHITE);
                    }
                    timer++;
                    if (timer > 50) {
                        scene = 5.6;
                        tnt = 7;
                        ballCenterGreen.x = -100;
                        ballCenterBlue.x = -200;
                    }
                }
            }
            if (scene2 == 3)ballCenterGreen.x--;
            if (scene == 1.5 && ballCenterRed.x >= 500) {
                int phraseLength = 150;

                playDialogue(
                        std::vector<std::string>{"You (Red): Quiet.", "", "", "",
                                                 "You: We don't have time to hang around here.",
                                                 "I'll get inside - you wait here."},
                        {150, 400},
                        time,
                        phraseLength);

                playDialogue(
                        std::vector<std::string>{"", "Victor (Blue): Do you think they are there?", "", "", "", ""},
                        {150, 400},
                        time,
                        phraseLength);
                playDialogue(
                        std::vector<std::string>{"", "",
                                                 "Charlie (Green): Well, we can't just take it and break in there.", "",
                                                 "", ""},
                        {70, 400},
                        time,
                        phraseLength);
                time = (int) (++time) % (phraseLength * 6);
                if (time == 0) {
                    scene = 2;
                    ballCenter = ballCenterRed;
                }
            }
            if (scene == 4.5) {
                int phraseLength = 150;

                playDialogue(
                        std::vector<std::string>{"You: Where did they go?", "How can it be?"},
                        {150, 400},
                        time,
                        phraseLength);
                time = (int) (++time) % (phraseLength * 2);
                if (time == 0) {
                    scene = 5;
                }
            }


            if (scene == 3 && CheckCollisionCircleRec
                    (ballCenter, radius,
                     {
                             780,
                             0,
                             50,
                             sceneHeight
                     }
                    )) {

                if (ap < 400 && app == 1) {
                    ap += 5;
                    if (ap == 220) {
                        ballCenter.y = 0;
                        ballCenter.x = 60;
                        scene = 4;
                    }
                }
                if (ap > 395) {
                    app = 2;
                }
                if (app == 2 && ap > 0)ap -= 5;
                if (app == 2 && ap == 0)app = 1;
                DrawRectangle(0, 0, 800, 450, {0, 0, 0, ap});

            }
            if(TO_BE_CONTINUED==1){
                DrawText("Thanks For Playing!     To be continued...",40,40,30,ORANGE);
            }

            EndDrawing();

            //----------------------------------------------------------------------------------
        }
        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

        return 0;
    }
