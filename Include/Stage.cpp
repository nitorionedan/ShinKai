#include "Stage.hpp"
#include <cmath>


Stage::Stage()
	: img(new Image)
	, sound(new Sound)
	, logo(new SoundLogo)
	, field( (FieldTask*)( new Field(true, true, true, true, eBackType::Normal, eBackMoveType::Wave_Level1) ) ) 
{
	img->Load("Images/sea00.png",		"sea");
	img->Load("Images/ground00.png",	"grd00");
	img->Load("Images/LWall00.png",		"lwall00");
	img->Load("Images/RWall00.png",		"rwall00");
	img->Load("Images/sky00.png",		"sky00");
	sound->Load("Sounds/kimeraii.mp3",	"bgm00");

	Initialize();
}


Stage::~Stage()
{
}


void Stage::Initialize()
{
	c_alpha = 0;

//	sound->PlayMem("bgm00", DX_PLAYTYPE_LOOP);
}


void Stage::Update()
{
	if(c_alpha < 255)	c_alpha++;

	field->Update();
	logo->Update();
}


void Stage::Draw()
{
	// Sky
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);
	if ( field->HasSky() )	img->Draw(0, 0, "sky00");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// Back
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - c_alpha);
	img->Draw(0, 0, "sea");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// Sea
	field->Draw();

	// Ground
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);
	if( field->HasGround() )	img->Draw(0, 0, "grd00", true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// Walls
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);
	if ( field->HasLWall() )	img->Draw(0, 0, "lwall00", true);
	if ( field->HasRWall() )	img->Draw(0, 0, "rwall00", true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	// Logo
	logo->Draw();
}


Stage::SoundLogo::SoundLogo()
	: img(new Image)
{
	img->Load("Images/sound_logo.png", "logo");
	counter = 0;
	c_alpha = 256;
}


void Stage::SoundLogo::Update()
{
	// –ñ‚S•b‚Ü‚Å
	if (counter < 240) {
		counter++;
	}else{
		if(c_alpha > 0)	c_alpha--;
	}
}


void Stage::SoundLogo::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);
	img->Draw(0, 0, "logo", true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

// EOF