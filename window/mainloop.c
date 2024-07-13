#include "mainloop.h"
#include "raylib.h"
#include <stdlib.h>

#define SCREEN_H 1080
#define SCREEN_W 1920

#define BACKGROUND CLITERAL(Color){ 86, 147, 175, 255 }
#define BALL_IMG "window/assets/imgs/looking_hell.png"


float full_time  ;
float left_time  ;

void drow_slider(float precent){
    Rectangle rec_lines = {10.0f, 1000.0f, 1900.0f, 20.0f};
    // Rectangle rec_slider = {13.0f, 1003.0f, (1900.0f - 6.0f), (20.0f - 0.06f)};


    DrawRectangleLinesEx(rec_lines, 3, BLACK);
    DrawRectangle(13 ,  1003, (int)((1900 - 6 ) * precent), 20 - 6, RED);
    // DrawRectangleLines(10, 1000, 1900, 20, BLUE);
}


void main_loop(float live_time){
    full_time = live_time;
    left_time = live_time;
    InitWindow(SCREEN_W , SCREEN_H, "Keep your eye health");
    SetTargetFPS(60);
    SetWindowState(FLAG_FULLSCREEN_MODE);

    Texture2D photo = LoadTexture(BALL_IMG);
    Vector2 img_pos = {550 , 10};
    img_pos.x = SCREEN_W /2 - (photo.width /2 *0.5f);

    Font main_font = LoadFont("window/assets/fonts/Montserrat_MediumItalic.ttf");


    while (!WindowShouldClose())
    {
        if(left_time <= 0) break;

        BeginDrawing();
            ClearBackground(BACKGROUND);
            DrawTextureEx(photo,img_pos,0.0f,0.5f, WHITE);
            DrawTextEx(main_font , "Take a break!", (Vector2){850 , 550} , 30, 1, BLACK);
            DrawTextEx(main_font ,  "Staring at screens for long periods can strain your eyes.", (Vector2){600 , 580} , 30, 1, BLACK);
            DrawTextEx(main_font ,  "Look away, stretch, and rest.", (Vector2){750 , 610} , 30, 1, BLACK);
            
            const char* clock = TextFormat("%i : %i", (int)(left_time / 60) , ((int)left_time % 60) );
	        const int textWidth = MeasureTextEx(GetFontDefault(), clock, 150, 1).x;
            DrawText(clock, SCREEN_W/2 - textWidth/2 , 700, 150, BLACK);
            
            drow_slider(left_time / full_time);

       EndDrawing();
       left_time -= GetFrameTime();

        if(IsKeyPressed(KEY_S)){
            TakeScreenshot("screenshot.png");
        }

        if((IsKeyDown(KEY_LEFT_CONTROL ) || IsKeyDown(KEY_RIGHT_CONTROL)) && IsKeyDown(KEY_X)){
            UnloadFont(main_font);
            UnloadTexture(photo); 
            CloseWindow();
            exit(0);
        }

    }

    UnloadFont(main_font);
    UnloadTexture(photo); 
    CloseWindow();
}