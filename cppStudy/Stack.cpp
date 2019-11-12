#include "Stack.h"
#include <iostream>



namespace Stack {
	StackNode *stackHead = {};

	void PushStack(const int& data) {

		StackNode *newNode = new StackNode();
		newNode->data = data;
		newNode->pUnderNode = stackHead;

		stackHead = newNode;
	}

	void PopStack() {


		//아무것도 없을때 빼는 예외 처리
		if (stackHead == nullptr) {
			return;
		}

		StackNode *tmpNode = stackHead->pUnderNode;
		
		delete stackHead;
		
		stackHead = tmpNode;


	}

	int GetSize() {

		StackNode *searchNode = stackHead;

		int cnt = 0;
		while (searchNode->pUnderNode != nullptr) {
			searchNode = searchNode->pUnderNode;
			
			cnt++;
		}


		return cnt;
	}

	void PrintInformation() {
		std::cout << "stack Node(위부터) : ";
		
		StackNode *searchNode = stackHead;
		while (searchNode != nullptr) {
			std::cout << searchNode->data << "  ";
			
			searchNode = searchNode->pUnderNode;

		}


		std::cout << "\n";
	}
}