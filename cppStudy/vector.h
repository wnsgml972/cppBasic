
#include "BaseVectorList.h"

namespace vectorListSpace {


	class Vector : public BaseVectorList {



	public:


		Vector();
		~Vector();
	

		bool AddData(int data);
		bool DeleteData(int data);
		int GetSize();

		const void PrintData();



	private:
		
		int getDataIndex(int data);
		bool leftShiftData(int index);
		
		int m_cnt;
		int *m_data;



	};




}