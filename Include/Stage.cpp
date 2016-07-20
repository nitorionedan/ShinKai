#include "Stage.hpp"
#include <cmath>


Stage::Stage()
	: img(new Image)
	, sound(new Sound)
	, field((FieldTask*)(new Field(true, true, false, false, eBackType::Normal, eBackMoveType::Wave_Level1)) ) 
{
	img->Load("Images/sea00.png",		"sea");
	img->Load("Images/ground00.png",	"grd0");
	img->Load("Images/sky00.png",		"sky0");
	sound->Load("Sounds/kimeraii.mp3", "bgm0");

	Initialize();
}


Stage::~Stage()
{
}


void Stage::Initialize()
{
	sound->PlayMem("bgm0", DX_PLAYTYPE_LOOP);
	c_alpha = 0;
}


void Stage::Update()
{
	c_alpha += 1;
	if (c_alpha > 255)	c_alpha = 255;

	field->Update();
}


void Stage::Draw()
{
	// Sky
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);
	if ( field->HasSky() )	img->Draw(0, 0, "sky0");

	// Back
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - c_alpha);
	img->Draw(0, 0, "sea");

	// Sea
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	field->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);

	// Ground
	if( field->HasGround() )	img->Draw(0, 0, "grd0", true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// EOF