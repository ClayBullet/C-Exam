#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


class SDLClass
{
public:
	SDLClass(std::string titleName, int width, int height);

	void HandleEvents();

	void Tick();

	void Render();

	void CleanEverything();

	SDL_Texture* playerTexture;
	/// <summary>
	/// Posición del jugador
	/// </summary>
	SDL_Rect destPlayer;

private:
	/// <summary>
	/// La ventana actual y su configuración
	/// </summary>
	SDL_Window* currentWindow;
	/// <summary>
	/// Crea contexto para el renderizado 2D de la ventana
	/// </summary>
	SDL_Renderer* currentRenderer;
	/// <summary>
	/// Vemos si se está ejecutando la ventana
	/// </summary>
	bool executingSDLWindow;
};

