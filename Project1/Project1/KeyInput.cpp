#include "DxLib.h"
#include "Key.h"
#include "iostream"


int Key[256];
char tmpKey[256];

int UpdateKeys()
{
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����

			Key[i]++;     // ���Z			
			
		}
		else {              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
		}
	}

	return 0;
}