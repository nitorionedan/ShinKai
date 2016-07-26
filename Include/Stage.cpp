#include "Stage.hpp"
#include "Keyboard.hpp"
#include <cmath>


Stage::Stage()
	: img(new Image)
	, sound(new Sound)
	, logo(new SoundLogo)
	, field( static_cast<FieldTask*>(new Field) )
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
	field->StageSwitching(8, 9);
//	sound->PlayMem("bgm00", DX_PLAYTYPE_LOOP);
}


void Stage::Update()
{
	if(c_alpha < 255)	c_alpha++;

	field->Update();
	logo->Update();

	// TEST
	if (Keyboard::Instance()->GetDown(KEY_INPUT_P) == 1)	field->StageSwitching(GetRand(9), GetRand(9));
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


void Stage::ChangeField(eChangeStage nextStage)
{
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
	if (counter < 240) {			// in 4 sec
		counter++;
	}else{
		if(c_alpha > 0)	c_alpha--;	// feed out this
	}
}


void Stage::SoundLogo::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, c_alpha);
	SetDrawBlendMode(DX_BLENDMODE_INVSRC, c_alpha);
	img->Draw(0, 0, "logo", true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}


// EOF