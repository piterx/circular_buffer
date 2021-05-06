/*
 * unittests.cpp
 *
 *  Created on: 8 Apr 2021
 *      Author: Piotr Golacki
 */

#include "unittests.h"
#include "circularbuffer.h"
#include <iostream>
#include <exception>
#include <string>
#include <vector>

unit_tests::unit_tests() {
	// TODO Auto-generated constructor stub

}

unit_tests::~unit_tests() {
	// TODO Auto-generated destructor stub
}

/*@brief Tests if overwriting the buffer results in the expected behaviour, i.e. the oldest element is overwritten
 *
 *
 */
test_result unit_tests::test_buffer_overwrite()
{

	test_result result=Passed;
		m_test_count++;

		constexpr size_t capacity=10;
		size_t expected_size=0;
		circular_buffer<int,capacity> buffer_under_test;
	    int input_values[capacity]={1,2,3,4,5,6,7,8,9,10};
	    int value=11;//value which will be pushed back when the buffer is full
		if(buffer_under_test.size()!=expected_size)
			{
			std::cout<<"non-zero size"<<std::endl;
			return result=Failed; //expect size of zero}
			}

		for(size_t i=0;i<capacity;i++)
		{
			buffer_under_test.push_back(input_values[i]);
			expected_size++;
		}
		if(buffer_under_test.size()!=expected_size)
		{
			std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
			return result=Failed; //check for size

		}

		for(size_t i=0;i<capacity;i++)
			{
				if(buffer_under_test[i]!=input_values[i])
				{
					std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
					return result=Failed; //check values
				}
			}

		buffer_under_test.push_back(value);
		if(buffer_under_test[0]!=value)
		{
			std::cout<<"values at index 0 does not correspond to the new pushed back value: "<<value<<std::endl;
							return result=Failed; //check values

		}

		value=-12;
		buffer_under_test.push_back(value);
			if(buffer_under_test[1]!=value)
			{
				std::cout<<"values at index 1 does not correspond to the new pushed back value: "<<value<<std::endl;
								return result=Failed; //check values

			}

		print_test_result(result,__func__);
		return result;
}


test_result unit_tests::test_capacity()
{
	test_result result = Passed;
	m_test_count++;
	constexpr size_t capacity = 10;

	circular_buffer<int, capacity> buffer_under_test;
	size_t expected_maximum_capacity = capacity;
	size_t expected_capacity = capacity;

	if (buffer_under_test.capacity() != expected_capacity)
	{
		std::cout << "capacity() failed" << std::endl;
		return result = Failed;
	}

	if (buffer_under_test.max_capacity() != expected_maximum_capacity)
	{
		std::cout << "max_capacity() failed" << std::endl;
		return result = Failed;
	}

	expected_capacity = 4;
	buffer_under_test.set_capacity(expected_capacity);

	if (buffer_under_test.capacity() != expected_capacity)
	{
		std::cout << "capacity() failed after set_capacity()" << std::endl;
		return result = Failed;
	}

	if (buffer_under_test.max_capacity() != expected_maximum_capacity)
	{
		std::cout << "max_capacity() failed after set_capacity()" << std::endl;
		return result = Failed;
	}

	buffer_under_test.set_capacity(expected_maximum_capacity + 1);
	if (buffer_under_test.capacity() != expected_capacity)
	{
		std::cout << "capacity() failed after set_capacity(expected_maximum_capacity + 1)" << std::endl;
		return result = Failed;
	}




	print_test_result(result, __func__);
	return result;
}

/*@brief Tests the size() function of the circular buffer*/
test_result unit_tests::test_circular_buffer_size()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<int,capacity> buffer_under_test;
    int input_values[capacity]={1,2,3,4,5,6,7,8,9,10};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
		if(buffer_under_test.size()!=expected_size)
		{
			std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
			return result=Failed; //check for size

		}
	}


	print_test_result(result,__func__);
	return result;
}


/*@brief  tests push_back() function and accessing via [] operator for a single int element*/
test_result unit_tests::test_push_back_and_access_single_int_element()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<int,capacity> buffer_under_test;
	int value=1;

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
	}

	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong value, buffer_under_test[0] is: "<<buffer_under_test[0]<<" but should be: "<<value<<std::endl;
		return result=Failed; //expect size of one
		}


	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and writing via [] operator for a single int element*/
