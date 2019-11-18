#include "Base.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <optional>
#include "typeinfo"

namespace manager {
	
	constexpr int VECTORLIST_ID_START_NUMBER = 1;


	template <typename ElementType>
	struct ManagerNode {
	public:
		int id = {};
		vector_list::Base<ElementType> *pVectorList;
		ManagerNode *pNextNode = {};	
	};


	template <typename ElementType>
	class ElementManager {

	public:
		ElementManager();
		~ElementManager();
		
		int AddVectorList(vector_list::Base<ElementType>* pVectorList);
		bool DeleteVectorList(const int& id);
		bool AddElement(const int& id,const ElementType& element);
		bool DeleteElement(const int& id,const ElementType& element);
		int GetSize() const;
		void PrintElement() const;
		bool AddVectorListsFromFile(std::wstring fileName);
		bool PrintElementToFile();

	private:		
		std::optional<vector_list::Base<ElementType>*> GetVectorList(const int& id) const;
		bool AddVectorListFromText(std::wstring text);

		bool WcharToElementTypeAndAddElement(vector_list::Base<int> *newVectorList, const wchar_t* ElementText);

		ManagerNode<ElementType> *m_pHead;
		int m_idCnt = VECTORLIST_ID_START_NUMBER;
	};


	template <typename ElementType>
	ElementManager<ElementType>::ElementManager() {
		m_pHead = {};
	}


	template <typename ElementType>
	ElementManager<ElementType>::~ElementManager() {
		ManagerNode<ElementType> *pSearchNode = m_pHead;
		ManagerNode<ElementType> *pDeleteNode = {};
		
		while (pSearchNode != nullptr) {
			pDeleteNode = pSearchNode;
			pSearchNode = pSearchNode->pNextNode;
			delete pDeleteNode;
		}
	}


	template <typename ElementType>
	int ElementManager<ElementType>::AddVectorList(vector_list::Base<ElementType>* pVectorList) {
		ManagerNode<ElementType> *pNewNode = new ManagerNode<ElementType>();
		pNewNode->pVectorList = pVectorList;
		pNewNode->id = m_idCnt;
		pNewNode->pNextNode = m_pHead;
		m_pHead = pNewNode;

		return m_idCnt++;
	}


	template <typename ElementType>
	bool ElementManager<ElementType>::DeleteVectorList(const int& id) {
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
	bool ElementManager<ElementType>::AddElement(const int& id, const ElementType& element) {
		std::optional<vector_list::Base<ElementType>*> pVectorListOptional = GetVectorList(id);
		if (!pVectorListOptional.has_value()) {
			return false;
		}
		vector_list::Base<ElementType> *pVectorList = pVectorListOptional.value();

		return pVectorList->AddElement(element);
	}

	
	template <typename ElementType>
	bool ElementManager<ElementType>::DeleteElement(const int& id, const ElementType& element) {
		std::optional<vector_list::Base<ElementType>*> pVectorListOptional = GetVectorList(id);
		if (!pVectorListOptional.has_value()) {
			return false;
		}
		vector_list::Base<ElementType> *pVectorList = pVectorListOptional.value();

		return pVectorList->DeleteElement(element);
	}


	template <typename ElementType>
	int ElementManager<ElementType>::GetSize() const{
		ManagerNode<ElementType> *pSearchNode = m_pHead;
		int cnt = 0;

		while (pSearchNode != nullptr) {
			cnt += pSearchNode->pVectorList->GetSize();
			pSearchNode = pSearchNode->pNextNode;
		}

		return cnt;
	}


	template <typename ElementType>
	void ElementManager<ElementType>::PrintElement() const{
		ManagerNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode != nullptr) {
			std::wcout << pSearchNode->id << L"번 아이디-";
			pSearchNode->pVectorList->PrintElement();
			pSearchNode = pSearchNode->pNextNode;
		}
	}


	template<typename ElementType>
	bool ElementManager<ElementType>::AddVectorListsFromFile(std::wstring fileName){
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
	bool ElementManager<ElementType>::PrintElementToFile() {
		std::wofstream outputFileText("test2.txt");
		ManagerNode<ElementType> *pSearchNode = m_pHead;

		if (outputFileText.is_open()) {
			while (pSearchNode != nullptr) {
				outputFileText << pSearchNode->pVectorList->GetElementListToWstring() << L"\n";
				pSearchNode = pSearchNode->pNextNode;
			}
		}

		return true;
	}


	template <typename ElementType>
	std::optional<vector_list::Base<ElementType>*> ElementManager<ElementType>::GetVectorList(const int& id) const {
		ManagerNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode != nullptr) {
			if (pSearchNode->id == id) {
				return pSearchNode->pVectorList;
			}
			pSearchNode = pSearchNode->pNextNode;
		}

		return {};
	}


	template<typename ElementType>
	bool ElementManager<ElementType>::AddVectorListFromText(std::wstring text){
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

		//split and data 넣기, 이런것도 함수화 해야 할까요?
		std::wstring textDelim = L",";
		int textStart = colonIndex + 1;
		int textEnd = text.find(textDelim);
		while (textEnd != std::string::npos) {
			WcharToElementTypeAndAddElement(newVectorList, text.substr(textStart, textEnd - textStart).c_str());
			textStart = textEnd + textDelim.length();
			textEnd = text.find(textDelim, textStart);
		}
		WcharToElementTypeAndAddElement(newVectorList, text.substr(textStart, textEnd - textStart).c_str());
		AddVectorList(newVectorList);
		
		return true;
	}


	template<typename ElementType>
	bool ElementManager<ElementType>::WcharToElementTypeAndAddElement(vector_list::Base<int>* newVectorList, const wchar_t* elementText)
	{
		ElementType element = {};

		if(typeid(ElementType) == typeid(int)){
			element = _wtoi(elementText);
		}
		else if (typeid(ElementType) == typeid(long)) {
			element = _wtol(elementText);
		}
		else if (typeid(ElementType) == typeid(double)) {
			element = _wtof(elementText);
		}
		else {
			return false;
		}

		newVectorList->AddElement(element);
		return true;
	}
}