#pragma once
#include "PlacableActor.h"

class Key : public PlacableActor
{
public:
	Key(int x, int y, int colour)
		: PlacableActor(x, y, colour)
	{

	}
	virtual void Draw() override;
};
