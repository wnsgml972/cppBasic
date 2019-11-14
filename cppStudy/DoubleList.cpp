#include "DoubleList.h"
#include <iostream>

namespace double_list {

	DoubleListNode *listHead = {};
	DoubleListNode *listTail = {};


	void AddHead(const int& data){
	
		DoubleListNode *newNode = new DoubleListNode();
		newNode->data = data;

		if (listHead == nullptr) {
			listTail = newNode;
		}
		else {
			listHead->dpPrevNode = newNode;
		}

		newNode->dpNextNode = listHead;
		listHead = newNode;
	}


	void AddTail(const int& data){

		DoubleListNode *newNode = new DoubleListNode();
		newNode->data = data;

		if (listTail == nullptr) {
			listHead = newNode;
		}
		else {
			listTail->dpNextNode = newNode;
		}

		newNode->dpPrevNode = listTail;
		listTail = newNode;
	}


	void DeleteHead(){

		if (listHead == nullptr) {
			return;
		}

		DoubleListNode *pDeleteNode = listHead->dpNextNode;
		delete listHead;
		listHead = pDeleteNode;

		if (listHead == nullptr) {
			listTail = {};
		}
		else {
			listHead->dpPrevNode = {};
		}
	}


	void DeleteTail(){
	
		if (listTail == nullptr) {
			return;
		}

		DoubleListNode *pDeleteNode = listTail->dpPrevNode;
		delete listTail;
		listTail = pDeleteNode;

		if (listTail == nullptr) {
			listHead = nullptr;
		}
		else {
			listTail->dpNextNode = {};
		}
	}


	void PrintInformation(){
		
		std::wcout << L"doublie list node(headºÎÅÍ) : ";

		DoubleListNode *pSearchNode = listHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->data << L"  ";
			pSearchNode = pSearchNode->dpNextNode;

		}

		std::wcout << L"\n";
	}


}