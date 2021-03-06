
#include "stdafx.h"
#include<thread>
#include<iostream>
#include <string>


using namespace std;

template <class... Is>
class ModularServer
{
public:
	ModularServer() { cout << "zero template" << endl; };

};

template <class I, class... Is>
class ModularServer<I, Is...> : public ModularServer<Is...>
{
public:
	//ModularServer<I, Is...>(I* _i, Is*... _is) : ModularServer<Is...>(_is...)
	//{
	//	_i->f();
	//}
	ModularServer(I* _i, Is*... _is);
};
template <class I, class... Is>
ModularServer<I, Is...>::ModularServer(I* _i, Is*... _is) : ModularServer<Is...>(_is...)
{
	_i->f();
}

class tm1
{
public:
	tm1() {};
	void f() { cout << "f1" << endl; }
	void b() { cout << "b" << endl; }
};

class tm2
{
public:
	tm2() {};
	void f() { cout << "f2" << endl; }
	void b() { cout << "b2" << endl; }
};

class tm3
{
public:
	tm3() {};
	void f() { cout << "f3" << endl; }
	void b() { cout << "b3" << endl; }
};

int main(int argc, char** argv)
{

	using fullserver = ModularServer<tm1, tm2, tm3>;

	auto a = new fullserver(new tm1(), new tm2(), new tm3());
	cin.get();
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
	return 0;
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