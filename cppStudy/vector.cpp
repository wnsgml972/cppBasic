#include "vector.h"


//decltype(auto) 정확한 데이터타입을 알아낼 수 있음


namespace VectorSpace
{
	Vector::Vector()
	{
		m_vectorId = 0;
		m_vectorSize = 0;

		m_pData = new int[30];
	}


	//데이터 추가
	bool Vector::AddData(int data)
	{
		if (const auto& index = IsDuplicateDataInVectorReturnIdx(data); !index) {
			m_pData[m_vectorSize] = data;
			m_vectorSize++;

			return true;
		}
		else
		{
			return false;
		}
	}

	//중복체크
	std::optional<int> Vector::IsDuplicateDataInVectorReturnIdx(int data)
	{
		for (int i = 0; i < m_vectorSize; i++)
		{
			if (m_pData[i] == data)
			{
				return i;
			}
		}

		return {};
	}

	//데이터 삭제
	bool Vector::DeleteData(int data)
	{
		if (const auto& index = IsDuplicateDataInVectorReturnIdx(data); index)
		{
			m_vectorSize--;
			ShiftLeft(*index);

			return true;
		}

		return false;
	}

	//삭제 후 데이터 재정렬
	void Vector::ShiftLeft(int index)
	{
		for (int i = index; i < m_vectorSize; i++)
		{
			m_pData[i] = m_pData[i + 1];
		}
	}


	//현재 벡터의 데이터 출력
	//cf) alt+shift를 이용하면 세로로 편집가능 :)
	void Vector::PrintData()
	{
		std::cout << "VectorData : ";


		for (int i = 0; i < m_vectorSize; i++)
		{
			std::cout << m_pData[i] << "  ";
		}

		std::cout << "\n";
		std::cout << "VectorSize : " << m_vectorSize << "\n";
	}

	//현재 데이터 개수 반환
	int Vector::GetSize()
	{
		return m_vectorSize;
	}

	void Vector::SetVectorId(int autoId)
	{
		m_vectorId = autoId;
	}

	const int Vector::GetVectorId() const
	{
		return m_vectorId;
	}

}
