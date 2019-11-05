
#include "vector.h"
#include <iostream>
#include <memory>




int main() 
{

	std::unique_ptr<vectorNameSpace::Vector> test = std::make_unique<vectorNameSpace::Vector>();
	
	
	test->AddData(1);
	test->AddData(2);


	test->PrintData();

	std::cout<<"vectorSize : "<<test->GetSize()<<std::endl;



	if (!test->AddData(2)) {
		std::cout << "입력 실패\n";
	}
	test->DeleteData(2);
	

	if(!test->DeleteData(2)) {
		std::cout << "삭제 실패\n";
	}
	
	test->PrintData();

	std::cout << "vectorSize : " << test->GetSize() << std::endl;

	
	test->AddData(3);

	test->AddData(5);

	test->PrintData();

	std::cout << "vectorSize : " << test->GetSize() << std::endl;

	


	// DataManager 예제
	{
		// std::smart_pointer<DataManager> dataManager = std::make_shared<DataManager>();
		// dataManager->CreateVector(std::make_shared<V>()); 1
		// dataManager->CreateVector(std::make_shared<V>()); 2  4
		// dataManager->CreateVector(std::make_shared<V>()); 3

		// dataManager->Append(2, 4); id, data

		// dataManager->PrintData(); 

		// if(dataManager->Delete(2, 3) ;

		// dataManager->PrintData(); 
	}

	// Next DataManager Template 예제
	{
		// double
		// std::smart_pointer<DataManager> dataManager = std::make_shared<DataManager>();
		// dataManager->CreateVector(std::make_shared<V>()); 1
		// dataManager->CreateVector(std::make_shared<V>()); 2  4
		// dataManager->CreateVector(std::make_shared<V>()); 3

		// dataManager->Append(2, 4.3); id, data

		// dataManager->PrintData(); 

		// if(dataManager->Delete(2, 3.2) ;

		// dataManager->PrintData(); 

		// int
		// std::smart_pointer<DataManager> dataManager = std::make_shared<DataManager>();
		// dataManager->CreateVector(std::make_shared<V>()); 1
		// dataManager->CreateVector(std::make_shared<V>()); 2  4
		// dataManager->CreateVector(std::make_shared<V>()); 3

		// dataManager->Append(2, 4); id, data

		// dataManager->PrintData(); 

		// if(dataManager->Delete(2, 3) ;

		// dataManager->PrintData(); 
	}
}