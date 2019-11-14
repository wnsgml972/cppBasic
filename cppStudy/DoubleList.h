namespace double_list {

	struct DoubleListNode {
		int data = {};

		DoubleListNode *dpNextNode = {};
		DoubleListNode *dpPrevNode = {};
	};

	void AddHead(const int& data);
	void AddTail(const int& data);
	void DeleteHead();
	void DeleteTail();
	void PrintInformation();

}