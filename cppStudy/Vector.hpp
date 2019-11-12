#include "Base.h"




namespace VectorList {

	constexpr int DATA_SIZE = 10;
	constexpr int NOT_FOUND_INDEX = -1;



	template <typename T>
	class Vector : public Base<T> {



	public:


		Vector();
		~Vector();


		bool AddData(const T& data);
		bool DeleteData(const T& data);
		int GetSize() const;

		void PrintData() const;



	private:
		
		int GetDataIndex(const T& data) const;
		bool ShiftLeftData(const int& index);
		
		int m_cnt;
		T *m_pData;



	};


	template <typename T>
	Vector<T>::Vector()
	{

		m_pData = new T[DATA_SIZE];

		m_cnt = 0;

	}
	template <typename T>
	Vector<T>::~Vector()
	{
		std::cout << "해제?";

		free(m_pData);
	}


	template <typename T>
	bool Vector<T>::AddData(const T& data) {

		if (GetDataIndex(data) != NOT_FOUND_INDEX) {
			return false;
		}


		//데이터가 꽉 찾을 경우에 배열 크기 조정
		if (m_cnt % DATA_SIZE == 0) {

			int changeSize = m_cnt + DATA_SIZE;

			m_pData = (T *)realloc(m_pData, sizeof(T) * changeSize);



		}

		m_pData[m_cnt] = data;
		m_cnt++;


		return true;
	}
	template <typename T>
	bool Vector<T>::DeleteData(const T& data) {


		int index = GetDataIndex(data);

		if (index == NOT_FOUND_INDEX) {
			return false;
		}

		ShiftLeftData(index);

		m_cnt--;




		//데이터칸수가 줄어들게 되면 사이즈 조정
		if (m_cnt % DATA_SIZE == 0) {

			int changeSize = m_cnt;


			m_pData = (T *)realloc(m_pData, sizeof(T) * changeSize);

		}




		return true;
	}
	template <typename T>
	int Vector<T>::GetSize() const{

		return m_cnt;
	}

	template <typename T>
	void Vector<T>::PrintData() const{

		std::cout << "출력";
		std::cout << "VectorData : ";

		for (int i = 0; i < m_cnt; i++) {
			std::cout << m_pData[i] << "  ";
		}

		std::cout << "\n";

	}

	template <typename T>
	int Vector<T>::GetDataIndex(const T& data) const{

		for (int i = 0; i < m_cnt; i++) {
			if (m_pData[i] == data) {
				return i;
			}
		}

		return NOT_FOUND_INDEX;

	}
	template <typename T>
	bool Vector<T>::ShiftLeftData(const int& index)
	{
		if (index < 0 || index >= m_cnt) {
			return false;
		}

		for (int i = index; i < m_cnt - 1; i++) {
			m_pData[i] = m_pData[i + 1];
		}

		m_pData[m_cnt - 1] = {};

		return true;
	}

}