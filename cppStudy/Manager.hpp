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
		virtual ~ElementManager();
		
		int AddVectorList(vector_list::Base<ElementType>* pVectorList);
		void DeleteVectorList(const int& id);
		bool AddNonDuplicateElementById(const int& id,const ElementType& element);
		void DeleteElementFromId(const int& id,const ElementType& element);
		int GetSize() const;
		void PrintElement() const;
		bool AddVectorListsFromFile(std::wstring fileName);
		void PrintElementToFile(const std::wstring& outputFileName);

	private:		
		std::optional<vector_list::Base<ElementType>*> GetVectorList(const int& id) const;
		bool AddVectorListByTextFormat(const std::wstring& text);

		ElementType WcharToElementType(const wchar_t* elementcharText);
		std::optional<vector_list::Base<ElementType> *> CreateVectorOrListByTextFormat(const std::wstring& text);

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
	void ElementManager<ElementType>::DeleteVectorList(const int& id) {
		ManagerNode<ElementType> *pSearchNode = new ManagerNode<ElementType>();
		pSearchNode->pNextNode = m_pHead;

		while (pSearchNode->pNextNode != nullptr) {
			if (pSearchNode->pNextNode->id == id) {
				ManagerNode *pDeleteNode = pSearchNode->pNextNode;
				pSearchNode->pNextNode = pDeleteNode->pNextNode;
				delete pDeleteNode;

				return ;
			}
		}

		assert(0); //데이터를 못찾았으니
	}


	template <typename ElementType>
	bool ElementManager<ElementType>::AddNonDuplicateElementById(const int& id, const ElementType& element) {
		std::optional<vector_list::Base<ElementType>*> pVectorListOptional = GetVectorList(id);
		if (!pVectorListOptional.has_value()) {
			return false;
		}
		vector_list::Base<ElementType> *pVectorList = pVectorListOptional.value();

		return pVectorList->AddNonDuplicateElement(element);
	}

	
	template <typename ElementType>
	void ElementManager<ElementType>::DeleteElementFromId(const int& id, const ElementType& element) {
		std::optional<vector_list::Base<ElementType>*> pVectorListOptional = GetVectorList(id);
		if (!pVectorListOptional.has_value()) {
			assert(0);
		}
		vector_list::Base<ElementType> *pVectorList = pVectorListOptional.value();

		pVectorList->DeleteElement(element);
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
	bool ElementManager<ElementType>::AddVectorListsFromFile(std::wstring inputFileName){
		std::wifstream inputFileText(inputFileName);

		if (!inputFileText.is_open()) { //없는 파일을 열려고 한 것은 파일탐색기 gui에서 거르지 못하고 왔기에 assert(0);
			std::wcout << L"파일을 찾을 수 없습니다!" << L"\n";
			assert(0);
		}

		std::wstring lineText;
		while (inputFileText) {
			std::getline(inputFileText, lineText);
			bool isLineTextValid = AddVectorListByTextFormat(lineText);
			if (!isLineTextValid) { //파일이 잘못된 것은 프로그래머 잘못이 아니고, 유저에게 알려야 하기에 false로 처리
				return false;
			}
		}

		return true;
	}


	template<typename ElementType>
	void ElementManager<ElementType>::PrintElementToFile(const std::wstring& outputFileName) {
		std::wofstream outputFileText(outputFileName);
		ManagerNode<ElementType> *pSearchNode = m_pHead;

		if (!outputFileText.is_open()) {
			assert(0);
		}

		while (pSearchNode != nullptr) {
			outputFileText << pSearchNode->pVectorList->GetElementListToWstring() << L"\n";
			pSearchNode = pSearchNode->pNextNode;
		}
		

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
	bool ElementManager<ElementType>::AddVectorListByTextFormat(const std::wstring& text){ 
		auto newVectorListOptional = CreateVectorOrListByTextFormat(text);
		if (!newVectorListOptional.has_value()) {
			return false;
		}

		vector_list::Base<ElementType> *newVectorList = CreateVectorOrListByTextFormat(text).value();

		std::wstring textDelim = L",";
		int textStart = text.find(':') + 1;
		int textEnd = text.find(textDelim);

		while (textEnd != std::string::npos) {
			ElementType element = WcharToElementType(text.substr(textStart, textEnd - textStart).c_str());
			newVectorList->AddNonDuplicateElement(element);

			textStart = textEnd + textDelim.length();
			textEnd = text.find(textDelim, textStart);
		}

		ElementType element = WcharToElementType(text.substr(textStart, textEnd - textStart).c_str());
		newVectorList->AddNonDuplicateElement(element);

		AddVectorList(newVectorList);
		return true;
	}


	template<typename ElementType>
	std::optional<vector_list::Base<ElementType> *> ElementManager<ElementType>::CreateVectorOrListByTextFormat(const std::wstring& text) {
		vector_list::Base<int> *newVectorList = {};
		int colonIndex = text.find(':');

		if (colonIndex == std::string::npos) {
			return {};
		}

		std::wstring typeText = text.substr(0, colonIndex);
		if (typeText == L"vector") {
			newVectorList = new vector_list::Vector<ElementType>();
		}
		else if (typeText == L"list") {
			newVectorList = new vector_list::List<ElementType>();
		}
		else {
			return {};
		}
		
		return newVectorList;
	}

	
	template<typename ElementType>
	ElementType ElementManager<ElementType>::WcharToElementType(const wchar_t* elementcharText){
		ElementType element = {};
		std::wstring elementString(elementcharText);

		//if문 노가다 대신에 함수 포인터 배열로 해결을 하려고 했으나.... 
		if(typeid(ElementType) == typeid(int)){
			element = std::stoi(elementString);
		}
		else if (typeid(ElementType) == typeid(long)) {
			element = std::stol(elementString);
		}
		else if (typeid(ElementType) == typeid(double)) {
			element = std::stod(elementString);
		}

		return element;
	}
}