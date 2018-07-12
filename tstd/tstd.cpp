
#include "stdafx.h"
#include<thread>
#include<iostream>
#include <string>


using namespace std;


template<class B>
class tt<B>
{
	tt() { B->b(); }
};

template<class A, class...B>
class tt<A, B...>:public tt<B...>
{
	tt<A, B...>(A* _a, B*... _b):tt<B...>(_b) { a->f(); }
};

class tm
{
	tm() {};
	void f() { cout << "f" << endl; }
	void b() { cout << "b" << endl; }
};

class tm2
{
	tm2() {};
	void f() { cout << "f2" << endl; }
	void b() { cout << "b2" << endl; }
};

class tm3
{
	tm3() {};
	void f() { cout << "f3" << endl; }
	void b() { cout << "b3" << endl; }
};

int main(int argc, char** argv)
{
	using tty = tt<tm, tm2, tm3>;
	tt<tm,tm,tm> ta;

}

class A
{
private:
	int n1;
	int n2;

public:
	A() :n2(0), n1(n2 + 2) {}

	void Print() {
		cout << "n1:" << n1 << ", n2: " << n2 << endl;
	}
};

int testB(int argc, char** argv)
{
	cout << stol("0x20", 0, 16) << endl;
	cout << stol("0x20") << endl;
	cin.get();

}

int testA(int argc, char** argv)
{
	A a;
	a.Print();
	cin.get();

	return 0;
}


int test(int argc, char** argv)
{
	cout << "a" << endl;

	std::thread a([]() { std::cout << "thread " << std::endl; });
	
	std::thread b([]() { std::cout << "thread " << std::endl; });

	std::thread c([]() { std::cout << "thread " << std::endl; });
	a.join();
	b.join();
	c.join();

	return 0;
}