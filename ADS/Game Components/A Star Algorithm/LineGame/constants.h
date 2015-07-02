#pragma once

namespace constants
{
	const int MAX_COLS = 10;
	const int MAX_ROWS = 10;
	const int TILE_SIZE = 64;

	enum class InputMode
	{
		START, END, WALL
	};

	const int MOVMENT_COST = 10;
}