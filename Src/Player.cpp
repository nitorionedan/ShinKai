#include "Player.hpp"
#include "Keyboard.hpp"
#include <algorithm>
#undef max
#undef min


const int Player::CONST_TEST;


Player::Player()
	: MASS(10.)
	, GRAVITY(MASS / 100.)
	, UNDER_BOUNDARY(224.)
	, MAX_SPEED(1.)
	, img(new Image)
{
	img->Load("Images/test_player.png",	"test");
	img->Load("Images/player00.png",	"player");
//	printfDx("%d", CONST_TEST);
	printfDx("hello");

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

	printfDx("hello");

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