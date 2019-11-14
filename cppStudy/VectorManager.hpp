#include "Base.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace manager {
	
	constexpr int ID_START_NUMBER = 1;

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
		
		int AddVectorList(vector_list::Base<ElementType> *vectorlist);
		bool DeleteVectorList(const int& id);
		bool AddData(const int& id,const ElementType& data);
		bool DeleteData(const int& id,const ElementType& data);
		
		int GetSize() const;
		void PrintData() const;

		bool AddVectorListsFromFile(std::wstring fileName);
		bool PrintDataToFile();


	private:		

		int m_idCnt = ID_START_NUMBER;
		ManagerNode<ElementType> *m_pHead;
		
		vector_list::Base<ElementType>* GetBase(const int& id) const;
	
		bool AddVectorListFromText(std::wstring text);

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
	int DataManager<ElementType>::AddVectorList(vector_list::Base<ElementType> *vectorlist) {

		ManagerNode<ElementType> *newNode = new ManagerNode<ElementType>();
		newNode->vectorlist = vectorlist;
		newNode->id = m_idCnt;
		newNode->pNextNode = m_pHead;
		m_pHead = newNode;

		return m_idCnt++;
	}


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


	template <typename ElementType>
	vector_list::Base<ElementType>* DataManager<ElementType>::GetBase(const int& id) const {

		ManagerNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode != nullptr) {
			if (pSearchNode->id == id) {
				return pSearchNode->vectorlist;
			}
			pSearchNode = pSearchNode->pNextNode;
		}

		return {};
	}


	template<typename ElementType>
	bool DataManager<ElementType>::AddVectorListsFromFile(std::wstring fileName){

		std::wifstream inputFileText(fileName);

		if (!inputFileText.is_open()) {
			std::wcout << L"파일을 찾을 수 없습니다!" << L"\n";
			return false;
		}

		std::wstring lineText;

		while (inputFileText) {
			std::getline(inputFileText, lineText);
			bool returns = AddVectorListFromText(lineText);
			if (!returns) {
				return false;
			}
		}

		return true;
	}


	template<typename ElementType>
	bool DataManager<ElementType>::AddVectorListFromText(std::wstring text){

		vector_list::Base<int> *newVectorList = {};

		int colonIndex = text.find(':');

		if (colonIndex == std::string::npos) {
			return false;
		}

		std::wstring typeText = text.substr(0, colonIndex);
		
		if (typeText == L"vector") {
			newVectorList = new vector_list::Vector<ElementType>();
		}
		else if (typeText == L"list") {
			newVectorList = new vector_list::List<ElementType>();
		}
		else {
			return false;
		}

		//split
		std::wstring textDelim = L",";

		auto textStart = colonIndex + 1;
		auto textEnd = text.find(textDelim);

		//우선은 int로 들어온다고 가정
		while (textEnd != std::string::npos) {
			ElementType data = _wtoi(text.substr(textStart, textEnd - textStart).c_str());

			newVectorList->AddData(data);
			textStart = textEnd + textDelim.length();
			textEnd = text.find(textDelim, textStart);
		}

		ElementType data = _wtoi(text.substr(textStart, textEnd - textStart).c_str());
		newVectorList->AddData(data);

		AddVectorList(newVectorList);
		
		return true;
	}


	template<typename ElementType>
	bool DataManager<ElementType>::PrintDataToFile(){

		std::wofstream outputFileText("test2.txt");

		ManagerNode<ElementType> *pSearchNode = m_pHead;

		if (outputFileText.is_open()) {
			while (pSearchNode != nullptr) {
				outputFileText << pSearchNode->vectorlist->GetDataListToWstring() << L"\n";
				
				pSearchNode = pSearchNode->pNextNode;
			}
		}
			
		return true;
	}
}