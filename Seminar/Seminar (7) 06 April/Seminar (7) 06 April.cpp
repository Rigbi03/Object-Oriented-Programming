
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

class MyString
{
    char* data = new char[10];

public:

    MyString(const MyString& source)
    {
        strcpy(data, source.data);
    }

    MyString(const char* source = " ")
    {
        strcpy(data, source);
        //*data = '\0';
    }

    MyString operator=(MyString& other)
    {
        if (other.data == data)
            return *this;

        data = other.data;
        other.data = nullptr;

        return *this;
    }

    ~MyString()
    {
        delete[] data;
    }

    size_t length() const
    {
        return strlen(data);
    }

    MyString concat(const MyString& source) const
    {
        MyString dest;
        
        strcpy(dest.data, data);
        dest.data += this->length();
        strcpy(dest.data, source.data);

        *dest.data = '\0';

        return dest;
    }

    void print() const
    {
        std::cout << data;
    }
};

int main()
{
    MyString string = "aaaaaaa";
    MyString newString(string);
    newString.print();
}

