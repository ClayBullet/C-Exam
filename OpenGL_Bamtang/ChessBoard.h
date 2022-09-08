#pragma once
#include <iostream>

struct ChessObject
{
	std::string id;
	std::string nameFile;
	unsigned xPos;
	unsigned yPos;
};

class ChessBoard
{
private:
	int widthTable;
	int heightTable;

	ChessObject objChess[81] = {};

	int coords[81][81] = {};

	std::string whiteChess[16] = {};

	std::string blackChess[16] = {};

	constexpr unsigned int str2int(const char* str, int h = 0);
	

	std::string idStringToNameFile(std::string str);

public:

	bool isANumber(std::string initPosition);

	int stringToNumber(std::string initPosition);

	std::string TakeValue(unsigned x, unsigned y);

	std::string TakeFileReference(unsigned x, unsigned y);


	ChessBoard();

	void ChessCheckPos(int index, unsigned x, unsigned y, std::string id, std::string nameFile);


	void InitTable();

	void DrawChessBoard(const char* initPosition);
};

