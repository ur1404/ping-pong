#include <raylib.h>

int player_score = 0;
int cpu_score = 0;

int main(){
class Ball{
  public:
float x,y;
int speed_x, speed_y;
int radius;  
   void draw(){
DrawCircle(x,y,radius,WHITE);

   };       
    void Update(){
      x += speed_x;
      y += speed_y;      
        
        if (y + radius>= GetScreenHeight() || y + radius <= 0){
;            speed_y *= -1;
        };
        if (x + radius >= GetScreenWidth())
        {cpu_score++
    ;ResetBall();};

            if (x + radius <= 0){
                {player_score++
                ;ResetBall();};
          speed_x *= -1;  
        };
    };
    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;

        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    };
};


class Paddle{
  protected:
void LimitMovement(){
         if(y <= 0){
        y = 0;};
        if (y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;};
}    

 public:
    float x,y;
    float width, height;
    int speed;
    void drawpad(){
         DrawRectangle(x, y, width, height, WHITE);
        
    };
    
    void Update2(){
        if(IsKeyDown(KEY_W)){
        y = y - speed;};
         if(IsKeyDown(KEY_S)){
        y = y + speed;};
        if(y <= 0){
        y = 0;};
        if (y + height >= GetScreenHeight()){
        y = GetScreenHeight() - height;};
        
        LimitMovement();
    };
      
};

class CPUpaddle:public Paddle{
    public:
    void Update3(int ball_y){
        if (y + height / 2 > ball_y) {
            y = y - speed;
        }
        if (y + height / 2 <= ball_y) {
            y = y + speed;
        }
       LimitMovement();
    };
        
        
    
    
    
    
};


Ball ball1;
Paddle player;
CPUpaddle cpu;
  const int screenheight = 800;
  const int screenwidth = 1280;
  InitWindow(screenwidth, screenheight, "welcome to ping pong");
  SetTargetFPS(60);
  ball1.radius = 20;
  ball1.x = screenwidth/2;
  ball1.y = screenheight/2;
  ball1.speed_x = 7;
  ball1.speed_y = 7;
  
  player.width = 25;
  player.height = 120;
  player.x = screenwidth - player.width - 10;
  player.y = screenheight/2 - player.height/2;
  player.speed = 6;
  
  cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screenheight / 2 - cpu.height / 2;
    cpu.speed = 6;

  
  while(WindowShouldClose() == false){
      
      ball1.Update();
      player.Update2();
      cpu.Update3(ball1.y);
      if(CheckCollisionCircleRec(Vector2{ball1.x, ball1.y}, ball1.radius, Rectangle{player.x, player.y, player.width, player.height})){
         ball1.speed_x *= -1; 
          
      };
      if(CheckCollisionCircleRec(Vector2{ball1.x, ball1.y}, ball1.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
         ball1.speed_x *= -1; 
          
      };
      
      ClearBackground(BLACK);
     BeginDrawing();
     DrawLine(screenwidth/2, 0, screenwidth/2, screenheight, WHITE);
     ball1.draw();
     player.drawpad();
     cpu.drawpad();
     DrawText(TextFormat("%i", cpu_score), screenwidth / 4 - 20, 20, 80, WHITE);
     DrawText(TextFormat("%i", player_score), 3 * screenwidth / 4 - 20, 20, 80, WHITE);
     EndDrawing();
      
      
      
  };
  
  
  
  
  CloseWindow();
    return 0;
};