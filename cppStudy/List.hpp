
#include "Base.hpp"
#include <optional>
namespace vector_list {

	template <typename ElementType>
	struct ListNode {
		ElementType element = {};
		ListNode *pNextNode = {};
	};


	template <typename ElementType>
	class List : public Base<ElementType> {

	public:
		List();
		virtual ~List() override;

		virtual bool AddNonDuplicateElement(const ElementType& element) override;
		virtual void DeleteElement(const ElementType& element) override;
		virtual const int GetSize() const override;
		virtual void PrintElement() const override;
		virtual void Copy(const Base<ElementType>& right) override;
		virtual std::wstring GetElementListToWstring() override;

		List<ElementType>& operator=(List<ElementType>& right);
	private:
		void DeleteAllElement();
		ListNode<ElementType>* GetHeadPointer() const;
		std::optional<ListNode<ElementType> *> FindElementExceptDuplicate(const ElementType& element);

		ListNode<ElementType> *m_pHead;		
	};


	template <typename ElementType>
	List<ElementType>::List() {
		m_pHead = new ListNode<ElementType>();
	}


	template <typename ElementType>
	List<ElementType>::~List() {
		DeleteAllElement();
	}


	template<typename ElementType>
	void List<ElementType>::DeleteAllElement(){
		ListNode<ElementType> *pSearchNode = m_pHead;
		ListNode<ElementType> *pDeleteNode = {};
		
		while (pSearchNode != nullptr) {
			pDeleteNode = pSearchNode;
			pSearchNode = pSearchNode->pNextNode;
			delete pDeleteNode;
		}
	}


	template <typename ElementType>
	bool List<ElementType>::AddNonDuplicateElement(const ElementType& element) {
		std::optional<ListNode<ElementType>*> pLastNodeOptional = FindElementExceptDuplicate(element);
		if (!pLastNodeOptional.has_value()) {
			return false;
		}
		ListNode<ElementType>* pLastNode = pLastNodeOptional.value();

		ListNode<ElementType> *pNewNode = new ListNode<ElementType>();
		pNewNode->element = element;
		pNewNode->pNextNode = {};
		pLastNode->pNextNode = pNewNode;
		return true;
	}


	template <typename ElementType>
	void List<ElementType>::DeleteElement(const ElementType& element) {
		ListNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode->pNextNode != nullptr) {
			if (pSearchNode->pNextNode->element == element) {
				ListNode<ElementType> * pDeleteNode = pSearchNode->pNextNode;
				pSearchNode->pNextNode = pDeleteNode->pNextNode;
				delete pDeleteNode;

				return ;
			}
			pSearchNode = pSearchNode->pNextNode;
		}

		assert(0);
	}


	template <typename ElementType>
	const int List<ElementType>::GetSize() const {
		int nodeCount = 0;
		ListNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			nodeCount++;
		}
		return nodeCount;
	}


	template <typename ElementType>
	void List<ElementType>::PrintElement() const {
		std::wcout << L"ListElement : ";
		ListNode<ElementType> *pSearchNode = m_pHead;
		
		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			std::wcout << pSearchNode->element << L"  ";
		}
		std::wcout << L"\n";
	}


	template<typename ElementType>
	void List<ElementType>::Copy(const Base<ElementType>& right){
		DeleteAllElement();
		m_pHead = new ListNode<ElementType>();		
		
		const List<ElementType>& original = static_cast<const List<ElementType>&>(right); //다운캐스팅
		
		ListNode<ElementType> *pSearchNode = original.GetHeadPointer();
		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			AddNonDuplicateElement(pSearchNode->element);
		}
	}


	template<typename ElementType>
	ListNode<ElementType>* List<ElementType>::GetHeadPointer() const{
		return m_pHead;
	}


	template<typename ElementType>
	List<ElementType>& List<ElementType>::operator=(List<ElementType>& right){
		Copy(right);
		return *this;
	}


	template<typename ElementType>
	std::wstring List<ElementType>::GetElementListToWstring() {
		std::wstring text = L"list:";
		ListNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			text += std::to_wstring(pSearchNode->element) + L",";
		}

		return text.substr(0, text.length() - 1);
	}


	template<typename ElementType>
	std::optional<ListNode<ElementType> *> List<ElementType>::FindElementExceptDuplicate(const ElementType& element){
		ListNode<ElementType> *pSearchNode = m_pHead;

		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			if (pSearchNode->element == element) {
				return {};
			}
		}

		return pSearchNode;
	}
}