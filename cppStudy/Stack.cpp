#include "Stack.h"
#include <iostream>



namespace stack {

	StackNode *stackHead = {};

	void PushStack(const int& data) {

		StackNode *newNode = new StackNode();
		newNode->data = data;
		newNode->pUnderNode = stackHead;
		stackHead = newNode;
	}


	void PopStack() {
		
		if (stackHead == nullptr) {
			return;
		}

		StackNode *pDeleteNode = stackHead->pUnderNode;
		delete stackHead;
		stackHead = pDeleteNode;
	}


	int GetSize(){

		StackNode *pSearchNode = stackHead;

		int cnt = 0;

		while (pSearchNode->pUnderNode != nullptr) {
			pSearchNode = pSearchNode->pUnderNode;
			
			cnt++;
		}

		return cnt;
	}


	void PrintInformation() {
	
		std::wcout << L"stack Node(À§ºÎÅÍ) : ";
		
		StackNode *pSearchNode = stackHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->data << L"  ";

			pSearchNode = pSearchNode->pUnderNode;
		}

		std::wcout << L"\n";
	}
}