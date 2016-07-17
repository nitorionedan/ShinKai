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
	static const double MASS;
	static const double GRAVITY;
	static const double UNDER_BOUNDARY;
	static const double MAX_SPEED;

	void Move();

	std::unique_ptr<Image> img;
	Vector2D pos, vMove;
	int gh_player[4];
	int elapsedTime;
	bool isTurn;
};