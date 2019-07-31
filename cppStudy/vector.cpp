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

	bool Vector::DeleteData(int data)
	{
		if (const auto& index = IsDuplicateDataInVectorReturnIdx(data); index)
		{
			m_vectorSize--;
			ShiftLeftSortingAfterDeleteDataInVector(*index);

			return true;
		}

		return false;
	}

	void Vector::ShiftLeftSortingAfterDeleteDataInVector(int index)
	{
		for (int i = index; i < m_vectorSize; i++)
		{
			m_pData[i] = m_pData[i + 1];
		}
	}
	
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
