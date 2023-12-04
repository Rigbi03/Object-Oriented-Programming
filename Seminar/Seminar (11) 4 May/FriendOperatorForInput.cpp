#include <iostream>
#include <fstream>

//Virtual Func -> Virtual Destructor

class Base
{
protected: 
	std::string name;
	virtual std::ostream& print(std::ostream& os) const
	{
		return os << "Rand Text Base \n";
		
	}

public:
	Base(std::string name) : name(name) {}

	virtual ~Base()
	{
		std::cout << "~Base()" << std::endl;
	}

	friend std::ostream& operator<< (std::ostream& os, const Base& base);
};

std::ostream& operator<< (std::ostream& os, const Base& base)
{
	return base.print(os);
}

class A : public Base 
{
private:
	int data;
protected:
	std::ostream& print(std::ostream& os) const
	{
		return os << "Rand Text A \n";
	}

public:
	A(std::string name, int data) : Base(name), data(data) {}

	~A()
	{
		std::cout << "~A() \n";
	}
};

class C : public Base
{
private:
	int data;
protected:
	std::ostream& print(std::ostream& os) const
	{
		return os << "Rand Text C \n";
	}

public:
	C(std::string name, int data) : Base(name), data(data) {}

	~C()
	{
		std::cout << "~C() \n";
	}
};

/*int main()
{
	Base* base = new Base("Hello World"), * a = new A("Hello World", 5), * c = new C("Hello World", 7);

	delete c;
	delete a;
	delete base;
}*/