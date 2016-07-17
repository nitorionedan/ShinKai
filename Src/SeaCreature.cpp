#include "SeaCreature.hpp"
#include "NullCreature.hpp"
#include <algorithm>


const double SeaCreature::L_BOUNDARY = -20.;
const double SeaCreature::R_BOUNDARY = 340.;
const double SeaCreature::T_BOUNDARY = -20.;
const double SeaCreature::B_BOUNDARY = 260.;


SeaCreature::SeaCreature()
	: defaFish(new DefaultFish(0, 0, 0))
{
	creature.reserve(100);
	creature.push_back( (Creature*)(new DefaultFish(0, 0, 0)) );
	creature.push_back( (Creature*)(new DefaultFish(1, 0, 0)) );
	creature.push_back( (Creature*)(new DefaultFish(2, 0, 0)) );
	creature.push_back((Creature*)(new NullCreature));

	Initialize();

	// TEST
	//printfDx("capa = %d\n", creature.capacity());
}


SeaCreature::~SeaCreature()
{
	if (creature.empty())	return;
	for (auto& i : creature)	delete i;
}


void SeaCreature::Initialize()
{
	elapsedTime = 0;
}


void SeaCreature::Update()
{
	elapsedTime++;

	if (creature.empty())	return;

	for(auto& i : creature)
	{
		i->Update();
	}

	// ERASE TEST
	for (auto i = std::begin(creature); i != std::end(creature); i++)
	{
		if ( (*i)->IsExist() )	continue;
		
		delete (*i);
		
		creature.erase(i);
	}

	SearchOverBounday();

	// TEST
//	defaFish->Update();
}


void SeaCreature::Draw()
{
	if (creature.empty())	return;

	for (auto i : creature)	i->Draw();

	// TEST
	//defaFish->Draw();
	DrawFormatString(100, 100, GetColor(255, 0, 0), "v_creture.size = %d", creature.size());
}

void SeaCreature::Create(eCreatureType type, int moveType, int colorType, int firstPos)
{
	switch (type)
	{
	case eCreatureType::defaFish:	creature.push_back( (Creature*)(new DefaultFish(moveType, colorType, firstPos)) );	break;
	case eCreatureType::None:		creature.push_back( (Creature*)(new NullCreature) );			break;
	
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

		delete (*i);
//		creature.erase( std::remove(std::begin(creature), std::end(creature), *i), std::end(creature) );
		creature.erase( std::remove(creature.begin(), creature.end(), *i), creature.end() );


		printfDx("deleted\n");
	}
}

// EOF