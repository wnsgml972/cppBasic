#pragma once

#include "vector.h"
#include <vector>
#include <map>


namespace VectorSpace 
{	
	class VectorManager 
	{	
	public : 
		VectorManager();
		virtual ~VectorManager() = default;
		//create Vector
		
		void CreateVector(std::shared_ptr<Vector> newVector);

		//append Data
		bool Append(int varId, int data);

		//print All information
		void PrintInformation();

		//delete Data
		bool DeleteDataInVector(int varId, int data);

		//delete Vector
		bool DeleteVector(int varId);

	private :
		std::map<int, std::shared_ptr<Vector>> m_id2Vector;
		int autoIncreasementId;// Vector Id
	};
}