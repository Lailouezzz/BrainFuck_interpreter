#include "../include/BFInterpreter.hpp"


namespace BF
{

	Interpreter::Interpreter()
	{
	}

	void Interpreter::exec(const Instruction& instruction)
	{
		switch (instruction)
		{
		case RIGHTMOVEPTR:
			m_BFPointer++;
			if (m_BFPointer >= 30000)
			{
				throw Exception("BF pointer was higher than 29,999");
			}
			break;
		case LEFTMOVEPTR:
			m_BFPointer--;
			if (m_BFPointer < 0)
			{
				throw Exception("BF pointer was smaller than 0");
			}
			break;
		case ADDATPTR:
			(*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer))) += 1;
			break;
		case SUBATPTR:
			(*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer))) -= 1;
			break;
		case DISPLAYBYTE:
			std::cout << (*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer)));
			break;
		case READBYTE:
			std::cin.get(*reinterpret_cast<char*>(m_BFMem + m_BFPointer));
			std::cin.ignore(INT_MAX, '\n');
			break;
		default:
			break;
		}
	}

	void Interpreter::exec(const InstructionsList& instructions)
	{
		verificator(instructions);
		std::stack<size_t> lastEnter;
		for (unsigned int i = 0; i < instructions.size(); i++)
		{
			switch (instructions[i])
			{
			case JZ:
				if (*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer)) != 0)
				{
					lastEnter.push(i);
				}
				else
				{
					for (size_t level = 0; level != 0 || instructions[i] != JNZ; i++)
					{
						switch (instructions[i])
						{
						case JZ:
							level++;
							break;
						case JNZ:
							level--;
							break;
						default:
							break;
						}
					}
					if (i >= instructions.size())
						return;
				}
				break;
			case JNZ:
				if (*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer)) == 0)
				{
					lastEnter.pop();
				}
				else
				{
					i = lastEnter.top();
				}
				break;
			default:
				try
				{
					exec(instructions[i]);
				}
				catch (const Exception& e)
				{
					throw Exception(e.what(), i);
				}
				break;
			}
		}
	}

}