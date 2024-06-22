#include "DxLib.h"
#include "Scene.h"
#include "bll.h"
#include "padlle.h"
#include "Key.h"
#include <string>

using namespace std;


VOID Scene(int SceneNumber, BALL& ball, PADDLE& leftpaddle, PADDLE& rightpaddle, SCORE& leftScore, SCORE& rightScore,int framecount)
{
	static SelectMenu selectedItem = START;

	switch (SceneNumber)
	{
	case inMenu :
		UpdateStartMenu(selectedItem);
		DrawStartMenu(selectedItem,framecount);
		break;
	case inGame:
		DrawGame(ball,leftpaddle,rightpaddle,leftScore,rightScore);
		break;
	case inDebug:
		DebugMode(ball,leftpaddle);
		break;
	case inEnd:
		break;

	default:
		break;
	}
}

VOID ChangeScene(int SceneNumber)
{
	NowScene = SceneNumber;
	
}

VOID DebugMode(const BALL& ball, const PADDLE& paddle)
{
	if (NowScene == inDebug)
	{

		DrawString(10, 480 - 110, ("NowbPositionX" + to_string(ball.x)).c_str() , GetColor(255, 255, 255));
		DrawString(10, 480 - 90, ("NowbPositionY" + to_string(ball.y)).c_str(), GetColor(255, 255, 255));
		DrawString(10, 480 - 70, ("NowPPositionX" + to_string(paddle.x)).c_str(), GetColor(255, 255, 255));
		DrawString(10, 480 - 50, ("NowPPositionY" + to_string(paddle.y)).c_str(), GetColor(255, 255, 255));
		DrawString(10, 480 - 30, ("KEY:" + to_string(Key[KEY_INPUT_DOWN])).c_str(), GetColor(255, 255, 255));
	}
	if (Key[KEY_INPUT_Q] == 1)
	{
		NowScene = inMenu;
	}
}

VOID DrawStartMenu(SelectMenu selectedItem,int frameCount)
{

	// STARTとENDの描画
	int startX = WINDOW_WIDTH / 2 - 50;
	int startY = WINDOW_HEIGHT / 2 - 20;
	int endY = startY + 40;

	//// グラデーションの色を計算
	//int r = (int)(127.5 * (1 + sin(frameCount * 2 * DX_PI / 60)));
	//int g = (int)(127.5 * (1 + sin(frameCount * 2 * DX_PI / 60 + 2 * DX_PI / 3)));
	//int b = (int)(127.5 * (1 + sin(frameCount * 2 * DX_PI / 60 + 4 * DX_PI / 3)));
	//unsigned int color = GetColor(r, g, b);


	//DrawString(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 60, "PONPINBON", color);

	DrawString(startX, startY, "START", selectedItem == 0 ? GetColor(255, 0, 0) : GetColor(255, 255, 255));
	DrawString(startX, endY, "END", selectedItem == 1 ? GetColor(255, 0, 0) : GetColor(255, 255, 255));

}

VOID DrawGame(BALL& ball,PADDLE& leftpaddle,PADDLE& rightpaddle,SCORE& leftScore,SCORE& rightScore)
{
	UpdateBall(ball, WINDOW_WIDTH, WINDOW_HEIGHT, leftScore, rightScore);
	UpdatePaddle(leftpaddle, KEY_INPUT_W, KEY_INPUT_S, WINDOW_HEIGHT);
	UpdatePaddle(rightpaddle, KEY_INPUT_UP, KEY_INPUT_DOWN, WINDOW_HEIGHT);

	CheckPaddleCollision(ball, leftpaddle);
	CheckPaddleCollision(ball, rightpaddle);

	DrawBall(ball);
	//DrawBallOutline(ball, GetColor(0, 255, 0)); debug用
	DrawPaddle(leftpaddle);
	DrawPaddle(rightpaddle);
	DrawScore(leftScore.points, rightScore.points);


}

VOID UpdateStartMenu(SelectMenu& selectedItem)
{

	if (Key[KEY_INPUT_DOWN] == 1)
	{
		selectedItem = (selectedItem == START) ? END : START;
	}
	if(Key[KEY_INPUT_UP] == 1)
	{
		selectedItem = (selectedItem == END) ? START : END;
	}
	if (Key[KEY_INPUT_ESCAPE] == 1)
	{
		ChangeScene(inDebug);
	}
	if (Key[KEY_INPUT_RETURN] == 1)
	{
		if (selectedItem == START)
		{
			ChangeScene(inGame);
		}
		else if (selectedItem == END)
		{
			DxLib_End();
			exit(0);
		}
	}
}

VOID ApplyMosaicEffect()
{
	
	int mosaicSize = 10;

	for (int y = 0; y < WINDOW_HEIGHT; y += mosaicSize)
	{
		for (int x = 0; x < WINDOW_WIDTH; x += mosaicSize)
		{
			unsigned int color = GetPixel(x, y);
			DrawBox(x, y, x + mosaicSize, y + mosaicSize, color, TRUE);
		}
	}
}