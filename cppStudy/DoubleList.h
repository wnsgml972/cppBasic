namespace double_list {

	struct DoubleListNode {
		int element = {};
		DoubleListNode *dpNextNode = {};
		DoubleListNode *dpPrevNode = {};
	};

	void AddHead(const int& element);
	void AddTail(const int& element);
	void DeleteHead();
	void DeleteTail();
	void PrintInformation();

}