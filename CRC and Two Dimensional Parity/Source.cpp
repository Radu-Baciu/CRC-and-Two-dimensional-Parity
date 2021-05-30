#include <iostream>
#include "TwoDParity.h"
#include "CRC.h"
int main()
{
	TwoDParity TwoDParity;
	CRC CRC;
	int menu = 1;
	std::string message; //100100111011010011011
	std::string message2; //11010011100110110110101
	std::string polynomial; //1011
	while (menu < 3 && menu > 0)
	{
		std::cout << "Introduceti optiunea :" << std::endl;
		std::cout << "1. Paritate bidimensionala" << std::endl;
		std::cout << "2. Redundanta ciclica" << std::endl;
		std::cout << "Pentru iesire introduceti o alta valoare." << std::endl;
		std::cin >> menu;
		bool check;
		switch (menu)
		{
		case 1:
			std::cout << "Introduceti mesajul:" << std::endl;
			std::cin >> message;
			check = TwoDParity.messageCheck(message);
			while (check == false)
			{
				std::cout << "Mesaj invalid. Incercati din nou." << std::endl;
				std::cin >> message;
				check = TwoDParity.messageCheck(message);
			}
			std::cout << "Mesajul transmis este: " << TwoDParity.finalMessage(message) << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Introduceti mesajul:" << std::endl;
			std::cin >> message2;
			check = CRC.messageCheck(message2);
			while (check == false)
			{
				std::cout << "Mesaj invalid. Incercati din nou." << std::endl;
				std::cin >> message2;
				check = CRC.messageCheck(message2);
			}
			std::cout << "Introduceti polinomul:" << std::endl;
			std::cin >> polynomial;
			check = CRC.polynomialCheck(polynomial);
			while (check == false)
			{
				std::cout << "Polinom invalid. Incercati din nou." << std::endl;
				std::cin >> polynomial;
				check = CRC.polynomialCheck(polynomial);
			}
			std::cout << "Mesajul transmis este: " << CRC.finalMessage(message2, polynomial) << std::endl << std::endl;
			break;
		default:
			std::cout << "Executie terminata cu succes!";
			break;
		}
	}
	return 0;
}