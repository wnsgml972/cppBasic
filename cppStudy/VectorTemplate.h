#pragma once

#include <iostream>
#include <memory>
#include <optional>
#include <map>
#include <assert.h>

namespace VectorSpace {

	template <class Type>
	class Vector {
	public:
		Vector();
		virtual ~Vector() 
		{ 
			// Safe Delete
			if (m_pData)
				delete[]m_pData;
			std::cout << "Delete Vector" << std::endl;
		};

		bool AddData(Type data);
		bool DeleteData(Type data);

		void PrintData();
		int GetSize() { return m_vectorSize; }

		void SetVectorId(int autoId) { m_vectorId = autoId; }
		const int GetVectorId() const{ return m_vectorId; }

	private:
		std::optional<int> IsDuplicateDataInVectorReturnIdx(Type data);
		void ShiftLeftSortingAfterDeleteDataInVector(int index);

		int m_vectorId;
		int m_vectorSize;
		Type *m_pData;


	};
	template <class Type>
	class VectorManager
	{
	public:
		VectorManager();
		virtual ~VectorManager() { std::cout << "Delete VectorManager" << std::endl; };

		void CreateVector(std::shared_ptr<Vector<Type>> newVector);
		bool Append(int varId, Type data);
		
		void PrintInformation();
		
		bool DeleteDataInVector(int varId, Type data);
		bool DeleteVector(int varId);			

	private:
		std::map<int, std::shared_ptr<Vector<Type>>> m_id2Vector{};
		int autoIncreasementVectorId;
	
	};

	//Vector Class 함수 구현
	template <class Type>
	std::optional<int> Vector<Type>::IsDuplicateDataInVectorReturnIdx(Type data) {

		for (int i = 0; i < m_vectorSize; i++)
		{
			if (m_pData[i] == data)
			{
				return i;
			}
		}

		return {};

	}

	template <class Type>
	void Vector<Type>::ShiftLeftSortingAfterDeleteDataInVector(int index) 
	{
		for (int i = index; i < m_vectorSize; i++)
		{
			m_pData[i] = m_pData[i + 1];
		}
	}

	template <class Type>
	Vector<Type>::Vector() 
	{
		m_vectorId = 0;
		m_vectorSize = 0;

		m_pData = new Type[30];
	}

	template <class Type>
	bool Vector<Type>::AddData(Type data) 
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

	template <class Type>
	bool Vector<Type>::DeleteData(Type data) 
	{
		if (const auto& index = IsDuplicateDataInVectorReturnIdx(data); index)
		{
			m_vectorSize--;
			ShiftLeftSortingAfterDeleteDataInVector(*index);

			return true;
		}

		return false;
	}

	template <class Type>
	void Vector<Type>::PrintData() 
	{
		std::cout << "VectorData : ";


		for (int i = 0; i < m_vectorSize; i++)
		{
			std::cout << m_pData[i] << "  ";
		}

		std::cout << "\n";
		std::cout << "VectorSize : " << m_vectorSize << "\n";

	}
	   
	//VectorManager Class 함수 구현
	template <class Type>
	VectorManager<Type>::VectorManager() 
	{
		autoIncreasementVectorId = 0;
	}

	template <class Type>
	void VectorManager<Type>::CreateVector(std::shared_ptr<Vector<Type>> newVector) 
	{
		newVector->SetVectorId(++autoIncreasementVectorId);
		m_id2Vector.emplace(autoIncreasementVectorId, newVector);
	}

	template <class Type>
	bool VectorManager<Type>::Append(int varId, Type data)
	{
		if (varId <= 0)
			assert(0);

		if (m_id2Vector.find(varId) != m_id2Vector.end()) 
		{
			return m_id2Vector[varId]->AddData(data);
		}			
		else 
		{
			return false;
		}
	}

	template <class Type>
	void VectorManager<Type>::PrintInformation() 
	{
		for (const auto& element : m_id2Vector) 
		{
			std::cout << "Vector (autoIncreasementVectorId : " << element.second->GetVectorId() << ") " << "\n";
			element.second->PrintData();
		}
		
		std::cout << "---------------------------------------" << "\n";
	}

	template <class Type>
	bool VectorManager<Type>::DeleteDataInVector(int varId, Type data) 
	{
		return m_id2Vector[varId]->DeleteData(data);
	}

	template <class Type>
	bool VectorManager<Type>::DeleteVector(int varId) 
	{
		if (varId <= 0)
			return false;

		if (m_id2Vector.find(varId) == m_id2Vector.end())
		{
			return false;
		}
		else
		{
			m_id2Vector.erase(varId);
			return true;
		}
	}










	


}

