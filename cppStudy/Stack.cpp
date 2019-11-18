#include "Stack.h"
#include <iostream>

namespace stack {

	StackNode *pStackHead = {};


	void PushStack(const int& element) {
		StackNode *pNewNode = new StackNode();
		pNewNode->element = element;
		pNewNode->pUnderNode = pStackHead;
		pStackHead = pNewNode;
	}


	void PopStack() {
		if (pStackHead == nullptr) {
			return;
		}

		StackNode *pDeleteNode = pStackHead->pUnderNode;
		delete pStackHead;
		pStackHead = pDeleteNode;
	}


	const int GetSize(){
		StackNode *pSearchNode = pStackHead;
		int nodeCount = 0;

		while (pSearchNode->pUnderNode != nullptr) {
			pSearchNode = pSearchNode->pUnderNode;
			nodeCount++;
		}

		return nodeCount;
	}


	void PrintInformation() {
		std::wcout << L"stack Node(À§ºÎÅÍ) : ";
		StackNode *pSearchNode = pStackHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->element << L"  ";
			pSearchNode = pSearchNode->pUnderNode;
		}
		std::wcout << L"\n";
	}
}