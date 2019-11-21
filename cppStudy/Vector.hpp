#include "Base.hpp"
#include <iostream>
#include <algorithm>
#include <optional>

namespace vector_list {
	constexpr int STANDARD_ELEMENT_ARRAY_SIZE = 10;


	template <typename ElementType>
	class Vector : public Base<ElementType> {

	public:
		Vector();
		virtual ~Vector() override;

		virtual bool AddNonDuplicateElement(const ElementType& element) override;
		virtual void DeleteElement(const ElementType& element) override;
		virtual const int GetSize() const override;
		virtual void PrintElement() const override;
		virtual void Copy(const Base<ElementType>& right) override;
		virtual std::wstring GetElementListToWstring() override;

		Vector<ElementType>& operator=(Vector<ElementType>& right);
	private:
		const std::optional<int> GetElementIndex(const ElementType& element) const;
		std::optional<ElementType> GetElement(const int& index) const;
		const void AutoControlElementSize();
		const void ShiftLeftElementAfterIndex(const int& index);

		int m_arrayElementSize = {};
		int m_cnt = {};
		ElementType *m_pElement;
	};


	template <typename ElementType>
	Vector<ElementType>::Vector(){
		m_pElement = new ElementType[STANDARD_ELEMENT_ARRAY_SIZE];
		m_arrayElementSize = STANDARD_ELEMENT_ARRAY_SIZE;
		m_cnt = 0;
	}


	template <typename ElementType>
	Vector<ElementType>::~Vector(){
		if(m_pElement) free(m_pElement);
	}


	template <typename ElementType>
	bool Vector<ElementType>::AddNonDuplicateElement(const ElementType& element) {
		
		if (GetElementIndex(element).has_value()) {
			return false;
		}
		m_pElement[m_cnt] = element;
		m_cnt++;

		AutoControlElementSize();
		return true;
	}


	template <typename ElementType>
	void Vector<ElementType>::DeleteElement(const ElementType& element) {
		const std::optional<int> indexOptional = GetElementIndex(element);
		if (!indexOptional.has_value()) {
			assert(0);
		}
		int index = indexOptional.value();

		ShiftLeftElementAfterIndex(index);
		m_cnt--;

		AutoControlElementSize(); 
	}


	template <typename ElementType>
	const int Vector<ElementType>::GetSize() const{
		return m_cnt;
	}


	template <typename ElementType>
	void Vector<ElementType>::PrintElement() const{
		std::wcout << L"VectorElement : ";
		//람다사용해보기
		std::for_each(m_pElement, &m_pElement[m_cnt], [](int& number) {
			std::wcout << number << L"  ";
		});
		std::wcout << L"\n";
	}


	template<typename ElementType>
	Vector<ElementType>& Vector<ElementType>::operator=(Vector & right) {
		Copy(right);
		return *this;
	}


	template<typename ElementType>
	void Vector<ElementType>::Copy(const Base<ElementType>& right) {
		if (m_pElement) {
			free(m_pElement);
		}
		
		m_pElement = new ElementType[STANDARD_ELEMENT_ARRAY_SIZE];
		m_cnt = 0;

		const Vector<ElementType>& original = static_cast<const Vector<ElementType>&>(right); //다운캐스팅

		for (int i = 0; i < original.GetSize(); i++) {
			AddNonDuplicateElement(original.GetElement(i).value());
		}
	}


	template<typename ElementType>
	std::wstring Vector<ElementType>::GetElementListToWstring() {
		std::wstring text = L"vector:";
		for (int i = 0; i < m_cnt; i++) {
			text += std::to_wstring(m_pElement[i]) + L",";
		}

		return text.substr(0, text.length() - 1);
	}


	template <typename ElementType>
	const std::optional<int> Vector<ElementType>::GetElementIndex(const ElementType& element) const {
		for (int i = 0; i < m_cnt; i++) {
			if (m_pElement[i] == element) {
				return i;
			}
		}
		return {};
	}


	template<typename ElementType>
	std::optional<ElementType> Vector<ElementType>::GetElement(const int & index) const {
		if (index < 0 || index >= m_cnt) {
			return {};
		}
		
		return m_pElement[index];
	}


	template <typename ElementType>
	const void Vector<ElementType>::AutoControlElementSize() {
		if (m_arrayElementSize == m_cnt) {
			m_arrayElementSize += STANDARD_ELEMENT_ARRAY_SIZE;
		}
		else if (m_arrayElementSize - STANDARD_ELEMENT_ARRAY_SIZE - 1 == m_cnt) {
			m_arrayElementSize -= STANDARD_ELEMENT_ARRAY_SIZE;
		}

		m_pElement = (ElementType *)realloc(m_pElement, sizeof(ElementType) * m_arrayElementSize);
	}


	template <typename ElementType>
	const void Vector<ElementType>::ShiftLeftElementAfterIndex(const int& index) {
		if (index < 0 || index >= m_cnt) {
			assert(0);
		}

		for (int i = index; i < m_cnt - 1; i++) {
			m_pElement[i] = m_pElement[i + 1];
		}
		m_pElement[m_cnt - 1] = {};
	}
}