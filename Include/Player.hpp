#pragma once

#include "Vector2D.hpp"
#include "Image.hpp"
#include <memory>


class Player
{
public:
	Player(int Mass, int UnderBoundary, int MaxSpeed);
	~Player();
	void Update();
	void Draw();
	void Initialize();

private:
	Player();
	void Move();

	const double UNDER_BOUNDARY;

	std::unique_ptr<Image> img;
	Vector2D pos, vMove;
	double maxSpeed, mass, gravity;
	int gh_player[4];
	int elapsedTime;
	bool isTurn;
};