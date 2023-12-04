#include <iostream>
using namespace std;

struct Person
{
	char name[256];
	unsigned age;
	void print() const;
	/*{
		cout << name;
	}*/
};
void Person::print() const
{
	cout << name;
}

int main()
{
	struct Student //Use Upper Case For Name
	{
		char name[256];
		char FN[256];
		unsigned age;
	}; 
	
	struct Point2D
	{
		double x;
		double y;
	};

	struct
	{
		double x;
		double y; 
	} MyPoint; // Pitano na Usten Izpit, dali sushtestvuva takuv sintaksis -> da sushtestvuva

	Point2D a;
	Point2D b, c = { 5.3, 3.4 };

	c.x; // Dostupvame pole
	c.y = 7;
	cout << c.y << endl;

	struct Test1
	{
		short s;
		int i;
		char d;
	};
	
	struct Test2
	{
		int i;
		short s;
		char d;
	};

	const int sizeTest1 = sizeof(struct Test1); // = 12 bytes
	const int sizeTest2 = sizeof(struct Test2); // = 8  bytes
	// Sortirame v nizhodqsht red goleminata na poletata

	struct ClassRoom
	{
		Student student1;
	};

	struct Student
	{
		Student* student1; //Pointers have fixed size
	};

	Point2D* myPoint;
	Student student;
	Student* ptrStudent = &student;
	student.age = 35;
	ptrStudent->age = 30; // Equal to (*ptrStudent).age = 30;
	
	
	
	//Create favorite game character

	return 0;
}