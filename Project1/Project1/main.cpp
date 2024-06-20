#include "DxLib.h"
#include "bll.h"
#include "padlle.h"
#include "Scene.h"
#include "score.h"

#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640

int NowScene = inGame;
SCORE leftScore, rightScore;
BALL ball;
PADDLE leftpaddle, rightpaddle;

VOID Init(BALL& ball, PADDLE& leftpaddle, PADDLE& rightpaddle);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		
	{
		return -1;			
	}
	unsigned int BorderCol = GetColor(255, 255, 255);

	

	Init(ball,leftpaddle,rightpaddle); //まとめて初期化する	

	ChangeWindowMode(TRUE);

	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	


	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();

		
		DrawLine(0, 0, 0, 480, BorderCol); //左
		DrawLine(640, 0, 640, 480, BorderCol);//右

		ChangeScene(NowScene, KEY_INPUT_ESCAPE);

		UpdateBall(ball, WINDOW_WIDTH,WINDOW_HEIGHT,leftScore,rightScore);
		UpdatePaddle(leftpaddle, KEY_INPUT_W, KEY_INPUT_S,WINDOW_HEIGHT);
		UpdatePaddle(rightpaddle, KEY_INPUT_UP,KEY_INPUT_DOWN,WINDOW_HEIGHT);
		
		CheckPaddleCollision(ball, leftpaddle);
		CheckPaddleCollision(ball, rightpaddle);

		DrawBall(ball);
		//DrawBallOutline(ball, GetColor(0, 255, 0)); debug用
		DrawPaddle(leftpaddle);
		DrawPaddle(rightpaddle);
		DrawScore(leftScore.points, rightScore.points);
		
		
		DebugMode(ball, leftpaddle);

		ScreenFlip();
	}


					

	DxLib_End();				

	return 0;				
}


VOID Init(BALL& ball,PADDLE& leftpaddle,PADDLE& rightpaddle) {

		
	InitBall(ball, 320, 240, 5, 5, 5, GetColor(255, 0, 0)); // 中心、移動速度、半径、色

	
	InitPaddle(leftpaddle, 50, 200, 60, 10, GetColor(255, 255, 255));
	InitPaddle(rightpaddle, 580, 200, 60, 10, GetColor(255, 255, 255));

	return;
}