#include <string>
#pragma once
class CRC
{
private:
	std::string messageFix(std::string message, std::string polynomial);
public:
	bool messageCheck(std::string message);
	bool polynomialCheck(std::string polynomial);
	std::string XOR(std::string message, std::string polynomial);
	std::string finalMessage(std::string message, std::string polynomial);
};

