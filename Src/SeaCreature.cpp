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

	// ERASE TEST
	for (auto i = std::begin(creature); i != std::end(creature); i++)
	{
		if ( (*i)->IsExist() == false )
			creature.erase(std::remove(std::begin(creature), std::end(creature), (*i)), std::end(creature));
	}

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
		creature.emplace(std::begin(creature), (Creature*)(new DefaultFish(moveType, colorType, firstPos)) );
		break;
	case eCreatureType::None:
		creature.emplace(std::begin(creature), (Creature*)(new NullCreature));
		break;
	
	default:	MessageBox(NULL, ERROR, "FAILED TO CREATE", MB_OK);	break;
	}
}


void SeaCreature::LostBody()
{
}


void SeaCreature::SearchOverBounday()
{
	// ERASE TEST
	for (auto i = std::begin(creature); i != std::end(creature); i++)
	{
		const bool& IS_OB = ( (*i)->GetPos().x < L_BOUNDARY || (*i)->GetPos().x > R_BOUNDARY ||
							  (*i)->GetPos().y < T_BOUNDARY || (*i)->GetPos().y > B_BOUNDARY);

		// If it's no OB, skip over delete this
		if (IS_OB == false) continue;

		creature.erase( std::remove(std::begin(creature), std::end(creature), (*i)), std::end(creature) );
	}
}

// EOF