namespace double_list {

	struct DoubleListNode {
		int element = {};
		DoubleListNode *pNextNode = {};
		DoubleListNode *pPrevNode = {};
	};

	void AddHead(const int& element);
	void AddTail(const int& element);
	void DeleteHead();
	void DeleteTail();
	void PrintInformation();

}