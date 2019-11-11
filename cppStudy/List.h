
#include "BaseVectorList.h"

namespace vectorListSpace {

	template <typename T>
	class Node {
	public:
		// uniform 초기화
		Node *m_nextNode = {};
		T m_data = {};
	};

	template <typename T>
	class List : public BaseVectorList<T> {

	public:
		
		List();
		~List();

		bool AddData(T data);
		bool DeleteData(T data);
		int GetSize() const;

		const void PrintData() const;


	private:
		Node<T> *m_head;

	};





	template <typename T>
	List<T>::List() {
		m_head = new Node<T>();

	}

	template <typename T>
	List<T>::~List() {

		Node<T> *searchNode = m_head;
		Node<T> *tmpNode = nullptr;
		while (searchNode != nullptr) {

			tmpNode = searchNode;

			searchNode = searchNode->m_nextNode;


			delete tmpNode;
		}

	}


	template <typename T>
	bool List<T>::AddData(T data) {


		//중복검사+ 데이터가 들어갈 위치 찾아놓기
		Node<T> *searchNode = m_head;
		while (searchNode->m_nextNode != nullptr) {
			searchNode = searchNode->m_nextNode;
			if (searchNode->m_data == data) {
				return false;
			}
		}



		Node<T> *addNode = new Node<T>();
		addNode->m_data = data;
		addNode->m_nextNode = nullptr;


		searchNode->m_nextNode = addNode;

		return true;
	}

	template <typename T>
	bool List<T>::DeleteData(T data) {

		Node<T> *searchNode = new Node<T>();
		searchNode->m_nextNode = m_head;



		while (searchNode->m_nextNode != nullptr) {

			if (searchNode->m_nextNode->m_data == data) {



				Node<T> * deleteNode = searchNode->m_nextNode;
				searchNode->m_nextNode = deleteNode->m_nextNode;
				delete deleteNode;

				return true;
			}
			searchNode = searchNode->m_nextNode;

		}

		return false;
	}

	template <typename T>
	int List<T>::GetSize() const {
		int cnt = 0;

		Node<T> *searchNode = m_head;
		while (searchNode->m_nextNode != nullptr) {
			searchNode = searchNode->m_nextNode;
			cnt++;
		}
		return cnt;


	}

	template <typename T>
	const void List<T>::PrintData() const {
		std::cout << "ListData : ";

		Node<T> *searchNode = m_head;
		while (searchNode->m_nextNode != nullptr) {
			searchNode = searchNode->m_nextNode;

			std::cout << searchNode->m_data << "  ";

		}

		std::cout << "\n";

	}



}