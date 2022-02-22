#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef> // ptrdiff_t
#include <memory>

#include "utils.hpp"
#include "revIterator.hpp"


namespace ft
{
	template<class Pair>
	class node
	{
	public:
	//	ft::pair<Key, Value> value;
		Pair value;
		node *parent;
		node *left;
		node *right;

		node(const Pair& value = Pair(), node* parent = NULL, node* left =
				NULL, node* right = NULL) :
		value(value), parent(parent), left(left), right(right) {}
		node(const node& other)
		{
			*this = other;
		}
		node &operator=(const node& other)
		{
			if (this != &other)
			{
				value = other.value;
				parent = other.parent;
				left = other.left;
				right = other.right;
			}
			return (*this);
		}
		~node() {}

		node *next()
		{
			node *iter = this;
			if (iter->right)
			{
				iter = iter->right;
				while (iter->left)
					iter = iter->left;
			}
			else
			{
				while (iter->parent && iter->parent->right == iter)
					iter = iter->parent;
				iter = iter->parent;
			}
			return(iter);
		}

		node *prev()
		{
			node *iter = this;
			if (iter->left)
			{
				iter = iter->left;
				while (iter->right)
					iter = iter->right;
			}
			else
			{
				while (iter->parent && iter->parent->left == iter)
					iter = iter->parent;
				iter = iter->parent;
			}
			return(iter);
		}
	};

template <class IteratorValue, class category = bidirectional_iterator_tag>
class mapIterator
{
public:
	typedef ft::node<IteratorValue>	node;

	typedef bidirectional_iterator_tag iterator_category;
	typedef IteratorValue* pointer;
	typedef IteratorValue& reference;
	typedef IteratorValue value_type;
	typedef ptrdiff_t difference_type;

	node *_ptr;

	operator mapIterator<const IteratorValue>(void) const
	{
		return mapIterator<const IteratorValue>(_ptr);
	}

	mapIterator( node *ptr = NULL) : _ptr(ptr){};

	mapIterator(const mapIterator& other)
	{
		*this = other;
	}
	~mapIterator(){};

	mapIterator &operator=(const mapIterator &other)
	{
		_ptr = other._ptr;
		return *this;
	}

	reference operator*() const { return _ptr->value; }
	pointer operator->() const { return &_ptr->value; }

	bool operator==(const mapIterator &rhs) const { return _ptr == rhs._ptr; }
	bool operator!=(const mapIterator &rhs) const { return _ptr != rhs._ptr; }


	mapIterator &operator++()
	{
		_ptr = _ptr->next();
		return (*this);
	}

	mapIterator operator++(int)
	{
		mapIterator old(*this);
		++(*this);
		return (old);
	}

	mapIterator &operator--()
	{
		_ptr = _ptr->prev();
		return (*this);
	}

	mapIterator operator--(int)
	{
		mapIterator old(*this);
		--(*this);
		return (old);
	}
};

template<class Key, class T, class Compare = ft::less<Key>,
        class allocator_type = std::allocator<ft::pair<const Key, T> > >
class map
{
public:
	typedef Key	key_type;
	typedef T	mapped_type;
	typedef  ft::pair<const Key, mapped_type>	value_type;
	typedef Compare	key_compare;
	typedef value_type&	reference;
	typedef const value_type&	const_reference;
	typedef value_type*	pointer;
	typedef const value_type*	const_pointer;
	typedef ft::mapIterator<value_type> iterator;
	typedef ft::mapIterator<ft::pair<const Key, mapped_type> >	const_iterator;
	typedef ft::rev_iterator<iterator> reverse_iterator;
	typedef ft::rev_iterator<const_iterator> const_reverse_iterator;
	typedef ptrdiff_t	difference_type;
	typedef size_t	size_type;

	class value_compare : public ft::binary_function<value_type, value_type, bool>
	{
	protected:
		key_compare comp;
	public:
		value_compare(key_compare c) : comp(c) {}
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return(comp(x.first, y.first));
		}
	};

private:
	typedef		ft::node<value_type> node;

	std::allocator<node> _node_alloc;
	node 	*_head;
	node 	*_tail;
	node	*_root;
	size_type	_size;
	key_compare	_compare;
	allocator_type	_alloc;

	void node_pos_tonull(node *p)
	{
		p->parent = NULL;
		p->left = NULL;
		p->right = NULL;
	}

	void	connect_node(node *parent, node **ptr_connection, node *child)
	{
		if (child)
			child->parent = parent;
		if ((child == _head || child == _tail) && (parent == _head || parent == _tail))
			return ;
		if (ptr_connection)
			*ptr_connection = child;
	}

