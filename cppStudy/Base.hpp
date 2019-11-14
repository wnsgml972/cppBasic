#pragma once
namespace vector_list{

	template <typename ElementType>
	class Base {

	public:

		virtual ~Base() {};

		virtual bool AddData(const ElementType& data) = 0;
		virtual bool DeleteData(const ElementType& data) = 0;
		virtual int GetSize() const = 0;
		virtual void PrintData() const = 0;
		
		virtual void Copy(const Base<ElementType>& right) = 0;
		virtual Base<ElementType>& operator=(Base<ElementType>& right);
		
		bool AddDataUsingStdInput();


	private:
		
	};


	template<typename ElementType>
	bool Base<ElementType>::AddDataUsingStdInput(){
		ElementType inputData;

		std::wcout << L"입력 데이터 ";
		std::wcin >> inputData; //오류처리 안함

		return AddData(inputData);
	}


	template<typename ElementType>
	Base<ElementType>& Base<ElementType>::operator=(Base & right){
		Copy(right);

		return *this;
	}

}