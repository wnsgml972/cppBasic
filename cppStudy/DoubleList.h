namespace DoubleListSpace {


	struct listNode {
		int data;
		listNode *nextNode = nullptr;
		listNode *prevNode = nullptr;
	};





	void addHead(int data);
	void addTail(int data);
	void deleteHead();
	void deleteTail();

	void printInformation();
}