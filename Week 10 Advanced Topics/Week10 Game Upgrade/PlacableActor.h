#pragma once
#include "Point.h"

enum class ActorColour 
{
    GreenColour = 10,
    GreenColourSolid = 34,
    RedColour = 12,
    RedColourSolid = 68,
    BlueColour = 9,
    BlueColourSolid = 153,
    RegularColour = 7,
};

enum class ActorType
{
    Door,
    Enemy,
    Goal,
    Key,
    Money,
    Player
};

class PlacableActor 
{
public:
    PlacableActor(int x, int y, ActorColour colour = ActorColour::RegularColour);
    virtual ~PlacableActor();

    int GetXPosition();
    int GetYPosition();
    int* GetXPositionPointer();
    int* GetYPositionPointer();
    void SetPosition(int x, int y);

    ActorColour GetColour() 
    {
        return m_colour;
    }

    void Remove() 
    {
        m_IsActive = false;
    }
    bool IsActive() 
    {
        return m_IsActive;
    }
    void Place(int x, int y);

    virtual ActorType GetType() = 0;
    virtual void Draw() = 0; // pure virtual
    virtual void Update() 
    {
        // Some players will not need to update themselves, so an empty function would do to create an instance
    }

protected:
    Point* m_pPosition;
    bool m_IsActive;
    ActorColour m_colour;
};