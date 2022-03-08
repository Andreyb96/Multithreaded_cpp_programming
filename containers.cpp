#include <string>
#include <iostream>
#include <map>

void FillMap(std::map<int, int, std::greater<int>>& mapToFill, const std::string& elem)
{
	size_t pos = 0;
	auto value = 0;

	if (elem.empty())
	{
		return;
	}

	if (elem.find('^') == std::string::npos)
	{
		if (elem.find('x') == std::string::npos)
		{
			mapToFill[0] = 0;
		}
		else
		{
			if ((pos = elem.find('*')) == std::string::npos)
			{
				value = 1;
			}
			else
			{
				value = std::stoi(elem.substr(0, pos));
			}

			if (mapToFill.find(1) == mapToFill.end())
			{
				mapToFill[1] = value;
			}
			else
			{
				mapToFill[1] += value;
			}
		}
	}
	else
	{
		if ((pos = elem.find('*')) == std::string::npos)
		{
			value = elem[0] == '-' ? -1 : 1;
		}
		else
		{
			value = std::stoi(elem.substr(0, pos));
		}

		pos = elem.find('^');
		auto coeff = std::stoi(elem.substr(pos + 1, elem.length()));

		if (mapToFill.find(coeff) == mapToFill.end())
		{
			mapToFill[coeff] = value;
		}
		else
		{
			mapToFill[coeff] += value;
		}
	}
}

std::string derivative(const std::string& polynomial) {

	std::map<int, int, std::greater<int>> terms;

	std::string s = polynomial;
	std::string delimiter = "+";
	std::string delimiter2 = "-";
	std::string symbol = "";
	bool isPlus = false;

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos || (pos = s.find(delimiter2)) != std::string::npos)
	{
		if (s.find(delimiter) < s.find(delimiter2))
		{
			pos = s.find(delimiter);
			isPlus = true;
		}
		else
		{
			pos = s.find(delimiter2);
			isPlus = false;
		}

		FillMap(terms, symbol + s.substr(0, pos));

		s.erase(0, pos + 1);

		symbol = isPlus ? delimiter : delimiter2;
	}
	FillMap(terms, symbol + s);

	std::string result = "";

	for (auto elem : terms)
	{
		auto prefix = elem.second * elem.first;
		std::string prefixStr = "";
		auto postfix = elem.first - 1;
		std::string postfixStr = "";

		if (prefix != 1)
		{
			prefixStr = prefix > 0 ? "+" + std::to_string(prefix) + "*" : std::to_string(prefix) + "*";
		}

		if (postfix == 0)
		{
			result += prefix > 0 ? "+" + std::to_string(prefix) : std::to_string(prefix);
			continue;
		}
		else if (postfix == 1)
		{
			postfixStr = "";
		}
		else
		{
			postfixStr = "^" + std::to_string(elem.first - 1);
		}

		if (elem.first == 0)
		{
			continue;
		}
		else if (elem.first == 1)
		{
			result += prefixStr + "x" + postfixStr;
		}
		else
		{
			result += prefixStr + "x" + postfixStr;
		}
	}

	if (result[0] == '+')
	{
		return result.substr(1, result.length());
	}

	return result;
}