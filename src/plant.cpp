#include "plant.hpp"

Plant::Plant(vector<float> settings)
{
    damage = settings[0];
    health = settings[1];
    cooldown = settings[2];
    hitrate = settings[3];
    speed = settings[4];
    price = settings[5];
}