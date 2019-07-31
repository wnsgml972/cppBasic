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

		bool AddData(int data);
		bool DeleteData(int data);
	
		void PrintData();

		int GetSize();
		void SetVectorId(int autoId);	
		const int GetVectorId() const;

	private:
		std::optional<int> IsDuplicateDataInVectorReturnIdx(int data);
		void ShiftLeftSortingAfterDeleteDataInVector(int index);

		int m_vectorId;
		int m_vectorSize;
		int *m_pData;
	};
	
}