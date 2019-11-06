namespace StackSpace {


	struct stackNode {
		int data;
		stackNode *underNode = nullptr;
	};

	
	
	

	void stackPush(int data);
	void stackPop();
	int getSize();
	void printInformation();
}