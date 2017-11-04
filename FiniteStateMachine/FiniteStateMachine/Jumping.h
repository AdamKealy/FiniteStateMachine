#pragma once
#include "Idle.h"

class Jumping: public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a);
};