#include "vector.h"
#include <iostream>
namespace vectorNameSpace {

	bool Vector::AddData(int data) {


		//중복검사+ 데이터가 들어갈 위치 찾아놓기
		Node *searchNode = m_head;
		while (searchNode->m_nextNode != nullptr) {
			searchNode = searchNode->m_nextNode;
			if (searchNode->m_data == data) {
				return false;
			}
		}



		Node *addNode = new Node();
		addNode->m_data = data;
		addNode->m_nextNode = nullptr;

		
		searchNode->m_nextNode = addNode;
		
		return true;
	}
	bool Vector::DeleteData(int data) {

		Node *searchNode = m_head;



		while (searchNode->m_nextNode != nullptr) {
			
			if (searchNode->m_nextNode->m_data == data) {
				
				
				
				Node * deleteNode = searchNode->m_nextNode;
				searchNode->m_nextNode = deleteNode->m_nextNode;
				delete deleteNode;

				return true;
			}
			searchNode = searchNode->m_nextNode;

		}

		return false;
	}

	int Vector::GetSize() {
		int cnt = 0;

		Node *searchNode = m_head;
		while (searchNode->m_nextNode != nullptr) {
			searchNode = searchNode->m_nextNode;
			cnt++;
		}
		return cnt;


	}


	const void Vector::PrintData() {
		std::cout << "vectorData : ";

		Node *searchNode = m_head;
		while (searchNode->m_nextNode != nullptr) {
			searchNode = searchNode->m_nextNode;

			std::cout << searchNode->m_data<<"  ";

		}

		std::cout << "\n";

	}

	
}