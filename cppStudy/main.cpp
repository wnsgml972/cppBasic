
#include "Stack.h"
#include "DoubleList.h"

#include "Vector.hpp"
#include "List.hpp"
#include "VectorManager.hpp" //템플릿을 사용하려면 cpp를 import 해야 한다?


#include <iostream>
#include <memory>

#include <string>



int main() 
{

	std::wcout.imbue(std::locale("")); //한글 출력 설정
	



	//List 검증

	/*{
		std::unique_ptr<vectorListSpace::Base<int>> test = std::make_unique<vectorListSpace::List<int>>();


		test->AddData(1);
		test->AddData(2);


		test->PrintData();

		std::wcout << "ListSize : " << test->GetSize() << std::endl;



		if (!test->AddData(2)) {
			std::wcout << "입력 실패\n";
		}
		test->DeleteData(2);


		if (!test->DeleteData(2)) {
			std::wcout << "삭제 실패\n";
		}

		test->PrintData();

		std::wcout << "ListSize : " << test->GetSize() << std::endl;


		test->AddData(3);

		test->AddData(5);

		test->PrintData();

		std::wcout << "ListSize : " << test->GetSize() << std::endl;

	}*/


	////Vector 검증
	//{
	//	std::unique_ptr<vectorListSpace::Base> test2 = std::make_unique<vectorListSpace::Vector>();


	//	test2->AddData(1);
	//	test2->AddData(2);
	//	test2->AddData(3);

	//	test2->PrintData();

	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;



	//	if (!test2->AddData(2)) {
	//		std::wcout << "입력 실패\n";
	//	}
	//	test2->DeleteData(2);

	//	

	//	if (!test2->DeleteData(1)) {
	//		std::wcout << "삭제 실패\n";
	//	}

	//	test2->PrintData();

	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;


	//	test2->AddData(2);
	//	
	//	test2->AddData(4);
	//	test2->AddData(5);
	//	test2->AddData(6);
	//	test2->AddData(7);
	//	test2->AddData(8);
	//	test2->AddData(9);
	//	test2->AddData(10);
	//	test2->PrintData();
	//	test2->AddData(11);

	//	test2->PrintData();
	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;

	//	test2->DeleteData(11);
	//	test2->DeleteData(10);
	//	test2->DeleteData(9);

	//	test2->PrintData();
	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;
	//	
	//}



	////stack 검증
	//{
	//	StackSpace::stackPop();
	//	StackSpace::stackPush(1);
	//	StackSpace::stackPush(2);
	//	StackSpace::stackPush(4);
	//	std::wcout << "스택 사이즈 : "<< StackSpace::getSize() << std::endl;
	//	StackSpace::printInformation();

	//	StackSpace::stackPop();
	//	StackSpace::printInformation();

	//	StackSpace::stackPush(7);
	//	StackSpace::stackPush(10);

	//	StackSpace::printInformation();

	//}


	////list 검증
	//{
	//	DoubleListSpace::deleteHead();
	//	DoubleListSpace::addHead(1);
	//	DoubleListSpace::addHead(2);
	//	DoubleListSpace::addHead(4);
	//	DoubleListSpace::printInformation();

	//	DoubleListSpace::deleteTail();
	//	DoubleListSpace::printInformation();

	//	DoubleListSpace::addHead(7);
	//	DoubleListSpace::addTail(10);

	//	DoubleListSpace::printInformation();

	//	DoubleListSpace::deleteHead();
	//	DoubleListSpace::printInformation();

	//}




	////Manager 검증
	{
		// namespace naming snake 소문자_
		vector_list::Base<int> *t1 = new vector_list::List<int>();
		vector_list::Base<int> *t2 = new vector_list::Vector<int>();
		vector_list::Base<int> *t3 = new vector_list::List<int>();
		vector_list::Base<int> *t4 = new vector_list::Vector<int>();
		vector_list::Base<int> *t5 = new vector_list::List<int>();
		vector_list::Base<int> *t6 = new vector_list::Vector<int>();

		std::unique_ptr<manager::DataManager<int>> d1 = std::make_unique<manager::DataManager<int>>();
		//Manager::DataManager<int> d1 = Manager::DataManager<int>();

		

		d1->AddVectorList(t1);
		d1->AddVectorList(t2);
		d1->AddVectorList(t3);
		d1->AddVectorList(t4);
		d1->AddVectorList(t5);
		d1->AddVectorList(t6);

		d1->AddData(1, 1);
		d1->AddData(1, 2);
		d1->AddData(1, 3);
		d1->AddData(2, 1);
		d1->AddData(2, 2);
		d1->AddData(3, 2);
		d1->AddData(4, 1);
		d1->AddData(5, 1);
		d1->AddData(0, 1);
		d1->AddData(3, 1);
		d1->AddData(7, 1);




		std::wcout << "size : " << d1->GetSize() << " \n";
		d1->PrintData();



		*t1 = *t3;
		*t4 = *t2;

		//우선은 int로 들어온다고 가정
		d1->AddVectorListsFromFile(L"test.txt");

		std::wcout << L"size : " << d1->GetSize() << L" \n";
		d1->PrintData();

		d1->PrintDataToFile();

	}



	return 0;

}