#include "print_ip.h"
#include <sstream>

int main()
{
	try
	{
		print_ip(char(-1));
		std::cout << std::endl;
		print_ip(short(0));
		std::cout << std::endl;
		print_ip(2130706433);
		std::cout << std::endl;
		print_ip(long(8875824491850138409));
		std::cout << std::endl;
		print_ip("192.168.0.1");
		std::cout << std::endl;
		print_ip(std::list<int>{10, 0, 254, 2});
		std::cout << std::endl;
		print_ip(std::vector<int>{255, 255, 0, 0});
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}