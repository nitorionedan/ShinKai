#include "DxLib.h"

#include "Game.hpp"
#include "Keyboard.hpp"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, img(new Image)
	, player(new Player)
	, stage(new Stage)
{
}


Game::~Game()
{
}


void Game::Initialize()
{
	isPause = false;
}


void Game::Update()
{
	// Pause
	if (Keyboard_Get(KEY_INPUT_SPACE) == 1)	isPause = !isPause;

	if (isPause)	return;

	player->Update();
	stage->Update();

	// TEST
	if (Keyboard_Get(KEY_INPUT_F2) == 1) mSceneChanger->ChangeScene(eScene_Menu);
}


void Game::Draw()
{
	stage->Draw();
	player->Draw();

<<<<<<< HEAD
	img->Draw(0, 0, "back");
=======
	// TEST
	//DrawFormatString(0, 20, GetColor(0, 255, 0), "GAME_NOW >> F2 >> MENU");
>>>>>>> dev
}
