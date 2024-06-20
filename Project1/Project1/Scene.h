#pragma once
#include "bll.h"
#include "padlle.h"

enum Scene
{
	inGame,
	inDebug
};

extern int NowScene;

VOID ChangeScene(int SceneNumber, int esckey);
VOID DebugMode(const BALL& ball, const PADDLE& paddle);