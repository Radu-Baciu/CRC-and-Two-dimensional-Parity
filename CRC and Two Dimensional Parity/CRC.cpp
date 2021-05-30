#include "CRC.h"

std::string CRC::messageFix(std::string message, std::string polynomial)
{
	for (int i = 0; i < polynomial.size() - 1; i++)
		message += "0";
	return message;
}

bool CRC::messageCheck(std::string message)
{
	for (int i = 0; i < message.size(); i++)
		if (message[i] != '0' && message[i] != '1')
			return false;
	return true;
}

bool CRC::polynomialCheck(std::string polynomial)
{
	for (int i = 0; i < polynomial.size(); i++)
		if (polynomial[i] != '0' && polynomial[i] != '1')
			return false;
	if (polynomial[0] != '1' || polynomial[polynomial.size() - 1] != '1')
		return false;
	return true;
}

std::string CRC::XOR(std::string message, std::string polynomial)
{
	std::string result = "";
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] != polynomial[i])
			result += "1";
		else
			result += "0";
	}
	return result;
}

std::string CRC::finalMessage(std::string message, std::string polynomial)
{
	message = messageFix(message, polynomial);
	std::string copymessage = message;
	while (message.size() >= polynomial.size())
	{
		std::string xorcheck = message.substr(0, polynomial.size());
		std::string xorreplace = XOR(xorcheck, polynomial);
		message.replace(0, polynomial.size(), xorreplace);
		while (message[0] == '0')
			message.erase(message.begin());
	}
	std::string finalxor = copymessage.substr(copymessage.size() - message.size(), copymessage.size());
	std::string finalreplace = XOR(finalxor, message);
	copymessage.replace(copymessage.size() - message.size(), copymessage.size(), finalreplace);
	return copymessage;
}
