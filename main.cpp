#include <iostream>
#include <fstream>
#include "include/BFInterpreter.hpp"
#include "include/BFCompiler.hpp"

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "\"BFInterpreter.exe [BF file]\" for execute BF file";
		return 0;
	}
	std::string BFFile = argv[1];
	
	std::cout << "Read file..." << std::endl;
	std::ifstream flux(BFFile, std::ios::in);
	if (!flux)
	{
		std::cerr << "Error when openning file : " << BFFile << std::endl;
		return -1;
	}
	std::string content;
	std::getline(flux, content, static_cast<char>(flux.eof()));
	
	std::cout << "Compiling file..." << std::endl;
	BF::InstructionsList compiledContent = BF::compile(content);

	std::cout << "Verify and execute..." << std::endl;

	try
	{
		BF::Interpreter().exec(compiledContent);
	}
	catch (const BF::Exception& e)
	{
		std::cerr << "ERROR : " << e.what() << ", at : " << e.at();
		return -1;
	}

    return 0;
}