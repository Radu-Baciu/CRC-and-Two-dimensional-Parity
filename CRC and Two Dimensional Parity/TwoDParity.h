#include <string>
#include <vector>
#pragma once

class TwoDParity
{
private:
	int rows;
	int cols = 8;
public:
	bool messageCheck(std::string message);
	std::string finalMessage(std::string message);
};

