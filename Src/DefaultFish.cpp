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
	isExist = true;
	isDead = false;
	isOB = false;
	isTurn = false;

	switch (PATTERN)
	{
	case 0:		vMove.SetVecor2D(0.1, 0.);	break;
	case 1:		vMove.SetVecor2D(0.5, 0.);	break;
	default:	vMove.SetVecor2D(0.1, 0.);	break;
	}

	switch(F_POS)
	{
	case 0:	pos.SetVecor2D(160., 120.);	break;
	default:	break;
	}
}


void DefaultFish::Update()
{
	switch (PATTERN)
	{
	case 0:	Move0();	break;
	case 1: Move1();	break;
	case 2: Move2();	break;
	default:			break;
	}
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
	pos.x += vMove.x;
	isTurn = true;
}


void DefaultFish::Move1()
{
	pos.x += vMove.x;
	isTurn = false;
}


void DefaultFish::Move2()
{


	isTurn = false;
}


// EOF