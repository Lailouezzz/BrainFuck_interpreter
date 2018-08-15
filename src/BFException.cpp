#include "../include/BFException.hpp"


namespace BF
{

	Exception::Exception(const std::string& what, const size_t at) :
		m_what(what),
		m_at(at)
	{
	}

}