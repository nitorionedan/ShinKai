#include "Player.hpp"
#include "Keyboard.hpp"
#include "DxLib.h"
#include "Graphics2D.hpp"
#include <algorithm>
#include <string>
#include <fstream>
#include <cassert>
#undef max
#undef min


Player::Player()
	: UNDER_BOUNDARY(224.)
	, img(new Image)
{
	img->Load("Images/player00.png", "player");
	LoadDivGraph("Images/player01.png", 4, 2, 2, 36, 28, gh_player);
	
	setup();
	Initialize();
}


Player::~Player()
{
	for (auto& i : gh_player)	DeleteGraph(i);
}


void Player::Initialize()
{
	// super class members
	{
		pos = Vector2D(160., 120.);
		vMove = Vector2D(0., 0.);
		elapsedTime = 0;
		isTurn = false;
	}

	gravity = (mass / 100.);
	c_color = 0;
}


void Player::Update()
{
	elapsedTime++;
	if (c_color < 255)	c_color++;

	Move();

	if (vMove.x > 0)	isTurn = false;
	if (vMove.x < 0)	isTurn = true;
}


void Player::Draw()
{
	SetDrawBright(c_color, c_color, c_color);
	DrawAnime(pos.x, pos.y, 1., 0., elapsedTime, sizeof(gh_player) / sizeof(gh_player[0]), 6, gh_player, isTurn);
	SetDrawBright(255, 255, 255);

	// TEST
	//DrawFormatString(0, 30, GetColor(255, 0, 0), "pos.y = %lf", pos.y);
}


void Player::setup()
{
	// file open
	std::ifstream ifs("Resource/PlayerStatus.csv", std::ios::in);

	// exception
	assert(ifs.is_open() && "Failed open the file.");

	std::string buf;	// input character
	int col = 1;		// column

	buf.clear();

	// header skip
	while (ifs.get() != '\n') {}

	// file reading
	while (!ifs.eof())
	{
		char c = ifs.get();

		// よくわからんけどなんか -1 がおるから
		if (c == -1)	break;

		// カンマ、改行以外なら
		if (c != ',' && c != '\n')
		{
			buf += c;
			continue;
		}

		switch (col)
		{
		case 1: mass = std::stoi(buf);		break;
		case 2: maxSpeed = std::stoi(buf);	break;
		default: break;
		}

		// go to next column
		col++;

		buf.clear();
	}

	ifs.close();
}


void Player::Move()
{
	const double& MAX_SPEED = maxSpeed;
	const double& GRAVITY = gravity;

	// moving
	vMove.SetZero();
	if (Keyboard::Instance()->GetDown(KEY_INPUT_D) >= 1)	vMove.x = MAX_SPEED;
	if (Keyboard::Instance()->GetDown(KEY_INPUT_A) >= 1)	vMove.x = -MAX_SPEED;
	if (Keyboard::Instance()->GetDown(KEY_INPUT_S) >= 1)	vMove.y = MAX_SPEED;
	if (Keyboard::Instance()->GetDown(KEY_INPUT_W) >= 1)	vMove.y = -MAX_SPEED;

	// add force
	pos.y += GRAVITY;
	pos += vMove;

	// over boundary
	pos.y = std::max(std::min(pos.y, UNDER_BOUNDARY), 48.);
}

// EOF