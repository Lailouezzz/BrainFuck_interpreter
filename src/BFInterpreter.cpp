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
			break;
		case LEFTMOVEPTR:
			m_BFPointer--;
			break;
		case ADDATPTR:
			if (m_BFPointer < 0)
			{
				throw Exception("BF mem access address was smaller than 0");
			}
			else if (m_BFPointer >= 30000)
			{
				throw Exception("BF mem access address was higher than 29,999");
			}
			(*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer))) += 1;
			break;
		case SUBATPTR:
			if (m_BFPointer < 0)
			{
				throw Exception("BF mem access address was smaller than 0");
			}
			else if (m_BFPointer >= 30000)
			{
				throw Exception("BF mem access address was higher than 29,999");
			}
			(*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer))) -= 1;
			break;
		case DISPLAYBYTE:
			if (m_BFPointer < 0)
			{
				throw Exception("BF mem access address was smaller than 0");
			}
			else if (m_BFPointer >= 30000)
			{
				throw Exception("BF mem access address was higher than 29,999");
			}
			std::cout << (*(reinterpret_cast<uint8_t*>(m_BFMem + m_BFPointer)));
			break;
		case READBYTE:
			if (m_BFPointer < 0)
			{
				throw Exception("BF mem access address was smaller than 0");
			}
			else if (m_BFPointer >= 30000)
			{
				throw Exception("BF mem access address was higher than 29,999");
			}
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
		for (size_t i = 0; i < instructions.size(); i++)
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
					for (size_t level = 0; (instructions[++i] != JNZ || level != 0);)
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