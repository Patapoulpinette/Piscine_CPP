
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>

template<class T>
class PmergeMe
{
	public:
		PmergeMe(T &list);
		~PmergeMe();

		void sort();
		void print(const std::string &msg);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &rhs);

		T	_list;
};

#endif //PMERGEME_HPP
