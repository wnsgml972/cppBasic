#pragma once
namespace VectorList{

	template <typename T>
	class Base {



	public:

		Base();
		virtual ~Base();

		virtual bool AddData(const T& data);
		virtual bool DeleteData(const T& data);
		virtual int GetSize() const;

		virtual void PrintData() const;


	private:
		
	};



	template <typename T>
	Base<T>::Base()
	{
	}

	template <typename T>
	Base<T>::~Base()
	{
	}

	template <typename T>
	bool Base<T>::AddData(const T& data)
	{
		return false;
	}

	template <typename T>
	bool Base<T>::DeleteData(const T& data)
	{
		return false;
	}

	template <typename T>
	int Base<T>::GetSize() const
	{
		return 0;
	}

	template <typename T>
	void Base<T>::PrintData() const
	{
		return void();
	}



}