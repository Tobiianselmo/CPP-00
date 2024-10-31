#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <cstdlib>
#include "Contacts.hpp"

class Phonebook
{
	private:
		Contacts list[8];
		int	total_contacts;
		int index;
		bool full_contacts;

	public:
		Phonebook();
		~Phonebook();

		void	add_new();
		void	search_contacts();
};

#endif