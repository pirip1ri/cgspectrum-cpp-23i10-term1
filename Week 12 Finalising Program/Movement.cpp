#include "Movement.h"

void Movement::MovingUp(int& newPlayerX, int& newPlayerY, bool& m_FloorBelow, bool& m_Jumping, bool& m_floating)
{
    if (m_FloorBelow)
    {
        // When the floor is below, set m_Jumping to true and decrement Y position
        newPlayerY = newPlayerY--;
        m_Jumping = true;
    }
    else if (m_Jumping)
    {
        if (!m_floating)
        {
            // When m_Jumping is true and m_floating is false, set m_floating to true
            m_floating = true;
        }
        else
        {
            // When m_Jumping is true, m_floating is true
            // In this condition, it sets m_floating to false and m_Jumping to false
            m_floating = false;
            m_Jumping = false;
        }
        // Always decrement Y position when m_Jumping is true
        newPlayerY--;
    }
    else
    {
        // When neither m_FloorBelow is true nor m_Jumping is true
        newPlayerY++;
    }
}

void Movement::MovingLeft(int& newPlayerX, int& newPlayerY, bool& m_FloorBelow, bool& m_Jumping, bool& m_floating)
{
    if (m_FloorBelow)
    {
        if (m_Jumping)
        {
            if (m_floating)
            {
                m_Jumping = false;
                m_floating = false;
                newPlayerX--;
            }
            else if (!m_floating)
            {
                m_floating = true;
                newPlayerX--;
                newPlayerY--;
            }
        }
        else if (!m_Jumping)
        {
            if (m_floating)
            {
                m_floating = false;
                newPlayerX--;
            }
            else if (!m_floating) //This is the most common instance. If on the floor, just move left
            {
                newPlayerX--;
            }
        }
    }
    else if (!m_FloorBelow)
    {
        if (m_Jumping)
        {
            if (m_floating)
            {
                m_Jumping = false;
                m_floating = false;
                newPlayerX--; // creates the illusion of holding the jump in the air
            }
            else if (!m_floating)
            {
                m_floating = true;
                newPlayerX--;
                newPlayerY--; // move up one more space
            }
        }
        else if (!m_Jumping)
        {
            if (m_floating)
            {
                m_floating = false;
                newPlayerX--;
            }
            else if (!m_floating)
            {
                newPlayerY++; // start falling
                newPlayerX--;
            }
        }
    }

}

void Movement::MovingRight(int& newPlayerX, int& newPlayerY, bool& m_FloorBelow, bool& m_Jumping, bool& m_floating)
{
    if (m_FloorBelow)
    {
        if (m_Jumping)
        {
            if (m_floating)
            {
                m_Jumping = false;
                m_floating = false;
                newPlayerX++;
            }
            else if (!m_floating)
            {
                m_floating = true;
                newPlayerX++;
                newPlayerY--;
            }
        }
        else if (!m_Jumping)
        {
            if (m_floating)
            {
                m_floating = false;
                newPlayerX++;
            }
            else if (!m_floating) //This is the most common instance. If on the floor, just move right
            {
                newPlayerX++;
            }
        }
    }
    else if (!m_FloorBelow)
    {
        if (m_Jumping)
        {
            if (m_floating)
            {
                m_Jumping = false;
                m_floating = false;
                newPlayerX++; // creates the illusion of holding the jump in the air
            }
            else if (!m_floating)
            {
                m_floating = true;
                newPlayerX++;
                newPlayerY--; // move up one more space
            }
        }
        else if (!m_Jumping)
        {
            if (m_floating)
            {
                m_floating = false;
                newPlayerX++;
            }
            else if (!m_floating)
            {
                newPlayerY++;
                newPlayerX++; // start falling
            }
        }
    }
}
