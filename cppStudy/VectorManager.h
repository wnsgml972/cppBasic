#include "Base.h"
namespace Manager {


	template <typename T>
	struct ManagerNode {
	public:
		int id = {};

		VectorList::Base<T> *vectorlist;
		ManagerNode *pNextNode = nullptr;
		
	};

	template <typename T>
	class DataManager {



	public:

		DataManager();
		~DataManager();
		
		int newVectorList(VectorList::Base<T> *vectorlist);
		bool deleteVectorList(int id);
		bool AddData(int id,T data);
		bool DeleteData(int id, T data);
		
		int GetSize();
		void PrintData();


	private:
		
		VectorList::Base<T>* getBase(T id);
		
		ManagerNode<T> *m_head;
		int id_cnt;



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

			searchNode = searchNode->pNextNode;


			delete tmpNode;
		}

	}


	template <typename T>
	int DataManager<T>::newVectorList(VectorList::Base<T> *vectorlist) {

		ManagerNode<T> *newNode = new ManagerNode<T>();
		newNode->vectorlist = vectorlist;
		newNode->id = id_cnt;

		newNode->pNextNode = m_head;
		m_head = newNode;


		return id_cnt++;


	}


	//백터리스트 삭제하는것, 그리고 매니저 검증

	template <typename T>
	bool DataManager<T>::deleteVectorList(int id) {

		ManagerNode<T> *searchNode = new ManagerNode<T>();

		searchNode->pNextNode = m_head;


		while (searchNode->pNextNode != nullptr) {
			if (searchNode->pNextNode->id == id) {

				ManagerNode *deleteNode = searchNode->pNextNode;
				searchNode->pNextNode = deleteNode->pNextNode;
				delete deleteNode;

				return true;
			}
		}

		return false;
	}


	template <typename T>
	bool DataManager<T>::AddData(int id, T data) {
		VectorList::Base<T> *Base = getBase(id);

		if (Base == nullptr) {
			return false;
		}

		return Base->AddData(data);


	}

	template <typename T>
	bool DataManager<T>::DeleteData(int id, T data) {
		VectorList::Base<T> *Base = getBase(id);

		if (Base == nullptr) {
			return false;
		}
		return Base->DeleteData(data);
	}

	template <typename T>
	int DataManager<T>::GetSize() {
		ManagerNode<T> *searchNode = m_head;
		int cnt = 0;
		while (searchNode != nullptr) {
			cnt += searchNode->vectorlist->GetSize();
			searchNode = searchNode->pNextNode;
		}

		return cnt;
	}

	template <typename T>
	void DataManager<T>::PrintData() {
		ManagerNode<T> *searchNode = m_head;

		while (searchNode != nullptr) {
			std::cout << searchNode->id << "번 아이디-";
			searchNode->vectorlist->PrintData();
			searchNode = searchNode->pNextNode;
		}
	}

	template <typename T>
	VectorList::Base<T>* DataManager<T>::getBase(T id) {
		ManagerNode<T> *searchNode = m_head;
		while (searchNode != nullptr) {

			if (searchNode->id == id) {
				return searchNode->vectorlist;
			}
			searchNode = searchNode->pNextNode;

		}

		return nullptr;

	}


}