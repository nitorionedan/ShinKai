#include "Stage.hpp"
#include <cmath>


Stage::Stage()
	: img(new Image)
{
	img->Load("Images/test_back.png", "test");
	img->Load("Images/sea00.png", "sea0");
	Initialize();
}


Stage::~Stage()
{
}


void Stage::Initialize()
{
	c_shake = 0;
	shake = 0;
}


void Stage::Update()
{
	c_shake += 0.01;

	shake = std::sin(c_shake) * 10;
}


void Stage::Draw()
{
	img->DrawRasterScroll(160, 160, 2.5, shake, 0.1, "sea0", false);
}

// EOF