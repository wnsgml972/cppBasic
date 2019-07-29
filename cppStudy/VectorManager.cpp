
#include "VectorManager.h"
#include <assert.h>

namespace VectorSpace 
{	
	VectorManager::VectorManager() 
	{
		autoIncreasementId = 0;
 	}

	void VectorManager::CreateVector(std::shared_ptr<Vector> newVector) 
	{
		
		newVector->SetVectorId(++autoIncreasementId);
		m_id2Vector.emplace(autoIncreasementId, newVector);		
	}
	
	bool VectorManager::Append(int varId, int data) 
	{
		// 아이디는 0 초과
		if (varId <= 0)
			assert(0); // Debug를 쉽게 하기 위해

		if (m_id2Vector.find(varId) != m_id2Vector.end())
		{
			return m_id2Vector[varId]->AddData(data);
		}
		else 
		{
			return false;
		}
	}

	
	void VectorManager::PrintInformation() 
	{
		// for each auto
		for (int i = 0; i < autoIncreasementId; i++) 
		{
			for(auto element : m_id2Vector)
			{
				std::cout << "Vector (autoIncreasementId : " << element.second->GetVectorId() << ") " << "\n";
				element.second->PrintData();
			}

		}
		std::cout << "---------------------------------------" << "\n";
	}

	
	bool VectorManager::DeleteDataInVector(int varId, int data) 
	{
		if (!m_id2Vector[varId])
			return false;

		return m_id2Vector[varId]->DeleteData(data);
	}

	
	bool VectorManager::DeleteVector(int varId) 
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