#include "DxLib.h"
#include "score.h"
#include <string>
using namespace std;

VOID DrawScore(int leftscore,int rightscore)
{
	string str = to_string(leftscore);

	DrawString(10, 60, str.c_str(), GetColor(255, 255, 255));

	str = to_string(rightscore);

	DrawString(640 - 10, 60, str.c_str(), GetColor(255, 255, 255));
}