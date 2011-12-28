#include "stdafx.h"

#include "System.h"
#include "Window.h"
#include "Game.h"
#include "Input.h"

#include "graphics/Graphics.h"
#include "level/Block.h"

bool			 System::running;
FileLogger	   System::errorLog;

bool System::Init() {
	errorLog.SetPath("error.txt");
	errorLog.EnableAppend();

	errorLog.AddInput(std::cerr);
	errorLog.AddInput(sf::Err());

	srand((unsigned int)time(nullptr));

	Block::Init();

	if (!Window::Init()) {
		return false;
	}

	Window::Maximize();

	Input::Init();
	Graphics::Init();

	Window::Display();

	if (!Res::Init()) {
		return false;
	}

	if (!Game::Init()) {
		return false;
	}

	Window::sfWindow.ShowMouseCursor(false);

	Graphics::InitGraphics();

	return true;
}

void System::Start() {
	if (running) return;
	running = true;

	Game::Start();

	while(running) {
		Game::Update();
		Game::Render();
		Window::Display();
	}
}

void System::Shutdown() {
	Game::Shutdown();
	Graphics::Shutdown();
	Res::Shutdown();
}

void System::Stop() {
	running = false;
}