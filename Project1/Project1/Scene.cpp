#include "DxLib.h"
#include "Scene.h"
#include "bll.h"
#include "padlle.h"
#include "Key.h"
#include "Sounds.h"
#include <string>

using namespace std;
int volume = 100;


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
	case inSetting:
		DrawSetting(volume);
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

	DrawString(startX, startY, "START", selectedItem == 0 ? GetColor(255, 0, 0) : GetColor(255, 255, 255));
	DrawString(startX, startY + 30, "SETTING", selectedItem == 2 ? GetColor(255, 0, 0) : GetColor(255, 255, 255));
	DrawString(startX, endY + 20, "END", selectedItem == 1 ? GetColor(255, 0, 0) : GetColor(255, 255, 255));

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
		selectedItem = (selectedItem == START) ? SETTING : (selectedItem == SETTING) ? END : START;
	}
	if(Key[KEY_INPUT_UP] == 1)
	{
		selectedItem = (selectedItem == START) ? END: (selectedItem == END) ? SETTING : START;
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
		else if (selectedItem == SETTING)
		{
			ChangeScene(inSetting);
		}
	}
}

VOID DrawSetting(int GetVolume)
{
	int startX = WINDOW_WIDTH / 2 - 50;
	int startY = WINDOW_HEIGHT / 2 - 20;

	//長押しでも音量を変更できるように
	if (Key[KEY_INPUT_DOWN] == 1 || Key[KEY_INPUT_DOWN] >= 60)
	{
		GetVolume = GetVolume > 0 ? GetVolume - 1 : 0;
	}
	if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_UP] >= 60)
	{
		GetVolume = GetVolume < 100 ? GetVolume + 1 : 100;
	}

	volume = GetVolume; // 現在の音量を更新
	int dxVolume = volume * 255 / 100; 

	ChangeVolumeSoundMem(dxVolume, PADDLESOUND.GetHandle());
	ChangeVolumeSoundMem(dxVolume, SCORESOUND.GetHandle());

	DrawFormatString(startX, startY, GetColor(255, 255, 255), "Volume: %d", volume);

}


//多分使用しない(重すぎるから)
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