#pragma once
#include <iostream>
#include <memory>
#include <optional>

namespace VectorSpace 
{
		
	class Vector 
	{
	public :
		Vector();
		virtual ~Vector() 
		{
			// Safe Delete
			if (m_pData)
				delete[]m_pData;
			std::cout << "Delete Vector" << std::endl;  
		};

		//데이터 추가
		bool AddData(int data);
		//데이터 삭제
		bool DeleteData(int data);
	
		//현재 벡터의 데이터 출력
		void PrintData();
		//현재 데이터 개수 반환
		int GetSize();

		void SetVectorId(int autoId);	
		const int GetVectorId() const;
	private:
		//중복체크
		std::optional<int> IsDuplicate(int data);
		//삭제 후 데이터 재정렬
		void ShiftLeft(int index);

		int m_vectorId;
		int m_vectorSize;
		int *m_pData;
	};
	
}