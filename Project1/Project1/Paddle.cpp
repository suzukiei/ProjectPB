#include "DxLib.h"
#include "padlle.h"
#include "bll.h"
#include "Sounds.h"


//‰Šú‰»
VOID InitPaddle(PADDLE& paddle, int x, int y, int height, int width, unsigned int col)
{
	paddle.x = x;
	paddle.y = y;
	paddle.height = height;
	paddle.width = width;
	paddle.col = col;
}


VOID UpdatePaddle(PADDLE& paddle,int upkey,int downkey,int ScHeight)
{
	if (CheckHitKey(upkey))
	{
		paddle.y -= 7;
	}
	else if(CheckHitKey(downkey))
	{
		paddle.y += 7;
	}

	if (paddle.y < 0)
	{
		paddle.y = 0;
	}

	if (paddle.y + paddle.height > ScHeight) {
		paddle.y = ScHeight - paddle.height;
	}

	return;
}

VOID DrawPaddle(const PADDLE& paddle)
{
	DrawBox(paddle.x, paddle.y, (paddle.x + paddle.width),(paddle.y + paddle.height),paddle.col,TRUE);

}

//ƒpƒhƒ‹‚Æ‚Ì“–‚½‚è”»’è
VOID CheckPaddleCollision(BALL& ball,const PADDLE& paddle)
{
	if (ball.x - ball.radius < paddle.x + paddle.width &&
		ball.x + ball.radius > paddle.x &&
		ball.y - ball.radius < paddle.y + paddle.height &&
		ball.y + ball.radius > paddle.y)
	{
		ball.vx = -ball.vx;

		SE_Paddle();

		if (ball.vx > 0)
		{
			ball.vx += 1;
		}
		else
		{
			ball.vx -= 1;
		}

		if (ball.vy > 0)
		{
			ball.vy += 1;
		}
		else
		{
			ball.vy -= 1;
		}
	}

	return;
}