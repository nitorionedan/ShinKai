#include "Stage.hpp"
#include "Keyboard.hpp"
#include <cmath>
#include <fstream>
#include <string>
#include <cassert>
#define T_T 1


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

	setup();
	Initialize();
}


Stage::~Stage()
{
}


void Stage::setup()
{
	std::ifstream ios("Resource/bgm.txt", std::ios::in);

	// exception
	assert(ios.is_open() && "failed open file");

	// input file strings
	std::string buf;

	while ( !ios.eof() )
	{
		// strcat
		char tmpChar;
		tmpChar = ios.get();
		buf += tmpChar;

		// set level01 bgm
		if(buf == "level01 = " || buf == "level01=")
		{
			buf.clear();
			while (T_T) // cry
			{
				tmpChar = ios.get();
				if(tmpChar == '\n' || tmpChar == EOF)
				{
					std::string dir("Sounds/");
					dir += buf;
					sound->Load(dir.c_str(), "bgm01");
					buf.clear();
					break;
				}
				// strcat
				buf += tmpChar;
			}
		}
	}

	ios.close();
}


void Stage::Initialize()
{
	c_alpha = 0;
	field->StageSwitching(8, 9);
	sound->List();
	sound->PlayMem("bgm01", DX_PLAYTYPE_LOOP);
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