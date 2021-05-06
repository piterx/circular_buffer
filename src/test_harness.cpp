//============================================================================
// Name        : test_harness.cpp
// Author      : Piotr Golacki
// Version     :
// Copyright   : Copyright April 2021
// Description : Test harness for circular buffer
//============================================================================

#include <iostream>
#include <cstdint>
#include <vector>
#include "circularbuffer.h"
#include "unittests.h"

//using namespace std;

/*@brief this is unit test harness for the circular buffer project
 *
 *
 *
 */




/*@brief function pointer to test functions*/
typedef test_result (*test_func_ptr_t)( void );

int main() {
	/*circular_buffer<int32_t, 10> buffer;*/

	/*success and failure counts*/
	int fail_count=0;
	int success_count=0;

	/* List of test functions*/
	std::vector<test_func_ptr_t> test_functions {
		unit_tests::test_buffer_overwrite,
		unit_tests::test_capacity,
		unit_tests::test_circular_buffer_size,
		unit_tests::test_push_back_and_access_single_int_element,
		unit_tests::test_push_back_and_write_single_int_element,
		unit_tests::test_push_back_and_access_multiple_int_elements,
		unit_tests::test_push_back_and_write_multiple_int_elements,
		unit_tests::test_push_back_and_access_single_double_element,
		unit_tests::test_push_back_and_access_multiple_double_elements,
		unit_tests::test_push_back_and_access_single_string_element,
		unit_tests::test_push_back_and_write_single_string_element,
		unit_tests::test_push_back_and_access_multiple_string_elements,
		unit_tests::test_push_back_and_write_multiple_string_elements,
		unit_tests::test_push_back_and_access_single_vectorint_element,
		unit_tests::test_push_back_and_write_single_vectorint_element,
		unit_tests::test_push_back_and_access_multiple_vectorint_elements,
		unit_tests::test_push_back_and_write_multiple_vectorint_elements,
		unit_tests::test_reset

	};

	/*Run test functions*/

	std::cout<<"Running test cases......."<<std::endl;
	for(size_t i=0;i<test_functions.size();i++)
	{
		if(test_functions[i]()==test_result::Passed)success_count++;
		else fail_count++;

	}

	/*Print summary*/
	std::cout<<"|*****SUMMARY*****|"<<std::endl;
	std::cout<<"Number of failed tests: "<< fail_count<<std::endl;
	std::cout<<"Number of passed tests: "<< success_count<<std::endl;
	std::cout<<"Total number of tests: "<< test_functions.size()<<std::endl;
	return 0;
}


