#include "Dxlib.h"
#include "Proc.h"

const int SampleNumFps = 60;
int CountFps = 0;
int StartTimeFps = 0;
float CalcFps = 0.0f;

// FPS���X�V����֐�
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


// FPS�𐧌䂷��֐�
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