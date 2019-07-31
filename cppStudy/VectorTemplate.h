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

		//데이터 추가		
		bool AddData(Type data);

		//데이터 삭제		
		bool DeleteData(Type data);

		//현재 벡터의 데이터 출력
		//cf) alt+shift를 이용하면 세로로 편집가능 :)		
		void PrintData();
		//현재 데이터 개수 반환		
		int GetSize() { return m_vectorSize; }

		void SetVectorId(int autoId) { m_vectorId = autoId; }
		const int GetVectorId() const{ return m_vectorId; }

	private:
		//중복체크
		//decltype(auto) 정확한 데이터타입을 알아낼 수 있음		
		std::optional<int> IsDuplicateDataInVectorReturnIdx(Type data);
		//삭제 후 데이터 재정렬
		void ShiftLeftDataInVector(int index);

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

		//벡터 생성
		void CreateVector(std::shared_ptr<Vector<Type>> newVector);
		//생성된 백터에 데이터 추가
		bool Append(int varId, Type data);
		//모든 자료구조 정보 출력
		void PrintInformation();
		//벡터 내에 있는 데이터 삭제
		bool DeleteDataInVector(int varId, Type data);
		//벡터 삭제
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
	void Vector<Type>::ShiftLeftDataInVector(int index) 
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
			ShiftLeftDataInVector(*index);

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

