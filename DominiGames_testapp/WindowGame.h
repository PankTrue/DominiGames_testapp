#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>


class WindowGame
{
public:
	WindowGame();
	~WindowGame();
	void Destroy();
	void Create();
	void SetUp(const  std::string& title, const sf::Vector2u& size);
	void BeginDraw();
	void EndDraw();
	void Updata();
	bool IsOpen();
	bool IsFullScreen();
	void Draw(sf::Drawable& d);
	sf::Vector2u &GetWindowSize();
	sf::RenderWindow* GetWindowGame();
private:
	sf::RenderWindow _window;
	sf::Vector2u _windowSize;
	std::string _windowTitle;
	bool _isFullScreen;
	bool _isDone;
};

