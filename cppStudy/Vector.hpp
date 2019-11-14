#include "Base.hpp"
#include <iostream>
#include <algorithm>

namespace vector_list {

	constexpr int DATA_SIZE = 10;
	constexpr int NOT_FOUND_INDEX = -1;


	template <typename ElementType>
	class Vector : public Base<ElementType> {

	public:

		Vector();
		~Vector();

		bool AddData(const ElementType& data) override;
		bool DeleteData(const ElementType& data) override;
		int GetSize() const override;
		void PrintData() const override;

		void Copy(const Base<ElementType>& right);
		virtual Vector<ElementType>& operator=(Vector<ElementType>& right);

	private:

		int m_cnt;
		ElementType *m_pData;

		bool ShiftLeftDataAfterIndex(const int& index);
		int GetDataIndex(const ElementType& data) const;
		ElementType GetData(const int& index) const;
	};


	template <typename ElementType>
	Vector<ElementType>::Vector(){

		m_pData = new ElementType[DATA_SIZE];
		m_cnt = 0;
	}


	template <typename ElementType>
	Vector<ElementType>::~Vector(){

		free(m_pData);
	}


	template <typename ElementType>
	bool Vector<ElementType>::AddData(const ElementType& data) {
		
		if (GetDataIndex(data) != NOT_FOUND_INDEX) {
			return false;
		}

		//데이터가 꽉 찾을 경우에 배열 크기 조정
		if (m_cnt % DATA_SIZE == 0) {
			int changeSize = m_cnt + DATA_SIZE;
			m_pData = (ElementType *)realloc(m_pData, sizeof(ElementType) * changeSize);
		}

		m_pData[m_cnt] = data;
		m_cnt++;

		return true;
	}


	template <typename ElementType>
	bool Vector<ElementType>::DeleteData(const ElementType& data) {

		int index = GetDataIndex(data);

		if (index == NOT_FOUND_INDEX) {
			return false;
		}

		ShiftLeftDataAfterIndex(index);
		m_cnt--;

		//데이터칸수가 줄어들게 되면 사이즈 조정
		if (m_cnt % DATA_SIZE == 0) {
			int changeSize = m_cnt;
			m_pData = (ElementType *)realloc(m_pData, sizeof(ElementType) * changeSize);
		}

		return true;
	}


	template <typename ElementType>
	int Vector<ElementType>::GetSize() const{

		return m_cnt;
	}


	template <typename ElementType>
	void Vector<ElementType>::PrintData() const{

		std::wcout << L"VectorData : ";

		//람다사용해보기
		std::for_each(m_pData, &m_pData[m_cnt], [](int& number) {
			std::wcout << number << L"  ";
		});

		std::wcout << L"\n";
	}


	template <typename ElementType>
	int Vector<ElementType>::GetDataIndex(const ElementType& data) const {

		for (int i = 0; i < m_cnt; i++) {
			if (m_pData[i] == data) {
				return i;
			}
		}

		return NOT_FOUND_INDEX;
	}


	template <typename ElementType>
	bool Vector<ElementType>::ShiftLeftDataAfterIndex(const int& index) {

		if (index < 0 || index >= m_cnt) {
			return false;
		}

		for (int i = index; i < m_cnt - 1; i++) {
			m_pData[i] = m_pData[i + 1];
		}
		m_pData[m_cnt - 1] = {};

		return true;
	}


	template<typename ElementType>
	Vector<ElementType>& Vector<ElementType>::operator=(Vector & right){

		Copy(right);
		return *this;
	}


	template<typename ElementType>
	void Vector<ElementType>::Copy(const Base<ElementType>& right){

		//기존에 있는 데이터를 지운다
		free(m_pData);
		m_pData = new ElementType[DATA_SIZE];
		m_cnt = 0;

		const Vector<ElementType>& original = static_cast<const Vector<ElementType>&>(right); //다운캐스팅
		
		for (int i = 0; i < original.GetSize(); i++){
			AddData(original.GetData(i));
		}
	}


	template<typename ElementType>
	ElementType Vector<ElementType>::GetData(const int & index) const {

		return m_pData[index];
	}

}