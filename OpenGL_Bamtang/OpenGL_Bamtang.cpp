// OpenGL_Bamtang.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenGLWindow.h"
#include "SDLClass.h"
#include "ChessBoard.h"
#include <iostream>

int main(int argv, char** args)
{
   /* OpenGLWindow* windowOpenGL = new OpenGLWindow();

    windowOpenGL->InitWindow();

    if (windowOpenGL->windowIsNull()) 
    { 
        std::cout << "FAILED " << std::endl;
        return -1; 
    }
    
    windowOpenGL->TickWindow();

    windowOpenGL->DestroyWindow();*/


	std::cout << "START TEST" << std::endl;
	while (true)
	{
		int number;
		std::cout << "\n" << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "1ºEjercicio --> ENCRIPTACIÓN" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "2ºEjercicio --> AJEDREZ" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "\n" << std::endl;

		std::cout << "3ºEjercicio / TEST --> AJEDREZ" << std::endl;
		std::cout << "\n" << std::endl;
		std::cout << "\n" << std::endl;
		std::cin >> number;

		ChessBoard* chessBoard = new ChessBoard();
		SDLClass* newSDLClass = new SDLClass("Title", 600, 600);

		switch (number)
		{
		case 1:
			break;
		case 2:

		

			chessBoard->InitTable();


			newSDLClass->GetReferenceToTheChess(chessBoard);

			newSDLClass->Tick();

			newSDLClass->CleanEverything();


			break;

		case 3:
			ChessBoard * chessBoard2 = new ChessBoard();

			//chessBoard2->InitTable();

			std::string inputWords;

			std::cin >> inputWords;

			chessBoard->DrawChessBoard(inputWords.c_str());

			newSDLClass->GetReferenceToTheChess(chessBoard);

			newSDLClass->Tick();

			newSDLClass->CleanEverything();

			break;

		}
	}

	return 0;



    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
