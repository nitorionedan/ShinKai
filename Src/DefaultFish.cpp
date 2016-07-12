#include "..\Include\DefaultFish.hpp"


DefaultFish::DefaultFish(int pattern)
	: PATTERN(pattern)
	, img(new Image)
{
	img->Load("Images/fish00.png", "body");
	Initialize();
}


void DefaultFish::Initialize()
{
	pos.SetZero();
	isTurn = false;
}


void DefaultFish::Update()
{
	switch (PATTERN)
	{
	case 0:	Move0();	break;
	default:			break;
	}
}


void DefaultFish::Draw()
{
	switch (PATTERN)
	{
	case 0:	img->DrawRota(pos.x, pos.y, 1., 0., "body", isTurn);	break;
	default:	break;
	}
}


void DefaultFish::Move0()
{
	pos.SetVecor2D(160., 120.);
}

// EOF