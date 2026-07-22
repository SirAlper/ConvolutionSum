#include <raylib.h>
#include <cmath>

class AnalyticDraw
{
    private:
        int scale;
        int screenWidth;
        int screenHeight;
        int pointCount;
        float startValue;
        bool drawPositiveSide;
        bool drawNegativeSide;

    public:
        
        AnalyticDraw()
        {
            scale = 100;
            pointCount = 1000;
            screenHeight = GetScreenHeight();
            screenWidth = GetScreenWidth();
            drawPositiveSide = true;
            drawNegativeSide = false;
        }

        template<typename Func, typename... Args>

        void DrawGraph(Func func, Args... args )
        {
		    Vector2 pointsPositive[pointCount];
    		Vector2 pointsNegative[pointCount];

            startValue = 0.0f;
    
   		     for(int i = 0; i < pointCount; i++)
   		            {

      			        pointsPositive[i] = {10 * (startValue * scale) + (screenWidth / 2) , -(func(startValue,args...) * scale) + (screenHeight / 2) }; 
       
       			        startValue = startValue + 0.001f;

    		        }
    
   		    startValue = 0.0f;

    		for(int i = 0; i < pointCount; i++)
   		        {
      		  	startValue = startValue - 0.01f;
        		pointsNegative[i] = {(startValue * scale) + (screenWidth / 2) , -(func(args...) * scale) + (screenHeight / 2)};     

   		        }

            if(drawPositiveSide)
      		    DrawSplineBezierCubic(pointsPositive, pointCount, 2, BLUE);
     	    
            if(drawNegativeSide)
                DrawSplineBezierCubic(pointsNegative, pointCount, 2, BLUE);
         
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
        
        void SetScale(int paramScale)
        {
            scale = paramScale;  
        }
        
        void SetScreenWidth(int screenWidth)
        {
            screenWidth = screenWidth;
        }

        void SetScreenHeight(int screenHeight)
        {
            screenHeight = screenHeight;
        }

        void SetDrawPositiveSide()
        {
            drawPositiveSide = !drawPositiveSide;
        }

        void SetDrawNegativeSide()
        {
            drawNegativeSide = !drawNegativeSide;            
        }

        float GetStartValue()
        {
            return startValue;
        }
        
};