	iterator	insert_root(const value_type& val)
	{
		_root = _node_alloc.allocate(1);
		_alloc.construct(&_root->value, value_type(val));
		node_pos_tonull(_root);
		connect_node(_root, &_root->left, _head);
		connect_node(_root, &_root->right, _tail);
		_size++;
		return(iterator(_root));
	}

	void delete_root(node *pos)
	{
		node_pos_tonull(_head);
		node_pos_tonull(_tail);
		_head->parent = _tail;
		_tail->parent = _head;
		_node_alloc.deallocate(pos, 1);
	}

	void delete_node(node *pos)
	{
		node **child_ptr;
		if (pos->parent->right == pos)
			child_ptr = &pos->parent->right;
		else
			child_ptr = &pos->parent->left;
		*child_ptr = NULL;
		_node_alloc.deallocate(pos, 1);
	}

	void delete_child_1(node* pos)
	{
		node **child_ptr;
		if (pos->parent->right == pos)
			child_ptr = &pos->parent->right;
		else
			child_ptr = &pos->parent->left;
		node *child;
		if (pos->right)
			child =  pos->right;
		else
			child = pos->left;
		connect_node(pos->parent, child_ptr, child);
		if (pos == _root)
			_root = child;
		_node_alloc.deallocate(pos, 1);
	}

	void delete_child_2(node *pos)
	{
		node *rep = pos;
		rep = rep->right;
		while(rep->left)
			rep= rep->left;
		if (rep == _tail)
			return delete_root(pos);
		node **child_ptr;
		if (pos->parent)  //right or left
		{
			if (pos->parent->right == pos)
				child_ptr = &pos->parent->right;
			else
				child_ptr = &pos->parent->left;
		}
		else
			child_ptr = &_root;
		*child_ptr = rep;
		ft::swap(rep->parent, pos->parent);
		ft::swap(rep->right, pos->right);
		ft::swap(rep->left, pos->left);
		if (rep->right == rep)
			rep->right = pos;
		rep->right->parent = rep;
		rep->left->parent = rep;
		if (pos->left || pos->right)
			delete_child_1(pos);
		else
			delete_node(pos);
	}

	void create_tree()
	{
		_head = _node_alloc.allocate(1);
		_alloc.construct(&_head->value,value_type());
		_tail = _node_alloc.allocate(1);//(sizeof (node));
		_alloc.construct(&_tail->value, value_type());
		_head->parent = _tail;
		_head->right = NULL;
		_head->left = NULL;
		_tail->parent = _head;
		_tail->right = NULL;
		_tail->left = NULL;
	}

public:
	explicit map(const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) :
			_root(NULL), _size(0), _compare(comp), _alloc(alloc)
	{
		create_tree();
	}

	template<class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()) :
			_root(NULL), _size(0), _compare(comp), _alloc(alloc)
	{
		create_tree();
		insert(first, last);
	}

	map(const map& x) :
		_root(NULL), _size(0), _compare(x._compare), _alloc(x._alloc)
	{
		create_tree();
		*this = x;
	}

	map& operator=(const map& x)
	{
		if (this != &x)
		{
			clear();
			insert(x.begin(), x.end());
		}
		return (*this);
	}

	~map()
	{
		clear();
		_node_alloc.deallocate(_head, 1);
		_node_alloc.deallocate(_tail, 1);
	}

