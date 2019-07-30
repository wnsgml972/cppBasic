
//#include "VectorManager.h"
#include "VectorTemplate.h"
#include <string>

void PrintMessage(std::string msg)
{	
	std::cout << msg << std::endl;
}

int main() 
{
	//Vector Template Test Code
	{
		std::unique_ptr<VectorSpace::VectorManager<int>> vectorTemplate = std::make_unique<VectorSpace::VectorManager<int>>();
		std::unique_ptr<VectorSpace::VectorManager<double>> vectorTemplate2 = std::make_unique<VectorSpace::VectorManager<double>>();

		//Initial 3 integer Vector
		{
			vectorTemplate->PrintInformation();
			vectorTemplate->CreateVector(std::make_shared<VectorSpace::Vector<int>>());
			vectorTemplate->PrintInformation();
			vectorTemplate->CreateVector(std::make_shared<VectorSpace::Vector<int>>());
			vectorTemplate->PrintInformation();
			vectorTemplate->CreateVector(std::make_shared<VectorSpace::Vector<int>>());
			vectorTemplate->PrintInformation();
		}
		
		// Invalid
		{
			if (auto check = vectorTemplate->Append(4, 5); !check)
				PrintMessage("No ID");

			// vectorManager->Append(0, 5); // Invalid ID는 0초과 assert
		}

		// ID : 1 Append Integer Vector
		{
			vectorTemplate->Append(1, 5);
			vectorTemplate->Append(1, 7);
			vectorTemplate->Append(1, 10);
			vectorTemplate->PrintInformation();
		}
		

		// ID : 2 Append Integer Vector
		{
			vectorTemplate->Append(2, 5);
			vectorTemplate->PrintInformation();
		}

		// ID : 3 Append Integer Vector
		{
			vectorTemplate->Append(3, 555);
			vectorTemplate->PrintInformation();
		}

		

		// Delete Data In Vector
		{
			if (auto check = vectorTemplate->DeleteDataInVector(3, 5); !check)
				PrintMessage("No Data");
			vectorTemplate->PrintInformation();

			if (auto check = vectorTemplate->DeleteDataInVector(3, 555); check)
				PrintMessage("Delete Data Success");
			vectorTemplate->PrintInformation();
		}

		// Delete Vector
		{
			if (auto check = vectorTemplate->DeleteVector(5); !check)
				PrintMessage("Delete Vector Fail");

			if (auto check = vectorTemplate->DeleteVector(1); check)
				PrintMessage("Delete Vector Success");
			if (auto check = vectorTemplate->DeleteVector(2); check)
				PrintMessage("Delete Vector Success");
			if (auto check = vectorTemplate->DeleteVector(3); check)
				PrintMessage("Delete Vector Success");
			vectorTemplate->PrintInformation();
		}

		//Initial 3 Double Vector
		{
			PrintMessage("----------Apeend Double Data--------------");
			vectorTemplate2->PrintInformation();
			vectorTemplate2->CreateVector(std::make_shared<VectorSpace::Vector<double>>());
			vectorTemplate2->PrintInformation();
			vectorTemplate2->CreateVector(std::make_shared<VectorSpace::Vector<double>>());
			vectorTemplate2->PrintInformation();
			vectorTemplate2->CreateVector(std::make_shared<VectorSpace::Vector<double>>());
			vectorTemplate2->PrintInformation();
		}
		// ID : 4 Append Double Vector
		{
			vectorTemplate2->Append(1, 1.5);
			vectorTemplate2->Append(1, 7.4);
			vectorTemplate2->Append(1, 10.234);
			vectorTemplate2->PrintInformation();
		}
	}


	/*
	//Vector,List DataManager Test Code
	{
		std::unique_ptr<VectorSpace::VectorManager> vectorManager = std::make_unique<VectorSpace::VectorManager>();

		// Initial 3 Vector
		{
			vectorManager->PrintInformation();
			vectorManager->CreateVector(std::make_shared<VectorSpace::Vector>());
			vectorManager->PrintInformation();
			vectorManager->CreateVector(std::make_shared<VectorSpace::Vector>());
			vectorManager->PrintInformation();
			vectorManager->CreateVector(std::make_shared<VectorSpace::Vector>());
			vectorManager->PrintInformation();
		}


		// Invalid
		{
			if (auto check = vectorManager->Append(4, 5); !check)
				PrintMessage("No ID");

			// vectorManager->Append(0, 5); // Invalid ID는 0초과 assert
		}


		// ID : 1 Append
		{
			vectorManager->Append(1, 5);
			vectorManager->Append(1, 7);
			vectorManager->Append(1, 10);
			vectorManager->PrintInformation();
		}

		// ID : 2 Append
		{
			vectorManager->Append(2, 5);
			vectorManager->PrintInformation();
		}

		// ID : 3 Append
		{
			vectorManager->Append(3, 555);
			vectorManager->PrintInformation();
		}


		// Delete Data In Vector
		{
			if (auto check = vectorManager->DeleteDataInVector(3, 5); !check)
				PrintMessage("No Data");
			vectorManager->PrintInformation();

			if (auto check = vectorManager->DeleteDataInVector(3, 555); check)
				PrintMessage("Delete Data Success");
			vectorManager->PrintInformation();
		}

		// Delete Vector
		{
			if (auto check = vectorManager->DeleteVector(5); !check)
				PrintMessage("Delete Vector Fail");

			if (auto check = vectorManager->DeleteVector(1); check)
				PrintMessage("Delete Vector Success");
			if (auto check = vectorManager->DeleteVector(2); check)
				PrintMessage("Delete Vector Success");
			if (auto check = vectorManager->DeleteVector(3); check)
				PrintMessage("Delete Vector Success");
			vectorManager->PrintInformation();
		}

	}
	*/

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