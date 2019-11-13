#include "Base.hpp"
namespace Manager {


	template <typename ElementType>
	struct ManagerNode {
	public:
		int id = {};

		VectorList::Base<ElementType> *vectorlist;
		ManagerNode *pNextNode = {};
		
	};

	template <typename ElementType>
	class DataManager {



	public:

		DataManager();
		~DataManager();
		
		int NewVectorList(VectorList::Base<ElementType> *vectorlist);
		bool DeleteVectorList(const int& id);
		bool AddData(const int& id,const ElementType& data);
		bool DeleteData(const int& id,const ElementType& data);
		
		int GetSize() const;
		void PrintData() const;


	private:
		
		VectorList::Base<ElementType>* GetBase(const int& id) const;
		
		ManagerNode<ElementType> *m_pHead;
		int m_idCnt = 1;



	};



	template <typename ElementType>
	DataManager<ElementType>::DataManager() {
		m_pHead = {};

	}

	template <typename ElementType>
	DataManager<ElementType>::~DataManager() {

		ManagerNode<ElementType> *searchNode = m_pHead;
		ManagerNode<ElementType> *tmpNode = {};
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->pNextNode;


			delete tmpNode;
		}

	}


	template <typename ElementType>
	int DataManager<ElementType>::NewVectorList(VectorList::Base<ElementType> *vectorlist) {

		ManagerNode<ElementType> *newNode = new ManagerNode<ElementType>();
		newNode->vectorlist = vectorlist;
		newNode->id = m_idCnt;

		newNode->pNextNode = m_pHead;
		m_pHead = newNode;


		return m_idCnt++;


	}


	//백터리스트 삭제하는것, 그리고 매니저 검증

	template <typename ElementType>
	bool DataManager<ElementType>::DeleteVectorList(const int& id) {

		ManagerNode<ElementType> *searchNode = new ManagerNode<ElementType>();

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


	template <typename ElementType>
	bool DataManager<ElementType>::AddData(const int& id, const ElementType& data) {
		VectorList::Base<ElementType> *Base = GetBase(id);

		if (Base == nullptr) {
			return false;
		}

		return Base->AddData(data);


	}

	template <typename ElementType>
	bool DataManager<ElementType>::DeleteData(const int& id, const ElementType& data) {
		VectorList::Base<ElementType> *Base = GetBase(id);

		if (Base == nullptr) {
			return false;
		}
		return Base->DeleteData(data);
	}

	template <typename ElementType>
	int DataManager<ElementType>::GetSize() const{
		ManagerNode<ElementType> *searchNode = m_pHead;
		int cnt = 0;
		while (searchNode != nullptr) {
			cnt += searchNode->vectorlist->GetSize();
			searchNode = searchNode->pNextNode;
		}

		return cnt;
	}

	template <typename ElementType>
	void DataManager<ElementType>::PrintData() const{
		ManagerNode<ElementType> *searchNode = m_pHead;

		while (searchNode != nullptr) {
			std::cout << searchNode->id << "번 아이디-";
			searchNode->vectorlist->PrintData();
			searchNode = searchNode->pNextNode;
		}
	}

	template <typename ElementType>
	VectorList::Base<ElementType>* DataManager<ElementType>::GetBase(const int& id) const{
		ManagerNode<ElementType> *searchNode = m_pHead;
		while (searchNode != nullptr) {

			if (searchNode->id == id) {
				return searchNode->vectorlist;
			}
			searchNode = searchNode->pNextNode;

		}

		return {};

	}


}