namespace vectorNameSpace {

	class Node {
	public:
		Node *m_nextNode = nullptr;
		int m_data;
	};

	class Vector {



	public:
		Node *m_head = new Node();


		bool AddData(int data);
		bool DeleteData(int data);
		int GetSize();

		const void PrintData();
		

	private:


	};




}