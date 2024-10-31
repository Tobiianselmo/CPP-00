#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>

class Contacts
{
	private:
		std::string content[5];

	public:
		Contacts();
		~Contacts();

		void setValues(std::string input, int i);
		void getValues() const;
		void getCompleteValues() const;
		std::string getValue(int i) const;
};

#endif