#include "Menu.hpp"
#include "DxLib.h"

#include "CKeyboard.hpp"


Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
{
}


Menu::~Menu()
{
}


void Menu::Update()
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Game);
}


void Menu::Draw()
{
	DrawFormatString(0, 20, GetColor(0, 255, 0), "MENU_SCENE_NOW");
}

//EOF