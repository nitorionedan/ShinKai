#include "Player.hpp"
#include "Keyboard.hpp"
#include "DxLib.h"
#include "Graphics2D.hpp"
#include <algorithm>
#undef max
#undef min


const double Player::MASS = 10.;
const double Player::GRAVITY = (MASS / 100.);
const double Player::UNDER_BOUNDARY = 224.;
const double Player::MAX_SPEED = 1.;


Player::Player()
	: img(new Image)
{
	img->Load("Images/player00.png", "player");
	LoadDivGraph("Images/player01.png", 4, 2, 2, 36, 28, gh_player);
	
	Initialize();
}


Player::~Player()
{
	for (auto& i : gh_player)	DeleteGraph(i);
}


void Player::Initialize()
{
	pos   = Vector2D(160., 120.);
	vMove = Vector2D(0., 0.);
	elapsedTime = 0;
	isTurn = false;
}


void Player::Update()
{
	elapsedTime++;

	Move();

	if (vMove.x > 0)	isTurn = false;
	if (vMove.x < 0)	isTurn = true;
}


void Player::Draw()
{
	DrawAnime(pos.x, pos.y, 1., 0., elapsedTime, sizeof(gh_player) / sizeof(gh_player[0]), 6, gh_player, isTurn);

	// TEST
	//DrawFormatString(0, 30, GetColor(255, 0, 0), "pos.y = %lf", pos.y);
}


void Player::Move()
{
	// use gravity
	pos.y += GRAVITY;

	// moving
	vMove.SetZero();
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	vMove.x = MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)	vMove.x = -MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)	vMove.y = MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_UP) >= 1)	vMove.y = -MAX_SPEED;

	// add force
	pos += vMove;

	// over boundary
	pos.y = std::max(std::min(pos.y, UNDER_BOUNDARY), 48.);
}

// EOF