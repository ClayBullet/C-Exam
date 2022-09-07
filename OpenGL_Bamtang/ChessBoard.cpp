#include "ChessBoard.h"
std::string ChessBoard::TakeValue(unsigned x, unsigned y)
{

	int count = sizeof(objChess) / sizeof(*objChess);
	for (int i = 0; i < count; i++)
	{
		if (objChess[i].xPos == x && objChess[i].yPos == y) {
			return objChess[i].id;
		}
	}

	

	return "x";
}

std::string ChessBoard::TakeFileReference(unsigned x, unsigned y)
{
	int count = sizeof(objChess) / sizeof(*objChess);
	for (int i = 0; i < count; i++)
	{
		if (objChess[i].xPos == x && objChess[i].yPos == y) {
			return objChess[i].nameFile;
		}
	}

	

	return "x";
}


ChessBoard::ChessBoard()
{
	widthTable = 8;
	heightTable = 8;

	//WHITE FACTION
	ChessCheckPos(0, 0, 8, "r", "assets/Chess/Tower_File.png");
	ChessCheckPos(1, 1, 8, "n", "assets/Chess/Horse_File.png");
	ChessCheckPos(2, 2, 8, "b", "assets/Chess/Alfil_Png.png"); //CORRECT
	ChessCheckPos(3, 3, 8, "q", "assets/Chess/Queen_Png.png");
	ChessCheckPos(4, 4, 8, "k", "assets/Chess/King_PNG.png");
	ChessCheckPos(5, 5, 8, "b", "assets/Chess/Alfil_Png.png"); //CORRECT
	ChessCheckPos(6, 6, 8, "n", "assets/Chess/Horse_File.png");
	ChessCheckPos(7, 7, 8, "r", "assets/Chess/Tower_File.png");
	ChessCheckPos(8, 0, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(9, 1, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(10, 2, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(11, 3, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(12, 4, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(13, 5, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(14, 6, 7, "p", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(15, 7, 7, "p", "assets/Chess/PawnChess_Png.png");

	//BLACK FACTION
	ChessCheckPos(16, 0, 0, "R", "assets/Chess/Tower_File.png");
	ChessCheckPos(17, 1, 0, "N", "assets/Chess/Horse_File.png");
	ChessCheckPos(18, 2, 0, "B", "assets/Chess/Alfil_Png.png");
	ChessCheckPos(19, 3, 0, "Q", "assets/Chess/Queen_Png.png");
	ChessCheckPos(20, 4, 0, "K", "assets/Chess/King_PNG.png");
	ChessCheckPos(21, 5, 0, "B", "assets/Chess/Alfil_Png.png");
	ChessCheckPos(22, 6, 0, "N", "assets/Chess/Horse_File.png");
	ChessCheckPos(23, 7, 0, "R", "assets/Chess/Tower_File.png");
	ChessCheckPos(24, 0, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(25, 1, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(26, 2, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(27, 3, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(28, 4, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(29, 5, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(30, 6, 1, "P", "assets/Chess/PawnChess_Png.png");
	ChessCheckPos(31, 7, 1, "P", "assets/Chess/PawnChess_Png.png");




}

void ChessBoard::ChessCheckPos(int index, unsigned x, unsigned y, std::string id, std::string nameFile)
{
	ChessObject chess = ChessObject();
	chess.id = id;
	chess.nameFile = nameFile;
	chess.xPos = x;
	chess.yPos = y;

	objChess[index] = chess;

}



void ChessBoard::InitTable()
{
	std::string word = "                   ";
	for (int x = 0; x < widthTable; x++)
	{
		for (int y = 0; y < heightTable; y++)
		{

			word += TakeValue(y, x);
		}

		word += "\n";
		word += "                   ";

	}

	std::cout << word << std::endl;


}