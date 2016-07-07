#include "Stage.hpp"


Stage::Stage()
	: img(new Image)
{
	img->Load("Images/sea00.png", "sea0");
}


Stage::~Stage()
{
}


void Stage::Initialzie()
{
}


void Stage::Update()
{
}


void Stage::Draw()
{
//	img->Draw(0, 0, "sea0");
	img->DrawRasterScroll(160, 160, 2.5, 10, "sea0", false);
}

// EOF