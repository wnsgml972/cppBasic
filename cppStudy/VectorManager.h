#include "BaseVectorList.h"
namespace dataManagerSpace {


	template <typename T>
	class ManagerNode {
	public:
		int m_id;
		vectorListSpace::BaseVectorList<T> *vectorlist;
		ManagerNode *m_nextNode = nullptr;
		
	};

	template <typename T>
	class DataManager {



	public:

		DataManager();
		~DataManager();
		
		int newVectorList(vectorListSpace::BaseVectorList<T> *vectorlist);
		bool deleteVectorList(T id);
		bool AddData(T id,T data);
		bool DeleteData(T id, T data);
		
		int GetSize();
		void PrintData();


	private:
		
		vectorListSpace::BaseVectorList<T>* getBaseVectorList(T id);
		
		ManagerNode<T> *m_head;
		int m_id_cnt;



	};



	template <typename T>
	DataManager<T>::DataManager() {
		m_head = nullptr;

	}

	template <typename T>
	DataManager<T>::~DataManager() {

		ManagerNode<T> *searchNode = m_head;
		ManagerNode<T> *tmpNode = nullptr;
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->m_nextNode;


			delete tmpNode;
		}

	}


	template <typename T>
	int DataManager<T>::newVectorList(vectorListSpace::BaseVectorList<T> *vectorlist) {

		ManagerNode<T> *newNode = new ManagerNode<T>();
		newNode->vectorlist = vectorlist;
		newNode->m_id = m_id_cnt;

		newNode->m_nextNode = m_head;
		m_head = newNode;


		return m_id_cnt++;


	}


	//백터리스트 삭제하는것, 그리고 매니저 검증

	template <typename T>
	bool DataManager<T>::deleteVectorList(T id) {

		ManagerNode<T> *searchNode = new ManagerNode<T>();

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


	template <typename T>
	bool DataManager<T>::AddData(T id, T data) {
		vectorListSpace::BaseVectorList<T> *baseVectorList = getBaseVectorList(id);

		if (baseVectorList == nullptr) {
			return false;
		}

		return baseVectorList->AddData(data);


	}

	template <typename T>
	bool DataManager<T>::DeleteData(T id, T data) {
		vectorListSpace::BaseVectorList<T> *baseVectorList = getBaseVectorList(id);

		if (baseVectorList == nullptr) {
			return false;
		}
		return baseVectorList->DeleteData(data);
	}

	template <typename T>
	int DataManager<T>::GetSize() {
		ManagerNode<T> *searchNode = m_head;
		int cnt = 0;
		while (searchNode != nullptr) {
			cnt += searchNode->vectorlist->GetSize();
			searchNode = searchNode->m_nextNode;
		}

		return cnt;
	}

	template <typename T>
	void DataManager<T>::PrintData() {
		ManagerNode<T> *searchNode = m_head;

		while (searchNode != nullptr) {
			std::cout << searchNode->m_id << "번 아이디-";
			searchNode->vectorlist->PrintData();
			searchNode = searchNode->m_nextNode;
		}
	}

	template <typename T>
	vectorListSpace::BaseVectorList<T>* DataManager<T>::getBaseVectorList(T id) {
		ManagerNode<T> *searchNode = m_head;
		while (searchNode != nullptr) {

			if (searchNode->m_id == id) {
				return searchNode->vectorlist;
			}
			searchNode = searchNode->m_nextNode;

		}

		return nullptr;

	}


}