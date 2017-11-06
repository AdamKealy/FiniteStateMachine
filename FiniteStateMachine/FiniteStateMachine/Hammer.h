#pragma once
#include "Idle.h"
#include "Animation.h"
#include "State.h"

class Hammer: public State
{
public:
	Hammer();
	~Hammer();
	void idle(Animation* a);
};