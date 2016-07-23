#pragma once
#include "Singleton.hpp"


class Keyboard : public Singleton<Keyboard>
{

	Keyboard();
	friend Singleton<Keyboard>;
public:
	bool Update();
	int GetDown(int keyCode);
	int GetUp(int keyCode);

private:
	// keyCodeは有効なキーコードか？
	bool IsAvailableCode(int keyCode);

	static const int KEY_NUM = 256;
	int mKeyDownCount[KEY_NUM];
	int mKeyUpCount[KEY_NUM];
};