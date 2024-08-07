#include "DxLib.h"
#include "bll.h"
#include "score.h"
#include "Sounds.h"
#include "Scene.h"

BOOL VXVY;

VOID InitBall(BALL& ball,int startx,int starty,int startVx,int startVy,int radius,unsigned int col)
{
	VXVY = (BOOL)GetRand(1);

	//最初の挙動で一定方向にvxvyが偏らないようにする
	if (VXVY == TRUE)
	{
		ball.vx = startVx;
		ball.vy = startVy;

	}
	else
	{
		ball.vx = -startVx;
		ball.vy = -startVy;
	}

	ball.x = startx;
	ball.y = starty;
	ball.radius = radius;
	ball.color = col;

	return;

}

//ボールと壁の判定
VOID UpdateBall(BALL& ball, int screenWidth, int screenHeight,SCORE& leftScore,SCORE& rightScore)
{
	if (!IsEND)
	{
		ball.x += ball.vx;
		ball.y += ball.vy;

		// 壁に衝突した場合の反射、そして速度をリセットする
		if (ball.x - ball.radius < 0 || ball.x + ball.radius > screenWidth) {

			ball.vx = -ball.vx;

			SE_Score();

			if (ball.x - ball.radius < 0)
			{
				rightScore.points += 1;
				ball.vx = 5;
				ball.vy = (ball.vy > 0 ? 5 : -5);

			}
			else if (ball.x + ball.radius > screenWidth)
			{
				leftScore.points += 1;
				ball.vx = -5;
				ball.vy = (ball.vy > 0 ? 5 : -5);


			}
		}
		if (ball.y - ball.radius < 0 || ball.y + ball.radius > screenHeight) {


			ball.vy = -ball.vy;
		}
	}

	return;
}

VOID DrawBall(const BALL& ball) {

	DrawCircle(ball.x, ball.y, ball.radius, ball.color, TRUE);

	return;
}

//これはデバッグ用 主な用途は判定の位置を確認する為
VOID DrawBallOutline(const BALL& ball,unsigned int col)
{
	DrawCircle(ball.x, ball.y, ball.radius,col,FALSE);
	
	return;
}
