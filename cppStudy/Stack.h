namespace stack {

	struct StackNode {
		int element = {};
		StackNode *pUnderNode = {};
	};

	void PushStack(const int& element);
	void PopStack();
	const int GetSize();
	void PrintInformation();
}