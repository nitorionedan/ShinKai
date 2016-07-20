#include "Field.hpp"


Field::Field(bool hasGround, bool hasSky, bool hasLWall, bool hasRWall, eBackType type, eBackMoveType m_type)
	: img(new Image)
{
	this->hasGround = hasGround;
	this->hasSky = hasSky;
	this->hasLWall = hasLWall;
	this->hasRWall = hasRWall;
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
		img->DrawRasterScroll(160, 160, 2.5, shake, 0.3, "sea", false);
		break;
	default:	break;
	}
}


bool Field::HasGround(){
	return hasGround;
}


bool Field::HasSky(){
	return hasSky;
}


bool Field::HasLWall(){
	return hasLWall;
}


bool Field::HasRWall(){
	return hasRWall;
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