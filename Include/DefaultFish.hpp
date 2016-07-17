#pragma once

#include "Image.hpp"
#include "Vector2D.hpp"
#include "Creature.hpp"
#include <memory>


class DefaultFish : public Creature
{
public:
	// @param[in]	pattern	
	explicit DefaultFish(int pattern, int colorType, int pos);
	~DefaultFish();
	void Update() override;
	void Draw() override;
	bool IsExist() override { return isExist; }
	bool IsDead() override { return isDead; }
	bool IsOB() override { return isOB; }
	Vector2D& GetPos() override { return pos; }

private:
	DefaultFish();
	void Initialize();
	void Move0();
	void Move1();
	void Move2();
	void Move3() {}
	
	const int PATTERN, C_PATTERN, F_POS;

	std::unique_ptr<Image> img;
	Vector2D vMove;
};