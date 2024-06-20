#include "DxLib.h"
#include "Scene.h"
#include "bll.h"
#include "padlle.h"
#include <string>

using namespace std;

VOID ChangeScene(int SceneNumber, int esckey)
{
	char buf[256];

	GetHitKeyStateAll(buf);

	if (buf[esckey] != 0)
	{
		
			if (NowScene == inGame)
			{
				NowScene = inDebug;
			}
			else if (NowScene == inDebug)
			{
				NowScene = inGame;
			}
		
	}
	
}

VOID DebugMode(const BALL& ball, const PADDLE& paddle)
{
	if (NowScene == inDebug)
	{

		DrawString(10, 480 - 110, ("NowbPositionX" + to_string(ball.x)).c_str() , GetColor(255, 255, 255));
		DrawString(10, 480 - 90, ("NowbPositionY" + to_string(ball.y)).c_str(), GetColor(255, 255, 255));
		DrawString(10, 480 - 70, ("NowPPositionX" + to_string(paddle.x)).c_str(), GetColor(255, 255, 255));
		DrawString(10, 480 - 50, ("NowPPositionY" + to_string(paddle.y)).c_str(), GetColor(255, 255, 255));
	}
}