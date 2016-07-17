#include "Keyboard.hpp"
#include <DxLib.h>


Keyboard::Keyboard()
{
	for (auto& i : mKeyDownCount)	i = 0;
	for (auto& i : mKeyUpCount)		i = 0;
}


bool Keyboard::Update()
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);

	for (int i = 0; i < KEY_NUM; i++)
	{
		if(nowKeyStatus[i] != 0)
		{
			if(mKeyUpCount[i] > 0)
			{
				mKeyUpCount[i] = 0;
			}
			mKeyDownCount[i]++;
		}
		else
		{
			if(mKeyDownCount[i] > 0)
			{
				mKeyDownCount[i] = 0;
			}
			mKeyUpCount[i]++;
		}
	}
	return true;
}


int Keyboard::GetDown(int keyCode)
{
	if (!Keyboard::IsAvailableCode(keyCode)) {
		return -1;
	}
	return mKeyDownCount[keyCode];
}


int Keyboard::GetUp(int keyCode)
{
	if (!Keyboard::IsAvailableCode(keyCode)) {
		return -1;
	}
	return mKeyUpCount[keyCode];
}


bool Keyboard::IsAvailableCode(int keyCode)
{
	if ( !(0 <= keyCode && keyCode<KEY_NUM) )	return false;
	return true;
}


// EOF