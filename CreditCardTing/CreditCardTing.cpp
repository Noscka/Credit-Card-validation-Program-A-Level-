#include <iostream>
#include <string>

/// <summary>
/// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
/// </summary>
/// <param name="s">String to check</param>
/// <returns>if string is numbers</returns>
bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
									  s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

/// <summary>
/// Make function for validating card number. uses subfunctions for each card type
/// </summary>
/// <param name="cardInput"> string containing card number </param>
/// <returns> if card number is valid or not</returns>
bool ValidateCard(std::string cardInput)
{
	if((cardInput.substr(0, 2) == "34" || cardInput.substr(0, 2) == "37") && cardInput.length() == 15)
	{
		printf("America Express\n");
		return true;
	}
	else if((51 <= std::atoi(cardInput.substr(0, 2).c_str()) && std::atoi(cardInput.substr(0, 2).c_str()) >= 55) && cardInput.length() == 16)
	{
		printf("MasterCard\n");
		return true;
	}
	else if((cardInput[0] == '4') && cardInput.length() == 16)
	{
		printf("Visa\n");
		return true;
	}
	else if((cardInput.substr(0, 4) == "6011") && cardInput.length() == 16)
	{
		printf("Discover\n");
		return true;
	}

	return false;
}

int main()
{
	std::string cardInputText; /* String that contains the card number */
	printf("Input Card number: ");
	std::getline(std::cin, cardInputText); /* Get full line, makes sure to get all characters */

	/* Validate if the input is actually numbers*/
	if(!is_number(cardInputText))
	{
		printf("the card number is invalid");
		return 1;
	}

	if(ValidateCard(cardInputText))
	{
		printf("The card is valid");
	}
	else
	{
		printf("The card is invalid");
	}
	return 0;
}

// 70 lines of code