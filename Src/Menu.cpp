#include "Menu.hpp"
#include "DxLib.h"

#include "Keyboard.hpp"


Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
	, img(new Image)
{
	img->Load("Images/sea00.png", "sea");
	img->Load("Images/title00.png", "title00");
	img->Load("Images/title01.png", "title01");
	img->Load("Images/title02.png", "title02");
}


Menu::~Menu()
{
}


void Menu::Update()
{
	if (Keyboard::Instance()->GetDown(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Game);
	DrawFormatString(0, 20, GetColor(0, 255, 0), "Z KEY START");
}


void Menu::Draw()
{
	img->Draw(0, 0, "sea");
	img->Draw(0, 0, "title00", true);
	img->Draw(0, 0, "title01", true);
	img->Draw(0, 0, "title02", true);

	// TEST
//	DrawFormatString(0, 20, GetColor(0, 255, 0), "MENU_SCENE_NOW");
}

//EOF