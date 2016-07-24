#pragma once
#include "FieldTask.hpp"
#include "Image.hpp"
#include "Graphics2D.hpp"
#include <memory>


enum class eBackType
{
	Normal,
	NormalShine,
};


enum class eBackMoveType
{
	Normal,
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
	void Move(); // Ç¢ÇÈÇ©ÅH

	std::unique_ptr<Image> img;
	eBackType type;
	eBackMoveType m_type;
	double c_shake;
	double shake;
};