#include "SeaCreature.hpp"
#include "NullCreature.hpp"
#include <algorithm>


const double SeaCreature::L_BOUNDARY = -40.;
const double SeaCreature::R_BOUNDARY = 360.;
const double SeaCreature::T_BOUNDARY = -40.;
const double SeaCreature::B_BOUNDARY = 280.;


SeaCreature::SeaCreature()
	: defaFish(new DefaultFish(0, 0, 0))
{
	creature.reserve(100);
	creature.emplace_back( std::shared_ptr<Creature>( (Creature*)(new NullCreature) ) );

	Initialize();
}


SeaCreature::~SeaCreature()
{
}


void SeaCreature::Initialize()
{
	elapsedTime = 0;
}


void SeaCreature::Update()
{
	elapsedTime++;

	if (creature.empty())	return;

	for(auto i : creature)	i->Update();

	SearchOverBounday();
}


void SeaCreature::Draw()
{
	if (creature.empty())	return;

	for (auto i : creature)	i->Draw();

	// TEST
	//DrawFormatString(100, 100, GetColor(255, 0, 0), "v_creture.size = %d", creature.size());
}


void SeaCreature::Create(eCreatureType type, int moveType, int colorType, int firstPos)
{
	switch (type)
	{
	case eCreatureType::defaFish:
		creature.emplace( std::begin(creature), static_cast<Creature*>(new DefaultFish(moveType, colorType, firstPos)) );
		break;
	case eCreatureType::None:
		creature.emplace( std::begin(creature), static_cast<Creature*>(new NullCreature) );
		break;
	
	default:	MessageBox(NULL, ERROR, "FAILED CREATE THE CREATURE", MB_OK);	break;
	}
}


void SeaCreature::LostBody()
{
}


void SeaCreature::SearchOverBounday()
{
	// Delete the creature
	for (auto i = std::begin(creature); i != std::end(creature); i++)
	{
		// check over boudary
		const bool& IS_OB = ( (*i)->GetPos().x < L_BOUNDARY || (*i)->GetPos().x > R_BOUNDARY ||
							  (*i)->GetPos().y < T_BOUNDARY || (*i)->GetPos().y > B_BOUNDARY);

		if ((*i)->IsExist() == false)
			creature.erase( std::remove(std::begin(creature), std::end(creature), (*i)), std::end(creature) );

		// If it's no OB, skip over delete this
		if (IS_OB == false) continue;

		creature.erase( std::remove(std::begin(creature), std::end(creature), (*i)), std::end(creature) );
	}
}


void SeaCreature::DeleteCreature(Creature * creature)
{
//	std::find(std::begin(creature), std;; end(creature), 0);
//	this->creature.erase(std::remove(std::begin(this->creature), std::end(this->creature), *creature), std::end(this->creature));
}

// EOF