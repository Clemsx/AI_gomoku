#include <exception>
#include "Core.hpp"

int main() {
	Core core;

	try
	{
		core.run();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}