test_result unit_tests::test_push_back_and_write_single_int_element()
{
	test_result result=Passed;
	m_test_count++;
	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<int,capacity> buffer_under_test;
	int value=1;

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}


	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
	}

	value=-10;
	buffer_under_test[0]=value;

	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong value, buffer_under_test[0] is: "<<buffer_under_test[0]<<" but should be: "<<value<<std::endl;
		return result=Failed; //expect size of one
		}


	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for multiple int elements*/
test_result unit_tests::test_push_back_and_access_multiple_int_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<int,capacity> buffer_under_test;
    int input_values[capacity]={1,2,3,4,5,6,7,8,9,10};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}



	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and writing via [] operator for multiple int elements*/
test_result unit_tests::test_push_back_and_write_multiple_int_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<int,capacity> buffer_under_test;
    int input_values[capacity]={1,2,3,4,5,6,7,8,9,10};
    int new_input_values[capacity]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}


	//insert new values via []operator

	for(size_t i=0;i<capacity;i++)
				{
					buffer_under_test[i]=new_input_values[i];
				}

	for(size_t i=0;i<capacity;i++)
			{
				if(buffer_under_test[i]!=new_input_values[i])
				{
					std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
					return result=Failed; //check values
				}
			}


	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for a single double element*/
test_result unit_tests::test_push_back_and_access_single_double_element()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<double,capacity> buffer_under_test;
	double value=10.5;

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}


	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size) return result=Failed; //expect size of one
	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
		}

	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for multiple double elements*/
test_result unit_tests::test_push_back_and_access_multiple_double_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<double,capacity> buffer_under_test;
    double input_values[capacity]={1.1,2.3,3.5,4.0,5.1,6.2,7.6,8.1,9.1};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}


	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for a single string element*/
test_result unit_tests::test_push_back_and_access_single_string_element()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::string,capacity> buffer_under_test;
	std::string value="Example string";

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}


	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
	}

	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong value, buffer_under_test[0] is: "<<buffer_under_test[0]<<" but should be: "<<value<<std::endl;
		return result=Failed; //expect size of one
		}

	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and writing via [] operator for a single string element*/
test_result unit_tests::test_push_back_and_write_single_string_element()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::string,capacity> buffer_under_test;
	std::string value="Old string";

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}


	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
	}

	value="New string";
	buffer_under_test[0]=value;

	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong value, buffer_under_test[0] is: "<<buffer_under_test[0]<<" but should be: "<<value<<std::endl;
		return result=Failed; //expect size of one
		}

	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for multiple string elements*/
test_result unit_tests::test_push_back_and_access_multiple_string_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::string,capacity> buffer_under_test;
	std::string input_values[capacity]={
			"one",
			"two",
			"three",
			"four",
			"five",
			"six",
			"seven",
			"eight",
			"nine",
			"ten"
	};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}


	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and writing via [] operator for multiple string elements*/
test_result unit_tests::test_push_back_and_write_multiple_string_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::string,capacity> buffer_under_test;
	std::string input_values[capacity]={
			"one",
			"two",
			"three",
			"four",
			"five",
			"six",
			"seven",
			"eight",
			"nine",
			"ten"
	};

	std::string new_input_values[capacity]={
			"111aaa",
			"222bbb",
			"333ccc",
			"444ddd",
			"555eee",
			"666fff",
			"777ggg",
			"888hhh",
			"999iii",
			"101010jjj"
	};
	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}


	//insert new values via []operator

	for(size_t i=0;i<capacity;i++)
				{
					buffer_under_test[i]=new_input_values[i];
				}

	for(size_t i=0;i<capacity;i++)
			{
				if(buffer_under_test[i]!=new_input_values[i])
				{
					std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
					return result=Failed; //check values
				}
			}

	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for a single std::vector<int> element*/
test_result unit_tests::test_push_back_and_access_single_vectorint_element()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::vector<int>,capacity> buffer_under_test;
	std::vector<int> value={0,1,2,3,5,6,7,8,9};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}


	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
	}

	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong value"<<std::endl;
		return result=Failed; //expect size of one
		}

	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and writing via [] operator for a single std::vector<int> element*/
test_result unit_tests::test_push_back_and_write_single_vectorint_element()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::vector<int>,capacity> buffer_under_test;
	std::vector<int> value={0,1,2,3,5,6,7,8,9};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}


	buffer_under_test.push_back(value);
	expected_size++;
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size, expect size of 1"<<std::endl;
		return result=Failed; //expect size of one
	}

	value={-1,-12,-45};
	buffer_under_test[0]=value;

	if(buffer_under_test[0]!=value)
		{
		std::cout<<"wrong value"<<std::endl;
		return result=Failed; //expect size of one
		}

	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and accessing via [] operator for multiple std::vector<int> elements*/
