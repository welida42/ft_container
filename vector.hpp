#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstddef> // ptrdiff_t
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>

#include "revIterator.hpp"
#include "utils.hpp"

namespace ft
{
	template <typename T>
	class vectorIterator;

	template <typename T, typename Alloc = std::allocator<T> >
	class vector
{
public:
	typedef T value_type;
	typedef Alloc allocator_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type*	pointer;
	typedef const value_type*	const_pointer;
	typedef vectorIterator<T> iterator;
	typedef vectorIterator<const T> const_iterator;
	typedef rev_iterator<vectorIterator<T> > reverse_iterator;
	typedef rev_iterator<vectorIterator<const T> > const_reverse_iterator;
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;


private:
	pointer _base;
	size_type _size;
	size_type _capacity;
	allocator_type _alloc;

public:
	// default (1)
	explicit vector(const allocator_type &alloc = allocator_type()) :
	_size(0), _capacity(0)
	{
		_alloc = alloc;
		_base = _alloc.allocate(1);
	}

	// fill (2)
	explicit vector(size_type n, const value_type &val = value_type(),
					const allocator_type &alloc = allocator_type()) :
					_size(n), _capacity(n)
	{
		_alloc = alloc;
		_base = _alloc.allocate(_capacity);
		for (size_type i = 0; i < n; i++)
			_alloc.construct(&_base[i], val);
	}

	// range (3)
	template <class InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
			InputIterator last, const allocator_type &alloc = allocator_type())
	{
		_alloc = alloc;
		_size = ft::distance(first, last);
		_capacity = _size;
		_base = _alloc.allocate(_capacity);
		for (size_type i = 0; first != last; first++, i++)
			_alloc.construct(&_base[i], *first);
	}

	// copy (4)
	vector(const vector &x)
	{
		_alloc = x._alloc;
		_size = x._size;
		_capacity = x._capacity;
		_base = _alloc.allocate(_capacity);

		size_type i = 0;
		for (vector::const_iterator it = x.begin(); it != x.end(); it++)
		{
			_base[i] = *it;
			i++;
		}
	}

	vector &operator=(const vector &x)
	{
		_alloc = x._alloc;
		_size = x._size;

		if (_capacity < x._capacity)
		{
			for (size_type i = 0; i < _capacity; i++)
			{
				_alloc.destroy(_base + i);
			}
			_alloc.deallocate(_base, _capacity);

			_capacity = x._capacity;
			_base = _alloc.allocate(_capacity);
			size_type i = 0;
			for (vector::const_iterator it = x.begin(); it != x.end(); it++)
			{
				_base[i] = *it;
				i++;
			}
			return *this;
		}

		size_type i = 0;
		for (vector::const_iterator it = x.begin(); it != x.end(); it++)
		{
			_base[i] = *it;
			i++;
		}
		return *this;
	}

