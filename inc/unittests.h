/*
 * unittests.h
 *
 *  Created on: 8 Apr 2021
 *      Author: Piotr Golacki
 */

#ifndef UNITTESTS_H_
#define UNITTESTS_H_

/*
 * @brief test result enum*/
enum test_result {Failed,Passed};

/*\class unit_tests
 * @brief this class contains all the unit test methods
 */

class unit_tests {
public:
	unit_tests();
	virtual ~unit_tests();
	static int m_test_count;

	/*tests if overwriting the buffer results in the expected behaviour, i.e. the oldest element is overwritten*/
	static test_result test_buffer_overwrite();
	
	/*tests capacity manipulation*/
	static test_result test_capacity();

	/* tests the size() function of the circular buffer*/
	static test_result test_circular_buffer_size();

	/* tests push_back() function and accessing via [] operator for a single int element */
	static test_result test_push_back_and_access_single_int_element();

	/* tests push_back() function and writing via [] operator for a single int element */
	static test_result test_push_back_and_write_single_int_element();

	/* tests push_back() function and accessing via [] operator for multiple int elements */
	static test_result test_push_back_and_access_multiple_int_elements();

	/* tests push_back() function and writing via [] operator for multiple int elements */
	static test_result test_push_back_and_write_multiple_int_elements();

	/* tests push_back() function and accessing via [] operator for a single element */
	static test_result test_push_back_and_access_single_double_element();

	/* tests push_back() function and accessing via [] operator for multiple elements */
	static test_result test_push_back_and_access_multiple_double_elements();

	/* tests push_back() function and accessing via [] operator for a single string element */
	static test_result test_push_back_and_access_single_string_element();

	/* tests push_back() function and writing via [] operator for a single string element */
	static test_result test_push_back_and_write_single_string_element();

	/* tests push_back() function and accessing via [] operator for multiple string elements */
	static test_result test_push_back_and_access_multiple_string_elements();

	/* tests push_back() function and writing via [] operator for multiple string elements */
	static test_result test_push_back_and_write_multiple_string_elements();

	/* tests push_back() function and accessing via [] operator for a single std::vector<int> element */
	static test_result test_push_back_and_access_single_vectorint_element();

	/* tests push_back() function and writing via [] operator for a single std::vector<int> element */
	static test_result test_push_back_and_write_single_vectorint_element();

	/* tests push_back() function and accessing via [] operator for multiple std::vector<int> elements */
	static test_result test_push_back_and_access_multiple_vectorint_elements();

	/* tests push_back() function and writing via [] operator for multiple std::vector<int> elements */
	static test_result test_push_back_and_write_multiple_vectorint_elements();
	
	/* tests reset() function  */
	static test_result test_reset();

private:
	static void print_test_result(test_result result,const char* function_name);

};

#endif /* UNITTESTS_H_ */
