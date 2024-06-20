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

//prototype ˆø”‚ÌŒ^‚ğ‚µ‚Á‚©‚è‚Æw’è‚µ‚Ä‚¨‚­‚±‚Æ LNK2019‚ÌŒ´ˆö‚Æ‚È‚é‚Ì‚Å

VOID InitBall(BALL& ball,int sx,int sy,int sVx,int sVy,int radi,unsigned int col);
VOID UpdateBall(BALL& ball, int scwidth, int scheight,SCORE& leftscore,SCORE& rightscore);
VOID DrawBall(const BALL& ball);
VOID DrawBallOutline(const BALL& ball,unsigned int color);
