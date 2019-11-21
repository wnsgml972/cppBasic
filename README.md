# cppBasic
## 총과제 진행 사항 예정
- c++ 교육 진행
  - 기본적인 c++ 교육 진행
  - 개발 환경 구성 : Visual Studio, Visual  등
  - 협업 : 기능 기반 브랜치 사용, 이슈 기반 개발, 코드 리뷰, Clean Code, 코딩 규칙
- MFC 프로젝트
  - 마찬가지로 진행, 지금까지 배운 것들을 활용한 프로젝트 개발 진행
- DB
  - 사내 메모리 DB를 활용한 기본적인 CRUD 개발 진행
- Phase
  - 사내 UI 프레임워크를 통한 UI 개발 및 로직 개발 교육 진행
- Alice UI or CAD
  - UI 엔진 개발자를 위한 Alice UI 개발 혹은
  - CAD 기능 개발을 위한 CAD 개발 교육 진행
- 실무
  - 전체 프로그램의 아키텍쳐 및 개발 철학 교육
  - 기본 디버깅 방법 및 메모리 DB 디버깅 방법 교육
  

## CPP 교육용
> 1. fork하여 feature/start branch에서 자신의 Github ID로 Branch를 만들어 개발 시작
> 2. Issue 생성
> 3. 궁금증 및 발생할 문제들, 기록할 것들 Issue에 기록
> 4. Commit 시 Issue 번호를 걸어 Commit `Commit Title(Issue-Num)`
> 5. Pull Request를 통해 Code Review 진행 (자신의 Github ID branch -> wnsgml972의 자신의 Github ID)

## C++ 기본 : 1차 과제
- C-Style로 구현 (클래스 사용말고, 구조체와 함수 사용)
- DataType int형
- 삽입,삭제 가능해야함
- Stack 구현 함수 : Push, Pop, SetSize
- List 구현 함수 : AddHead, AddTail, DeleteHead, DeleteTail)
- PrintInfomation - 전체 정보 출력 함수 제공"

<br/>

## 함수 메모리 클래스 기본 : 2차 과제 (C->C++로 변경)
### 조건
1. C++ Style Casting 사용 - static_cast, dynamic_cast 등등
2. auto, decltype(auto) 사용 - 데이터 입력때 사용해보자
3. 스마트 포인터 사용 - main.cpp 구현시 사용해보자
4. 람다 사용해보기 - 필수 아님, unique pointer에 소멸자 오버라이딩
### Vector/List 클래스 구현
- DataType int형
- namespace 사용
- 가변으로 데이터를 삽입가능해야함
- Add : 동일한 데이터가 있으면 Add 실패
- Delete : 동일한 데이터가 없으면 Delete 실패
- GetSize : 현재 데이터 개수 반환
- PrintData : 현재 데이터 정보를 표준 출력으로 출력
- 삽입되는 데이터를 표준 입력으로 받음 (유니코드 형식)
- 변수는 private, 함수는 public
- 상속을 통해 기반 클래스는 동일하게 구현
### DataManager 클래스 구현
- 생성/삭제되는 Vector/List 정보를 관리
- GetSize - 전체 자료구조의 갯수를 반환
- PrintInfomation - 전체 자료구조의 정보 출력

### Reference
* <https://github.com/wnsgml972/midas_log/blob/master/contents/BasicEducation/CppBasic.md>


<br/>

## Vector/List 템플릿 구현 : 3차 과제
- 전날 구현한 클래스 템플릿화
- 파일 입력을 활용한 데이터 삽입 기능
- 파일 출력을 통한 데이터 정보 출력 기능
- 연산자 오버로딩 구현 - 대입연산자

## MFC 프로젝트 : 4차 과제
- 해당 기능을 포함한 UI가 있는 프로젝트 진행하기
- 해당 UI는 다음과 같지만 어떤 것이든 기능을 포함한 경우에 UI는 상관없음
- Reference <https://github.com/wnsgml972/MFCPhoneBook>

