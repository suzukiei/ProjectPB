#include "DxLib.h"
#include "bll.h"
#include "score.h"

BOOL VXVY;

VOID InitBall(BALL& ball,int startx,int starty,int startVx,int startVy,int radius,unsigned int col)
{
	VXVY = (BOOL)GetRand(1);

	//�ŏ��̋����ň�������vxvy���΂�Ȃ��悤�ɂ���
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


VOID UpdateBall(BALL& ball, int screenWidth, int screenHeight,SCORE& leftScore,SCORE& rightScore)
{
	ball.x += ball.vx;
	ball.y += ball.vy;
	
	// �ǂɏՓ˂����ꍇ�̔���
	if (ball.x - ball.radius < 0 || ball.x + ball.radius > screenWidth) {
		ball.vx = -ball.vx;

		if (ball.x - ball.radius < 0)
		{
			leftScore.points += 1;
		}
		else if (ball.x + ball.radius > screenWidth)
		{
			rightScore.points += 1;
		}
	}
	if (ball.y - ball.radius < 0 || ball.y + ball.radius > screenHeight) {
		ball.vy = -ball.vy;
	}

	return;
}

VOID DrawBall(const BALL& ball) {

	DrawCircle(ball.x, ball.y, ball.radius, ball.color, TRUE);

	return;
}

//����̓f�o�b�O�p ��ȗp�r�͔���̈ʒu���m�F�����
VOID DrawBallOutline(const BALL& ball,unsigned int col)
{
	DrawCircle(ball.x, ball.y, ball.radius,col,FALSE);
	
	return;
}
