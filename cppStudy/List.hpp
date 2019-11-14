
#include "Base.hpp"

namespace vector_list {


	template <typename ElementType>
	struct ListNode {
		ElementType data = {};
		ListNode *pNextNode = {};
	};



	template <typename ElementType>
	class List : public Base<ElementType> {

	public:

		List();
		~List();

		bool AddData(const ElementType& data) override;
		bool DeleteData(const ElementType& data) override;
		int GetSize() const override;
		void PrintData() const override;

		void Copy(const Base<ElementType>& right);
		virtual List<ElementType>& operator=(List<ElementType>& right);

		ListNode<ElementType>* GetHeadPointer() const;		
		

	private:

		ListNode<ElementType> *m_pHead;

		void DeleteAllNode();

	};



	template <typename ElementType>
	List<ElementType>::List() {
		
		m_pHead = new ListNode<ElementType>();
	}


	template <typename ElementType>
	List<ElementType>::~List() {
		
		DeleteAllNode();
	}


	template<typename ElementType>
	void List<ElementType>::DeleteAllNode(){
		
		ListNode<ElementType> *pSearchNode = m_pHead;
		ListNode<ElementType> *pDeleteNode = {};
		
		while (pSearchNode != nullptr) {
			pDeleteNode = pSearchNode;
			pSearchNode = pSearchNode->pNextNode;
			delete pDeleteNode;
		}
	}


	template <typename ElementType>
	bool List<ElementType>::AddData(const ElementType& data) {
		
		//중복검사+ 데이터가 들어갈 위치 찾아놓기
		ListNode<ElementType> *pSearchNode = m_pHead;
		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;

			if (pSearchNode->data == data) {
				return false;
			}
		}

		ListNode<ElementType> *pAddNode = new ListNode<ElementType>();
		pAddNode->data = data;
		pAddNode->pNextNode = {};

		pSearchNode->pNextNode = pAddNode;

		return true;
	}


	template <typename ElementType>
	bool List<ElementType>::DeleteData(const ElementType& data) {
		
		ListNode<ElementType> *pSearchNode = new ListNode<ElementType>();
		pSearchNode->pNextNode = m_pHead;

		while (pSearchNode->pNextNode != nullptr) {

			if (pSearchNode->pNextNode->data == data) {
				ListNode<ElementType> * pDeleteNode = pSearchNode->pNextNode;
				pSearchNode->pNextNode = pDeleteNode->pNextNode;
				delete pDeleteNode;

				return true;
			}

			pSearchNode = pSearchNode->pNextNode;
		}

		return false;
	}


	template <typename ElementType>
	int List<ElementType>::GetSize() const {
		
		int cnt = 0;

		ListNode<ElementType> *pSearchNode = m_pHead;
		
		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			cnt++;
		}

		return cnt;
	}


	template <typename ElementType>
	void List<ElementType>::PrintData() const {
		
		std::wcout << L"ListData : ";

		ListNode<ElementType> *pSearchNode = m_pHead;
		
		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;

			std::wcout << pSearchNode->data << L"  ";
		}

		std::wcout << L"\n";
	}


	template<typename ElementType>
	void List<ElementType>::Copy(const Base<ElementType>& right){
		
		DeleteAllNode(); //기존에 있는 데이터를 지운다

		m_pHead = new ListNode<ElementType>();		
		const List<ElementType>& original = static_cast<const List<ElementType>&>(right); //다운캐스팅
		
		ListNode<ElementType> *pSearchNode = original.GetHeadPointer();
		
		while (pSearchNode->pNextNode != nullptr) {
			pSearchNode = pSearchNode->pNextNode;
			
			AddData(pSearchNode->data);
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
}