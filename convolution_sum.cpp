#include <cmath>
#include <iostream>
#include <raylib.h>
#include <raymath.h>

const int screenWidth = 1600;
const int screenHeight = 900;
const int pointCount = 300;

Vector2 center = {50.0f, 50.0f};


auto equation = [](auto a)  {return a * a * a;};
auto sin_signal = [] (auto t, auto f) {return std::sin(t * 360.0f * f);};

void DrawGraph(unsigned long pointCount, float startValue);
void DrawCoordinatePlane();

int main(void)
{
   
    InitWindow(screenWidth, screenHeight, "ConvolutionSum");
    
    while(!WindowShouldClose())
    {
        BeginDrawing(); 
       
        ClearBackground(RAYWHITE);

        DrawCoordinatePlane();

        DrawGraph(pointCount, 0.0f);

        EndDrawing();
    }
          
    CloseWindow();

    return 0;
    
}

void DrawGraph(int pointCount, float startValue){
    Vector2 pointsPositive[pointCount];
    Vector2 pointsNegative[pointCount];


    
    for(int i = 0; i < pointCount; i++)
    {


       pointsPositive[i] = {10 * (startValue * 100) + (screenWidth / 2) , -(sin_signal(startValue, 0.2f) * 100) + (screenHeight / 2) }; 
       
       startValue = startValue + 0.001f;

    }
    
    startValue = 0.0f;

    for(int i = 0; i < pointCount; i++)
    {
        startValue = startValue - 0.01f;
        pointsNegative[i] = {(startValue * 200) + (screenWidth / 2) , -(equation(startValue) * 200) + (screenHeight / 2)};     

    }
      
       DrawSplineBezierCubic(pointsPositive, pointCount, 2, BLUE);
      // DrawSplineBezierCubic(pointsNegative, pointCount, 2, BLUE);
     
}
void DrawCoordinatePlane()
{
  Vector2 horizontalStartPos;
  Vector2 horizontalEndPos;

  horizontalStartPos = (Vector2){800 , 150};
  horizontalEndPos = (Vector2){800 , 750};
  
  Vector2 verticalStartPos;
  Vector2 verticalEndPos; 
  
  verticalStartPos = (Vector2){500, 450};
  verticalEndPos = (Vector2) {1100, 450};  

  DrawLineEx(horizontalStartPos, horizontalEndPos, 2, RED);
  DrawLineEx(verticalStartPos, verticalEndPos, 2, RED);
      
}



