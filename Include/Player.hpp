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
	void Move();

	const double UNDER_BOUNDARY;

	std::unique_ptr<Image> img;
	Vector2D pos, vMove;
	double maxSpeed, mass, gravity;
	int gh_player[4];
	int elapsedTime;
	bool isTurn;
};