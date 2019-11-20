
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

		d1->AddVectorList(t1);
		d1->AddVectorList(t2);
		d1->AddVectorList(t3);
		d1->AddVectorList(t4);
		d1->AddVectorList(t5);
		d1->AddVectorList(t6);

		d1->AddNonDuplicateElementById(1, 1);
		d1->AddNonDuplicateElementById(1, 2);
		d1->AddNonDuplicateElementById(1, 3);
		d1->DeleteElementFromId(1, 1);
		// d1->DeleteElementFromId(1, 4); //고의적 오류 테스트
		// d1->DeleteElementFromId(-1, 4);
		d1->AddNonDuplicateElementById(7, 1);

		std::wcout << "size : " << d1->GetSize() << " \n";
		d1->PrintElement();

		*t4 = *t2;

		d1->AddVectorListsFromFile(L"test.txt");
		std::wcout << L"size : " << d1->GetSize() << L" \n";
		d1->PrintElement();
		d1->CreateFilebyElement(L"test2.txt");

	}


	return 0;

}
