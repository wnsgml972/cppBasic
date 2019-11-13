
#include "Base.hpp"

namespace VectorList {

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

		bool AddData(const ElementType& data);
		bool DeleteData(const ElementType& data);
		int GetSize() const;
		void PrintData() const;

		void Copy(Base<ElementType>* right);

		virtual List<ElementType>& operator=(List<ElementType>& right);
		ListNode<ElementType>* GetHead() const;
		
		
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


	template <typename ElementType>
	bool List<ElementType>::AddData(const ElementType& data) {


		//중복검사+ 데이터가 들어갈 위치 찾아놓기
		ListNode<ElementType> *searchNode = m_pHead;
		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;
			if (searchNode->data == data) {
				return false;
			}
		}



		ListNode<ElementType> *addNode = new ListNode<ElementType>();
		addNode->data = data;
		addNode->pNextNode = {};


		searchNode->pNextNode = addNode;

		return true;
	}

	template <typename ElementType>
	bool List<ElementType>::DeleteData(const ElementType& data) {

		ListNode<ElementType> *searchNode = new ListNode<ElementType>();
		searchNode->pNextNode = m_pHead;



		while (searchNode->pNextNode != nullptr) {

			if (searchNode->pNextNode->data == data) {



				ListNode<ElementType> * deleteNode = searchNode->pNextNode;
				searchNode->pNextNode = deleteNode->pNextNode;
				delete deleteNode;

				return true;
			}
			searchNode = searchNode->pNextNode;

		}

		return false;
	}

	template <typename ElementType>
	int List<ElementType>::GetSize() const {
		int cnt = 0;

		ListNode<ElementType> *searchNode = m_pHead;
		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;
			cnt++;
		}
		return cnt;


	}

	template <typename ElementType>
	void List<ElementType>::PrintData() const {
		std::cout << "ListData : ";

		ListNode<ElementType> *searchNode = m_pHead;
		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;

			std::cout << searchNode->data << "  ";

		}

		std::cout << "\n";

	}

	template<typename ElementType>
	void List<ElementType>::Copy(Base<ElementType>* right)
	{
		DeleteAllNode(); //기존에 있는 데이터를 지운다


		m_pHead = new ListNode<ElementType>();
		
		List<ElementType> *original = static_cast<List<ElementType>* >(right); //다운캐스팅



		ListNode<ElementType> *searchNode = original->GetHead();

		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;

			AddData(searchNode->data);
		}
	}





	template<typename ElementType>
	ListNode<ElementType>* List<ElementType>::GetHead() const
	{
		return m_pHead;
	
	}



	template<typename ElementType>
	List<ElementType>& List<ElementType>::operator=(List<ElementType>& right)
	{
		Copy(&right);
		return *this;
	}


	template<typename ElementType>
	void List<ElementType>::DeleteAllNode()
	{
		ListNode<ElementType> *searchNode = m_pHead;
		ListNode<ElementType> *tmpNode = {};
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->pNextNode;


			delete tmpNode;
		}
	}


}