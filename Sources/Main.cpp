#include <iostream>
#include <string>
#include <list>

using namespace std;

class Osztaly
{
private:
public:
	Osztaly(void);
	Osztaly(int a, int b);
	~Osztaly();
	int a = 0, b = 0;
	list<int> l;
};

Osztaly::Osztaly(void)
{
}

Osztaly::Osztaly(int a, int b)
{
	this->a = a; this->b = b;

	l.push_back(a); l.push_back(b);
}

Osztaly::~Osztaly()
{
	cout << "delete " <<  this << endl;
}


list<Osztaly> osztalyList;

void addToList(void)
{

	cout << "add to list" << endl;

	Osztaly o1;
	Osztaly o2(5, 15);

	cout << "o1 a: " << o1.a << " o1 b: " << o1.b << " o1 l0: " << o1.l.front() << " o1 l1: " << o1.l.back() << endl;
	cout << "o2 a: " << o2.a << " o2 b: " << o2.b << " o2 l0: " << o2.l.front() << " o2 l1: " << o2.l.back() << endl;

	cout << "&o1.a: " << &o1.a << " &o1.b: " << &o1.b << " &o1.l[0]: " << &(o1.l.front()) << endl <<endl;

	osztalyList.push_back(o1);
	osztalyList.push_back(o2);

	cout << "add to list vege" << endl;

}

int main()
{

	addToList();
	cout << "add to list vege 2" << endl << endl;

	cout << "&osztalyList[0]: " << &osztalyList.front() << " &osztalyList[1]:  " << &osztalyList.back() << endl;

	Osztaly osztTmp = osztalyList.front();
	cout << "erase" << endl;
	osztalyList.erase(osztalyList.begin());
	cout << "erase vege" << endl << endl;

	cout << "&OsztTmp: " << &osztTmp << " OsztTmp.a: " << osztTmp.a << endl << endl;
	
	return 0;
}
	