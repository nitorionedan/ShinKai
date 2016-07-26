#pragma once
#include "FieldTask.hpp"
#include "Image.hpp"
#include "Graphics2D.hpp"
#include "Vector2D.hpp"
#include <memory>
#include <array>


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
	explicit Field(bool hasGround, bool hasSky, bool hasLWall, bool hasRWall, bool hasCeiling, eBackType type, eBackMoveType m_type);
	Field();
	~Field(){}
	void Update() override;
	void Draw() override;
	void StageSwitching(int x, int y) override;
	bool HasGround() const override;
	bool HasSky() const override;
	bool HasLWall() const override;
	bool HasRWall() const override;

private:
	void Initialize();
	void setup();
	void Move(); // Ç¢ÇÈÇ©ÅH

	static const int MAP_SIZE = 10;

	std::unique_ptr<Image> img;
	std::array<std::array<int, MAP_SIZE>, MAP_SIZE> fieldID;
	eBackType type;
	eBackMoveType m_type;
	Vector2D field_pos;
	double c_shake;
	double shake;
};