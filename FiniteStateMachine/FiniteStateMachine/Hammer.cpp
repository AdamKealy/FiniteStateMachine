#include "Hammer.h"

Hammer::Hammer()
{
}

Hammer::~Hammer()
{
}

void Hammer::idle(Animation * a)
{
	std::cout << "Going from Hammering to Idling" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
