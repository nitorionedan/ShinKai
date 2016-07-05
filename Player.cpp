#include "Player.hpp"
#include "Keyboard.hpp"
#include <algorithm>
#undef max
#undef min


Player::Player()
	: MASS(10.)
	, GRAVITY(MASS / 100.)
	, UNDER_BOUNDARY(300.)
	, MAX_SPEED(1.)
	, img(new Image)
{
	img->Load("Images/test_player.png", "player");
}


Player::~Player()
{
}


void Player::Initialize()
{
	pos.SetVecor2D(160., 120.);
}


void Player::Update()
{
	Move();
}


void Player::Draw()
{
	img->DrawRota(pos.x, pos.y, 1., 0., "player", true);
}


void Player::Move()
{
	// use gravity
//	pos.y += GRAVITY;

	// moving
	if (Keyboard_Get(KEY_INPUT_RIGHT) >= 1)	pos.x + MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_LEFT) >= 1)	pos.x - MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_DOWN) >= 1)	pos.y + MAX_SPEED;
	if (Keyboard_Get(KEY_INPUT_UP) >= 1)	pos.y - MAX_SPEED;

	// over boundary
	pos.y = std::max(std::min(pos.y, 0.), UNDER_BOUNDARY);
}

// EOF