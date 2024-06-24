#pragma once
#include "DxLib.h"

#define GAME_FPS 60
//--------経過時間カウントクラス--------
class TIME_COUNT
{
private:
	int TimeCou = 0;
	BOOL CountFlag = false;

public:
	//----カウント初期化----
	VOID RESET(VOID)
	{
		TimeCou = 0;
		return;
	}
	//----カウント開始----
	VOID START(VOID)
	{
		CountFlag = TRUE;
		return;
	}
	//----現在の経過時間----
	int NOW(VOID)
	{
		return(TimeCou / GAME_FPS);
	}
	//----カウント停止----
	VOID STOP(VOID)
	{
		CountFlag = FALSE;
		return;
	}
	//----カウント---
	VOID UPDATE(VOID)
	{
		if (CountFlag)TimeCou++;
		return;
	}

};