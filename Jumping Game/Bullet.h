#pragma once
#include "PlacableActor.h"



class Bullet : public PlacableActor 
{
public:
    bool BulletActive;
    bool IsActive() const 
    { 
        return BulletActive; 
    }

    int x;
    int y;
    Bullet();

    virtual ActorType GetType() override 
    {
        return ActorType::Bullet;
    }

    virtual void Draw() override;
    void Activate(int playerX, int playerY);
    void UpdateBullet(bool FacingLeft, bool FacingRight);

    bool FacingLeft;
    bool FacingRight;
    int BulletMoveX(bool FacingLeft, bool FacingRight);
};