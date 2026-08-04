#include <iostream>

// To work with pairs
#include <utility>

#include "Static/Son.h"

#include "Friends/Acumulator.h" // It should be Accumulator :()

#include "Friends/MultipleFriends.h"

int main()
{
    Humidity hum { 10 };
    Temperature temp { 12 };

    printWeather(temp, hum);

    return 0;
}