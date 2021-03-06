// ptr.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <iostream>

using namespace std;

class BB;
class AA
{
public:
	AA() { cout << "AA::AA() called" << endl; }
	~AA() { cout << "AA::~AA() called" << endl; }
	shared_ptr<BB> m_bb_ptr;  //!
};

class BB
{
public:
	BB() { cout << "BB::BB() called" << endl; }
	~BB() { cout << "BB::~BB() called" << endl; }
	shared_ptr<AA> m_aa_ptr; //!
};

void main_ptr()
{
	shared_ptr<AA> ptr_a(new AA);
	{
		shared_ptr<BB> ptr_b(new BB);
		cout << "ptr_a use_count: " << ptr_a.use_count() << endl;
		cout << "ptr_b use_count: " << ptr_b.use_count() << endl;
		//下面两句导致了AA与BB的循环引用，结果就是AA和BB对象都不会析构
		//ptr_a->m_bb_ptr = ptr_b;
		ptr_b->m_aa_ptr = ptr_a;
		cout << "ptr_a use_count: " << ptr_a.use_count() << endl;
		cout << "ptr_b use_count: " << ptr_b.use_count() << endl;
	}
	cout << "---------------------------------" << endl;
	ptr_a.reset();

	cout << "ptr_a use_count: " << ptr_a.use_count() << endl;

	cin.get();

}

int main()
{
	const int * a;
	int const * b; //指针可以修改， 指向的值不可以修改。

	int * const in_c = new int(3);   //指针不可以修改， 指向的值可修改。

	b = in_c;
	a = in_c;
	cout << "1:"<< *b << *in_c << *a << endl;

	int * const in_d = new int(4);
	b = in_d;
	a = in_d;
	//in_c = in_d;
	cout << "2:"<< *b << *in_d << *a << endl;
	cout << "-------------" << endl;
	cin.get();

	return 0;
}