//		void printBT(const std::string& prefix, const node* nod, bool isLeft)
//		{
//			if( nod != nullptr )
//			{
//				std::cout << prefix;
//
//				std::cout << (isLeft ? "├──" : "└──" );
//
//			// print the value of the node
//			std::cout << nod->value.first << nod->value.second << std::endl;
//
//		// enter the next tree level - left and right branch
//			printBT( prefix + (isLeft ? "│   " : "    "), nod->left, true);
//			printBT( prefix + (isLeft ? "│   " : "    "), nod->right, false);
//			}
//		}
//
//		void print()
//		{
//			printBT("", _root, false);
//		}

	iterator begin() { return (iterator(_head->parent)); }

	const_iterator begin() const { return (const_iterator(_head->parent)); }

	iterator end() { return (iterator(_tail)); }

	const_iterator end() const { return (const_iterator(_tail)); }

	reverse_iterator rbegin() { return (reverse_iterator(_tail)); }

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(_tail));
	}

	reverse_iterator rend() { return (reverse_iterator(_head->parent)); }

	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(_head->parent));
	}

	bool empty() const
	{
		return (_size == 0);
	}

	size_type size() const { return _size; }

	size_type max_size() const { return (_alloc.max_size() / 2); }

	mapped_type& operator[] (const key_type& k)
	{
		iterator it = find(k);
		if (it == end() || it == iterator(_head))
			it = insert(value_type(k, T())).first;
		return(it->second);
	}

	ft::pair<iterator, bool> insert(const value_type& val)
	{
		if (empty())
			return(ft::pair<iterator, bool>(insert_root(val), true));
		node *iter = _root;
		node *tmp_parent = NULL;
		while (iter && iter != _head && iter != _tail)
		{
			tmp_parent = iter;
			if (_compare(val.first, iter->value.first))
				iter = iter->left;
			else if (_compare(iter->value.first, val.first))
				iter = iter->right;
			else
				return(ft::pair<iterator, bool>(iterator(iter), false));
		}
		node *res = _node_alloc.allocate(1);
		_alloc.construct(&res->value, value_type(val));
		res->parent = tmp_parent;
		res->right = NULL;
		res->left = NULL;

		if (iter == _head || _compare(val.first, tmp_parent->value.first))
		{
			connect_node(tmp_parent, &tmp_parent->left, res);
			connect_node(res, &res->left, iter);
		}
		else if (iter == _tail || _compare(tmp_parent->value.first, val.first))
		{
			connect_node(tmp_parent, &tmp_parent->right, res);
			connect_node(res, &res->right, iter);
		}
		_size++;
		return(ft::pair<iterator, bool>(iterator(res), true));
	}

	iterator insert(iterator position, const value_type& val)
	{
		(void)position;
		return(insert(val).first);
	}

	template<class InputIterator>
	void insert(InputIterator first, InputIterator last)
	{
		for (;first != last; first++)
			insert(*first);
	}

	void erase(iterator position)
	{
		if (!size())
			return;
		node *pos = position._ptr;
		if (pos->left != NULL && pos->right != NULL)
			delete_child_2(pos);
		else if (pos->left != NULL || pos->right != NULL)
			delete_child_1(pos);
		else
			delete_node(pos);
		_size--;
	}

	size_type erase (const key_type& k)
	{
		iterator pos = find(k);
		if (pos != end())
		{
			erase(pos);
			return (1);
		}
		return (0);
	}

	void erase (iterator first, iterator last)
	{
		bool is_root = false;
		while (first != last)
		{
			if (first == iterator(_root))
				is_root = true;
			erase(first++);
		}
		if (is_root && last != iterator(_root))
			erase(iterator(_root));
	}

	void swap(map& x)
	{
		ft::swap(_head, x._head);
		ft::swap(_tail, x._tail);
		ft::swap(_root, x._root);
		ft::swap(_size, x._size);
		ft::swap(_compare, x._compare);
		ft::swap(_alloc, x._alloc);
	}

	void clear()
	{
		erase(begin(), end());
	}

	key_compare key_comp() const { return(_compare); }

	value_compare value_comp() const { return (value_compare(_compare)); }

	iterator find (const key_type& k)
	{
		if (empty())
			return (end());
		node* iter = _root;
		while (iter && iter != _head && iter != _tail)
		{
			if (_compare(k, iter->value.first))
				iter = iter->left;
			else if (_compare(iter->value.first, k))
				iter = iter->right;
			else
				return (iterator(iter));
		}
		return(end());
	}

	const_iterator find (const key_type& k) const
	{
		if (empty())
			return (end());
		node* iter = _root;
		while (iter && iter != _head && iter != _tail)
		{
			if (_compare(k, iter->value.first))
				iter = iter->left;
			else if (_compare(iter->value.first, k))
				iter = iter->right;
			else
				return (const_iterator(iter));
		}
		return(end());
	}

	size_type count(const key_type &k) const
	{
		size_type ret = 1;
		if (find(k) == end())
			ret = 0;
		return ret;
	}

	iterator lower_bound (const key_type& k)
	{
		iterator it = find(k);
		if (it == end())
			for (it = begin(); it != end(); it++)
			{
				if  (!_compare(it->first, k))
					break;
			}
		return (it);
	}

	const_iterator lower_bound(const key_type& k) const
	{
		iterator it = find(k);
		if (it == end())
			for (it = begin(); it != end(); it++)
			{
				if  (!_compare(it->first, k))
					break;
			}
		return const_iterator(it);
	}

	iterator upper_bound(const key_type& k)
	{
		iterator it = lower_bound(k);
		if (it == end())
			return it;
		if (!_compare(k, it->first))
			it++;
		return it;
	}

	const_iterator upper_bound(const key_type& k) const
	{
		iterator it = lower_bound(k);
		if (it == end())
			return it;
		if (!_compare(k, it->first))
			it++;
		return const_iterator(it);
	}

	ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
	{
		return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
	}

	ft::pair<iterator, iterator> equal_range(const key_type& k)
	{
		return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
	}

	allocator_type get_allocator() const { return(_alloc); }

};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs,
			const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
			return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs,
			const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs,
			const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs,
			const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs,
		 	const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs,
			const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
