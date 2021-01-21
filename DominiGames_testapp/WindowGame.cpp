#include "WindowGame.h"
WindowGame::WindowGame()
{
	_isFullScreen = false;
	_isDone = false;
}
void WindowGame::SetUp(const  std::string& title, const sf::Vector2u& size)
{
	_windowTitle = title;
	_windowSize = size;
	Create();
}
WindowGame::~WindowGame()
{
	Destroy();
}
void WindowGame::Create()
{
	auto style = (_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
	_window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _windowTitle, style);
}
void WindowGame::Destroy()
{
	_window.close();
}
void WindowGame::BeginDraw()
{
	_window.clear(sf::Color::Black);
}
void WindowGame::EndDraw()
{
	_window.display();
}
bool WindowGame::IsOpen()
{
	return _window.isOpen();
}
bool WindowGame::IsFullScreen()
{
	return _isFullScreen;
}
sf::Vector2u &WindowGame::GetWindowSize()
{
	return _windowSize;
}
void WindowGame::Draw(sf::Drawable& d)
{
	_window.draw(d);
}
sf::RenderWindow* WindowGame::GetWindowGame()
{
	return &_window;
}