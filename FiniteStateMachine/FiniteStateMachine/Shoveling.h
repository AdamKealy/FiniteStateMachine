#pragma once
#include "Idle.h"
#include "Animation.h"
#include "State.h"


class Shoveling : public State
{
public:
	Shoveling();
	~Shoveling();
	void idle(Animation* a);
};