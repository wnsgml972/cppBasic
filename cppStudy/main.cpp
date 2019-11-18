
#include "Stack.h"
#include "DoubleList.h"

#include "Vector.hpp"
#include "List.hpp"
#include "Manager.hpp" 

#include <iostream>
#include <memory>
#include <string>
#include <optional>



int main() 
{

	std::wcout.imbue(std::locale("")); //한글 출력 설정
	



	//List 검증

	/*{
		std::unique_ptr<vectorListSpace::Base<int>> test = std::make_unique<vectorListSpace::List<int>>();


		test->AddElement(1);
		test->AddElement(2);


		test->PrintElement();

		std::wcout << "ListSize : " << test->GetSize() << std::endl;



		if (!test->AddElement(2)) {
			std::wcout << "입력 실패\n";
		}
		test->DeleteElement(2);


		if (!test->DeleteElement(2)) {
			std::wcout << "삭제 실패\n";
		}

		test->PrintElement();

		std::wcout << "ListSize : " << test->GetSize() << std::endl;


		test->AddElement(3);

		test->AddElement(5);

		test->PrintElement();

		std::wcout << "ListSize : " << test->GetSize() << std::endl;

	}*/


	////Vector 검증
	//{
	//	std::unique_ptr<vectorListSpace::Base> test2 = std::make_unique<vectorListSpace::Vector>();


	//	test2->AddElement(1);
	//	test2->AddElement(2);
	//	test2->AddElement(3);

	//	test2->PrintElement();

	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;



	//	if (!test2->AddElement(2)) {
	//		std::wcout << "입력 실패\n";
	//	}
	//	test2->DeleteElement(2);

	//	

	//	if (!test2->DeleteElement(1)) {
	//		std::wcout << "삭제 실패\n";
	//	}

	//	test2->PrintElement();

	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;


	//	test2->AddElement(2);
	//	
	//	test2->AddElement(4);
	//	test2->AddElement(5);
	//	test2->AddElement(6);
	//	test2->AddElement(7);
	//	test2->AddElement(8);
	//	test2->AddElement(9);
	//	test2->AddElement(10);
	//	test2->PrintElement();
	//	test2->AddElement(11);

	//	test2->PrintElement();
	//	std::wcout << "VectorSize : " << test2->GetSize() << std::endl;

	//	test2->DeleteElement(11);
	//	test2->DeleteElement(10);
	//	test2->DeleteElement(9);

	//	test2->PrintElement();
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

		std::unique_ptr<manager::ElementManager<int>> d1 = std::make_unique<manager::ElementManager<int>>();
		//Manager::ElementManager<int> d1 = Manager::ElementManager<int>();

		

		d1->AddVectorList(t1);
		d1->AddVectorList(t2);
		d1->AddVectorList(t3);
		d1->AddVectorList(t4);
		d1->AddVectorList(t5);
		d1->AddVectorList(t6);

		d1->AddElement(1, 1);
		d1->AddElement(1, 2);
		d1->AddElement(1, 3);
		d1->DeleteElement(1, 1);
		d1->AddElement(2, 1);
		d1->AddElement(2, 2);
		d1->AddElement(3, 2);
		d1->AddElement(4, 1);
		d1->AddElement(5, 1);
		d1->AddElement(0, 1);
		d1->AddElement(3, 1);
		d1->AddElement(7, 1);




		std::wcout << "size : " << d1->GetSize() << " \n";
		d1->PrintElement();



		*t1 = *t3;
		*t4 = *t2;

		//우선은 int로 들어온다고 가정
		d1->AddVectorListsFromFile(L"test.txt");

		std::wcout << L"size : " << d1->GetSize() << L" \n";
		d1->PrintElement();

		d1->PrintElementToFile();

	}


	return 0;

}
