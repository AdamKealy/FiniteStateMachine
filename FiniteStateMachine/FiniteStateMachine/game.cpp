// author Peter Lowe

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Finite State Machine" },
	m_exitGame{false} //when true game will exit
{
	setupSprite(); // load texture
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	Animation fsm;

	while (m_window.pollEvent(event))
	{	
		
		fsm.idle();
		m_Sprite.setTexture(m_texture[0]);


		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
				

			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_exitGame = true;
				break;
			case sf::Keyboard::Up:
				fsm.climbing();
				m_Sprite.setTexture(m_texture[2]);
				
				break;
			case sf::Keyboard::Right:
				fsm.hammering();
				m_Sprite.setTexture(m_texture[4]);

				break;
			case sf::Keyboard::Space:
				fsm.jumping();
				m_Sprite.setTexture(m_texture[1]);

				break;
			case sf::Keyboard::Down:
				fsm.shoveling();
				m_Sprite.setTexture(m_texture[3]);

				break;
			default:
				break;
			}
			
		}
	
	}

}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{


}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_Sprite);
	m_window.display();
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_texture[0].loadFromFile("ASSETS\\IMAGES\\Idle.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	if (!m_texture[1].loadFromFile("ASSETS\\IMAGES\\jump.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	if (!m_texture[2].loadFromFile("ASSETS\\IMAGES\\Climb.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	if (!m_texture[3].loadFromFile("ASSETS\\IMAGES\\Dig.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	if (!m_texture[4].loadFromFile("ASSETS\\IMAGES\\Hammer.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	
	m_Sprite.setTexture(m_texture[0]);																																					
	m_Sprite.setPosition(350.0f, 200.0f);

}