	~vector()
	{
		if (_capacity == 0)
			_alloc.deallocate(_base, 1);
		else
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_base[i]);
			_alloc.deallocate(_base, _capacity);
		}
	};



	// Iterators
	iterator begin() { return iterator(_base); }
	const_iterator begin() const { return const_iterator(_base); }

	iterator end() { return iterator(_base + _size); }
	const_iterator end() const { return const_iterator(_base + _size); }

	reverse_iterator rbegin() { return reverse_iterator(_base + _size); } //
	// check it. maybe -1
	const_reverse_iterator rbegin() const { return const_reverse_iterator(_base + _size); }

	reverse_iterator rend() { return reverse_iterator(_base); }
	const_reverse_iterator rend() const { return const_reverse_iterator(_base); }

	// Capacity

	size_type size() const { return _size; }

	size_type max_size() const { return _alloc.max_size(); }

	void resize(size_type n, value_type val = value_type())
	{
		if (n < _size)
			_size = n;
		if (n > _size)
		{
			reserve(n);
			while (_size != n)
			{
				_base[_size] = val;
				_size++;
			}
		}
	}

	size_type capacity() const { return _capacity; }

	bool empty() const { return _size == 0; }

	void reserve(size_type n)
	{
		if (n > _capacity)
		{
			pointer p = _alloc.allocate(n);
			if (!p)
				throw std::bad_alloc();
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&p[i], _base[i]);
		//	destroy
			if (_capacity == 0)
				_alloc.deallocate(_base, 1);
			else
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_base[i]);
				_alloc.deallocate(_base, _capacity);
			}
			_base = p;
			_capacity = n;
		}
	}

	// Element access
	reference operator[](size_type n)
	{
		return _base[n];
	}
	const_reference operator[](size_type n) const
	{
		return _base[n];
	}

	reference at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("vector");
		return _base[n];
	}
	const_reference at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("vector");
		return _base[n];
	}

	reference front() { return *_base; };
	const_reference front() const { return *_base; };

	reference back() { return _base[_size - 1]; };
	const_reference back() const { return _base[_size - 1]; };

	// range (1)
	template <class InputIterator>
	void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
		size_type len = ft::distance(first, last);
		if (len > _capacity)
		{
			_alloc.deallocate(_base, _capacity);
			_base = _alloc.allocate(len);
			_capacity = len;
		}
		_size = len;
		for (size_type i = 0; first != last; first++, i++)
		{
			_alloc.construct(&_base[i], *first);
		}
	}

	// fill (2)
	void assign(size_type n, const value_type &val)
	{
		if (n > _capacity)
		{
			_alloc.deallocate(_base, _capacity);
			_base = _alloc.allocate(n);
			_capacity = n;
		}
		_size = n;
		for (size_type i = 0; i < n; i++)
			_alloc.construct(&_base[i], val);
	}

	void push_back(const value_type &val)
	{
		if (_capacity <= _size)
		{
			if (_capacity == 0)
				reserve(1);
			else
				reserve(_capacity * 2);
		}
		_alloc.construct(&_base[_size], val);
		_size++;
	}

	void pop_back()
	{
		_size--;
	}

	// single element (1)
	iterator insert(iterator position, const value_type &val)
	{
		size_type pos = ft::distance(begin(), position);

		if (_size == _capacity)
			reserve(_size * 2);

		for (size_type i = _size; i != pos; i--)
			_base[i] = _base[i - 1];
		_base[pos] = val;
		_size++;
		return iterator(_base + pos);
	}

			// fill (2)
	void insert(iterator position, size_type n, const value_type &val)
	{
		size_type pos = ft::distance(begin(), position);

		if ((_size + n) >= _capacity)
			reserve((_size + n));

		for (size_type i = _size + n - 1; i != pos + n - 1; i--)
			_base[i] = _base[i - n];

		for (size_type i = pos; i != pos + n; i++)
			_base[i] = val;
		_size += n;
	}

			// range (3)
	template <class InputIterator>
	void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
	{
		size_type pos = ft::distance(begin(), position);
		size_type n = ft::distance(first, last);

		if ((_size + n) > _capacity)
				reserve((_size + n));

		for (size_type i = _size + n - 1; i != pos + n - 1; i--)
			_base[i] = _base[i - n];

		for (; first != last; first++, pos++)
			_base[pos] = *first;
		_size += n;
	}

	iterator erase(iterator position)
	{
		size_type pos = ft::distance(begin(), position);

		for (size_type i = pos; i != _size - 1; i++)
			_base[i] = _base[i + 1];
		_size--;
		return iterator(_base + pos);
	}

	iterator erase(iterator first, iterator last)
	{
		size_type pos = ft::distance(begin(), first);
		size_type dist = ft::distance(first, last);

		for (size_type i = pos; i != _size - dist; i++)
			_base[i] = _base[i + dist];

		_size -= dist;
		return iterator(_base + pos);
	}

	void swap(vector &x)
	{
		ft::swap(_base, x._base);
		ft::swap(_capacity, x._capacity);
		ft::swap(_size, x._size);
		ft::swap(_alloc, x._alloc);
	}

	void clear() { _size = 0; }

	allocator_type get_allocator() const { return _alloc; }
};

	template <typename T>
	class vectorIterator
{
public:
	typedef ptrdiff_t difference_type;
	typedef T value_type;
	typedef random_access_iterator_tag iterator_category;
	typedef value_type* pointer;
	typedef value_type& reference;

private:
	T *_p;

public:
	vectorIterator() : _p(NULL){};
	vectorIterator(const vectorIterator &copy) : _p(copy._p){};
	vectorIterator(T *ptr) : _p(ptr){};

	vectorIterator &operator=(const vectorIterator &other)
	{
		_p = other._p;
		return (*this);
	}

	T *base() const
	{
		return _p;
	};

	operator vectorIterator<const T>(void) const
	{
		return vectorIterator<const T>(this->_p);
	}

	~vectorIterator() {};

	T &operator*(void)
	{
		return *_p;
	}

	T *operator->(void)
	{
		return _p;
	}

	vectorIterator &operator++()
	{
		_p++;
		return *this;
	}
	vectorIterator &operator--()
	{
		_p--;
		return *this;
	}

	vectorIterator operator++(int)
	{
		vectorIterator it = *this;
		++(*this);
		return it;
	}

	vectorIterator operator--(int)
	{
		vectorIterator it = *this;
		--(*this);
		return it;
	}

	vectorIterator operator+(difference_type i) const
	{
		return vectorIterator(_p + i);
	}

	vectorIterator operator-(int i) const
	{
		vectorIterator<T> it(_p - i);
		return it;
	}

	ptrdiff_t operator-(vectorIterator it) const
	{
		return _p - it.base();
	}

	vectorIterator &operator+=(int i)
	{
		_p += i;
		return (*this);
	}

	vectorIterator &operator-=(int i)
	{
		_p -= i;
		return (*this);
	}

	T &operator[](size_t b)
	{
		return (*(_p + b));
	}

	bool operator==(const vectorIterator<T> &rhs) const
	{
		return (this->base() == rhs.base());
	}

	bool operator<(const vectorIterator<T> &rhs) const
	{
		return (this->base() < rhs.base());
	}

	bool operator>(const vectorIterator<T> &rhs) const
	{
		return (this->base() > rhs.base());
	}

	bool operator<=(const vectorIterator<T> &rhs) const
	{
		return (this->base() <= rhs.base());
	}

	bool operator>=(const vectorIterator<T> &rhs) const
	{
		return (this->base() >= rhs.base());
	}

	bool operator!=(const vectorIterator<T> &rhs) const
	{
		return (!((*this) == rhs));
	}
};

	template <typename T>
	vectorIterator<T> operator+(typename vectorIterator<T>::difference_type n,
			const vectorIterator<T> &rhs)
	{
		return vectorIterator<T>(rhs.base() + n);
	}

	template <typename T>
	vectorIterator<T> operator-(typename vectorIterator<T>::difference_type n,
		const vectorIterator<T> &rhs)
	{
		return vectorIterator<T>(rhs.base() - n);
	}

	// (1)
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return(false);
	}

	// (2)
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	// (3)
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
										rhs.end());
	}

	// (4)
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);
	}

	// (5)
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	// (6)
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}

}

#endif
