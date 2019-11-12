
#include "Base.h"

namespace VectorList {

	template <typename T>
	struct ListNode {
		T data = {};
		ListNode *pNextNode = {};
	};

	template <typename T>
	class List : public Base<T> {

	public:
		
		List();
		~List();

		bool AddData(const T& data);
		bool DeleteData(const T& data);
		int GetSize() const;

		void PrintData() const;


	private:
		ListNode<T> *m_pHead;

	};





	template <typename T>
	List<T>::List() {
		m_pHead = new ListNode<T>();

	}

	template <typename T>
	List<T>::~List() {

		ListNode<T> *searchNode = m_pHead;
		ListNode<T> *tmpNode = {};
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->pNextNode;


			delete tmpNode;
		}

	}


	template <typename T>
	bool List<T>::AddData(const T& data) {


		//중복검사+ 데이터가 들어갈 위치 찾아놓기
		ListNode<T> *searchNode = m_pHead;
		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;
			if (searchNode->data == data) {
				return false;
			}
		}



		ListNode<T> *addNode = new ListNode<T>();
		addNode->data = data;
		addNode->pNextNode = {};


		searchNode->pNextNode = addNode;

		return true;
	}

	template <typename T>
	bool List<T>::DeleteData(const T& data) {

		ListNode<T> *searchNode = new ListNode<T>();
		searchNode->pNextNode = m_pHead;



		while (searchNode->pNextNode != nullptr) {

			if (searchNode->pNextNode->data == data) {



				ListNode<T> * deleteNode = searchNode->pNextNode;
				searchNode->pNextNode = deleteNode->pNextNode;
				delete deleteNode;

				return true;
			}
			searchNode = searchNode->pNextNode;

		}

		return false;
	}

	template <typename T>
	int List<T>::GetSize() const {
		int cnt = 0;

		ListNode<T> *searchNode = m_pHead;
		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;
			cnt++;
		}
		return cnt;


	}

	template <typename T>
	void List<T>::PrintData() const {
		std::cout << "ListData : ";

		ListNode<T> *searchNode = m_pHead;
		while (searchNode->pNextNode != nullptr) {
			searchNode = searchNode->pNextNode;

			std::cout << searchNode->data << "  ";

		}

		std::cout << "\n";

	}



}