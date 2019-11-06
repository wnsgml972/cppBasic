
#include "List.h"
#include "Vector.h"
#include <iostream>
#include <memory>


int main() 
{

	{
		std::unique_ptr<vectorListSpace::BaseVectorList> test = std::make_unique<vectorListSpace::List>();


		test->AddData(1);
		test->AddData(2);


		test->PrintData();

		std::cout << "ListSize : " << test->GetSize() << std::endl;



		if (!test->AddData(2)) {
			std::cout << "입력 실패\n";
		}
		test->DeleteData(2);


		if (!test->DeleteData(2)) {
			std::cout << "삭제 실패\n";
		}

		test->PrintData();

		std::cout << "ListSize : " << test->GetSize() << std::endl;


		test->AddData(3);

		test->AddData(5);

		test->PrintData();

		std::cout << "ListSize : " << test->GetSize() << std::endl;

	}
	
	{
		std::unique_ptr<vectorListSpace::BaseVectorList> test2 = std::make_unique<vectorListSpace::Vector>();


		test2->AddData(1);
		test2->AddData(2);
		test2->AddData(3);

		test2->PrintData();

		std::cout << "VectorSize : " << test2->GetSize() << std::endl;



		if (!test2->AddData(2)) {
			std::cout << "입력 실패\n";
		}
		test2->DeleteData(2);

		

		if (!test2->DeleteData(2)) {
			std::cout << "삭제 실패\n";
		}

		test2->PrintData();

		std::cout << "VectorSize : " << test2->GetSize() << std::endl;


		test2->AddData(2);
		
		test2->AddData(4);
		test2->AddData(5);
		test2->AddData(6);
		test2->AddData(7);
		test2->AddData(8);
		test2->AddData(9);
		test2->AddData(10);
		test2->PrintData();
		test2->AddData(11);

		test2->PrintData();
		std::cout << "VectorSize : " << test2->GetSize() << std::endl;

		test2->DeleteData(11);
		test2->DeleteData(10);
		test2->DeleteData(9);

		test2->PrintData();
		std::cout << "VectorSize : " << test2->GetSize() << std::endl;
		
	}
	return 0;

}