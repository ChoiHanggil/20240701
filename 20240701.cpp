#include <iostream>
#include <array>		// std::array
#include <vector>		// std::vector
#include <string>		// std::string
#include <forward_list> // std::forward
#include <list>			//std::list
#include <deque>		// std::deqie

#include <stack>        //std::stack
#include <queue>        //std::queue, std::priority_queue

#include <set>			//std::set
#include <map>			//std::map

#include <algorithm>	// std::sort

void ArrayEx()
{
	// std::array
	// 일반 정적 배일 - 컴파일타임에 크기가 고정
	// Sequence
	// Random Acces

	// 선언
	std::array<int, 5> arr{ 5, 2, 4, 1, 3 };

	//순회(Traverse)
	for (const auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//크기 
	std::cout << arr.size() << std::endl;
	std::cout << "sizeof : " << sizeof(arr) << std::endl;

	//정렬
	std::sort(arr.begin(), arr.end());
	
	for (const auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//인텍스
	std::cout << arr[0] << " : " << *arr.begin() << " : " << arr.front() << std::endl;
	std::cout << arr[4] << " : " << *(arr.end()-1) << " : " << arr.back() << std::endl;
	
	
}

void VectorEx()
{
	// std::vector
	// 동적 배열
	// Sequence
	// Random Acces
	
	// 선언
	std::vector<int> vec{ 5,2,1,3,4 };

	//크기
	std::cout << vec.size() << std::endl;
	std::cout << "sizeof : " << sizeof(vec) << std::endl;

	//정렬
	std::sort(vec.begin(), vec.end());

	//순회
	for (const auto& e : vec)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//인덱스
	std::cout << vec[0] << " : " << *vec.begin() << " : " << vec.front() << std::endl;
	std::cout << vec[4] << " : " << *(vec.end()-1) << " : " << vec.back() << std::endl;

	////////////////////////////////////////
	// 동적 배열이므로 사이즈 변경이 가능
	vec.push_back(6);
	vec.push_back(10);
	
	vec.pop_back();

	for (const auto& e : vec)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	// 뒤에서 추가/삭제가 빠름
	std::cout << vec.capacity() << std::endl;
	

}

void StringEx()
{
	//std::string
	//내부적으로 std::vector<char>와 유사
	//문자열에 특화된 기능 추가

	//선언
	std::string str = "hello";
	std::string str2 = { 'h','e','l','l','0','\0' };

	//크기
	std::cout << str.size() << std::endl;
	std::cout << "sizeof : " << sizeof(str) << std::endl;

	//정렬
	std::sort(str.begin(), str.end());

	//순회
	for (const auto& e : str)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//뒤에서 추가
	str.push_back('!');
	str.push_back('?');

	str.pop_back();

	std::cout << str << std::endl;

	//인덱스
	std::cout << str[0] << " : " << *str.begin() << " : " << str.front() << std::endl;
	std::cout << str[5] << " : " << *(str.end()-1) << " : " << str.back() << std::endl;

	std::cout << str.substr(0,3) << std::endl;
	
	
}

void ForwardListEx()
{
	// std::forwardlist
	// single Linked List
	// Sequential
	// Random Access X

	//선언
	std::forward_list<int> list{ 5,3,1,2,4 };

	//크기
	std::cout << list.max_size() << std::endl;  // size() 가 없음
	std::cout << "sizeof : " << sizeof(list) << std::endl;
	int count{};
	auto itr = list.begin();
	while (itr != list.end()) { count++; itr++; }
	std::cout << count << std::endl;
	//정렬
	list.sort();

	//순회
	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//인덱스 X
	std::cout << *list.begin() << " : " << list.front() << std::endl;
	//단방향이라서 이터레이터 - 연산이 불가능 & back X 
	// (list.end() - 1) X & list.back()X;
	
	/////////////////////////////////////////////
	// 링크드 리스트의 장점 - 중간에 추가
	//std::forward_list::itrerator
	//auto result = std::find(list.begin(), list.end(), 4);
	list.insert_after(std::find(list.begin(), list.end(), 4), 0);
	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}

void ListEx()
{
	//std::list
	//double linked list
	// Sequential
	// Random Access X
	
	//선언
	std::list<int> list{ 5,4,1,3,2 };

	//크기
	std::cout << list.size() << std::endl;
	std::cout << "sizeof : " << sizeof(list) << std::endl;

	//정렬
	//Random Access X - std::sort() x
	list.sort();

	//순회
	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//인덱스
	std::cout << *list.begin() << " : " << list.front() << std::endl;
	// (list.end() - 1) X
	std::cout << list.back() << std::endl;

	//list 툭장
	list.push_back(10);
	list.push_front(0);

	list.insert(std::find(list.begin(), list.end(), 4), 0);
	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	list.pop_back();
	list.pop_front();
}

void DequeEx()
{
	//Double Ended Queue
	//std::vector와 유사 - 작은 배열들의 블럭

	//선언 
	std::deque<int> c = { 5,4,1,3,2 };

	//크기

	//크기
	std::cout << c.size() << std::endl;
	std::cout << "sizeof : " << sizeof(c) << std::endl;

	//정렬
	std::sort(c.begin(), c.end());

	//순회
	for (const auto& e : c)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//인덱스
	std::cout << c[0] << " : " << *c.begin() << " : " << c.front() << std::endl;
	std::cout << c[4] << " : " << *(c.end()-1) << " : " << c.back() << std::endl;

	//특징
	c.push_back(10);
	c.push_front(0);

	for (const auto& e : c)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

}

void StackEx()
{
	//선언
	std::stack<int> s;
	
	//삽입
	s.push(1);
	s.push(2);
	s.push(3);

	//삭제
	s.pop();

	//크기
	std::cout << s.size() << std::endl;
	std::cout << "sizeof : " << sizeof(s) << std::endl;

	//가장 위에 있는 원소(LAST)
	std::cout << s.top() << std::endl;

	//초기화식 X
	// std::stack<int> s2 {1,2,3,4,5};

	//순회
	//범위기반 : X
	//for(auto e : s){}
	//이터레이터 : X
	//std::stack<int>::iterator;
	//인덱스 : X
	//s[0]

	std::stack<int> temp = s;
	while (!temp.empty())
	{
		std::cout << temp.top() << " ";
		temp.pop();
	}
	std::cout << std::endl;
}

void QueueEx()
{
	std::queue<int> q;

	//삽입
	q.push(1);
	q.push(2);
	q.push(3);

	//삭제
	q.pop();

	//크기
	std::cout << q.size() << std::endl;
	std::cout << "sizeof : " << sizeof(q) << std::endl;
	//순회
	while (!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;
}

void PriorityQueueEx() //Heap 구조
{
	std::priority_queue<int> pq; // heap data structre

	//삽입
	pq.push(5);
	pq.push(3);
	pq.push(4);
	pq.push(2);

	//삭제
	
	//크기
	std::cout << pq.size() << std::endl;
	std::cout << "sizeof : " << sizeof(pq) << std::endl;
	
	//출력
	std::priority_queue<int> temp = pq;
	while (!temp.empty())
	{
		//왜 top 이지? 쌓아올리는 자료구조 Heap구조 그래서 제일 위에 있는 것 Top사용;
		std::cout << temp.top()<< " ";
		temp.pop();
	}
	std::cout << std::endl;
}

void SetEx()
{
	//unique한 값 : 중복값X
	// Binary Search Tree
	// 정력
	
	//선언
	std::set<int> s{ 5,2,4,3,1 };

	//삽입
	s.insert(6);

	//삭제
	s.erase(3);

	//크기
	std::cout << s.size() << std::endl;

	//순회
	for (auto e : s)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//검색
	std::cout << (s.find(4) != s.end()) << std::endl;
}

void MapEx()
{
	// (키 - 벨류)
	std::map<int, std::string> m {
		{ 1,"one" },
		{ 2,"two" },
		{ 3,"three"},
		{ 4,"four" },
	};

	//삽입
	m.insert({ 5, "five" });
	m[6] = "six";

	//크기
	std::cout << m.size() << std::endl;

	//값에 접근
	std::cout << m.at(2) << std::endl;
	std::cout << m[2] << std::endl;

	//{ key, value }
	//std::pair<T1,T2>
	
	//검색
	std::map<int, std::string>::iterator result = m.find(1);
	//auto result = m.find(1);
	if (result != m.end())
	{
		//찾음
		//*result = std::pair<int, string>
		//					.first	.second
		
		std::cout <<"find :" << (*result).second << std::endl;
	}

	//순회
	//모든 원소를 "키 : 밸류" 출력
	//값수정 X : const &만 가능
	for (std::pair<const int, std::string>& e : m)
	{
		//e - std::pair<int,std::string>
		std::cout << e.first <<" : " << e.second << std::endl;;
	}

	std::map <const std::string, int> items
	{
		{"sword", 10},
		{"hammer", 100},
		{"shield", 50},
		{"armor", 50}
	};

	std::cout << items["sword"] << std::endl;
	items["knife"] = 30; //삽입
}
int main()
{
	// Sequence Container
	ArrayEx();
	std::cout << "------------------------------" << std::endl;
	/*
	int array1[10]{ 1,2,3,4,5,7,8,9,6 };
	std::cout << sizeof(array1) << std::endl;
	std::cout << sizeof(*array1) << std::endl;
	*/
	VectorEx();
	std::cout << "------------------------------" << std::endl;
	StringEx();
	std::cout << "------------------------------" << std::endl;
	ForwardListEx();
	std::cout << "------------------------------" << std::endl;
	ListEx();
	std::cout << "------------------------------" << std::endl;
	DequeEx();
	std::cout << "------------------------------------" << std::endl;

	//Container Adaptor
	StackEx();
	std::cout << "------------------------------------" << std::endl;
	QueueEx();
	std::cout << "------------------------------------" << std::endl;
	PriorityQueueEx();
	std::cout << "------------------------------------" << std::endl;

	//Associative Container
	SetEx();
	std::cout << "------------------------------------" << std::endl;
	MapEx();
	std::cout << "------------------------------------" << std::endl;

}

// 임의 접근이 가장 순서
// 0(1)						O(n)          
// array - vector - deqie - list - forward_list

//끝에서 삽입/삭제 
// arrayX
// O(1)
// vector - deqie - list - forward_list

// 앞에서 삽입/삭제
// O(1)                         O(n)
//deque - list - forward_list - vector

// 중간에서 삽입/삭제
// O(1)                   O(n)
// list - forward_list - deque - vector 


// 보조 컨테이너 (Container Adaptor)
//	특정한 목적에 맞도록 변형된 컨테이너
//						push	 pop		top/front
// stack				O(1)	 O(1)		O(1)
// queue				O(1)	 O(1)		O(1)
// priority_queue		O(logN)  O(logN)    O(1)

//연관 컨테이너 (Associative Container)
// 
// 이진 탐색 트리
// 중복 불가능
//set
//map

//중복 가능
//multiset
//multimap