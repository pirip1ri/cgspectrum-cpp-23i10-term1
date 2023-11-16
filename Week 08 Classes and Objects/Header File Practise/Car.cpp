#include <iostream>
#include "Car.h"

using namespace std;

Car::Car()
    : m_year(2023)  // Setting default values for the function
    , m_miles(0)
    , m_brand("Unspecified")
{

}

Car::Car(int year, int miles, std::string brand)
    : m_year(year)
    , m_miles(miles)
    , m_brand(brand)
{

}

Car::~Car()
{
    //Empty destructor, only needed if memory is allocated to the car constructor (aka anything in the {}
}

void Car::Display()
{
    cout << "Brand: " << m_brand << endl;
    cout << "Miles: " << m_miles << endl;
    cout << "Year: " << m_year << endl;
}

void Car::Drive(int miles)
{
    m_miles = m_miles + miles;
}
