#include "../include/BFCompiler.hpp"


namespace BF
{
	
	InstructionsList compile(const std::string& content)
	{
		InstructionsList buf;
		for (unsigned int i = 0; i < content.size(); i++)
		{
			switch (content[i])
			{
			case '>':
				buf.push_back(RIGHTMOVEPTR);
				break;
			case '<':
				buf.push_back(LEFTMOVEPTR);
				break;
			case '+':
				buf.push_back(ADDATPTR);
				break;
			case '-':
				buf.push_back(SUBATPTR);
				break;
			case '.':
				buf.push_back(DISPLAYBYTE);
				break;
			case ',':
				buf.push_back(READBYTE);
				break;
			case '[':
				buf.push_back(JZ);
				break;
			case ']':
				buf.push_back(JNZ);
				break;
			case ';':
				for (; content[i] != '\n' && i < content.size(); i++);
				break;
			default:
				break;
			}
		}
		return buf;
	}

}