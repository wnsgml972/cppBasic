#include "VectorManager.h"
#include <iostream>
namespace dataManagerSpace {


	DataManager::DataManager() {
		m_head = nullptr;

	}


	DataManager::~DataManager() {

		ManagerNode *searchNode = m_head;
		ManagerNode *tmpNode = nullptr;
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->m_nextNode;


			delete tmpNode;
		}

	}


	int DataManager::newVectorList(vectorListSpace::BaseVectorList *vectorlist) {
		
		ManagerNode *newNode = new ManagerNode();
		newNode->vectorlist = vectorlist;
		newNode->m_id = m_id_cnt;
		
		newNode->m_nextNode = m_head;
		m_head = newNode;


		return m_id_cnt++;
		

	}


	//백터리스트 삭제하는것, 그리고 매니저 검증


	bool DataManager::deleteVectorList(int id) {
		
		ManagerNode *searchNode = new ManagerNode();

		searchNode->m_nextNode = m_head;


		while (searchNode->m_nextNode != nullptr) {
			if (searchNode->m_nextNode->m_id == id) {

				ManagerNode *deleteNode = searchNode->m_nextNode;
				searchNode->m_nextNode = deleteNode->m_nextNode;
				delete deleteNode;

				return true;
			}
		}

		return false;
	}



	bool DataManager::AddData(int id, int data) {
		vectorListSpace::BaseVectorList *baseVectorList = getBaseVectorList(id);

		if (baseVectorList == nullptr) {
			return false;
		}

		return baseVectorList->AddData(data);


	}

	bool DataManager::DeleteData(int id, int data) {
		vectorListSpace::BaseVectorList *baseVectorList = getBaseVectorList(id);

		if (baseVectorList == nullptr) {
			return false;
		}
		return baseVectorList->DeleteData(data);
	}

	int DataManager::GetSize() {
		ManagerNode *searchNode = m_head;
		int cnt = 0;
		while (searchNode != nullptr) {
			cnt += searchNode->vectorlist->GetSize();
			searchNode = searchNode->m_nextNode;
		}

		return cnt;
	}


	void DataManager::PrintData() {
		ManagerNode *searchNode = m_head;

		while (searchNode != nullptr) {
			std::cout << searchNode->m_id << "번 아이디-";
			searchNode->vectorlist->PrintData();
			searchNode = searchNode->m_nextNode;
		}
	}

	vectorListSpace::BaseVectorList* DataManager::getBaseVectorList(int id) {
		ManagerNode *searchNode = m_head;
		while (searchNode != nullptr) {

			if (searchNode->m_id == id) {
				return searchNode->vectorlist;
			}
			searchNode = searchNode->m_nextNode;

		}

		return nullptr;

	}




}