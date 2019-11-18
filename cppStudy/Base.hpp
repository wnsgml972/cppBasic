#pragma once
#include <string>

namespace vector_list{

	template <typename ElementType>
	class Base {

	public:
		Base() = default;
		virtual ~Base() = default;

		virtual bool AddElement(const ElementType& element) = 0;
		virtual bool DeleteElement(const ElementType& element) = 0;
		virtual const int GetSize() const = 0;
		virtual void PrintElement() const = 0;
		virtual Base<ElementType>& operator=(Base<ElementType>& right);
		virtual void Copy(const Base<ElementType>& right) = 0;
		virtual std::wstring GetElementListToWstring() = 0;

		bool AddElementUsingStdInput();
	};


	template<typename ElementType>
	bool Base<ElementType>::AddElementUsingStdInput(){
		ElementType inputElement;

		std::wcout << L"입력 데이터 ";
		std::wcin >> inputElement; //오류처리 안함

		return AddElement(inputElement);
	}


	template<typename ElementType>
	Base<ElementType>& Base<ElementType>::operator=(Base & right){
		Copy(right);

		return *this;
	}

}