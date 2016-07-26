#include "Field.hpp"
#include <fstream>
#include <cassert>


Field::Field(bool hasGround, bool hasSky, bool hasLWall, bool hasRWall, eBackType type, eBackMoveType m_type)
	: img(new Image)
{
	fieldStatus.hasGround = hasGround;
	fieldStatus.hasSky = hasSky;
	fieldStatus.hasLWall = hasLWall;
	fieldStatus.hasRWall = hasRWall;
	type = type;
	m_type = m_type;

	switch (type)
	{
	case eBackType::Normal:		 img->Load("Images/sea00.png", "sea");	break;
	case eBackType::Level2:		 img->Load("Images/sea01.png", "sea");	break;
	case eBackType::Level3:		 img->Load("Images/sea02.png", "sea");	break;
	case eBackType::Level4:		 img->Load("Images/sea03.png", "sea");	break;
	case eBackType::NormalShine: img->Load("Images/sea01.png", "sea");	break;
	default:					 img->Load("Images/sea00.png", "sea");	break;
	}

	Initialize();
	setup();
}


void Field::Initialize()
{
	c_shake = 0;
	shake = 0;
}


void Field::setup()
{
	// file open
	std::ifstream ifs("Resource/FieldTable.csv", std::ios::in);

	// exception
	assert(ifs.is_open() && "Failed open the file.");

	std::string buf;	// input character
	int nowCol = 1;		// column
	int nowRaw = 1;		// raw

						// header skip
	while (ifs.get() != '\n') {}

	// file reading
	while (!ifs.eof())
	{
		char tmpChar = ifs.get();

		// I don't know, tmpChar becomes -1 when it wents EOF X(
		if (tmpChar == -1)	break;

		// if tmpChar is ',' and '\n', string catch
		if (tmpChar != ',' && tmpChar != '\n')
		{
			buf += tmpChar; // strcat
			continue;
		}

		// sets member
		switch (nowCol)
		{
		case 1: mass = std::stoi(buf);		break;
		case 2: maxSpeed = std::stoi(buf);	break;
		default: break;
		}

		// increment column counter
		nowCol++;
		buf.clear();
	}

	ifs.close();
}


Field::~Field()
{
}


void Field::Update()
{
	Move();
}


void Field::Draw()
{
	switch (m_type)
	{
	case eBackMoveType::Normal:
		img->DrawRota(160., 160., 1., 0., "sea", true);
		break;
	case eBackMoveType::Into:
		img->Draw(0, 0, "sea");
		break;
	case eBackMoveType::Wave_Level1:
		img->DrawRasterScroll(160, 160, 2.5, shake, -shake / 10, "sea", false);
		break;
	default:	break;
	}
}


bool Field::HasGround() const{
	return fieldStatus.hasGround;
}


bool Field::HasSky() const{
	return fieldStatus.hasSky;
}


bool Field::HasLWall() const{
	return fieldStatus.hasLWall;
}


bool Field::HasRWall() const{
	return fieldStatus.hasRWall;
}


void Field::Move()
{
	switch (m_type)
	{
	case eBackMoveType::Wave_Level1:
		c_shake += 0.009;
		shake = std::sin(c_shake) * 10;
		break;
	default:	break;
	}
}


// EOF