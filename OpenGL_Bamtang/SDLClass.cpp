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
        Render();
        HandleEvents();

    }
}

void SDLClass::Render()
{
    SDL_RenderClear(currentRenderer);
    SDL_RenderCopy(currentRenderer, playerTexture, NULL, &destPlayer);
    SDL_RenderPresent(currentRenderer);
}

/// <summary>
/// Hacemos limpieza cuando vayamos a terminar de usar esto
/// </summary>
void SDLClass::CleanEverything()
{
    SDL_DestroyWindow(currentWindow);
    SDL_DestroyRenderer(currentRenderer);
}


