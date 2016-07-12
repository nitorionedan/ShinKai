#pragma once


#include "DefaultFish.hpp"
#include <memory>


enum class eCreatureType
{
	defaFish,

	None,
};


class Creature
{
public:
	Creature();
	~Creature();
	void Initialize();
	void Update();
	void Draw();
	void Create(eCreatureType type);

private:

	std::unique_ptr<DefaultFish> defaFish;
	eCreatureType type;
};