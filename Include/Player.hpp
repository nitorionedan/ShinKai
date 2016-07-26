#pragma once

#include "Vector2D.hpp"
#include "Image.hpp"
#include "Field.hpp"
#include <memory>


class Player
{
public:
	Player();
	~Player();
	void Update(const std::unique_ptr<FieldTask>& field);
	void Draw();
	void Initialize();

private:
	void setup();
	void Move();

	static const int T_BOUNDARY = 48;
	static const int B_BOUNDARY = 224;
	static const int L_BOUNDARY = 32;
	static const int R_BOUNDARY = 287;

	std::unique_ptr<Image> img;
	Vector2D pos, vMove;
	double maxSpeed, mass, gravity;
	int gh_player[4];
	int elapsedTime;
	int c_color;
	bool isTurn;
};