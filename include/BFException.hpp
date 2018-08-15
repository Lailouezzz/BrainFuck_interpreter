#ifndef HEADER_BFException
#define HEADER_BFException
#include <string>
#include "BF.hpp"


namespace BF
{

	class Exception
	{

		size_t m_at;
		std::string m_what;

	public:

		Exception(const std::string& what, const size_t at=0);
		std::string what() const throw () { return m_what; }
		size_t at() const throw () { return m_at; }

	};

}


#endif