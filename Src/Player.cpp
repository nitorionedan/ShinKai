#include "Player.hpp"
#include "Keyboard.hpp"
#include <algorithm>
#include "DxLib.h"
#undef max
#undef min


const double Player::MASS = 10.;
const double Player::GRAVITY = (MASS / 100.);
const double Player::UNDER_BOUNDARY = 224.;
const double Player::MAX_SPEED = 1.;


Player::Player()
	: img(new Image)
{
	img->Load("Images/test_player.png",	"test");
	img->Load("Images/player00.png",	"player");
	
	Initialize();
}


Player::~Player()
{
}


void Player::Initialize()
{
	pos.SetVecor2D(160., 120.);
	isTurn = false;
}


void Player::Update()
{
	if (Keyboard_Get(KEY_INPUT_RIGHT) == 1)	isTurn = false;
	if (Keyboard_Get(KEY_INPUT_LEFT) == 1)	isTurn = true;

	Move();
}


void Player::Draw()
{
	img->DrawRota(pos.x, pos.y, 1., 0., "player", true, isTurn);

	// TEST
	//DrawFormatString(0, 30, GetColor(255, 0, 0), "pos.y = %lf", pos.y);
}


void Player::Move()
{
	// use gravity
	pos.y += GRAVITY;

	// moving
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	pos.x += MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)	pos.x -= MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)	pos.y += MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_UP) >= 1)	pos.y -= MAX_SPEED;

	// over boundary
	pos.y = std::max(std::min(pos.y, UNDER_BOUNDARY), 48.);
}

// EOF