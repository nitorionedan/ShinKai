#include "Creature.hpp"


Creature::Creature()
	: defaFish( new DefaultFish(0) )
{
	Initialize();
}


Creature::~Creature()
{
}


void Creature::Initialize()
{
	type = eCreatureType::None;
}


void Creature::Update()
{
}


void Creature::Draw()
{
}


void Creature::Create(eCreatureType type)
{

}

// EOF