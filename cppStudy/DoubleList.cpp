#include "DoubleList.h"
#include <iostream>

namespace double_list {

	DoubleListNode *pListHead = {};
	DoubleListNode *pListTail = {};


	void AddHead(const int& element){
		DoubleListNode *pNewNode = new DoubleListNode();
		pNewNode->element = element;

		if (pListHead == nullptr) {
			pListTail = pNewNode;
		}
		else {
			pListHead->dpPrevNode = pNewNode;
		}
		pNewNode->dpNextNode = pListHead;
		pListHead = pNewNode;
	}


	void AddTail(const int& element){
		DoubleListNode *pNewNode = new DoubleListNode();
		pNewNode->element = element;

		if (pListTail == nullptr) {
			pListHead = pNewNode;
		}
		else {
			pListTail->dpNextNode = pNewNode;
		}
		pNewNode->dpPrevNode = pListTail;
		pListTail = pNewNode;
	}


	void DeleteHead(){
		if (pListHead == nullptr) {
			return;
		}

		DoubleListNode *pDeleteNode = pListHead->dpNextNode;
		delete pListHead;
		pListHead = pDeleteNode;
		if (pListHead == nullptr) {
			pListTail = {};
		}
		else {
			pListHead->dpPrevNode = {};
		}
	}


	void DeleteTail(){
		if (pListTail == nullptr) {
			return;
		}

		DoubleListNode *pDeleteNode = pListTail->dpPrevNode;
		delete pListTail;
		pListTail = pDeleteNode;
		if (pListTail == nullptr) {
			pListHead = {};
		}
		else {
			pListTail->dpNextNode = {};
		}
	}


	void PrintInformation(){
		std::wcout << L"doublie list node(headºÎÅÍ) : ";
		DoubleListNode *pSearchNode = pListHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->element << L"  ";
			pSearchNode = pSearchNode->dpNextNode;
		}
		std::wcout << L"\n";
	}
}