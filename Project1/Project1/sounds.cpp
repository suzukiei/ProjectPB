#include "DxLib.h"
#include "Sounds.h"

SOUND PADDLESOUND;
SOUND SCORESOUND;

VOID SE_Paddle(VOID)
{
	if (CheckSoundMem(PADDLESOUND.GetHandle() == 0))
	{
		PlaySoundMem(PADDLESOUND.GetHandle(), DX_PLAYTYPE_BACK);
	}
	return;
}

VOID SE_Score(VOID)
{
	if (CheckSoundMem(SCORESOUND.GetHandle() == 0))
	{
		PlaySoundMem(SCORESOUND.GetHandle(), DX_PLAYTYPE_BACK);
	}
	return;
}

//âπÇì«Ç›çûÇﬁ
BOOL LoadSoundMem(VOID)
{
	PADDLESOUND.SetPath(PADDLE_SOUND);
	PADDLESOUND.SetHandle(LoadSoundMem(PADDLESOUND.GetPath()));
	if (PADDLESOUND.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), PADDLE_SOUND, LOAD_ERR_MES, MB_OK);
		return(FALSE);
	}

	SCORESOUND.SetPath(SCORE_SOUND);
	SCORESOUND.SetHandle(LoadSoundMem(SCORESOUND.GetPath()));
	if (SCORESOUND.GetHandle() == -1)
	{
		MessageBox(GetMainWindowHandle(), SCORE_SOUND, LOAD_ERR_MES, MB_OK);
		return(FALSE);
	}
}

//âπÇçÌèú
BOOL DeleteSoundMem(VOID)
{
	PADDLESOUND.DeleteHandle();
	SCORESOUND.DeleteHandle();

	return TRUE;
}