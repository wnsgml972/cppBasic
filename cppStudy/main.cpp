
#include "List.h"
#include "Vector.h"
#include "Stack.h"
#include "DoubleList.h"

#include <iostream>
#include <memory>





int main() 
{
	//List 검증

	//{
	//	std::unique_ptr<vectorListSpace::BaseVectorList> test = std::make_unique<vectorListSpace::List>();


	//	test->AddData(1);
	//	test->AddData(2);


	//	test->PrintData();

	//	std::cout << "ListSize : " << test->GetSize() << std::endl;



	//	if (!test->AddData(2)) {
	//		std::cout << "입력 실패\n";
	//	}
	//	test->DeleteData(2);


	//	if (!test->DeleteData(2)) {
	//		std::cout << "삭제 실패\n";
	//	}

	//	test->PrintData();

	//	std::cout << "ListSize : " << test->GetSize() << std::endl;


	//	test->AddData(3);

	//	test->AddData(5);

	//	test->PrintData();

	//	std::cout << "ListSize : " << test->GetSize() << std::endl;

	//}
	//

	////Vector 검증
	//{
	//	std::unique_ptr<vectorListSpace::BaseVectorList> test2 = std::make_unique<vectorListSpace::Vector>();


	//	test2->AddData(1);
	//	test2->AddData(2);
	//	test2->AddData(3);

	//	test2->PrintData();

	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;



	//	if (!test2->AddData(2)) {
	//		std::cout << "입력 실패\n";
	//	}
	//	test2->DeleteData(2);

	//	

	//	if (!test2->DeleteData(2)) {
	//		std::cout << "삭제 실패\n";
	//	}

	//	test2->PrintData();

	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;


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
	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;

	//	test2->DeleteData(11);
	//	test2->DeleteData(10);
	//	test2->DeleteData(9);

	//	test2->PrintData();
	//	std::cout << "VectorSize : " << test2->GetSize() << std::endl;
	//	
	//}



	////stack 검증
	//{
	//	StackSpace::stackPop();
	//	StackSpace::stackPush(1);
	//	StackSpace::stackPush(2);
	//	StackSpace::stackPush(4);
	//	std::cout << "스택 사이즈 : "<< StackSpace::getSize() << std::endl;
	//	StackSpace::printInformation();

	//	StackSpace::stackPop();
	//	StackSpace::printInformation();

	//	StackSpace::stackPush(7);
	//	StackSpace::stackPush(10);

	//	StackSpace::printInformation();

	//}


	//list 검증
	{
		DoubleListSpace::deleteHead();
		DoubleListSpace::addHead(1);
		DoubleListSpace::addHead(2);
		DoubleListSpace::addHead(4);
		DoubleListSpace::printInformation();

		DoubleListSpace::deleteTail();
		DoubleListSpace::printInformation();

		DoubleListSpace::addHead(7);
		DoubleListSpace::addTail(10);

		DoubleListSpace::printInformation();

		DoubleListSpace::deleteHead();
		DoubleListSpace::printInformation();

	}




	return 0;

}