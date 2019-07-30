# cppBasic
CPP 교육용

> 1. Issue 생성
> 2. 궁금증 및 발생할 문제들 기록할 것들 Issue에 기록
> 3. Commit 시 Issue 걸어 Commit `Commit Title(Issue-Num)`
> 4. 자신의 Github ID로 Branch를 만들고 Pull Request를 통해 개발 진행


## C++ 기본
- C-Style로 구현 (클래스 사용말고, 구조체와 함수 사용)
- DataType int형
- 삽입,삭제 가능해야함
- Stack 구현 함수 : Push, Pop, SetSize
- List 구현 함수 : AddHead, AddTail, DeleteHead, DeleteTail)
- PrintInfomation - 전체 정보 출력 함수 제공"

<br/>

## 함수 메모리 클래스 기본
### 조건
1. C++ Style Casting 사용
2. auto, decltype(auto) 사용
3. 스마트 포인터 사용
4. 람다 사용해보기
### Vector/List 클래스 구현
- DataType int형
- namespace 사용
- 가변으로 데이터를 삽입가능해야함
- Add : 동일한 데이터가 있으면 Add 실패
- Delete : 동일한 데이터가 없으면 Delete 실패
- GetSize : 현재 데이터 개수 반환
- PrintData : 현재 데이터 정보를 표준 출력으로 출력
- 삽입되는 데이터를 표준 입력으로 받음
- 변수는 private, 함수는 public
- 상속을 통해 기반 클래스는 동일하게 구현
### DataManager 클래스 구현
- 생성/삭제되는 Vector/List 정보를 관리
- GetSize - 전체 자료구조의 갯수를 반환
- PrintInfomation - 전체 자료구조의 정보 출력

### Reference
* <https://github.com/wnsgml972/midas_log/blob/master/contents/BasicEducation/CppBasic.md>


<br/>

## Vector/List 템플릿 구현
- 전날 구현한 클래스 템플릿화
- 파일 입력을 활용한 데이터 삽입 기능
- 파일 출력을 통한 데이터 정보 출력 기능
- 연산자 오버로딩 구현
