namespace DoubleList {


	// 구조체도 마찬가지 파스칼
	struct DoubleListNode {
		int data = {};
		// Raw Pointer는 헝가리체를
		// Raw Pointer
		//   1. 변수를 넘길 때 모양이 다르다. &
		//   2. 해제를 
		DoubleListNode *dpNextNode = {};
		DoubleListNode *dpPrevNode = {};
	};




	// 함수명 파스칼 체
	void AddHead(const int& data);
	void AddTail(const int& data);
	void DeleteHead();
	void DeleteTail();

	void PrintInformation();
}