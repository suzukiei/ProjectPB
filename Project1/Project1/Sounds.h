#pragma once
#include "DxLib.h"

#define PADDLE_SOUND TEXT(".\\SOUNDS\\�{�C��.mp3")
#define SCORE_SOUND TEXT(".\\SOUNDS\\�V�X�e�����艹_12.mp3")
#define LOAD_ERR_MES TEXT("�T�E���h�ǂݍ��݃G���[")

//mp3��ǂݍ��݂���폜�܂ŊǗ�����
class SOUND
{
private:
	int Handle;
	char path[255];

public:
	VOID SetHandle(int Data)
	{
		Handle = Data;
		return;
	}
	VOID DeleteHandle(VOID)
	{
		DeleteSoundMem(Handle);
		return;
	}
	VOID SetPath(const char* Mpath)
	{
		strcpy_s(path, Mpath);
		return;
	}
	int GetHandle(VOID)
	{
		return(Handle);
	}
	char* GetPath(VOID)
	{
		return(path);
	}
};

extern SOUND PADDLESOUND;
extern SOUND SCORESOUND;

VOID SE_Paddle(VOID);
VOID SE_Score(VOID);

BOOL LoadSoundMem(VOID);
BOOL DeleteSoundMem(VOID);
