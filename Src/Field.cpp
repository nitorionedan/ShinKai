#include "Field.hpp"
#include <fstream>
#include <cassert>


Field::Field(bool hasGround, bool hasSky, bool hasLWall, bool hasRWall, bool hasCeiling, eBackType type, eBackMoveType m_type)
	: img(new Image)
{
	fieldStatus.hasGround = hasGround;
	fieldStatus.hasSky = hasSky;
	fieldStatus.hasLWall = hasLWall;
	fieldStatus.hasRWall = hasRWall;
	fieldStatus.hasCeiling = hasCeiling;
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


Field::Field()
	: img(new Image)
	, type(eBackType::Normal)
	, m_type(eBackMoveType::Wave_Level1)
{
	img->Load("Images/sea00.png", "sea00");
	img->Load("Images/sea01.png", "sea01");
	img->Load("Images/sea02.png", "sea02");
	img->Load("Images/sea03.png", "sea03");
	Initialize();
	setup();
}


void Field::Initialize()
{
	field_pos = Vector2D(9, 0);
	c_shake = 0;
	shake = 0;
	for (int i = 0; i < MAP_SIZE; i++){
		for (int j = 0; j < MAP_SIZE; j++) {
			fieldID[i][j] = 0;
		}
	}
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
	while ( !ifs.eof() )
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
		fieldID.at(nowRaw - 1).at(nowCol - 1) = std::stoi(buf);

		// increment column counter
		nowCol++;
		if (tmpChar == '\n')
		{
			nowRaw++;
			nowCol = 1; // reset
		}
		buf.clear();
	}

	ifs.close();


	/* TEST--------------------------------------
	std::ofstream ofs("FieldStatusTest.txt", std::ios::out);
	
	int count = 0;
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			count++;
			ofs << fieldID.at(i).at(j) << ",";
			if (j == 9)	ofs << std::endl;
		}
	}

	ofs.close();
	~TEST--------------------------------------*/
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
		switch (type)
		{
		case eBackType::Normal:			img->DrawRota(160., 160., 1., 0., "sea00", true);	break;
		case eBackType::NormalShine:	break;
		case eBackType::Level2:			img->DrawRota(160., 160., 1., 0., "sea01", true);	break;
		case eBackType::Level3:			img->DrawRota(160., 160., 1., 0., "sea02", true);	break;
		case eBackType::Level4:			img->DrawRota(160., 160., 1., 0., "sea03", true);	break;
		default:	break;
		}
		break;
	case eBackMoveType::Into:
		switch (type)
		{
		case eBackType::Normal:			img->Draw(0, 0, "sea00");	break;
		case eBackType::NormalShine:	break;
		case eBackType::Level2:			img->Draw(0, 0, "sea01");	break;
		case eBackType::Level3:			img->Draw(0, 0, "sea02");	break;
		case eBackType::Level4:			img->Draw(0, 0, "sea03");	break;
		default:	break;
		}
		break;		
	case eBackMoveType::Wave_Level1:
		switch (type)
		{
		case eBackType::Normal:			img->DrawRasterScroll(160, 160, 2.5, shake, -shake / 10, "sea00", false);	break;
		case eBackType::NormalShine:	break;
		case eBackType::Level2:			img->DrawRasterScroll(160, 160, 2.5, shake, -shake / 10, "sea01", false);	break;
		case eBackType::Level3:			img->DrawRasterScroll(160, 160, 2.5, shake, -shake / 10, "sea02", false);	break;
		case eBackType::Level4:			img->DrawRasterScroll(160, 160, 2.5, shake, -shake / 10, "sea03", false);	break;
		default:	break;
		}
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


void Field::StageSwitching(int x, int y)
{
	int tmpID = fieldID.at(y).at(x);

	FieldStatus tmpStatus = { false, false, false, false, false };

	// set field status
	for (int i = 0; i < 5; i++)
	{
		switch (tmpID % 10)
		{
		case 1:	tmpStatus.hasGround = true;		break;
		case 2: tmpStatus.hasSky = true;		break;
		case 3:	tmpStatus.hasLWall = true;		break;
		case 4:	tmpStatus.hasRWall = true;		break;
		case 5:	tmpStatus.hasCeiling = true;	break;
		default:	break;
		}
		tmpID /= 10;
	}

	// set Back type
	if		(y <= 3)	type = eBackType::Normal;
	else if (y <= 6)	type = eBackType::Level2;
	else if (y <= 8)	type = eBackType::Level3;
	else if (y <= 10)	type = eBackType::Level4;

	// set move type
	if (y == 0)	m_type = eBackMoveType::Wave_Level1;
	else		m_type = eBackMoveType::Into;

	fieldStatus = tmpStatus;
}


// EOF