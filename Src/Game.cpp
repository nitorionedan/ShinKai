#include "Game.hpp"
#include "Keyboard.hpp"
#include "DxLib.h"


Game::Game(ISceneChanger * changer)
	: BaseScene(changer)
	, img(new Image)
	, player(new Player)
	, stage(new Stage)
	, seaCre(new SeaCreature)
{
	Initialize();
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
	if (Keyboard::Instance()->GetDown(KEY_INPUT_Q) == 1)
	{
		isPause = !isPause;
		Image::ChengeIsUpdate();
	}

	if (isPause)	return;

	player->Update( stage->GetField() );
	stage->Update();
	seaCre->Update();

	// TEST
	if (Keyboard::Instance()->GetDown(KEY_INPUT_F2) == 1) mSceneChanger->ChangeScene(eScene_Menu);
	if (Keyboard::Instance()->GetDown(KEY_INPUT_O) == 1) seaCre->Create(eCreatureType::defaFish, GetRand(5), 0, 0);
}


void Game::Draw()
{
	stage->Draw();
	seaCre->Draw();
	player->Draw();

	// TEST
	//DrawFormatString(0, 20, GetColor(0, 0, 0), "GAME_NOW >> F2 >> MENU");
}

// EOF