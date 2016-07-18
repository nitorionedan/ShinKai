#include "Player.hpp"
#include "Keyboard.hpp"
#include "DxLib.h"
#include "Graphics2D.hpp"
#include <algorithm>
#undef max
#undef min


Player::Player()
	: UNDER_BOUNDARY(224.)
	, img(new Image)
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
	
	{
		FILE* fp;
		int c;
		char buf[100];
		int col = 1;
		int row = 0;
		
		for (auto& i : buf)	i = 0;

		fopen_s(&fp, "Resource/PlayerStatus.csv", "rb");
		
		while (fgetc(fp) != '\n');

		while (1)
		{
			while(1)
			{
				c = fgetc(fp);

				// 末尾なら全てのループを抜ける
				if (c == EOF)	goto out;

				// カンマか改行以外なら、文字として連結
				if (c != ',' && c != '\n') {
					strcat_s(buf, sizeof(buf) / sizeof(buf[0]), (const char*)&c);
				}
				// カンマか改行ならループを抜ける
				else {
					break;
				}
			}

			switch (col)
			{
			case 1:	mass = atoi(buf);		break;
			case 2:	maxSpeed = atoi(buf);	break;
			default:	break;
			}

			// バッファを初期化
			for (auto& i : buf)	i = 0;

			// 列数を足す
			++col;

			// もし読み込んだ文字列が改行だったら列数を初期化して行数を増やす
			if(c == '\n')
			{
				col = 1;
				++row;
			}
		}

		out:
		fclose(fp);
	}

	gravity = (mass / 100.);
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
	const double& MAX_SPEED = maxSpeed;
	const double& GRAVITY = gravity;

	// use gravity
	pos.y += GRAVITY;

	// moving
	vMove.SetZero();
	if (Keyboard::Instance()->GetDown(KEY_INPUT_D) >= 1)	vMove.x = MAX_SPEED;
	if (Keyboard::Instance()->GetDown(KEY_INPUT_A) >= 1)	vMove.x = -MAX_SPEED;
	if (Keyboard::Instance()->GetDown(KEY_INPUT_S) >= 1)	vMove.y = MAX_SPEED;
	if (Keyboard::Instance()->GetDown(KEY_INPUT_W) >= 1)	vMove.y = -MAX_SPEED;

	// add force
	pos += vMove;

	// over boundary
	pos.y = std::max(std::min(pos.y, UNDER_BOUNDARY), 48.);
}

// EOF