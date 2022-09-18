/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:01:19 by bsavinel          #+#    #+#             */
/*   Updated: 2022/07/25 19:34:06 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAMESPACE_USE
# define NAMESPACE_USE std
# define NB_NAMESPACE 1
#endif

//? partie if pour namespace std
//? partie else pour namespace ft

#if NB_NAMESPACE
# include <vector>
#else
# include "vector.hpp"
#endif

#include <list>
#include "testeur.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}


using namespace NAMESPACE_USE;

template <typename T>
void	printSize(vector<T> const &vct, bool print_content = true)
{
	const int size = vct.size();
	const int capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename vector<T>::const_iterator it = vct.begin();
		typename vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

void	vector_test()
{
	const int size = 5;
	vector<foo<int> > vct(size);
	vector<foo<int> >::reverse_iterator it_0(vct.rbegin());
	vector<foo<int> >::reverse_iterator it_1(vct.rend());
	vector<foo<int> >::reverse_iterator it_mid;

	vector<foo<int> >::const_reverse_iterator cit_0 = vct.rbegin();
	vector<foo<int> >::const_reverse_iterator cit_1;
	vector<foo<int> >::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	printSize(vct, 1);
	
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; 
	cit_mid = cit_0 + 3; 
	cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid);
	ft_eq_ope(it_0, it_1);
	ft_eq_ope(it_1 - 3, it_mid);
	// const it
	ft_eq_ope(cit_0 + 3, cit_mid);
	ft_eq_ope(cit_0, cit_1);
	ft_eq_ope(cit_1 - 3, cit_mid);
	// both it
	ft_eq_ope(it_0 + 3, cit_mid);
	ft_eq_ope(it_mid, cit_0 + 3);
	ft_eq_ope(it_0, cit_1);
	ft_eq_ope(it_1, cit_0);
	ft_eq_ope(it_1 - 3, cit_mid);
	ft_eq_ope(it_mid, cit_1 - 3);
	exit(0);
	
}
	/*std::cout << std::endl << std::endl << "Test vector:" << std::endl << std::endl;
	
	vector<int> vct;
	vector<int>::iterator it = vct.begin();
	vector<int>::const_iterator cit = vct.begin();

	vector<int>::reverse_iterator rit(it);

	vector<int>::const_reverse_iterator crit(rit);
	vector<int>::const_reverse_iterator crit_(it);
	vector<int>::const_reverse_iterator crit_2(cit);*/

	/* error expected
	TESTED_NAMESPACE::vector<int>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::vector<int>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::vector<int>::iterator it2(rit);
	TESTED_NAMESPACE::vector<int>::const_iterator cit2(crit);
	*/

	/*std::cout << "OK" << std::endl;	

	{
		vector<int> test1;

		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.pop_back();
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.pop_back();
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
	}
	{
		std::cout << "autre test" << std::endl;
		vector<int> test1;

		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		test1.push_back(1);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		test1.clear();
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		vector<int>::const_iterator it_const = test1.begin();
		std::cout << *it_const << std::endl;
		it_const++;
		std::cout << *it_const << std::endl;
	}
	{
		vector<int> my_vector;
		std::cout << my_vector.size() << " " << my_vector.capacity() << std::endl;
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		my_vector.push_back(22);
		std::cout << my_vector.size() << " " << my_vector.capacity() << std::endl;
		vector<int> test1;
		test1.push_back(122);
		test1.push_back(232);
		test1.push_back(252);
		test1.push_back(229);
		test1.push_back(228);
		test1.push_back(32);
		test1.push_back(92);
		test1.push_back(82);
		test1.push_back(72);
		test1.push_back(2);
		test1.push_back(23);
		test1.push_back(25);
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
		std::cout << *my_vector.begin();
		std::cout << "valeur fin " << *(test1.end() - 1) << std::endl;
		std::cout << "valeur debut " << *(test1.begin()) << std::endl;
		test1.insert(test1.begin() + 3, my_vector.begin(), my_vector.begin() + 13);
		test1.insert(test1.begin() + 3, 4);
		for (int i = 0; i < static_cast<int>(test1.size()); i++)
			std::cout << "elem [" << i << "] : " << test1[i] << std::endl;
		std::cout << test1.size() << " " << test1.capacity() << std::endl;
	}
	{
		vector<int> test1;
		test1.push_back(122);
		test1.push_back(232);
		test1.push_back(252);
		test1.push_back(229);
		test1.push_back(228);
		test1.push_back(32);
		test1.push_back(92);
		test1.push_back(82);
		test1.push_back(72);
		test1.push_back(2);
		test1.push_back(23);
		test1.push_back(25);
		for (int i = 0; i < static_cast<int>(test1.size()); i++)
			std::cout << "elem [" << i << "] : " << test1.at(i) << std::endl;
	}
	{
		std::cout << "test ici" << std::endl;
		vector<int> vct(7);

		std::cout << "151" << std::endl;
		for (unsigned long int i = 0; i < vct.size(); ++i)
		{
			vct.at(i) = (vct.size() - i) * 3;
			std::cout << "vct.at(): " << vct.at(i) << " | ";
			std::cout << "vct[]: " << vct[i] << std::endl;
		}

		vector<int> const vct_c(vct);

		std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
		std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;
		std::cout << vct.size() << " " << vct.capacity() << std::endl;

		try
		{
			vct.at(10) = 42;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Catch out_of_range exception!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Catch exception: " << e.what() << std::endl;
		}
		printSize(vct);
	}
	{
		vector<int> vct(7);
		vector<int> vct_two(4);
		vector<int> vct_three;
		vector<int> vct_four;
		
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;
		printSize(vct);
		printSize(vct_two);

		vct_three.assign(vct.begin(), vct.end());
		vct.assign(vct_two.begin(), vct_two.end());
		vct_two.assign(2, 42);
		vct_four.assign(4, 21);

		std::cout << "\t### After assign(): ###" << std::endl;

		printSize(vct);
		printSize(vct_two);
		printSize(vct_three);
		printSize(vct_four);

		vct_four.assign(6, 84);
		printSize(vct_four);

		std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

		vct.assign(5, 53);
		vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

		printSize(vct);
		printSize(vct_two);
	}
	{
		std::list<int> lst;
		std::list<int>::iterator lst_it;
		std::cout << "241" << std::endl;
		for (int i = 1; i < 5; ++i)
			lst.push_back(i * 3);
		
		std::cout << "245" << std::endl;
		vector<int> vct(lst.begin(), lst.end());
		std::cout << "247" << std::endl;
		printSize(vct);
	
		std::cout << "249" << std::endl;
		lst_it = lst.begin();
		for (int i = 1; lst_it != lst.end(); ++i)
			*lst_it++ = i * 5;
		std::cout << "253" << std::endl;
		vct.assign(lst.begin(), lst.end());
		printSize(vct);

		std::cout << "257" << std::endl;
		vct.insert(vct.end(), lst.rbegin(), lst.rend());
		printSize(vct);
	}
	{
		vector<int> vct(10);
		vector<int> vct2;
		vector<int> vct3;
	
		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		printSize(vct);
	
		vct2.insert(vct2.end(), 42);
		vct2.insert(vct2.begin(), 2, 21);
		printSize(vct2);
	
		vct2.insert(vct2.end() - 2, 42);
		printSize(vct2);
	
		vct2.insert(vct2.end(), 2, 84);
		printSize(vct2);
	
		vct2.resize(4);
		printSize(vct2);
	
		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		vct.clear();
		printSize(vct2);
	
		printSize(vct);
	
		for (int i = 0; i < 5; ++i)
			vct3.insert(vct3.end(), i);
		vct3.insert(vct3.begin() + 1, 2, 111);
		printSize(vct3);
	}
	{
		const int size = 5;
		vector<int> vct(size);
		vector<int>::iterator it_ = vct.begin();
		vector<int>::reverse_iterator it(it_);
	
		for (int i = 0; i < size; ++i)
			vct[i] = (i + 1) * 5;
		printSize(vct);
	
		std::cout << (it_ == it.base()) << std::endl;
		std::cout << (it_ == (it + 3).base()) << std::endl;
	
		std::cout << *(it.base() + 1) << std::endl;
		std::cout << *(it - 3) << std::endl;
		std::cout << *(it - 3).base() << std::endl;
		it -= 3;
		std::cout << *it.base() << std::endl;
	
		std::cout << "TEST OFFSET" << std::endl;
		std::cout << *(it) << std::endl;
		std::cout << *(it).base() << std::endl;
		std::cout << *(it - 0) << std::endl;
		std::cout << *(it - 0).base() << std::endl;
		std::cout << *(it - 1).base() << std::endl;
	}
	{

		vector<int> vct(4);
		vector<int> vct2(4);
	
		cmp(vct, vct);  // 0
		cmp(vct, vct2); // 1
	
		vct2.resize(10);
	
		cmp(vct, vct2); // 2
		cmp(vct2, vct); // 3
	
		vct[2] = 42;
	
		cmp(vct, vct2); // 4
		cmp(vct2, vct); // 5
	
		swap(vct, vct2);
	
		cmp(vct, vct2); // 6
		cmp(vct2, vct); // 7
	}*/
