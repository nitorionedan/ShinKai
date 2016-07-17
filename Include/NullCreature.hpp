#pragma once
#include "Creature.hpp"


class NullCreature : public Creature
{
public:
	NullCreature()
	{
		pos.SetVecor2D(100., 100.);
		isExist = true, isOB = false, isDead = false, isTurn = false;
	}
	~NullCreature(){}
	void Draw() override {}
	void Update() override {}
	bool IsExist() override { return isExist; }
	bool IsDead() override { return isDead; }
	bool IsOB() override { return isOB; }
	Vector2D& GetPos() override { return pos; }
};