#include "DxLib.h"
#include "bll.h"
#include "padlle.h"
#include "Scene.h"
#include "score.h"
#include "Key.h"



int NowScene = inMenu;
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

	

	Init(ball,leftpaddle,rightpaddle); //�܂Ƃ߂ď���������	

	ChangeWindowMode(TRUE);

	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	int frameCount = 0;


	//�v���Z�X���b�Z�[�W�Ɠ��������ăL�[���͂̎擾������ #1��̓��͂�1��̂ݎ󂯎�邽��#
	while (ProcessMessage() == 0 && UpdateKeys() == 0)
	{
		ClearDrawScreen();

		frameCount++;
				
		Scene(NowScene, ball,leftpaddle,rightpaddle,leftScore,rightScore,frameCount);

		DebugMode(ball, leftpaddle);

		ScreenFlip();
	}


					

	DxLib_End();				

	return 0;				
}


VOID Init(BALL& ball,PADDLE& leftpaddle,PADDLE& rightpaddle) {

		
	InitBall(ball, 320, 240, 3, 3, 5, GetColor(255, 0, 0)); // ���S�A�ړ����x�A���a�A�F

	
	InitPaddle(leftpaddle, 50, 200, 60, 10, GetColor(255, 255, 255));
	InitPaddle(rightpaddle, 580, 200, 60, 10, GetColor(255, 255, 255));

	return;
}