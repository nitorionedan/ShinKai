/*

‚­‚»IÝŒv‚ðŽ¸”s‚µ‚½I‰÷‚µ‚¢‚Å‚·„ƒ

*/


#include "DefaultFish.hpp"


DefaultFish::DefaultFish(int pattern, int colorType, int pos)
	: PATTERN(pattern)
	, C_PATTERN(colorType)
	, F_POS(pos)
	, img(new Image)
{
	img->Load("Images/fish00.png", "body");

	Initialize();
}


DefaultFish::~DefaultFish()
{
}


void DefaultFish::Initialize()
{
	// shared variables
	isExist = true;
	isDead = false;
	isOB = false;
	isTurn = false;

	switch (PATTERN)
	{
	case 0:		vMove = Vector2D(0.1, 0.);	break;
	case 1:		vMove = Vector2D(-0.1, 0.);	break;
	case 2:		vMove = Vector2D(0.5, 0.);	break;
	case 3:		vMove = Vector2D(-0.5, 0.);	break;
	case 4:		vMove = Vector2D(0.1, 0.05);	break;
	case 5:		vMove = Vector2D(-0.1, 0.05);	break;
	default:	vMove = Vector2D(0.1, 0.);	break;
	}

	switch(F_POS)
	{
	case 0:	pos = Vector2D(160., 120.);	break;
	default:	break;
	}

	if (vMove.x > 0)	isTurn = true;
	if (vMove.x < 0)	isTurn = false;
}


void DefaultFish::Update()
{
	/*
	switch (PATTERN)
	{
	case 0:	Move0();	break;
	case 1: Move1();	break;
	case 2: Move2();	break;
	default:			break;
	}
	*/

	Move0();

	if (vMove.x > 0)	isTurn = true;
	if (vMove.x < 0)	isTurn = false;
}


void DefaultFish::Draw()
{
	switch (C_PATTERN)
	{
	case 0:	img->DrawRota(pos.x, pos.y, 1., 0., "body", true, isTurn);	break;
	default:	break;
	}

	// TEST
//	DrawFormatString(pos.x, pos.y, GetColor(0, 0, 0), "%d", PATTERN);
}


void DefaultFish::Move0(){
	pos += vMove;
}


void DefaultFish::Move1()
{
	pos += vMove;
}


void DefaultFish::Move2()
{
	pos += vMove;
}


// EOF