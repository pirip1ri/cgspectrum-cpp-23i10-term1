#pragma once
#include "PlacableActor.h"

class Key : public PlacableActor
{
public:
	Key(int x, int y, ActorColour colour)
		: PlacableActor(x, y, colour)
	{

	}
	virtual ActorType GetType() override
	{
		return ActorType::Key;
	}

	virtual void Draw() override;
};
