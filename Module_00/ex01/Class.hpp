/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:11:53 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/14 13:13:07 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void	set_first_name(std::string value);
		void	set_last_name(std::string value);
		void	set_nickname(std::string value);
		void	set_phone_number(std::string value);
		void	set_darkest_secret(std::string value);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_darkest_secret(void) const;

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		int	add_function(int index);
		int search_function(void);

	private:
		Contact _directory[8];
};

int is_only_digits(std::string str);

#endif //PHONEBOOK_H