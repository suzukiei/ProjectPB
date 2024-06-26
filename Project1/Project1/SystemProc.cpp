#include "Dxlib.h"
#include "Proc.h"

const int SampleNumFps = 60;
const int DURATION = 120;
int CountFps = 0;
int StartTimeFps = 0;
float CalcFps = 0.0f;

// FPSを更新する関数
VOID MY_FPS_UPDATE(VOID)
{
    if (CountFps == 0)
    {
        StartTimeFps = GetNowCount();
    }

    if (CountFps == SampleNumFps)
    {
        int now = GetNowCount();
        CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
        CountFps = 0;
        StartTimeFps = now;
    }

    CountFps++;
    return;
}


// FPSを制御する関数
VOID MY_FPS_WAIT(VOID)
{
    int now = GetNowCount();
    int elapsedTime = now - StartTimeFps;
    int waitTime = CountFps * 1000 / GAME_FPS - elapsedTime;

    

    if (waitTime > 0)
    {
        WaitTimer(waitTime);
    }
    return;
}

VOID TimeCount(VOID)
{
        //開始時の時間を記録
    static int startTime = GetNowCount();
    int frameStartTime = GetNowCount();
    int keikaTime = (frameStartTime - startTime) / 1000; // 経過時間（秒）

    DrawFormatString(200, 50, GetColor(255, 255, 255), "Time: %d / %d", keikaTime, DURATION);
}