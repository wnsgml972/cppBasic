namespace DoubleListSpace {


	// 구조체도 마찬가지 파스칼
	struct listNode {
		int data;
		// Raw Pointer는 헝가리체를
		// Raw Pointer
		//   1. 변수를 넘길 때 모양이 다르다. &
		//   2. 해제를 
		listNode *nextNode = nullptr;
		listNode *prevNode = nullptr;
	};




	// 함수명 파스칼 체
	void addHead(int data);
	void addTail(int data);
	void deleteHead();
	void deleteTail();

	void printInformation();
}