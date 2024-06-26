#pragma once
#include "DxLib.h"
#include "score.h"

typedef struct _BALL{

	int x, y;
	int vx, vy;
	int radius;
	unsigned int color;

}BALL;

extern BOOL VXVY;

//prototype 引数の型をしっかりと指定しておくこと LNK2019の原因となるので

VOID InitBall(BALL& ball,int sx,int sy,int sVx,int sVy,int radi,unsigned int col);
VOID UpdateBall(BALL& ball, int scwidth, int scheight,SCORE& leftscore,SCORE& rightscore);
VOID DrawBall(const BALL& ball);
VOID DrawBallOutline(const BALL& ball,unsigned int color);
