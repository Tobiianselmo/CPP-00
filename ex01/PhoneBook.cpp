#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	this->index = 0;
	this->full_contacts = 0;
	this->total_contacts = 0;
}

Phonebook::~Phonebook()
{
	return ;
}

static int ft_stoi(std::string str)
{
	int i = 0;
	int res = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return res;
}

static int	correct_input(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return 1;
		i++;
	}
	return 0;
}

void	Phonebook::add_new()
{
	Contacts New_contact;
	std::string input;
	std::string values[5] = {"First name",
							"Last name",
							"Nickname",
							"Phone number",
							"Secret message"};

	for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter " << values[i] << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "Input error. Exiting..." << std::endl;
            exit(1);
        }
        if (input.empty())
        {
            std::cout << "Insert a valid argument..." << std::endl;
            i--;
        }
        else if (i == 3 && correct_input(input))
        {
            std::cout << "Insert only numbers" << std::endl;
            i--;
        }
        else
            New_contact.setValues(input, i);
    }
	this->list[index] = New_contact;
	this->index = (index + 1) % 8;
	if (!full_contacts && total_contacts < 8)
		total_contacts++;
	if (total_contacts == 8)
		this->full_contacts = true;
}

void Phonebook::search_contacts()
{
	if (this->total_contacts == 0)
	{
		std::cout << "Phonebook is empty. You must add Contacts to be able to search for them." << std::endl;
		return ;
	}
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Index | First Name      | Last Name       | Nick Name        " << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < this->total_contacts; i++)
	{
		std::cout << std::setw(5) << i + 1 << " | ";
		std::cout << std::setw(15) << this->list[i].getValue(0) << " | ";
		std::cout << std::setw(15) << this->list[i].getValue(1) << " | ";
		std::cout << std::setw(15) << this->list[i].getValue(2) << std::endl;
	}
	std::cout << "\nEnter the index of the contact you want to view: ";
	int index;
	std::string input;
	if (!std::getline(std::cin, input))
	{
		if (std::cin.eof())
		{
			std::cout << "Input error. Exiting..." << std::endl;
            exit(1);
		}
	}
	if (correct_input(input) == 0)
	{
		index = ft_stoi(input);
		if (index < 1 || index > this->total_contacts)
			std::cout << "Invalid index. Please enter a number between 1 and " << this->total_contacts << "." << std::endl;
		else
		{
			std::cout << "Contact Details:" << std::endl;
			this->list[index - 1].getCompleteValues();
		}
	}
	else
		std::cout << "Invalid input. Please enter a numeric index." << std::endl;

}
