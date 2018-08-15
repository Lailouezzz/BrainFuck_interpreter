#ifndef HEADER_BF
#define HEADER_BF
#include <cstdint>
#include <vector>


namespace BF
{
	enum Instruction : uint8_t // Only 3 bits are used
	{
		RIGHTMOVEPTR = 0,
		LEFTMOVEPTR = 1,
		ADDATPTR = 2,
		SUBATPTR = 3,
		DISPLAYBYTE = 4,
		READBYTE = 5,
		JZ = 6,
		JNZ = 7
	};
	using InstructionsList = std::vector<Instruction>;
}


#endif