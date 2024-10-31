#include "PhoneBook.hpp"
#include "Contacts.hpp"

int main(int argc, char **argv)
{
	Phonebook	book;
	std::string input;

	(void)argv;
	if (argc != 1)
		return 0;
	while (true)
	{
		std::cout << "Insert a command: | ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "Input error. Exiting..." << std::endl;
			exit(1);
		}
		if (input == "ADD")
			book.add_new();
		else if (input == "SEARCH")
			book.search_contacts();
		else if (input == "EXIT")
			break ;
		else if (input.empty())
			return 1;
		else
			std::cout << "Unknown command." << std::endl;
	}
	return 0;
}
