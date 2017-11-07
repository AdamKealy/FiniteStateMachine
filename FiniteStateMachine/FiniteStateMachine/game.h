// author Peter Lowe
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Animation.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	enum FiniteStates{climb,hammer,jump,dig};

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Texture m_texture; // texture used for sfml logo
	sf::Sprite m_Sprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	int m_whichState;
	int m_lastState;

};

#endif // !GAME

