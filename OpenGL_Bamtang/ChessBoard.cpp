#include "ChessBoard.h"
bool ChessBoard::isANumber(std::string initPosition)
{
	return initPosition == "0" || initPosition == "2" || initPosition == "3" || initPosition == "4" || initPosition == "5" ||
		initPosition == "6" || initPosition == "7" || initPosition == "8" || initPosition == "9";
}
int ChessBoard::stringToNumber(std::string initPosition)
{
	if (initPosition == "0") return 0;
	if (initPosition == "1") return 1;
	if (initPosition == "2") return 2;
	if (initPosition == "3") return 3;
	if (initPosition == "4") return 4;
	if (initPosition == "5") return 5;
	if (initPosition == "6") return 6;
	if (initPosition == "7") return 7;
	if (initPosition == "8") return 8;
	if (initPosition == "9") return 9;

	std::cout << "INIT POS " + initPosition << std::endl;
	return 0;
}
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
	widthTable = 7;
	heightTable = 7;

	//WHITE FACTION
	ChessCheckPos(0, 0, 7, "r", "assets/Chess/Tower_File.png");
	ChessCheckPos(1, 1, 7, "n", "assets/Chess/Horse_File.png");
	ChessCheckPos(2, 2, 7, "b", "assets/Chess/Alfil_Png.png"); //CORRECT
	ChessCheckPos(3, 3, 7, "q", "assets/Chess/Queen_Png.png");
	ChessCheckPos(4, 4, 7, "k", "assets/Chess/King_PNG.png");
	ChessCheckPos(5, 5, 7, "b", "assets/Chess/Alfil_Png.png"); //CORRECT
	ChessCheckPos(6, 6, 7, "n", "assets/Chess/Horse_File.png");
	ChessCheckPos(7, 7, 7, "r", "assets/Chess/Tower_File.png");
	ChessCheckPos(8, 0, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(9, 1, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(10, 2, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(11, 3, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(12, 4, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(13, 5, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(14, 6, 6, "p", "assets/Chess/PawnChess_Png.png");
ChessCheckPos(15, 7, 6, "p", "assets/Chess/PawnChess_Png.png");

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

	//	std::cout << word << std::endl;


}

void ChessBoard::DrawChessBoard(const char* initPosition)
{
	std::string currentName = initPosition;


	int count = 0;
	for (int y = 0; y < 8; y++)
	{
		std::string finalResult = "";


		for (int x = 0; x < 8; x++)
		{
			if (currentName.length() < count) break;

			if (isANumber(currentName.substr(count, 1)))
			{
				int number = stringToNumber(currentName.substr(count, 1));

				for (int i = x; i < number; i++)
				{
					finalResult += "X";
				}

				if (8 <= x + number) 
				{ 
					count += 1;

					break; 
				}
				else {

					x += number;
				}

				

			}
			else {
				if (currentName.substr(count, 1) == "/")
					finalResult += "X";
				else
					finalResult += currentName.substr(count, 1);



			}

			count += 1;


		}

		/*count = 0;
		count = (8 * (y + 1));*/
		std::cout << finalResult << std::endl;

		if (!isANumber(currentName.substr(count, 1)))
			count += 1;
		else
			count -= 1;
	}
}
