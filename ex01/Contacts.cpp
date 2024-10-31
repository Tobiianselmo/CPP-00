#include "Contacts.hpp"

Contacts::Contacts()
{
	return ;
}

Contacts::~Contacts()
{
	return ;
}

void Contacts::setValues(std::string input, int i)
{
	this->content[i] = input;
}

void Contacts::getValues() const
{
    std::string values[5] = {"First name",
							"Last name",
							"Nickname",
							"Phone number",
							"Secret message"};
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << values[i] << ": " << getValue(i) << std::endl;
    }
    std::cout << std::endl;
}

std::string Contacts::getValue(int i) const
{
    if (i >= 0 && i < 5)
    {
        if(this->content[i].length() > 10)
            return (this->content[i].substr(0, 9) + ".");
        return (this->content[i]);
    }
    return ("");
}

void Contacts::getCompleteValues() const
{
    std::string values[5] = {"First name",
							"Last name",
							"Nickname",
							"Phone number",
							"Secret message"};
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << values[i] << ": " << this->content[i] << std::endl;
    }
    std::cout << std::endl;
}