test_result unit_tests::test_push_back_and_access_multiple_vectorint_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::vector<int>,capacity> buffer_under_test;
	std::vector<int> input_values[capacity]={
			{0,1,2,3,5,6,7,8,9},
			{-1,-2},
			{99,2,9},
			{-6,8,9,1},
			{0,0,0,1,1,1,1},
			{0},
			{12,9,9,9,9,9,9,9,9,9},
			{4,6},
			{1,9,5},
			{-1,2,0,2}
	};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}


	print_test_result(result,__func__);
	return result;
}

/*@brief  tests push_back() function and writing via [] operator for for multiple std::vector<int> elements*/
test_result unit_tests::test_push_back_and_write_multiple_vectorint_elements()
{
	test_result result=Passed;
	m_test_count++;

	constexpr size_t capacity=10;
	size_t expected_size=0;
	circular_buffer<std::vector<int>,capacity> buffer_under_test;
	std::vector<int> input_values[capacity]={
			{0,1,2,3,5,6,7,8,9},
			{-1,-2},
			{99,2,9},
			{-6,8,9,1},
			{0,0,0,1,1,1,1},
			{0},
			{12,9,9,9,9,9,9,9,9,9},
			{4,6},
			{1,9,5},
			{-1,2,0,2}
	};

	std::vector<int> new_input_values[capacity]={
			{-1,-2,-3,-5,-6,-7,-8,-9,-10},
			{1},
			{-2,-9},
			{10,-6,8,9,1},
			{11,-2,0,0,0,1,1,1,1},
			{99,0},
			{12,9999},
			{-4,6,8},
			{1,9,5,1},
			{1,2,0,2}
	};

	if(buffer_under_test.size()!=expected_size)
		{
		std::cout<<"non-zero size"<<std::endl;
		return result=Failed; //expect size of zero}
		}

	for(size_t i=0;i<capacity;i++)
	{
		buffer_under_test.push_back(input_values[i]);
		expected_size++;
	}
	if(buffer_under_test.size()!=expected_size)
	{
		std::cout<<"wrong size"<<"expected_size is: "<<expected_size<<" and buffer_under_test.size() is:"<<buffer_under_test.size()<<std::endl;
		return result=Failed; //check for size

	}

	for(size_t i=0;i<capacity;i++)
		{
			if(buffer_under_test[i]!=input_values[i])
			{
				std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
				return result=Failed; //check values
			}
		}


	//insert new values via []operator

	for(size_t i=0;i<capacity;i++)
				{
					buffer_under_test[i]=new_input_values[i];
				}

	for(size_t i=0;i<capacity;i++)
			{
				if(buffer_under_test[i]!=new_input_values[i])
				{
					std::cout<<"values in the buffer don't correspond to the input values at index: "<<i<<std::endl;
					return result=Failed; //check values
				}
			}

	print_test_result(result,__func__);
	return result;
}

/*@brief prints out the test number, name and the result to the standard output*/
void unit_tests::print_test_result(test_result result,const char*  function_name)
{
	std::cout<<"Test #"<<m_test_count<<": "<<function_name<<std::endl<<"Result:"<<(result?"Passed":"Failed")<<std::endl<<std::endl;
}

test_result unit_tests::test_reset()
{
	test_result result = Passed;
	m_test_count++;
	constexpr size_t capacity = 10;

	circular_buffer<int, capacity> buffer_under_test;
	size_t expected_maximum_capacity = capacity;
	size_t expected_capacity = capacity;

	if (buffer_under_test.capacity() != expected_capacity)
	{
		std::cout << "capacity() failed" << std::endl;
		return result = Failed;
	}

	if (buffer_under_test.max_capacity() != expected_maximum_capacity)
	{
		std::cout << "max_capacity() failed" << std::endl;
		return result = Failed;
	}

	expected_capacity = expected_maximum_capacity;
	buffer_under_test.reset();

	if (buffer_under_test.capacity() != expected_capacity)
	{
		std::cout << "capacity() failed after reset()" << std::endl;
		return result = Failed;
	}

	if (buffer_under_test.size() != 0)
	{
		std::cout << "size() failed after reset()" << std::endl;
		return result = Failed;
	}

	if (buffer_under_test.max_capacity() != expected_maximum_capacity)
	{
		std::cout << "max_capacity() failed after reset()" << std::endl;
		return result = Failed;
	}


	print_test_result(result, __func__);
	return result;
}


/*counter of the tests run*/
int unit_tests::m_test_count=0;
