#include <iostream>
#include<cstring>

using namespace std;

bool isPrime(int number)
{
    int end = int(sqrt(number));

    for (size_t i = 2; i <= end; i++)
    {
        if (number % i == 0)
            return false;
    }

    return number > 1;
}



class Comparator {
public:
    virtual int compare(int left, int right) const = 0;
};



class AscendingIntComparator : public Comparator {
public:
    int compare(int left, int right) const {
        cout << "AscendingIntComparator::compare" << endl;
        return right - left;
    }
};

class FancyIntComparator : public AscendingIntComparator {
public:
    int compare(int left, int right) const {
        if (left % 2 == right % 2) {
            return right - left;
        }

        return left % 2 == 0 ? 1 : -1;
    }
};

class DescendingIntComparator : public Comparator {
public:
    int compare(int left, int right) const {
        cout << "DescendingIntComparator::compare" << endl;
        return left - right;
    }
};

class PrimeComperator : public Comparator
{
public:
    int compare(int left, int right) const
    {
        bool leftIsPrime = isPrime(left);
        bool rightIsPrime = isPrime(right);
        
        if (leftIsPrime)
        {
            if (rightIsPrime)
                return left - right;
            else
                return -1;
        }
        else
        {
            if (rightIsPrime)
                return 1;
            else
                return right - left;
        }
        
        
    }
};



void sort(int arr[10], Comparator& comparator) {
    for (int i = 0; i < 9; ++i) {
        int outlier = i;

        for (int j = i + 1; j < 10; j++) {
            if (comparator.compare( arr[j], arr[outlier]) < 0) {
                outlier = j;
            }
        }

        swap(arr[i], arr[outlier]);
    }
}

void print(int arr[10]) {
    for (int i = 0;i < 10;i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    cout << endl;
}

//int main() {
//    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//    FancyIntComparator fancyIntComparator = FancyIntComparator();
//    DescendingIntComparator descendingComparator = DescendingIntComparator();
//    AscendingIntComparator ascendingIntComparator = AscendingIntComparator();
//    PrimeComperator primeComperator = PrimeComperator();
//
//    sort(arr, primeComperator);
//    print(arr);
//
//    // sort(arr, ascendingIntComparator);
//    // print(arr);
//
//    // sort(arr, fancyIntComparator);
//    // print(arr);
//
//
//    return 0;
//}

