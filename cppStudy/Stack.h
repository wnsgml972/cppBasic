namespace stack {

	struct StackNode {
		int data = {};
		StackNode *pUnderNode = {};
	};

	void PushStack(const int& data);
	void PopStack();
	int GetSize();
	void PrintInformation();
}