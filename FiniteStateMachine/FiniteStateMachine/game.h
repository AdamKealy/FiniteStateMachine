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
	
	static const int MAX_SPRITES = 5;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Texture m_texture[MAX_SPRITES]; // texture used for sfml logo
	sf::Sprite m_Sprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

};

#endif // !GAME

