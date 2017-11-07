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
				m_whichState = climb;
				break;
			case sf::Keyboard::Right:
				fsm.hammering();
				m_whichState = hammer;
				break;
			case sf::Keyboard::Space:
				fsm.jumping();
				m_whichState = jump;
				break;
			case sf::Keyboard::Down:
				fsm.shoveling();
				m_whichState = dig;
				break;
			default:
				break;
			}
			
		}
	
	}
	fsm.idle();
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
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\Dig.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_Sprite.setTexture(m_texture);
	m_Sprite.setPosition(300.0f, 180.0f);
}
