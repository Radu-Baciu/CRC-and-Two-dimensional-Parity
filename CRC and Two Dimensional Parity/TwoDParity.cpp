#include "TwoDParity.h"


bool TwoDParity::messageCheck(std::string message)
{
	if (message.size() % 7 != 0)
		return false;
	for (int i = 0; i < message.size(); i++)
		if (message[i] != '0' && message[i] != '1')
			return false;
	return true;
}

std::string TwoDParity::finalMessage(std::string message)
{
	std::string final = "";
	rows = message.size() / 7;
	std::vector<std::vector<int>> matrix(rows + 1, std::vector<int> (cols));
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 7; j++)
		{
			matrix[i][j] = message[0] - '0';
			message.erase(message.begin());
		}
	for (int i = 0; i < rows; i++)
		{
		int sum = 0;
		for (int j = 0; j < 7; j++)
			sum = sum + matrix[i][j];
		matrix[i][7] = sum % 2;
		}
	for (int j = 0; j < 7; j++)
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
			sum = sum + matrix[i][j];
		matrix[rows][j] = sum % 2;
	}
	for (int i = 0; i < rows + 1; i++)
		for (int j = 0; j < 8; j++)
			final += std::to_string(matrix[i][j]);
	final.erase(final.end()-1);
	return final;
}
