#pragma once

#include <Windows.h>
/*
===============================================================================
Enum used to quickly define a console color
===============================================================================
*/
enum ConsoleColor : WORD {
	BLACK			= 0b0000,
	DARK_BLUE		= 0b0001,
	DARK_GREEN		= 0b0010,
	DARK_CYAN		= 0b0011,
	DARK_RED		= 0b0100,
	DARK_MAGENTA	= 0b0101,
	DARK_YELLOW		= 0b0110,
	DARK_WHITE		= 0b0111,
	BRIGHT_BLACK	= 0b1000,
	BRIGHT_BLUE		= 0b1001,
	BRIGHT_GREEN	= 0b1010,
	BRIGHT_CYAN		= 0b1011,
	BRIGHT_RED		= 0b1100,
	BRIGHT_MAGENTA	= 0b1101,
	BRIGHT_YELLOW	= 0b1110,
	WHITE			= 0b1111
};
