#include <iostream>
#include <raylib.h>

const int screenWidth = 900;
const int screenHeight = 600;


int main(void){

    InitWindow(screenWidth, screenHeight, "ConvolutionSum");

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
    
}
