#include <iostream>
#include "utils.hpp"
#include <string>
#include <map>
#include "map.hpp"
#include <cstdlib>
#include "vector.hpp"
#include <vector>
#include <stack>
#include "stack.hpp"
#include "tests/funcs_headers.hpp"


void vector_constuct_my()
{
	std::cout << "-------------vector_constuctors----------------------\n";
	std::cout << "-------------empty, size, max_size----------------------\n";
	std::cout << "My container: \n";
	// constructors used in the same order as described above:
	ft::vector<int> first;    // empty vector of ints
	std::cout << "first size: " << first.size() << "\n";
	std::cout << "first empty: " << first.empty() << "\n";
	ft::vector<int> second (4,100);      // four ints with value 100
	std::cout << "second size: "<< second.size() << "\n";
	std::cout << "second empty: " << second.empty() << "\n";
	ft::vector<int> third (second.begin(),second.end());
	// iterating through second
	std::cout << "third max_size: " << third.max_size() << "\n";
	ft::vector<int> fourth (third);                       // a copy of third

	for (size_t  i = 0; i < fourth.size(); i++)
		std::cout << fourth[i] << "\n";

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void vector_constuct_std()
{
	std::cout << "-------------vector_constuctors----------------------\n";
	std::cout << "-------------empty, size, max_size----------------------\n";
	std::cout << "Std container: \n";
	// constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::cout<< "first size: "  << first.size() << "\n";
	std::cout << "first empty: " << first.empty() << "\n";
	std::vector<int> second (4,100);                       // four ints with value 100
	std::cout << "second size: "<< second.size() << "\n";
	std::cout << "second empty: " << second.empty() << "\n";
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::cout<< "third max_size: " << third.max_size() << "\n";
	std::vector<int> fourth (third);                       // a copy of third

	for (size_t i = 0; i < fourth.size(); i++)
		std::cout << fourth[i] << "\n";

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
void vector_asinnation_my()
{
	std::cout << "-------------vector_asignation----------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> foo (3,0);
	ft::vector<int> bar (5,0);

	bar = foo;
	std::cout << "bar size after = : ";
	for (size_t i = 0; i < bar.size(); i++)
		std::cout << bar[i] << " ";
	std::cout << "\n";
	std::cout << "foo = : std::vector<int>()\n";
	foo = ft::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void vector_asinnation_std()
{
	std::cout << "-------------vector_asignation----------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	std::cout << "bar size after = : ";
	for (size_t i = 0; i < bar.size(); i++)
		std::cout << bar[i] << " ";
	std::cout << "\n";
	std::cout << "foo = : std::vector<int>()\n";
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void vector_begin_end_my()
{
	std::cout << "-------------vector_begin_end----------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end
	(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
void vector_begin_end_std()
{
	std::cout << "-------------vector_begin_end----------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void vector_reverse_begin_end_my()
{
	std::cout << "-------------vector_reverse_begin_end----------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end()
	; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
void vector_reverse_begin_end_std()
{
	std::cout << "-------------vector_reverse_begin_end----------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void vector_size_my()
{
	std::cout << "-------------vector_size---------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}
void vector_size_std()
{
	std::cout << "-------------vector_size---------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void vector_max_size_my()
{
	std::cout << "-------------vector_max_size---capacity-------------------\n";
	std::cout << "My container: \n";
	std::cout << "When empty: \n";
	ft::vector<int> myvector;
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);
	std::cout << "After 100 pushbacks: \n";
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}
void vector_max_size_std()
{
	std::cout << "-------------vector_max_size--capacity-------------------\n";
	std::cout << "Std container: \n";
	std::cout << "When empty: \n";
	std::vector<int> myvector;
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);
	std::cout << "After 100 pushbacks: \n";
	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void vector_resize_my()
{
	std::cout << "-------------vector_resize-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}
void vector_resize_std()
{
	std::cout << "-------------vector_resize-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_reserve_my()
{
	std::cout << "-------------vector_reserve-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}
void vector_reserve_std()
{
	std::cout << "-------------vector_reserve-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void  vector_sq_brackets_my()
{
	std::cout << "-------------vector_[]-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector (10);   // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void  vector_sq_brackets_std()
{
	std::cout << "-------------vector_[]-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}
void vector_at_my()
{
	std::cout << "-------------vector_at-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	try
	{
		myvector.at(20)=20;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

void vector_at_std()
{
	std::cout << "-------------vector_at-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	try
	{
		myvector.at(20)=20;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

void vector_front_my()
{
	std::cout << "-------------vector_front-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}
void vector_front_std()
{
	std::cout << "-------------vector_front-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void vector_back_my()
{
	std::cout << "-------------vector_back-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}
void vector_back_std()
{
	std::cout << "-------------vector_back-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}
void vector_assign_my()
{
	std::cout << "-------------vector_assign-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}
void vector_assign_std()
{
	std::cout << "-------------vector_assign-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void vector_push_pop_back_my()
{
	std::cout << "-------------vector_push_pop_back-------------------\n";
	std::cout << "My container: \n";
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}
	std::cout << "size after pop backs: " << myvector.size() << '\n';
	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void vector_push_pop_back_std()
{
	std::cout << "-------------vector_push_pop_back-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}
	std::cout << "size after pop backs: " << myvector.size() << '\n';
	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void vector_insert_my()
{
	std::cout << "-------------vector_insert-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	myvector.insert (it,10000,42);
	myvector.clear();
	std::cout << '\n';
}

void vector_insert_std()
{
	std::cout << "-------------vector_insert-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	myvector.insert (it,10000,42);
	myvector.clear();
	std::cout << '\n';
}

void vector_erase_my()
{
	std::cout << "-------------vector_erase-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_erase_std()
{
	std::cout << "-------------vector_erase-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_swap_my()
{
	std::cout << "-------------vector_swap-------------------\n";
	std::cout << "Std container: \n";
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}
void vector_swape_std()
{
	std::cout << "-------------vector_swap-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void vector_clear_my()
{
	std::cout << "-------------vector_clear-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_clear_std()
{
	std::cout << "-------------vector_clear-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void vector_get_allocator_my()
{
	std::cout << "-------------vector_get_allocator-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}
void vector_get_allocator_std()
{
	std::cout << "-------------vector_get_allocator-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void vector_iterator_cmp_my()
{
	std::cout << "-------------vector_iterators-cmp---------------------\n";
	std::cout << "My container: \n";
	std::cout << "iter V iter\n";
	ft::vector<int> vec_1;
	for (int i = 0; i < 10;i++)
		vec_1.push_back(i);
	ft::vector<int>::iterator it_1 = vec_1.begin();
	ft::vector<int>::iterator it_2 = vec_1.end();

	std::cout << (it_1 == it_2) << (it_1 != it_2) << (it_1 > it_2) << (it_1 >= it_2)
	<< (it_1 < it_2) << (it_1 <= it_2) << "\n";

	std::cout << "const_iter V const_iter\n";
	ft::vector<int> vec_2;
	for (int i = 0; i < 10;i++)
		vec_1.push_back(i);
	ft::vector<const int>::const_iterator cit_1 = vec_2.begin();
	ft::vector<const int>::const_iterator cit_2 = vec_2.end();

	std::cout << (cit_1 == cit_2) << (cit_1 != cit_2) << (cit_1 > cit_2) <<
	(cit_1 >= cit_2) << (cit_1 < cit_2) << (cit_1 <= cit_2) << "\n";

	std::cout << "iter V const_iter\n";
	ft::vector<int> vec;
	for (int i = 0; i < 10;i++)
		vec.push_back(i);
	ft::vector<const int>::iterator it = vec.begin();
	ft::vector<const int>::const_iterator cit = vec.end();

	std::cout << (it == cit) << (it != cit) << (it > cit) << (it >= cit)
	<< (it < cit) << (it <= cit) << "\n";
}

void vector_iterator_cmp_std()
{
	std::cout << "-------------vector_iterators-cmp---------------------\n";
	std::cout << "Std container: \n";
	std::cout << "iter V iter\n";
	std::vector<int> vec_1;
	for (int i = 0; i < 10;i++)
		vec_1.push_back(i);
	std::vector<int>::iterator it_1 = vec_1.begin();
	std::vector<int>::iterator it_2 = vec_1.end();

	std::cout << (it_1 == it_2) << (it_1 != it_2) << (it_1 > it_2) << (it_1 >= it_2)
	<< (it_1 < it_2) << (it_1 <= it_2) << "\n";

	std::cout << "const_iter V const_iter\n";
	std::vector<int> vec_2;
	for (int i = 0; i < 10;i++)
		vec_1.push_back(i);
	std::vector<const int>::const_iterator cit_1 = vec_2.begin();
	std::vector<const int>::const_iterator cit_2 = vec_2.end();

	std::cout << (cit_1 == cit_2) << (cit_1 != cit_2) << (cit_1 > cit_2) <<
	(cit_1 >= cit_2) << (cit_1 < cit_2) << (cit_1 <= cit_2) << "\n";

	std::cout << "iter V const_iter\n";
	std::vector<int> vec;
	for (int i = 0; i < 10;i++)
		vec.push_back(i);
	std::vector<const int>::iterator it = vec.begin();
	std::vector<const int>::const_iterator cit = vec.end();

	std::cout << (it == cit) << (it != cit) << (it > cit) << (it >= cit)
	<< (it < cit) << (it <= cit) << "\n";
}

void vector_relation_op_my()
{
	std::cout << "-------------vector_relation_operators-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
void vector_relation_op_std()
{
	std::cout << "-------------vector_relation_operators-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}


void stack_construct_my()
{
	std::cout << "-------------stack_construct-------------------\n";
	std::cout << "My container: \n";
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack
	std::cout << "first.empty() : " << first.empty() << '\n';

	ft::stack<int,ft::vector<int> > second;  // empty stack using vector
	ft::stack<int,ft::vector<int> > third (myvector);
	std::cout << "third.empty() : " << third.empty() << '\n';

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
}
void stack_construct_std()
{
	std::cout << "-------------stack_construct-------------------\n";
	std::cout << "Std container: \n";
	std::vector<int> myvector (2,200);        // vector with 2 elements

	std::stack<int> first;                    // empty stack
	std::cout << "first.empty() : " << first.empty() << '\n';

	std::stack<int,std::vector<int> > second;  // empty stack using vector
	std::stack<int,std::vector<int> > third (myvector);
	std::cout << "third.empty() : " << third.empty() << '\n';

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';

}

void stack_size_push_pop_top_my()
{
	std::cout << "-------------stack_size_push_pop_top-------------------\n";
	std::cout << "My container: \n";
	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
	std::cout << "3. top after pop: " << myints.top() << '\n';

	ft::stack<int> myints2;
	for (int i=0; i<5; i++) myints.push(10);

	std::cout << "stacks relation operators: " << (myints > myints2)
	<< (myints >= myints2) << (myints < myints2) << (myints <= myints2)
	<< (myints == myints2) << (myints != myints2) << '\n';

	for (int i=0; i<1000; i++) myints.push(i);
	for (int i=0; i<1000; i++) myints.pop();



	std::cout << "--------------\n";
	ft::stack<int, std::deque<int> > stack_deq;
	stack_deq.push(42);
	std::cout << "ft::stack<int, std::deque<int> > " << stack_deq.top() << "\n";

	ft::stack<int, std::list<int> > stack_list;
	stack_list.push(21);
	std::cout << "ft::stack<int, std::list<int> > " << stack_list.top() << "\n";

}

void stack_size_push_pop_top_std()
{
	std::cout << "-------------stack_size_push_pop_top-------------------\n";
	std::cout << "Std container: \n";
	std::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
	std::cout << "3. top after pop: " << myints.top() << '\n';

	std::stack<int> myints2;
	for (int i=0; i<5; i++) myints.push(10);

	std::cout << "stacks relation operators: " << (myints > myints2)
	<< (myints >= myints2) << (myints < myints2) << (myints <= myints2)
	<< (myints == myints2) << (myints != myints2) << '\n';

	for (int i=0; i<1000; i++) myints.push(i);
	for (int i=0; i<1000; i++) myints.pop();


	std::cout << "--------------\n";
	std::stack<int, std::deque<int> > stack_deq;
	stack_deq.push(42);
	std::cout << "std::stack<int, std::deque<int> > " << stack_deq.top() <<
	"\n";

	std::stack<int, std::list<int> > stack_list;
	stack_list.push(21);
	std::cout << "std::stack<int, std::list<int> > " << stack_list.top() <<
	"\n";
}


//void print_tree()
//{
//std::cout << "---------------print_tree---------------------------\n";
//	ft::map<char, int> mv;
//	mv['G'] = 1;
//	mv['E'] = 2;
//	mv['D'] = 3;
//	mv['U'] = 4;
//	mv['F'] = 5;
//	mv['T'] = 6;
//	mv['S'] = 7;
//	std::cout << "\n\n";
//	mv.print();
//}
//


void map_construct_my()
{
	std::cout << "\nMy container: \n";
	std::cout << "---------------map_construct-empty---------------------\n";

	ft::map<char,int> first;

	std::cout << first.empty() << "\n";
	std::cout << first.size() << "\n";

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	std::cout << first.empty() << "\n";
	std::cout << first.size() << "\n";

	ft::map<char,int> ::iterator it = first.begin();
	for (;it != first.end();it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "---------------map_construct-range---------------------\n";
	ft::map<char,int> second (first.begin(),first.end());
	for (it = second.begin();it != second.end();it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "---------------map_construct-copy---------------------\n";
	ft::map<char,int> third (second);
	for (it = third.begin();it != third.end();it++)
		std::cout << it->first << " => " << it->second << '\n';
}

void map_construct_std()
{
	std::cout << "\nStd container: \n";
	std::cout << "---------------map_construct-empty---------------------\n";

	std::map<char,int> first_std;

	std::cout << first_std.empty() << "\n";
	std::cout << first_std.size() << "\n";

	first_std['a']=10;
	first_std['b']=30;
	first_std['c']=50;
	first_std['d']=70;
	std::cout << first_std.empty() << "\n";
	std::cout << first_std.size() << "\n";

	std::map<char,int> ::iterator it_std = first_std.begin();
	for (;it_std != first_std.end();it_std++)
		std::cout << it_std->first << " => " << it_std->second << '\n';
	std::cout << "---------------map_construct-range---------------------\n";
	std::map<char,int> second_std (first_std.begin(),first_std.end());
	for (it_std = second_std.begin();it_std != second_std.end();it_std++)
		std::cout << it_std->first << " => " << it_std->second << '\n';
	std::cout << "---------------map_construct-copy---------------------\n";
	std::map<char,int> third_std (second_std);
	for (it_std = third_std.begin();it_std != third_std.end();it_std++)
		std::cout << it_std->first << " => " << it_std->second << '\n';

}

void pair_tests_my()
{
	std::cout << "---------------pair_tests---------------------------\n";
	std::cout << "My container: \n";
	std::cout << "ft::make_pair" << '\n';
	ft::pair<int, float> sp0;
	sp0 = ft::make_pair(42, 10.0);
	std::cout << sp0.first << " => " << sp0.second << '\n';

	std::cout << "relation operators" << '\n';

	ft::pair<int, float> p1(42, 10.0);

	ft::pair<int, float> p2(p1);

	std::cout << (p1==p2) << (p1>p2) << (p1<p2) << (p1>=p2) << (p1<=p2) <<(p1!=p2);
	std::cout << std::endl;
}

void pair_tests_std()
{
	std::cout << "---------------pair_tests---------------------------\n";
	std::cout << "Std container: \n";
	std::cout << "std::make_pair" << '\n';
	std::pair<int, float> sp0;
	sp0 = std::make_pair(42, 10.0);
	std::cout << sp0.first << " => " << sp0.second << '\n';

	std::cout << "relation operators" << '\n';
	std::pair<int, float> sp1(42, 10.0);

	std::pair<int, float> sp2(sp1);

	std::cout << (sp1==sp2) << (sp1>sp2) << (sp1<sp2) << (sp1>=sp2) <<
	(sp1<=sp2) <<(sp1!=sp2);
	std::cout << std::endl;
}

void begin_end_my()
{
	std::cout << "---------------begin_end---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void begin_end_std()
{
	std::cout << "---------------begin_end---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}


void rbegin_end_my()
{
	std::cout << "-------------reverse-begin_end---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['z'] = 300;
	mymap['y'] = 200;


	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void rbegin_end_std()
{
	std::cout << "-------------reverse-begin_end---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['z'] = 300;
	mymap['y'] = 200;


	// show content:
	std::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void max_size_my()
{
	std::cout << "-------------max_size---------------------------\n";
	std::cout << "My container: \n";
	ft::map<std::string, double> mymap;
	std::cout << mymap.max_size() << '\n';
}

void max_size_std()
{
	std::cout << "-------------max_size---------------------------\n";
	std::cout << "Std container: \n";
	std::map<std::string, double> mymap;
	std::cout << mymap.max_size() << '\n';
}

void sq_brackets_my()
{
	std::cout << "-------------sq_brackets---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	mymap['a']="new value";
	std::cout << "mymap['a'] is " << mymap['a'] << '\n';

	for (ft::map<char,std::string>::iterator it=mymap.begin(); it!=mymap.end()
	; ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void sq_brackets_std()
{
	std::cout << "-------------sq_brackets---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

	mymap['a']="new value";
	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	for (std::map<char,std::string>::iterator it=mymap.begin(); it!=mymap.end()
	; ++it)
		std::cout << it->first << " => " << it->second << '\n';
}


void insert_my()
{
	std::cout << "-------------insert---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency
	// inserting

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	ft::map<int,int> mymap2;
	ft::map<int,int>::iterator it_int;
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
		mymap2.insert ( ft::pair<int,int> (i,100) ) ;
	for (int i = 0; i < 1000000; i++)
	{
		int n = rand() % 1000000;
		mymap2.insert ( ft::pair<int,int> (n,100) ) ;
	}

	mymap2.clear();
}

void insert_std()
{
	std::cout << "-------------insert---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	srand(time(NULL));
	std::map<int,int> mymap2;
	for (int i = 0; i < 100; i++)
		mymap2.insert ( std::pair<int,int> (i,100) ) ;
	for (int i = 0; i < 1000000; i++)
	{
		int n = rand() % 1000000;
		mymap2.insert ( std::pair<int,int> (n,100) ) ;
	}
	mymap2.clear();

}

void erase_my()
{
	std::cout << "-------------erase---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key
	it=mymap.find ('e');

	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void erase_std()
{
	std::cout << "-------------erase---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key
	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}


void swap_my()
{
	std::cout << "-------------swap---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void swap_std()
{
	std::cout << "-------------swap---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void clear_my()
{
	std::cout << "-------------clear---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void clear_std()
{
	std::cout << "-------------clear---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void key_comp_my()
{
	std::cout << "-------------key_comp---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
}

void key_comp_std()
{
	std::cout << "-------------key_comp---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
}

void value_comp_my()
{
	std::cout << "-------------value_comp---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

void value_comp_std()
{
	std::cout << "-------------value_comp---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element

	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

void find_my()
{
	std::cout << "-------------find---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void find_std()
{
	std::cout << "-------------find---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;
	std::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void count_my()
{
	std::cout << "-------------count---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}
}

void count_std()
{
	std::cout << "-------------count---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}
}

void lower_upper_bound_my()
{
	std::cout << "-------------lower_upper_bound---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void lower_upper_bound_std()
{
	std::cout << "-------------lower_upper_bound---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void equal_range_my()
{
	std::cout << "-------------equal_range---------------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void equal_range_std()
{
	std::cout << "-------------equal_range---------------------------\n";
	std::cout << "Std container: \n";
	std::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void get_allocator_my()
{
	std::cout << "-------------get_allocator---------------------------\n";
	std::cout << "My container: \n";
	int psize;
	ft::map<char,int> mymap;
	ft::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
}

void get_allocator_std()
{
	std::cout << "-------------get_allocator---------------------------\n";
	std::cout << "Std container: \n";
	int psize;
	std::map<char,int> mymap;
	std::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);
	// assign some values to array
	psize = sizeof(std::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
}

void map_relation_op_my()
{
	std::cout << "-------------map_relation_operations----------------------\n";
	std::cout << "My container: \n";
	ft::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void map_relation_op_std()
{
	std::cout << "-------------map_relation_operations----------------------\n";
	std::cout << "Std container: \n";
	ft::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

//void print_tree()
//{
//	std::cout << "---------------print_tree---------------------------\n";
//	ft::map<char, int> mv;
//	mv['G'] = 1;
//	mv['E'] = 2;
//	mv['D'] = 3;
//	mv['U'] = 4;
//	mv['F'] = 5;
//	mv['T'] = 6;
//	mv['S'] = 7;
//	std::cout << "\n\n";
//	mv.print();
//}

int main(void)
{
std::cout << "              VECTOR testing\n\n";
	vector_constuct_my();
	vector_constuct_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_asinnation_my();
	vector_asinnation_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_begin_end_my();
	vector_begin_end_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_reverse_begin_end_my();
	vector_reverse_begin_end_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_size_my();
	vector_size_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_max_size_my();
	vector_max_size_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_resize_my();
	vector_resize_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_reserve_my();
	vector_reserve_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_sq_brackets_my();
	vector_sq_brackets_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_at_my();
	vector_at_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_front_my();
	vector_front_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_back_my();
	vector_back_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_assign_my();
	vector_assign_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_push_pop_back_my();
	vector_push_pop_back_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_insert_my();
	vector_insert_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_erase_my();
	vector_erase_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_swap_my();
	vector_swape_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_clear_my();
	vector_clear_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_get_allocator_my();
	vector_get_allocator_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_iterator_cmp_my();
	vector_iterator_cmp_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	vector_relation_op_my();
	vector_relation_op_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";


	std::cout << "\n\n              STACK testing\n\n";

	stack_construct_my();
	stack_construct_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	stack_size_push_pop_top_my();
	stack_size_push_pop_top_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";


	std::cout << "\n\n              MAP testing\n\n";

	map_construct_my();
	map_construct_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	pair_tests_my();
	pair_tests_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	begin_end_my();
	begin_end_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	rbegin_end_my();
	rbegin_end_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	max_size_my();
	max_size_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	sq_brackets_std();
	sq_brackets_my();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	insert_my();
	insert_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	erase_my();
	erase_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	swap_my();
	swap_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	clear_my();
	clear_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	key_comp_my();
	key_comp_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	value_comp_my();
	value_comp_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	find_my();
	find_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	count_my();
	count_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	lower_upper_bound_my();
	lower_upper_bound_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	equal_range_my();
	equal_range_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	get_allocator_my();
	get_allocator_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	map_relation_op_my();
	map_relation_op_std();
	std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

//	print_tree();


//	test_speed_vector();
//	test_speed_stack();
//	test_speed_map();

return 0;
}
