
#include "stdafx.h"
#include<thread>
#include<iostream>


using namespace std;


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

int main(int argc, char** argv)
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