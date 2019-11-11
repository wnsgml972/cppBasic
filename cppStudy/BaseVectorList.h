#pragma once
namespace vectorListSpace {

	template <typename T>
	class BaseVectorList {



	public:

		BaseVectorList();
		virtual ~BaseVectorList();

		virtual bool AddData(T data);
		virtual bool DeleteData(T data);
		virtual int GetSize();

		virtual const void PrintData() const;


	private:
		
	};



	template <typename T>
	BaseVectorList<T>::BaseVectorList()
	{
	}

	template <typename T>
	BaseVectorList<T>::~BaseVectorList()
	{
	}

	template <typename T>
	bool BaseVectorList<T>::AddData(T data)
	{
		return false;
	}

	template <typename T>
	bool BaseVectorList<T>::DeleteData(T data)
	{
		return false;
	}

	template <typename T>
	int BaseVectorList<T>::GetSize()
	{
		return 0;
	}

	template <typename T>
	const void BaseVectorList<T>::PrintData() const
	{
		return void();
	}



}