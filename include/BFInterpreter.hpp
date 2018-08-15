#ifndef HEADER_BFInterpreter
#define HEADER_BFInterpreter
#include <cstring>
#include <iostream>
#include <stack>
#include "BF.hpp"
#include "BFVerificator.hpp"



namespace BF
{

	class Interpreter // Brain Fuck interpreter
	{

		uint8_t m_BFMem[30000]; // Brain Fuck mem 30'000 bytes
		int16_t m_BFPointer = 0; // Offset of pointer for BF mem

	public:

		Interpreter();
		void exec(const Instruction& instruction);
		void exec(const InstructionsList& instructions);

	};

}


#endif