#include "DxLib.h"

#include "Game.hpp"
#include "Keyboard.hpp"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, img(new Image)
{
	img->Load("Images/test_back.png", "back");
}


Game::~Game()
{
}


void Game::Update()
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Menu);
}


void Game::Draw()
{
	// TEST
	DrawFormatString(0, 20, GetColor(0, 255, 0), "GAME_SCENE_NOW");

//	img->Draw(0, 0, "back");
	img->DrawRasterScroll(0, 20, 5., 100., "back");
}
