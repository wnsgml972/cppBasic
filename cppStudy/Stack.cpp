#include "Stack.h"
#include <iostream>



namespace StackSpace {
	stackNode *stackHead = nullptr;

	void stackPush(int data) {
		stackNode *newNode = new stackNode();
		newNode->data = data;


		newNode->underNode = stackHead;
		stackHead = newNode;
	}

	void stackPop() {


		//아무것도 없을때 빼는 예외 처리
		if (stackHead == nullptr) {
			return;
		}

		stackNode *tmpNode = stackHead->underNode;
		delete stackHead;
		stackHead = tmpNode;


	}

	int getSize() {

		stackNode *searchNode = stackHead;

		int cnt = 0;

		while (searchNode->underNode != nullptr) {

			searchNode = searchNode->underNode;
			cnt++;

		}
		return cnt;

	}

	void printInformation() {
		std::cout << "stack Node(위부터) : ";
		stackNode *searchNode = stackHead;

		while (searchNode != nullptr) {

			std::cout << searchNode->data << "  ";
			searchNode = searchNode->underNode;

		}


		std::cout << "\n";
	}
}