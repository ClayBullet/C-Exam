#include "SDLClass.h"

SDLClass::SDLClass(std::string titleName, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    currentWindow = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    currentRenderer = SDL_CreateRenderer(currentWindow, -1, 0);

    SDL_SetRenderDrawColor(currentRenderer, 0, 0, 0, 255);
    SDL_RenderClear(currentRenderer);
   
    executingSDLWindow = true;

    SDL_Surface* tmpSurface = IMG_Load("assets/Redsquare.png");

    playerTexture = SDL_CreateTextureFromSurface(currentRenderer, tmpSurface);
    /// <summary>
    /// Tras haber puesto el personaje sobre una superficie, no nos hace falta más,
    /// por lo que procedemos a limpiarla
    /// </summary>
    /// <param name="titleName"></param>
    /// <param name="width"></param>
    /// <param name="height"></param>
    SDL_FreeSurface(tmpSurface);

    SDL_Surface* tmpSurface2 = IMG_Load("assets/Redsquare.png");

    player2Texture = SDL_CreateTextureFromSurface(currentRenderer, tmpSurface2);

    SDL_FreeSurface(tmpSurface2);

    SDL_Surface* tmpSurface3 = IMG_Load("assets/WhiteCircle.png");

    ballTexture = SDL_CreateTextureFromSurface(currentRenderer, tmpSurface3);

    SDL_FreeSurface(tmpSurface3);

}

/// <summary>
/// Gestionar los eventos generados durante la ejecución de la ventana SDL.
/// </summary>
void SDLClass::HandleEvents()
{
    SDL_Event currentEvent;

    SDL_PollEvent(&currentEvent);

    switch (currentEvent.type)
    {
    case SDL_QUIT:
        executingSDLWindow = false;
        break;
    default:
        break;
    }
}
/// <summary>
/// Actualizamos el estado del SDL para refrescar la información
/// </summary>
void SDLClass::Tick()
{
    while (executingSDLWindow) 
    {
        destPlayer.w = 20;
        destPlayer.h = 20;
        destPlayer.x = 80;
        destPlayer2.w = 20;
        destPlayer2.h = 20;
        destPlayer2.x = 150;

        ballDest.w = 10;
        ballDest.h = 10;
        ballDest.x = 80;

        Render();
        HandleEvents();

    }
}

void SDLClass::Render()
{
    SDL_RenderClear(currentRenderer);
  /*  SDL_RenderCopy(currentRenderer, playerTexture, NULL, &destPlayer);
    SDL_RenderCopy(currentRenderer, playerTexture, NULL, &destPlayer2);
    SDL_RenderCopy(currentRenderer, ballTexture, NULL, &ballDest);*/
    DrawGrid();
    SDL_RenderPresent(currentRenderer);
}

void SDLClass::DrawGrid()
{
    //if (updateGridOnlyFirstTime) return;

    unsigned counter = 0;
    for (int x = 0; x < 8; x++)
    {
        for (unsigned y = 0; y < 9; y++) 
        {
            SDL_Surface* tmpSurface = IMG_Load("assets/Redsquare.png");

            textures[counter] = SDL_CreateTextureFromSurface(currentRenderer, tmpSurface);

            SDL_FreeSurface(tmpSurface);

           SDL_Rect rectInfo;
            rectInfo.w = 30;
            rectInfo.h = 30;

            rectInfo.x = (40 * x) + 50;
            rectInfo.y = 40 * y;

           SDL_RenderCopy(currentRenderer, textures[counter], NULL, &rectInfo);

          DrawCoordsInGrid(currentChessBoard->TakeFileReference(x, y), counter, rectInfo.x, rectInfo.y);
        }

    }

    updateGridOnlyFirstTime = true;
}

void SDLClass::DrawCoordsInGrid(std::string name, int index, int xCoords, int yCoords)
{
    const char* takeName = name.c_str();
    SDL_Surface* tmpSurface = IMG_Load(takeName);

    std::cout << "TAKE NAME " + name << std::endl;

    charactersChess[index] = SDL_CreateTextureFromSurface(currentRenderer, tmpSurface);

    SDL_FreeSurface(tmpSurface);

    SDL_Rect rectInfo;
    rectInfo.w = 30;
    rectInfo.h = 30;

    rectInfo.x = xCoords;
    rectInfo.y = yCoords;

    SDL_RenderCopy(currentRenderer, charactersChess[index], NULL, &rectInfo);

}





/// <summary>
/// Hacemos limpieza cuando vayamos a terminar de usar esto
/// </summary>
void SDLClass::CleanEverything()
{
    SDL_DestroyWindow(currentWindow);
    SDL_DestroyRenderer(currentRenderer);
}

void SDLClass::GetReferenceToTheChess(ChessBoard* chessBoard)
{
    currentChessBoard = chessBoard;
}


