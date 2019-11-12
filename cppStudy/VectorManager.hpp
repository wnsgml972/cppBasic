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
		
		int NewVectorList(VectorList::Base<T> *vectorlist);
		bool DeleteVectorList(const int& id);
		bool AddData(const int& id,const T& data);
		bool DeleteData(const int& id,const T& data);
		
		int GetSize() const;
		void PrintData() const;


	private:
		
		VectorList::Base<T>* GetBase(const T& id) const;
		
		ManagerNode<T> *m_pHead;
		int m_idCnt;



	};



	template <typename T>
	DataManager<T>::DataManager() {
		m_pHead = {};

	}

	template <typename T>
	DataManager<T>::~DataManager() {

		ManagerNode<T> *searchNode = m_pHead;
		ManagerNode<T> *tmpNode = {};
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->pNextNode;


			delete tmpNode;
		}

	}


	template <typename T>
	int DataManager<T>::NewVectorList(VectorList::Base<T> *vectorlist) {

		ManagerNode<T> *newNode = new ManagerNode<T>();
		newNode->vectorlist = vectorlist;
		newNode->id = m_idCnt;

		newNode->pNextNode = m_pHead;
		m_pHead = newNode;


		return m_idCnt++;


	}


	//백터리스트 삭제하는것, 그리고 매니저 검증

	template <typename T>
	bool DataManager<T>::DeleteVectorList(const int& id) {

		ManagerNode<T> *searchNode = new ManagerNode<T>();

		searchNode->pNextNode = m_pHead;


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
	bool DataManager<T>::AddData(const int& id, const T& data) {
		VectorList::Base<T> *Base = GetBase(id);

		if (Base == nullptr) {
			return false;
		}

		return Base->AddData(data);


	}

	template <typename T>
	bool DataManager<T>::DeleteData(const int& id, const T& data) {
		VectorList::Base<T> *Base = GetBase(id);

		if (Base == nullptr) {
			return false;
		}
		return Base->DeleteData(data);
	}

	template <typename T>
	int DataManager<T>::GetSize() const{
		ManagerNode<T> *searchNode = m_pHead;
		int cnt = 0;
		while (searchNode != nullptr) {
			cnt += searchNode->vectorlist->GetSize();
			searchNode = searchNode->pNextNode;
		}

		return cnt;
	}

	template <typename T>
	void DataManager<T>::PrintData() const{
		ManagerNode<T> *searchNode = m_pHead;

		while (searchNode != nullptr) {
			std::cout << searchNode->id << "번 아이디-";
			searchNode->vectorlist->PrintData();
			searchNode = searchNode->pNextNode;
		}
	}

	template <typename T>
	VectorList::Base<T>* DataManager<T>::GetBase(const T& id) const{
		ManagerNode<T> *searchNode = m_pHead;
		while (searchNode != nullptr) {

			if (searchNode->id == id) {
				return searchNode->vectorlist;
			}
			searchNode = searchNode->pNextNode;

		}

		return {};

	}


}