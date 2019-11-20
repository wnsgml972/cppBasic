#include "DoubleList.h"
#include <iostream>
#include <cassert>

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
			pListHead->pPrevNode = pNewNode;
		}
		pNewNode->pNextNode = pListHead;
		pListHead = pNewNode;
	}


	void AddTail(const int& element){
		DoubleListNode *pNewNode = new DoubleListNode();
		pNewNode->element = element;

		if (pListTail == nullptr) {
			pListHead = pNewNode;
		}
		else {
			pListTail->pNextNode = pNewNode;
		}
		pNewNode->pPrevNode = pListTail;
		pListTail = pNewNode;
	}


	void DeleteHead(){
		if (pListHead == nullptr) {
			assert(0);
		}

		DoubleListNode *pListHeadNextNode = pListHead->pNextNode;
		delete pListHead;

		pListHead = pListHeadNextNode;
		if (pListHead == nullptr) {
			pListTail = {};
		}
		else {
			pListHead->pPrevNode = {};
		}
	}


	void DeleteTail(){
		if (pListTail == nullptr) {
			assert(0);
		}

		DoubleListNode *pListTailPrevNode = pListTail->pPrevNode;
		delete pListTail;

		pListTail = pListTailPrevNode;
		if (pListTail == nullptr) {
			pListHead = {};
		}
		else {
			pListTail->pNextNode = {};
		}
	}


	void PrintInformation(){
		std::wcout << L"doublie list node(headºÎÅÍ) : ";
		DoubleListNode *pSearchNode = pListHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->element << L"  ";
			pSearchNode = pSearchNode->pNextNode;
		}
		std::wcout << L"\n";
	}
}