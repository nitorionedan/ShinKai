#pragma once


#include "Creature.hpp"
#include "DefaultFish.hpp"
#include <memory>
#include <vector>


enum class eCreatureType
{
	defaFish,

	None,
};


class SeaCreature
{
public:
	SeaCreature();
	~SeaCreature();
	void Update();
	void Draw();
	void Create(eCreatureType type, int moveType, int colorType, int firstPos);

private:
	void Initialize();
	void LostBody();
	void SearchOverBounday();
	void DeleteCreature(Creature* creature);

	// Left, Right, Top and Bottom boundary
	static const double L_BOUNDARY, R_BOUNDARY, T_BOUNDARY, B_BOUNDARY;

	std::vector< std::shared_ptr<Creature> > creature;
	std::unique_ptr<DefaultFish> defaFish;
	eCreatureType type;
	int elapsedTime;
};

// EOF