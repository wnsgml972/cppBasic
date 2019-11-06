#include "Vector.h"
#include <iostream>


//vector array size 크기 기준 
#define DATA_ARRAY_SIZE 10

#define NOT_FOUND_INDEX -1

namespace vectorListSpace {
	

	
	Vector::Vector()
	{
		
		m_data = (int *)malloc(sizeof(int) * DATA_ARRAY_SIZE) ;
		
		m_cnt = 0;

	}
	
	Vector::~Vector()
	{
		std::cout << "해제?";

		free(m_data);
	}



	bool Vector::AddData(int data) {

		if (getDataIndex(data) != NOT_FOUND_INDEX) {
			return false;
		}


		//데이터가 꽉 찾을 경우에 배열 크기 조정
		if (m_cnt % DATA_ARRAY_SIZE == 0) {

			int changeSize = m_cnt+DATA_ARRAY_SIZE;
			
			m_data = (int *)realloc(m_data,sizeof(int) * changeSize);



		}

		m_data[m_cnt] = data;
		m_cnt++;


		return true;
	}

	bool Vector::DeleteData(int data) {


		int index = getDataIndex(data);

		if (index == NOT_FOUND_INDEX) {
			return false;
		}
		
		leftShiftData(index);
		
		m_cnt--;


		

		//데이터칸수가 줄어들게 되면 사이즈 조정
		if (m_cnt % DATA_ARRAY_SIZE == 0) {

			int changeSize = m_cnt;
			
			
			m_data = (int *)realloc(m_data, sizeof(int) * changeSize);
		
		}




		return true;
	}

	int Vector::GetSize() {

		return m_cnt;
	}


	const void Vector::PrintData() {


		std::cout << "VectorData : ";

		for (int i = 0; i < m_cnt; i++) {
			std::cout << m_data[i] << "  ";
		}

		std::cout << "\n";

	}


	int Vector::getDataIndex(int data) {

		for (int i = 0; i < m_cnt; i++){
			if (m_data[i] == data) {
				return i;
			}
		}

		return NOT_FOUND_INDEX;

	}

	bool Vector::leftShiftData(int index)
	{
		if (index < 0 || index >= m_cnt) {
			return false;
		}

		for (int i = index; i < m_cnt - 1; i++){
			m_data[i] = m_data[i + 1];
		}

		m_data[m_cnt - 1] = NULL;

		return true;
	}


}