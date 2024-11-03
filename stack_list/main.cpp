#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    struct Element
    {
        T data;
        Element* Next;
    };

    Element* Head;
    Element* Tail;
    int size;

public:
    bool IsEmpty() const
    {
        return Head == nullptr;
    }

    Stack() : size(0)
    {
        Head = Tail = NULL;
    }

    ~Stack() 
    {
        while (!IsEmpty()) 
        {
            Pop();
        }
    }

    void Push(const T& data)
    {
        Element* temp = new Element;
        temp->data = data;

        temp->Next = Head; 
        Head = temp;

        size++;
    }

    void Pop() 
    {
        if (IsEmpty()) return;

        Element* temp = Head;
        Head = temp->Next;
        delete temp;

        size--;
    }

    int GetSize() const 
    {
        return size;
    }

    void Print()
    {
        Element* temp = Head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->Next;
        }

        cout << "\n\n";
    }
};

int main()
{
    Stack<int> stack;

    for (int i = 0; i < 5; i++)
    {
        stack.Push(i);
    }
    stack.Print();
    cout << "Size: " << stack.GetSize() << endl << endl;

    stack.Pop();
    stack.Pop();
    stack.Print();
    cout << "Size: " << stack.GetSize() << endl << endl;

    return 0;
}