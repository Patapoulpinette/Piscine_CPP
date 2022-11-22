/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:29:35 by dbouron           #+#    #+#             */
/*   Updated: 2022/11/21 20:29:35 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc == 4)
	{
		std::string 	filename = argv[1];
		std::string 	s1 = argv[2];
		std::string 	s2 = argv[3];
		std::string		buffer;
		std::size_t		pos;
		std::size_t		saved_pos;
		std::string		replaced_line;

		if (s1.empty())
		{
			std::cerr << "Error: empty string s1" << std::endl;
			return (1);
		}

		//opening and creating input and output files
		std::ifstream	file(filename, std::ios::in);
		if (!file.is_open())
		{
			std::cerr << "Error: failed to open " << filename << std::endl;
			return (1);
		}
		std::ofstream	file_replace(filename.append(".replace"), std::ios::out);
		if (!file_replace.is_open())
		{
			std::cerr << "Error: failed to create " << filename << std::endl;
			return (1);
		}

		//get lines (one by one) of file and put them in new file.replace replacing s1 by s2
		while (getline(file, buffer))
		{
			saved_pos = 0;
			while ((pos = buffer.find(s1, saved_pos)) != std::string::npos)
			{
				replaced_line.append(buffer, saved_pos, pos - saved_pos);
				replaced_line.append(s2);
				saved_pos = pos + s1.size();
			}
			replaced_line.append(buffer, saved_pos);
			file_replace << replaced_line << std::endl;
			replaced_line.clear();
		}

		//closing opening files
		file.close();
		file_replace.close();
	}
	else
		std::cerr << "Error: wrong number of arguments: ./replace [file] [s1] [s2]" << std::endl;
	return (0);
}


