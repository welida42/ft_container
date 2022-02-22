#include <iostream>
#include <ctime>
#include "funcs_headers.hpp"

class Timer
		{

	std::clock_t _start;

		public:
			Timer();
			Timer(const Timer &ref);
			Timer &operator=(const Timer &ref);
			~Timer();
			void start();
			std::clock_t stop();
		};
Timer::Timer()
{
	_start = 0;
}

Timer::~Timer()
{
}

void Timer::start()
{
	_start = std::clock();
}

std::clock_t Timer::stop()
{
	return std::clock() - _start;
}

Timer::Timer(const Timer &ref)
{
	_start = ref._start;
}

Timer &Timer::operator=(const Timer &ref)
{
	_start = ref._start;
	return (*this);
}

std::clock_t map_speed_my()
{
	Timer t;
	t.start();
	map_construct_my();
	pair_tests_my();
	begin_end_my();
	rbegin_end_my();
	max_size_my();
	sq_brackets_my();
	insert_my();
	erase_my();
	swap_my();
	clear_my();
	key_comp_my();
	value_comp_my();
	find_my();
	count_my();
	lower_upper_bound_my();
	equal_range_my();
	get_allocator_my();
	map_relation_op_my();
	return t.stop();
}

std::clock_t map_speed_std()
{
	Timer t;
	t.start();
	map_construct_std();
	pair_tests_std();
	begin_end_std();
	rbegin_end_std();
	max_size_std();
	sq_brackets_std();
	insert_std();
	erase_std();
	swap_std();
	clear_std();
	key_comp_std();
	value_comp_std();
	find_std();
	count_std();
	lower_upper_bound_std();
	equal_range_std();
	get_allocator_std();
	map_relation_op_std();
	return t.stop();
}

std::clock_t vector_speed_my()
{
	Timer t;
	t.start();
	vector_constuct_my();
	vector_asinnation_my();
	vector_begin_end_my();
	vector_reverse_begin_end_my();
	vector_size_my();
	vector_max_size_my();
	vector_resize_my();
	vector_reserve_my();
	vector_sq_brackets_my();
	vector_at_my();
	vector_front_my();
	vector_back_my();
	vector_assign_my();
	vector_push_pop_back_my();
	vector_insert_my();
	vector_erase_my();
	vector_swap_my();
	vector_clear_my();
	vector_get_allocator_my();
	vector_relation_op_my();
	return t.stop();
}

std::clock_t vector_speed_std()
{
	Timer t;
	t.start();
	vector_constuct_std();
	vector_asinnation_std();
	vector_begin_end_std();
	vector_reverse_begin_end_std();
	vector_size_std();
	vector_max_size_std();
	vector_resize_std();
	vector_reserve_std();
	vector_sq_brackets_std();
	vector_at_std();
	vector_front_std();
	vector_back_std();
	vector_assign_std();
	vector_push_pop_back_std();
	vector_insert_std();
	vector_erase_std();
	vector_swape_std();
	vector_clear_std();
	vector_get_allocator_std();
	vector_relation_op_std();
	return t.stop();
}

std::clock_t stack_speed_my()
{
	Timer t;
	t.start();
	stack_construct_my();
	stack_size_push_pop_top_my();
	return t.stop();
}

std::clock_t stack_speed_std()
{
	Timer t;
	t.start();
	stack_construct_std();
	stack_size_push_pop_top_std();
	return t.stop();
}

void test_speed_map()
{
	std::cout << "-- MAP Speed testing ---" << std::endl;
	std::clock_t std;
	std::clock_t my;

	my = map_speed_my();
	std = map_speed_std();

	std::cout << "Std: " << std << std::endl;
	std::cout << "My: " << my << std::endl;

	std::cout << "My map is " << (double)my / (double)std << " times slower.\n";
	std::cout << std::endl;
}

void test_speed_vector()
{
	std::cout << "-- VECTOR Speed testing ---" << std::endl;
	std::clock_t std;
	std::clock_t my;

	my = vector_speed_my();
	std = vector_speed_std();

	std::cout << "Std: " << std << std::endl;
	std::cout << "My: " << my << std::endl;

	std::cout << "My vector is " << (double)my / (double)std << " times slower.\n";
	std::cout << std::endl;
}

void test_speed_stack()
{
	std::cout << "-- STACK Speed testing ---" << std::endl;
	std::clock_t std;
	std::clock_t my;

	my = stack_speed_my();
	std = stack_speed_std();

	std::cout << "Std: " << std << std::endl;
	std::cout << "My: " << my << std::endl;

	std::cout << "My stack is " << (double)my / (double)std << " times slower.\n";
	std::cout << std::endl;
}
