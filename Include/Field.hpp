#pragma once
#include "FieldTask.hpp"
#include "Image.hpp"
#include "Graphics2D.hpp"
#include <memory>


// type of sea image
enum class eBackType
{
	Normal,
	NormalShine,
	Level2,
	Level3,
	Level4,
};


// type of sea movings
enum class eBackMoveType
{
	Normal,
	Into,
	Wave_Level1,
};


class Field : public FieldTask
{
public:
	explicit Field(bool hasGround, bool hasSky, bool hasLWall, bool hasRWall, eBackType type, eBackMoveType m_type);
	~Field();
	void Update() override;
	void Draw() override;
	bool HasGround() const override;
	bool HasSky() const override;
	bool HasLWall() const override;
	bool HasRWall() const override;

private:
	Field();
	void Initialize();
	void setup();
	void Move(); // Ç¢ÇÈÇ©ÅH

	static const int MAP_SIZE = 10;

	std::unique_ptr<Image> img;
	eBackType type;
	eBackMoveType m_type;
	double c_shake;
	double shake;
//	int field[MAP_SIZE];
};