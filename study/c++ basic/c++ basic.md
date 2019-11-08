# c와 Java를 배운사람의 c++ 기본 도전기

- 변수보다 인스턴스라는 말을 많이 사용해야 한다

### 새로운 방식의 변수 선언
```c++
int a = 10;
int b(a);  //b는 a를 복제해서 생성한다, '복사 생성자' 개념
auto c(b);

std::cout << a + b + c << std::endl;
//출력결과 : 30

```
  

### new delete, 객체생성 삭제

```c++

int *pData = new int;
int *arr = new int[5];

delete pData;
delete[] arr; //배열 형태로 생성한 대상은 배열 형태로 삭제

```
- new 연산자는 객체의 **생성자 호출**, delete 연산자는 객체의 **소멸자 호출**


### 참조형 변수  
```c++

int nData = 10;
int &ref = nData;
ref = 20;

std::cout << nData << std::endl;
//출력결과 20;
```
- 겉보기만 다른 포인터
- 덩치 큰 자료는 '참조'로 전달하자!
- 매개변수 사용가능 - 함수사용만 보면 call by value, reference를 구분 못한다

### for-each문
```c++
int aList[5] = {10, 20, 30, 40, 50};


 // c언어 스타일
for(int i = 0; i < aList.length(); i++){
    aList[i] = 1;
}

//for each문, n에 값복사, aList값 변경 안됨
for(auto n : aList){
    n = 1; 
}

//for each문, n에 참조, aList값 변경 됨
for(auto &n : aList){
    n = 1;
}

//for each문, n에 참조, aList값 변경이 필요없을 때 베스트 코드
for(const auto &n : aList){
    n = 1; 
}

```

### 디폴트 매개변수

```c++
TestFunc(int nParam = 10);

TestFunc(20); //20이 nParam으로
TestFunc(); //default값 10이 nParam으로
```

`Size(int Width, int Height)`함수가 `Size(int Widht, int Height, int depth = 1)`로 바뀌게 되었을 때   
기존에 사용하고 있던 함수 호출자는 살리면서 새롭게 변경 가능(활용법)

### 함수 템플릿

```c++

template <typename T>
T Add(T a, T b){
    return a+b;
}

std::cout << Add<int>(3, 4) << std::endl;
```

### class에 관하여

```c++
CTest(int &nParam) : m_nData(nParam) //생성자 호출을 할때 초기화도 가능한 구문
```

### const
- c++ 개발자의 실력은 const 개수에서 나온다 - 많이 달면 좋다는 듯
- human error를 방지하기 위한 좋은 것

```c++
void GetData(const int &id) const;
// Get함수에서 멤버변수를 변경시키지 않겠다는 굳은 의지
//id를 복사해서 가져와서 메모리 용량을 줄임
//const_cast라고 const를 풀어버리는 뭔가가 있는데 안쓰는게 좋을듯

void GetData(string id) = delete;
//id가 실수로 string형태로 넘어오는 경우를 방지
```
- 좋은코드, 클래스란 - *api형태*로 짜는 것, 클래스를 사용하는 사람이 실수를 해도 막아주는 것

 ### explicit
```c++
TestFunc(CTestData(5))
TestFunc(5) //CTestData에 int 생성자가 있으면 컴파일러가 위와같이 변환을 해준다
//CTestData int 생성자에 explicit를 넣으면 막힌다 - 코드에서 명시를 해라는 의미
```

### 형변환과 explicit
```c++
class CTestData{
    ...
    m_nData = 10;
    operator int(void) { return m_nData; }
    ...
}

cout<<a.GetData();
cout<<a; //형변환 연산자로 cout에서 자동으로 int 찾아서 가져옴
cout<<(int)a; //c-style 형변환, 비추
cout<<static_cast<int>(a);
//결과 모두 10

// explicit operator을 하게 되면 묵시적인 cout<<a가 변환이 안된다 
```

### 연산자 다중 정의
```c++
CMyData operator+(const cMyData &rhs);
//CMyData에 더하기 연산을 할때 어떻게 반환해 줄지 만드는 것
CMyData& operator=(const CMyData &rhs);
//대입 연산을 할때 어떻게 대처할지 보여준다
//a=b=c 연산을 대비하기 위해 주소를 반환한다
int operator[](int nIndex) const
// 배열도 가능, !=, ==, 비교연산자도 가능 웬만한거 다 가능??!!!!
```

### 캐스트
- c-style 캐스트는 하지 마라!
- static_cast<>(), c타입 캐스팅과 비슷, 다형성 없이도, void도 가능
- dynamic_cast<>(), 이걸 쓴다는 것은 가상함수를 잘 이용하지 못했다, 성능도 좋지 못해 웬만하면 안씀
- reinterpret_cast<>(), 뭐든지 다되자만 그만큼 에러 발생도 높음
- 결론 - static_cast<>()를 주로 쓰자

### friend
- 함수 선언에 이거 넣으면 private 이든 protected든 접근 가능?????
- 뭐야 이거(웬만하면 이것도 안쓰는 쪽으로??? 자유도를 높여준다)

### template<typename T> class
- 클래스에서도 동일하게 사용

### 스마트포인터
- shared_ptr : 참조가 2개가 된다면 cnt = 2 참조가 0이 되면 그때 삭제처리
- unique_ptr : 참조를 딱 1개만 가능하도록, (휴먼에러 방지?)
- week_ptr : 참조를 할 수 있는데 shared_ptr의 count에 영향을 안미치게 한다.





