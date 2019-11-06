
#include "BaseVectorList.h"

namespace vectorListSpace {

	class Node {
	public:
		Node *m_nextNode = nullptr;
		int m_data;
	};

	class List : public BaseVectorList {



	public:
		
		List();
		~List();

		bool AddData(int data);
		bool DeleteData(int data);
		int GetSize();

		const void PrintData();


	private:
		Node *m_head;

	};




}