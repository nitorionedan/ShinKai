#pragma once

#include "Image.hpp"
#include <memory>

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
	void Initialize();

private:
	void Move();

	std::unique_ptr<Image> img;
};