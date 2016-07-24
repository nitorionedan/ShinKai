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
	: img(new Image)
{
	// load media
	img->Load("Images/player00.png", "player");
	LoadDivGraph("Images/player01.png", 4, 2, 2, 36, 28, gh_player);

	// load player statsu
	setup();

	// set status
	Initialize();
}


Player::~Player()
{
	// release media memory
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


void Player::Update(const std::shared_ptr<FieldTask>& field)
{
	elapsedTime++;
	if (c_color < 255)	c_color++;

	Move();

	// temporary
	double	t_boundaty = -100.,
			b_boundary = 420.,
			l_boundary = -100.,
			r_boundary = 260.;

	// set boundary in some cases
	if ( field->HasGround() )	b_boundary = static_cast<double>(B_BOUNDARY);
	if ( field->HasSky() )		t_boundaty = static_cast<double>(T_BOUNDARY);
	if ( field->HasLWall() )	l_boundary = static_cast<double>(L_BOUNDARY);
	if ( field->HasRWall() )	r_boundary = static_cast<double>(R_BOUNDARY);

	// over boundary check
	pos.x = std::max( std::min(pos.x, r_boundary), l_boundary );
	pos.y = std::max( std::min(pos.y, b_boundary), t_boundaty );

	// change player directions
	if (vMove.x > 0)	isTurn = false;
	if (vMove.x < 0)	isTurn = true;
}


void Player::Draw()
{
	SetDrawBright(c_color, c_color, c_color);
	DrawAnime(pos.x, pos.y, 1., 0., elapsedTime, sizeof(gh_player) / sizeof(gh_player[0]), 6, gh_player, isTurn);
	SetDrawBright(255, 255, 255);

	// TEST
//	DrawFormatString(0, 30, GetColor(255, 0, 0), "pos.y = %lf, pos.x = %lf", pos.y, pos.x);
}


void Player::setup()
{
	// file open
	std::ifstream ifs("Resource/PlayerStatus.csv", std::ios::in);

	// exception
	assert(ifs.is_open() && "Failed open the file.");

	std::string buf;	// input character
	int nowCol = 1;		// column

	// header skip
	while (ifs.get() != '\n') {}

	// file reading
	while ( !ifs.eof() )
	{
		char tmpChar = ifs.get();

		// I don't know, tmpChar becomes -1 when it wents EOF X(
		if (tmpChar == -1)	break;

		// if tmpChar is ',' and '\n', string catch
		if (tmpChar != ',' && tmpChar != '\n')
		{
			buf += tmpChar; // strcat
			continue;
		}

		// sets member
		switch (nowCol)
		{
		case 1: mass = std::stoi(buf);		break;
		case 2: maxSpeed = std::stoi(buf);	break;
		default: break;
		}

		// increment column counter
		nowCol++;
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
}

// EOF