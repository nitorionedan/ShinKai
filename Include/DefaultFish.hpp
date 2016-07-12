#pragma once

#include "Image.hpp"
#include "Vector2D.hpp"
#include <memory>


class DefaultFish
{
public:
	// @param[in]	pattern	
	DefaultFish(int pattern);
	void Update();
	void Draw();

private:
	void Initialize();
	void Move0();
	
	const int PATTERN;

	std::unique_ptr<Image> img;
	Vector2D pos;
	bool isTurn;
};