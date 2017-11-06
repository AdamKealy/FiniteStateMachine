/// <summary>
/// 
/// 
/// 
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#include "Animation.h"


/// <summary>
/// main entry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	Animation fsm;
	int i = 0;
	while (true)
	{
		if (i == 0)
		{
			fsm.jumping();
			i = 1;
		}
		if (i == 1)
		{
			fsm.climbing();
			i = 2;
		}
		if (i == 2)
		{
			fsm.hammering();
			i = 3;
		}
		if (i == 3)
		{
			fsm.shoveling();
			i = 0;
		}
	}
}