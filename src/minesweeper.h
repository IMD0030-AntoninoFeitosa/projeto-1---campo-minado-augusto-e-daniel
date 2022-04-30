#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <iostream>
#include <algorithm>
#include <array>

const char MINE = 'B';
const char NONE = '-';

enum class Difficulty { beginner, intermediary, advanced };

struct Cell {
	bool isMine = false;
	bool isNum = false;
	bool isMarked = false;
	bool isNone = true;
};

using Map = std::array<std::array<Cell,10>,10>;

Map generateMap();

void showMap(Map map);

#endif