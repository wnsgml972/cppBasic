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
		void CreateFilebyElement(const std::wstring& outputFileName);

	private:		
		std::optional<vector_list::Base<ElementType>*> GetVectorList(const int& id) const;
		bool AddVectorListByTextFormat(const std::wstring& text);

		ElementType WcharToElementType(const wchar_t* elementcharText);
		vector_list::Base<ElementType> * CreateVectorOrListByTextFormat(const std::wstring& text);

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

		if (m_pHead == nullptr) {
			m_pHead = pNewNode;
			pNewNode->pNextNode = {};
			
		}
		else {
			ManagerNode<ElementType> *pSearchNode = m_pHead;
			while (pSearchNode->pNextNode != nullptr) {
				pSearchNode = pSearchNode->pNextNode;
			}
			pSearchNode->pNextNode = pNewNode;
		}
		
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

		assert(0); //�����͸� ��ã������
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
			std::wcout << pSearchNode->id << L"�� ���̵�-";
			pSearchNode->pVectorList->PrintElement();
			pSearchNode = pSearchNode->pNextNode;
		}
	}


	template<typename ElementType>
	bool ElementManager<ElementType>::AddVectorListsFromFile(std::wstring inputFileName){
		std::wifstream inputFileText(inputFileName);

		if (!inputFileText.is_open()) { //���� ������ ������ �� ���� ����Ž���� gui���� �Ÿ��� ���ϰ� �Ա⿡ assert(0);
			std::wcout << L"������ ã�� �� �����ϴ�!" << L"\n";
			assert(0);
		}

		std::wstring lineText;
		while (inputFileText) {
			std::getline(inputFileText, lineText);
			bool isLineTextValid = AddVectorListByTextFormat(lineText);
			if (!isLineTextValid) { //������ �߸��� ���� ���α׷��� �߸��� �ƴϰ�, �������� �˷��� �ϱ⿡ false�� ó��
				return false;
			}
		}

		return true;
	}


	template<typename ElementType>
	void ElementManager<ElementType>::CreateFilebyElement(const std::wstring& outputFileName) {
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


		vector_list::Base<ElementType> *newVectorList = CreateVectorOrListByTextFormat(text);

		std::wstring textDelim = L",";
		auto textStart = text.find(':') + 1;
		auto textEnd = text.find(textDelim);

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
	vector_list::Base<ElementType> * ElementManager<ElementType>::CreateVectorOrListByTextFormat(const std::wstring& text) {
		vector_list::Base<int> *newVectorList = {};
		auto colonIndex = text.find(':');

		if (colonIndex == std::string::npos) {
			// ���� ���������� �������� �ʴ� Ÿ���Դϴ�.
			assert(0);
		}

		std::wstring typeText = text.substr(0, colonIndex);
		if (typeText == L"vector") {
			newVectorList = new vector_list::Vector<ElementType>();
		}
		else if (typeText == L"list") {
			newVectorList = new vector_list::List<ElementType>();
		}
		else {
			// ���� ���������� �������� �ʴ� Ÿ���Դϴ�.
			assert(0);
		}
		
		return newVectorList;
	}

	
	template<typename ElementType>
	ElementType ElementManager<ElementType>::WcharToElementType(const wchar_t* elementcharText){
		ElementType element = {};
		std::wstring elementString(elementcharText);

#pragma warning(push)
#pragma warning(disable: 4244)
		//if�� �밡�� ��ſ� �Լ� ������ �迭�� �ذ��� �Ϸ��� ������.... 
		if(typeid(ElementType) == typeid(int)){
			element = std::stoi(elementString);
		}
		else if (typeid(ElementType) == typeid(long)) {
			element = std::stol(elementString);
		}
		else if (typeid(ElementType) == typeid(double)) {
			element = std::stod(elementString);
		}
		else {
			// ���� ���������� �������� �ʴ� Ÿ���Դϴ�.
			assert(0);
		}
#pragma warning(pop)

		return element;
	}
}