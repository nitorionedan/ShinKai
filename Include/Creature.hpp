#pragma once


class Creature
{
public:
	explicit Creature(int Type, int move_pattern);
	void Initialize();
	void Update();
	void Draw();

private:
	Creature();
};