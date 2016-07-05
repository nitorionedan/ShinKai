#include "DxLib.h"

#include "Game.hpp"
#include "Keyboard.hpp"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, img(new Image)
	, player(new Player)
{
	img->Load("Images/test_back.png", "back");
}


Game::~Game()
{
}


void Game::Update()
{
	player->Update();

	// TEST
	if (Keyboard_Get(KEY_INPUT_Z) == 1) mSceneChanger->ChangeScene(eScene_Menu);
}


void Game::Draw()
{
	// TEST
	DrawFormatString(0, 20, GetColor(0, 255, 0), "GAME_NOW >> F2 >> MENU");

	img->Draw(0, 0, "back");
	player->Draw();
}
