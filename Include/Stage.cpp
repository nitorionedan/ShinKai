#include "Stage.hpp"
#include <cmath>


Stage::Stage()
	: img(new Image)
{
	img->Load("Images/test_back.png",	"test");
	img->Load("Images/sea00.png",		"sea0");
	img->Load("Images/sea01.png",		"sea1");
	img->Load("Images/ground00.png",	"grd0");
	img->Load("Images/sky00.png",		"sky0");

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
	img->Draw(0, 0, "sky0");
	img->DrawRasterScroll(160, 160, 2.5, shake, 0.3, "sea1", false);
	img->Draw(0, 0, "grd0", true);
}

// EOF