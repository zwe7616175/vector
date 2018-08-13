#include "vector.h"

void test1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.diplay();
	cout << "Size="<<v.Size() << endl;
	cout << "Capacity=" << v.Capacity() << endl;
 
	v.PopBack();
	v.PopBack();
	v.diplay();
	cout << "Size=" << v.Size() << endl;
	cout << "Capacity=" << v.Capacity() << endl;
 
	v.Insert(2, 0);
	v.diplay();
	cout << "Size=" << v.Size() << endl;
	cout << "Capacity=" << v.Capacity() << endl;
 
	v.Erase(2);
	v.diplay();
	cout << "Size=" << v.Size() << endl;
	cout << "Capacity=" << v.Capacity() << endl;
 
	v.Resize(10);
	v.diplay();
	cout << "Size=" << v.Size() << endl;
	cout << "Capacity=" << v.Capacity() << endl;
}
 
int main()
{
	test2();
	system("pause:");
	return 0;
}
