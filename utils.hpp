#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft
{
	//---------iterator utils----------

	template<class InputIterator>
	size_t	distance(InputIterator first, InputIterator last)
	{
		size_t n = 0;
		while(first != last)
		{
			n++;
			first++;
		}
		return (n);
	}

	template<class InputIterator, class Distance>
	void	advance(InputIterator& it, Distance n)
	{
		while (n > 0)
		{
			it++;
			n--;
		}
	}


	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};



	// Our iterator traits will just consist of iterator's nested types
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

	//---------types----enable-if-----

	template <class T, T v>
	struct integral_constant
	{
		typedef integral_constant<T, v> type;
		typedef T value_type;
		static const T value = v;  //bool
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type {};

	template <>
	struct is_integral<bool> : public true_type {};

	template <>
	struct is_integral<char> : public true_type {};

	template <>
	struct is_integral<wchar_t> : public true_type {};

	template <>
	struct is_integral<signed char> : public true_type {};

	template <>
	struct is_integral<short int> : public true_type {};

	template <>
	struct is_integral<int> : public true_type {};

	template <>
	struct is_integral<long int> : public true_type {};

	template <>
	struct is_integral<long long int> : public true_type {};

	template <>
	struct is_integral<unsigned char> : public true_type {};

	template <>
	struct is_integral<unsigned short int> : public true_type {};

	template <>
	struct is_integral<unsigned int> : public true_type {};

	template <>
	struct is_integral<unsigned long int> : public true_type {};

	template <>
	struct is_integral<unsigned long long int> : public true_type {};




	template <typename T>
	void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

//	template <typename T>
//	T min(T a, T b)
//	{
//		return a < b ? a : b;
//	}

	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}

//from cplusplus.com
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

// -------------MAP UTILS------------------------------

	template<class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

	template <class T>
	struct less: binary_function<T, T, bool>
	{
		inline bool operator()(const T &x, const T &y) const
		{
		return x < y;
		}
	};

	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		// (1) default constructor
		pair() : first(T1()), second(T2()){};

		// (2) copy / move constructor (and implicit conversion)
		template <class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};

		// (3) initialization constructor
		pair(const first_type& a, const second_type& b) : first(a), second(b){};
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}

	// (1)
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	// (2)
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	// (3)
	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	// (4)
	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	}

	// (5)
	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	// (6)
	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}



}

#endif
