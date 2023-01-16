/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:18:45 by dbouron           #+#    #+#             */
/*   Updated: 2023/01/16 15:14:54 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include "easyfind.hpp"

int main()
{
	// LIST ───────────────────────────────────────────────────────────────────
	std::list<int> 		lst(5, 0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	std::cout << "─ LIST ──────────────────────\n";
	try { std::cout << "easyfind: " << easyfind(lst, 3) << "\n"; }
	catch (std::exception &e) { std::cerr << "no occurrence found" << std::endl; }
	try { std::cout << "easyfind: " << easyfind(lst, 12) << "\n"; }
	catch (std::exception &e) { 	std::cerr << "no occurrence found" << std::endl; }

	// VECTOR ─────────────────────────────────────────────────────────────────
	std::vector<int>	vct(5, 0);
	vct.push_back(11);
	vct.push_back(12);
	vct.push_back(13);
	vct.push_back(14);
	vct.push_back(15);

	std::cout << "\n─ VECTOR ────────────────────\n";
	try { 	std::cout << "easyfind: " << easyfind(vct, 3) << "\n"; }
	catch (std::exception &e) { 	std::cerr << "no occurrence found" << std::endl; }
	try { 	std::cout << "easyfind: " << easyfind(vct, 12) << std::endl; }
	catch (std::exception &e) { 	std::cerr << "no occurrence found" << std::endl; }

	return 0;
}
