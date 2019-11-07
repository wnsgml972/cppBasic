#include "BaseVectorList.h"
namespace dataManagerSpace {
	
	
	class ManagerNode {
	public:
		int m_id;
		vectorListSpace::BaseVectorList *vectorlist;
		ManagerNode *m_nextNode = nullptr;
		
	};

	class DataManager {



	public:

		DataManager();
		~DataManager();
		
		int newVectorList(vectorListSpace::BaseVectorList *vectorlist);
		bool deleteVectorList(int id);
		bool AddData(int id,int data);
		bool DeleteData(int id, int data);
		
		int GetSize();
		void PrintData();


	private:
		
		vectorListSpace::BaseVectorList* getBaseVectorList(int id);
		
		ManagerNode *m_head;
		int m_id_cnt;



	};




}