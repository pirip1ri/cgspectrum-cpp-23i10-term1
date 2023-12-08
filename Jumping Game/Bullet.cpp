#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
    : PlacableActor(0, 0) // Initialize with default position (you can adjust as needed)
    , BulletActive(false)
    , FacingLeft(true)
    , FacingRight(false)
{
    // Initialize bullet properties
}

void Bullet::Draw()
{
    if (BulletActive)
    {
        std::cout << '.'; // Display bullet if active (using a dot for illustration)
    }
}

void Bullet::Activate(int playerX, int playerY)
{
    x = playerX + (FacingLeft ? -1 : 1); // Adjust x-position based on player's direction
    y = playerY;
    BulletActive = true;
    SetPosition(x, y);
}

void Bullet::UpdateBullet(bool FacingLeft, bool FacingRight)
{
    if (BulletActive)
    {
        SetPosition(GetXPosition() + (FacingLeft ? -1 : 1), GetYPosition());
    }
}

int Bullet::BulletMoveX(bool FacingLeft, bool FacingRight)
{
    if (FacingLeft)
    {
        return -1; // Move left
    }
    else if (FacingRight)
    {
        return 1; // Move right
    }
    return 0; // No movement if neither direction
}