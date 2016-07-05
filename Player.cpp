#include "Player.hpp"


Player::Player()
	: img(new Image)
{
	img->Load("Images/test_player.png", "player");
}


Player::~Player()
{
}


void Player::Update()
{
	Move();
}


void Player::Draw()
{
	img->DrawRota(160, 120, 1., 0., "player", true);
}


void Player::Initialize()
{
}


void Player::Move()
{
}

// EOF