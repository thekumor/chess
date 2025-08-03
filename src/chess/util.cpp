#include "util.h"

namespace chess
{

	void Message(const std::string& what)
	{
		MessageBoxA(nullptr, what.c_str(), "Message", IDOK);
	}

}