#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ChessBoard.h"

#include <iostream>


class SDLClass
{
public:
	SDLClass(std::string titleName, int width, int height);

	void HandleEvents();

	void Tick();

	void Render();

	void DrawGrid();

	void DrawCoordsInGrid(std::string name, int index, int xCoords, int yCoords);

	void CleanEverything();

	void GetReferenceToTheChess(ChessBoard* chessBoard);

	ChessBoard* currentChessBoard;

	SDL_Texture* playerTexture;
	SDL_Texture* player2Texture;
	SDL_Texture* ballTexture;
	/// <summary>
	/// Posición del jugador
	/// </summary>
	SDL_Rect destPlayer;

	SDL_Rect destPlayer2;

	SDL_Rect ballDest;

	bool updateGridOnlyFirstTime;

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

	SDL_Texture* textures[81];

	SDL_Texture* charactersChess[81];

};

