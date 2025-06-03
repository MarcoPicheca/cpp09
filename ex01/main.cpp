#include "RNP.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Uso: ./RPN \"espressione in RPN\"\n";
		return 1;
	}
	std::string input(argv[1]);
	std::istringstream iss(input);
	std::stack<int> s;
	std::string token;
	int b = -1;
	int a = -1;
	int result = -1;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (s.size() < 2)
			{
				std::cerr << "Errore: operandi insufficienti\n";
				return 1;
			}
			b = s.top(); s.pop();
			a = s.top(); s.pop();
			result;

			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Errore: divisione per zero\n";
					return 1;
				}
				result = a / b;
			}
			s.push(result);
		}
		else
		{
			char* end;
			int value = std::strtol(token.c_str(), &end, 10);
			if (*end != '\0')
			{
				std::cerr << "Errore: token non valido: " << token << "\n";
				return 1;
			}
			s.push(value);
		}
	}
	if (s.size() != 1)
	{
		std::cerr << "Errore: espressione malformata\n";
		return 1;
	}
	std::cout << s.top() << std::endl;
	return 0;
}
