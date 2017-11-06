#pragma once
#include "Idle.h"
#include "Animation.h"
#include "State.h"

class Jumping: public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation* a);
};