#include "Shoveling.h"

Shoveling::Shoveling()
{
}

Shoveling::~Shoveling()
{
}

void Shoveling::idle(Animation * a)
{
	std::cout << "Going from Shoveling to Idling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
