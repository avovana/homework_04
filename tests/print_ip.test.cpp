//
// File: print_ip.test.cpp
//

#define BOOST_TEST_MODULE PrintIpTest
#include <boost/test/unit_test.hpp>

#include "print_ip.h"
#include <sstream>

// Функция должна распознавать нужные типы фундаментальных данных
BOOST_AUTO_TEST_CASE(PrintIntegrals) {

	std::stringstream result;

	print_ip(char(-1), result);
	print_ip(short(0), result);
	print_ip(2130706433, result);
	print_ip(long(8875824491850138409), result);

	std::string outputData =
		"255"
		"0.0"
		"127.0.0.1"
		"123.45.67.89.101.112.131.41";

	BOOST_CHECK_EQUAL(result.str(), outputData);
}

// Функция должна распознавать контейнеры
BOOST_AUTO_TEST_CASE(PrintContainers) {

	std::stringstream result;
	std::string outputData = "10.0.254.2";

	print_ip(std::list<int>{10, 0, 254, 2}, result);
	BOOST_CHECK_EQUAL(result.str(), outputData);

	std::stringstream result2;
	std::string outputData2 = "255.255.0.0";

	print_ip(std::vector<int>{255, 255, 0, 0}, result);
	BOOST_CHECK_EQUAL(result2.str(), outputData2);
}

// Функция должна работать с пустыми контейнерами
BOOST_AUTO_TEST_CASE(PrintEmptyContainers) {

	std::stringstream result;
	std::string outputData = "";

	print_ip(std::list<int>{}, result);
	BOOST_CHECK_EQUAL(result.str(), outputData);
}

// Функция должна распознавать нужные тип строки
BOOST_AUTO_TEST_CASE(PrintString) {

	std::stringstream result;
	std::string outputData = "192.168.0.1";

	print_ip("192.168.0.1", result);
	BOOST_CHECK_EQUAL(result.str(), outputData);
}