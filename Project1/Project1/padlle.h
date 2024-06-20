#pragma once
#include "DxLib.h"
#include "bll.h"

typedef struct _paddle {
	
	int width, height;
	int x, y;
	unsigned int col;

}PADDLE;

//prototypeêÈåæ 

VOID InitPaddle(PADDLE& paddle, int x, int y, int height, int width, unsigned int col);
VOID UpdatePaddle(PADDLE& paddle, int upkey, int downkey, int Scheight);
VOID DrawPaddle(const PADDLE& paddle);
VOID CheckPaddleCollision(BALL& ball, const PADDLE& paddle);