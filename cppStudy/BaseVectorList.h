#pragma once
namespace vectorListSpace {


	class BaseVectorList {



	public:

		BaseVectorList();
		virtual ~BaseVectorList();

		virtual bool AddData(int data);
		virtual bool DeleteData(int data);
		virtual int GetSize();

		virtual const void PrintData();


	private:
		
	};




}