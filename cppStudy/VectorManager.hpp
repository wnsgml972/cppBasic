#include "Base.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace manager {


	template <typename ElementType>
	struct ManagerNode {
	public:
		int id = {};

		vector_list::Base<ElementType> *vectorlist;
		ManagerNode *pNextNode = {};
		
	};

	template <typename ElementType>
	class DataManager {



	public:

		DataManager();
		~DataManager();
		
		int NewVectorList(vector_list::Base<ElementType> *vectorlist);
		bool DeleteVectorList(const int& id);
		bool AddData(const int& id,const ElementType& data);
		bool DeleteData(const int& id,const ElementType& data);
		
		int GetSize() const;
		void PrintData() const;

		bool AddDataFromFile();
		bool PrintDataToFile();


	private:
		
		vector_list::Base<ElementType>* GetBase(const int& id) const;
		
		ManagerNode<ElementType> *m_pHead;
		int m_idCnt = 1;



	};



	template <typename ElementType>
	DataManager<ElementType>::DataManager() {
		m_pHead = {};

	}

	template <typename ElementType>
	DataManager<ElementType>::~DataManager() {

		ManagerNode<ElementType> *pSearchNode = m_pHead;
		ManagerNode<ElementType> *pDeleteNode = {};
		while (pSearchNode != nullptr) {

			pDeleteNode = pSearchNode;

			pSearchNode = pSearchNode->pNextNode;


			delete pDeleteNode;
		}

	}


	template <typename ElementType>
	int DataManager<ElementType>::NewVectorList(vector_list::Base<ElementType> *vectorlist) {

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

		ManagerNode<ElementType> *pSearchNode = new ManagerNode<ElementType>();

		pSearchNode->pNextNode = m_pHead;


		while (pSearchNode->pNextNode != nullptr) {
			if (pSearchNode->pNextNode->id == id) {

				ManagerNode *pDeleteNode = pSearchNode->pNextNode;
				pSearchNode->pNextNode = pDeleteNode->pNextNode;
				delete pDeleteNode;

				return true;
			}
		}

		return false;
	}


	template <typename ElementType>
	bool DataManager<ElementType>::AddData(const int& id, const ElementType& data) {
		vector_list::Base<ElementType> *Base = GetBase(id);

		if (Base == nullptr) {
			return false;
		}

		return Base->AddData(data);


	}

	template <typename ElementType>
	bool DataManager<ElementType>::DeleteData(const int& id, const ElementType& data) {
		vector_list::Base<ElementType> *Base = GetBase(id);

		if (Base == nullptr) {
			return false;
		}
		return Base->DeleteData(data);
	}

	template <typename ElementType>
	int DataManager<ElementType>::GetSize() const{
		ManagerNode<ElementType> *pSearchNode = m_pHead;
		int cnt = 0;
		while (pSearchNode != nullptr) {
			cnt += pSearchNode->vectorlist->GetSize();
			pSearchNode = pSearchNode->pNextNode;
		}

		return cnt;
	}

	template <typename ElementType>
	void DataManager<ElementType>::PrintData() const{
		ManagerNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->id << L"번 아이디-";
			pSearchNode->vectorlist->PrintData();
			pSearchNode = pSearchNode->pNextNode;
		}
	}

	template<typename ElementType>
	bool DataManager<ElementType>::AddDataFromFile(){

		std::ifstream inputFileText("data.txt");

		if (!inputFileText.is_open()) {
			std::wcout << L"파일을 찾을 수 없습니다!" << L"\n";
			return false;
		}

		std::wstring lineText;

		while (inputFileText) {
			getline(inputFileText, lineText);
			std::wcout << lineText << L"\n";
		}


		return false;
	}

	template<typename ElementType>
	bool DataManager<ElementType>::PrintDataToFile()
	{
		return false;
	}

	template <typename ElementType>
	vector_list::Base<ElementType>* DataManager<ElementType>::GetBase(const int& id) const{
		ManagerNode<ElementType> *pSearchNode = m_pHead;
		while (pSearchNode != nullptr) {

			if (pSearchNode->id == id) {
				return pSearchNode->vectorlist;
			}
			pSearchNode = pSearchNode->pNextNode;

		}

		return {};

	}


}