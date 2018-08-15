#include "../include/BFVerificator.hpp"


namespace BF
{

	void verificator(const InstructionsList& instructions)
	{
		int64_t level = 0;
		std::stack<size_t> lastEnter;
		for (unsigned int i = 0; i < instructions.size(); i++)
		{
			switch (instructions[i])
			{
			case JZ:
				level++;
				lastEnter.push(i);
				break;
			case JNZ:
				level--;
				if (level < 0)
				{
					throw Exception("too much \"]\"", i + 1);
				}
				lastEnter.pop();
				break;
			default:
				break;
			}
		}
		if (level > 0)
		{
			throw Exception("missing \"]\"", lastEnter.top() + 1);
		}
	}

}