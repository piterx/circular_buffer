/*
 * circularbuffer.h
 *
 *  Created on: 8 Apr 2021
 *      Author: Piotr Golacki
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_
#include <cstdio>
#include <iostream>
#include <exception>

template <typename T,std::size_t Capacity>
class circular_buffer {

public:
	//default constructor
	circular_buffer()
	{
		//default values at the bottom of the class
	}

	~circular_buffer()=default;
	/*@brief return current capacity it is always*/
	std::size_t capacity()
	{
		return m_current_capacity;
	}

	/*@brief returns maximum capacity it is equal to the initial capacity defined in the templated parameter*/
	std::size_t max_capacity()
	{
		return m_max_capacity;
	}

	/*@brief adds new element to the buffer at next position, when buffer is full the oldest value is overwrittern
	 *
	 *@param val is value to be inserted into the circular buffer
	 * */
	void push_back(T val)
	{
		if(m_current_capacity==0) throw std::out_of_range("index out of range, initialise with non-zero capacity");

		m_buffer[m_current_index]=val;//insert value to the buffer
		m_current_index++;//move index for the next insertion position
		if(m_size< m_current_capacity) m_size++;//increase size until it reaches the capacity
		if(m_current_index== m_current_capacity) m_current_index=0;//reset index to zero so the oldest value will be overwritten

	}

	/*@brief resets buffer to initial state i.e. sizes capacities and other internal variables*/
	void reset()
	{
		m_size = 0;
		m_current_capacity = m_max_capacity;
		m_current_index = 0;
	}

	/*@brief sets new user defined capacity, it mus be less or to maximum capacity defined in the template parameter*/
	void set_capacity(size_t new_capacity)
	{
		if (new_capacity <= m_max_capacity)
			m_current_capacity = new_capacity;
		else
			std::cout << "maximum capacity is: " << m_max_capacity << " elements, please use number smaller or equal to maxiimum capacity for a new capacity value" << std::endl;
	}

	/*@brief get size of the circular buffer, which is always less or equal than its internal capacity
	 *@return current size of the buffer
	 * */
	std::size_t size()
	{
		return m_size;
	}



	//subscript operator overloading for writing operation
	T& operator[](std::size_t index)
	{
		if((index+1)>m_size||index<0) throw std::out_of_range(m_oor_msg);

		return m_buffer[index];
	}

	//subscript operator overloading for reading operation
	T operator[](std::size_t index)const
	{
		if((index+1)>m_size||index<0) throw std::out_of_range(m_oor_msg);

		return m_buffer[index];
	}

private:
	T m_buffer[Capacity];//initialise an array of type T with size of Capacity
	//T* m_buffer= new T [Capacity];//initialise an array of type T with size of Capacity, it really doesn't matter here as the template argument must be constant at compile time anyway
	std::size_t m_max_capacity{Capacity};//maximum capacity - unavailable to the user, equal to the template parameter Capacity, throughout the lifespan of the object
	std::size_t m_current_capacity{Capacity};//current capacity modifiable
	std::size_t m_size{0};//current buffer size
	std::size_t m_current_index{0};//current
	std::string m_oor_msg{ "index out of range, add new element using push_back() function" };
};

#endif /* CIRCULARBUFFER_H_ */
