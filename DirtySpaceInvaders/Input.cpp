#include "Input.h"

#include "Random.h"

bool RndInput::Left()
{
	floatRand keyRate(0, 1);
	return (keyRate(rGen) < 0.3f);
}

bool RndInput::Right()
{
	floatRand keyRate(0, 1);
	return (keyRate(rGen) < 0.4f);
}

bool RndInput::Fire()
{
	floatRand keyRate(0, 1);
	return (keyRate(rGen) < 0.5f);
}