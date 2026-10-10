
#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class Myvector
{
    int* ptr;
    int size;

public:
    Myvector()
    {
        ptr = nullptr;
        size = 0;
    }

    Myvector(int s)
    {
        if (s < 0)
        {
            throw invalid_argument("Invalid vector size");
        }

        size = s;
        ptr = new int[size]{};
    }

    Myvector(const Myvector& obj)
    {
        size = obj.size;
        ptr = new int[size];

        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
    }

    Myvector& operator=(const Myvector& obj)
    {
        if (this != &obj)
        {
            int* temp = new int[obj.size];

            for (int i = 0; i < obj.size; i++)
            {
                temp[i] = obj.ptr[i];
            }

            delete[] ptr;
            ptr = temp;
            size = obj.size;
        }

        return *this;
    }

    ~Myvector()
    {
        delete[] ptr;
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Invalid index");
        }

        return ptr[index];
    }

    void Init()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = rand() % 100;
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << "\t";
        }

        cout << endl;
    }

    void AddBack(int a)
    {
        int* temp = new int[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }

        temp[size] = a;

        delete[] ptr;
        ptr = temp;
        size++;
    }

    void AddFirst(int b)
    {
        int* temp = new int[size + 1];

        temp[0] = b;

        for (int i = 0; i < size; i++)
        {
            temp[i + 1] = ptr[i];
        }

        delete[] ptr;
        ptr = temp;
        size++;
    }

    void DelBack()
    {
        if (size == 0)
        {
            throw out_of_range("Vector is empty");
        }

        int* temp = new int[size - 1];

        for (int i = 0; i < size - 1; i++)
        {
            temp[i] = ptr[i];
        }

        delete[] ptr;
        ptr = temp;
        size--;
    }

    void AddIndex(int a, int index)
    {
        if (index < 0 || index > size)
        {
            throw out_of_range("Invalid insert index");
        }

        int* temp = new int[size + 1];

        for (int i = 0; i < index; i++)
        {
            temp[i] = ptr[i];
        }

        temp[index] = a;

        for (int i = index; i < size; i++)
        {
            temp[i + 1] = ptr[i];
        }

        delete[] ptr;
        ptr = temp;
        size++;
    }

    void DelIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Invalid delete index");
        }

        int* temp = new int[size - 1];

        for (int i = 0; i < index; i++)
        {
            temp[i] = ptr[i];
        }

        for (int i = index; i < size - 1; i++)
        {
            temp[i] = ptr[i + 1];
        }

        delete[] ptr;
        ptr = temp;
        size--;
    }

    int Search(int a)
    {
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] == a)
            {
                return i;
            }
        }

        return -1;
    }

    void Concat(int* arr, int arrSize)
    {
        if (arrSize < 0)
        {
            throw invalid_argument("Invalid array size");
        }

        if (arr == nullptr && arrSize > 0)
        {
            throw invalid_argument("Array is null");
        }

        int* temp = new int[size + arrSize];

        for (int i = 0; i < size; i++)
        {
            temp[i] = ptr[i];
        }

        for (int i = 0; i < arrSize; i++)
        {
            temp[size + i] = arr[i];
        }

        delete[] ptr;
        ptr = temp;
        size += arrSize;
    }
};

int main()
{
    srand(0);

    try
    {
        Myvector obj1(-5);
        obj1.Print();
    }
    catch (const exception& ex)
    {
        cout << "Constructor error: " << ex.what() << endl;
    }

    Myvector obj1(5);

    obj1.Init();
    obj1.Print();

    cout << endl;

    obj1.AddFirst(2);
    obj1.Print();

    cout << endl;

    try
    {
        cout << obj1[100] << endl;
    }
    catch (const exception& ex)
    {
        cout << "Index error: " << ex.what() << endl;
    }

    try
    {
        obj1.AddIndex(50, 100);
    }
    catch (const exception& ex)
    {
        cout << "AddIndex error: " << ex.what() << endl;
    }

    try
    {
        obj1.DelIndex(-1);
    }
    catch (const exception& ex)
    {
        cout << "DelIndex error: " << ex.what() << endl;
    }

    try
    {
        Myvector obj2;
        obj2.DelBack();
    }
    catch (const exception& ex)
    {
        cout << "DelBack error: " << ex.what() << endl;
    }

    try
    {
        obj1.Concat(nullptr, 5);
    }
    catch (const exception& ex)
    {
        cout << "Concat error: " << ex.what() << endl;
    }

    cout << endl;
    cout << "Final vector:" << endl;
    obj1.Print();
}
