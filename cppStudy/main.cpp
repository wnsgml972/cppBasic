
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
		std::unique_ptr<VectorSpace::VectorManager<int>> vectorManagerForIntType = std::make_unique<VectorSpace::VectorManager<int>>();

		//Initial 3 integer Vector
		{
			vectorManagerForIntType->PrintInformation();
			vectorManagerForIntType->CreateVector(std::make_shared<VectorSpace::Vector<int>>());
			vectorManagerForIntType->PrintInformation();
			vectorManagerForIntType->CreateVector(std::make_shared<VectorSpace::Vector<int>>());
			vectorManagerForIntType->PrintInformation();
			vectorManagerForIntType->CreateVector(std::make_shared<VectorSpace::Vector<int>>());
			vectorManagerForIntType->PrintInformation();
		}
		
		// Invalid
		{
			if (auto check = vectorManagerForIntType->Append(4, 5); !check)
				PrintMessage("No ID");

			// vectorManager->Append(0, 5); // Invalid ID´Â 0ÃÊ°ú assert
		}

		// ID : 1 Append Integer Vector
		{
			vectorManagerForIntType->Append(1, 5);
			vectorManagerForIntType->Append(1, 7);
			vectorManagerForIntType->Append(1, 10);
			vectorManagerForIntType->PrintInformation();
		}
		

		// ID : 2 Append Integer Vector
		{
			vectorManagerForIntType->Append(2, 5);
			vectorManagerForIntType->PrintInformation();
		}

		// ID : 3 Append Integer Vector
		{
			vectorManagerForIntType->Append(3, 555);
			vectorManagerForIntType->PrintInformation();
		}

		// Delete Data In Vector
		{
			if (auto check = vectorManagerForIntType->DeleteDataInVector(3, 5); !check)
				PrintMessage("No Data");
			vectorManagerForIntType->PrintInformation();

			if (auto check = vectorManagerForIntType->DeleteDataInVector(3, 555); check)
				PrintMessage("Delete Data Success");
			vectorManagerForIntType->PrintInformation();
		}

		// Delete Vector
		{
			if (auto check = vectorManagerForIntType->DeleteVector(5); !check)
				PrintMessage("Delete Vector Fail");

			if (auto check = vectorManagerForIntType->DeleteVector(1); check)
				PrintMessage("Delete Vector Success");
			if (auto check = vectorManagerForIntType->DeleteVector(2); check)
				PrintMessage("Delete Vector Success");
			if (auto check = vectorManagerForIntType->DeleteVector(3); check)
				PrintMessage("Delete Vector Success");
			vectorManagerForIntType->PrintInformation();
		}


		std::unique_ptr<VectorSpace::VectorManager<double>> vectorManagerForDoubleType = std::make_unique<VectorSpace::VectorManager<double>>();
		//Initial 3 Double Vector
		{
			PrintMessage("----------Apeend Double Data--------------");
			vectorManagerForDoubleType->PrintInformation();
			vectorManagerForDoubleType->CreateVector(std::make_shared<VectorSpace::Vector<double>>());
			vectorManagerForDoubleType->PrintInformation();
			vectorManagerForDoubleType->CreateVector(std::make_shared<VectorSpace::Vector<double>>());
			vectorManagerForDoubleType->PrintInformation();
			vectorManagerForDoubleType->CreateVector(std::make_shared<VectorSpace::Vector<double>>());
			vectorManagerForDoubleType->PrintInformation();
		}
		// ID : 4 Append Double Vector
		{
			vectorManagerForDoubleType->Append(1, 1.5);
			vectorManagerForDoubleType->Append(1, 7.4);
			vectorManagerForDoubleType->Append(1, 10.234);
			vectorManagerForDoubleType->PrintInformation();
		}
	}
}