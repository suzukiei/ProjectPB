#pragma once
#include "bll.h"
#include "padlle.h"
#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640

enum ScenE
{
	inMenu,
	inGame,
	inDebug,
	inSetting,
	inEnd
};

enum SelectMenu
{
	START,
	END,
	SETTING,
	DEBUG
};
extern int NowScene;

VOID ChangeScene(int SceneNumber);
VOID DebugMode(const BALL& ball, const PADDLE& paddle);
VOID Scene(int SceneNumber, BALL& ball, PADDLE& leftpaddle, PADDLE& rightpaddle, SCORE& leftScore, SCORE& rightScore,int framecount);
VOID DrawStartMenu(SelectMenu selectedItem,int framecount);
VOID DrawGame(BALL& ball, PADDLE& leftpaddle, PADDLE& rightpaddle, SCORE& leftScore, SCORE& rightScore);
VOID UpdateStartMenu(SelectMenu& selectedItem);
VOID DrawSetting(int volume);
VOID ApplyMosaicEffect();