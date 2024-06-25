#pragma once
#include "DxLib.h"

#define GAME_FPS 60

extern const int SampleNumFps;
extern int CountFps;
extern int StartTimeFps;
extern float CalcFps;

VOID MY_FPS_UPDATE(VOID);
VOID MY_FPS_WAIT(VOID);

////--------�o�ߎ��ԃJ�E���g�N���X--------
//class TIME_COUNT
//{
//private:
//	int TimeCou = 0;
//	BOOL CountFlag = false;
//
//public:
//	//----�J�E���g������----
//	VOID RESET(VOID)
//	{
//		TimeCou = 0;
//		return;
//	}
//	//----�J�E���g�J�n----
//	VOID START(VOID)
//	{
//		CountFlag = TRUE;
//		return;
//	}
//	//----���݂̌o�ߎ���----
//	int NOW(VOID)
//	{
//		return(TimeCou / GAME_FPS);
//	}
//	//----�J�E���g��~----
//	VOID STOP(VOID)
//	{
//		CountFlag = FALSE;
//		return;
//	}
//	//----�J�E���g---
//	VOID UPDATE(VOID)
//	{
//		if (CountFlag)TimeCou++;
//		return;
//	}
//
//};