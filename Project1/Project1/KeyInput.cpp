#include "DxLib.h"
#include "Key.h"
#include "iostream"


int Key[256];
char tmpKey[256];

int UpdateKeys()
{
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら

			Key[i]++;     // 加算			
			
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}

	return 0;
}