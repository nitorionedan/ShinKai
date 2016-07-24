#include "Field.hpp"


Field::Field(bool hasGround, bool hasSky, bool hasLWall, bool hasRWall, eBackType type, eBackMoveType m_type)
	: img(new Image)
{
	this->fieldStatus.hasGround = hasGround;
	this->fieldStatus.hasSky = hasSky;
	this->fieldStatus.hasLWall = hasLWall;
	this->fieldStatus.hasRWall = hasRWall;
	this->type = type;
	this->m_type = m_type;

	switch (type)
	{
	case eBackType::Normal:
		img->Load("Images/sea00.png", "sea");
		break;
	case eBackType::NormalShine:
		img->Load("Images/sea01.png", "sea");
		break;
	default:
		img->Load("Images/sea00.png", "sea");
		break;
	}

	Initialize();
}


void Field::Initialize()
{
	c_shake = 0;
	shake = 0;
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
	case eBackMoveType::Normal:
		break;
	case eBackMoveType::Wave_Level1:
		c_shake += 0.009;
		shake = std::sin(c_shake) * 10;
		break;
	default:	break;
	}
}


// EOF