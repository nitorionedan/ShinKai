#pragma once

#include "Vector2D.hpp"
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
	const double MASS;
	const double GRAVITY;
	const double UNDER_BOUNDARY;
	const double MAX_SPEED;

	void Move();

	std::unique_ptr<Image> img;
	Vector2D pos;
};