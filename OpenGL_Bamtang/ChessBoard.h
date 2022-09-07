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



public:

	std::string TakeValue(unsigned x, unsigned y);

	std::string TakeFileReference(unsigned x, unsigned y);


	ChessBoard();

	void ChessCheckPos(int index, unsigned x, unsigned y, std::string id, std::string nameFile);


	void InitTable();
};

