#include <iostream>
#include <vector>

// Data can be anytype, so 
// TODO:templating
union Data
{
    int intData;
    std::vector<int> arrData;

    Data()
        :intData(0) {}

    ~Data()
    {
        intData = NULL;
    }

    void operator()(int srcIntData)
    {
        intData = srcIntData;
    }

    void operator=(int srcIntData)
    {
        intData = srcIntData;
    }

    void operator()(const std::vector<int>& srcVecData)
    {
        arrData = srcVecData;
    }

    void operator=(const std::vector<int>& srcVecData)
    {
        arrData = srcVecData;
    }
};


struct Node{
    Node* Next;
    Data m_Data;

    Node(int data = NULL)
        :Next(nullptr)
    {
        m_Data = data;
    }

    Node(std::vector<int> vecData)
    {
        m_Data = vecData;
    }


    int& GetData()
    {
        return m_Data.intData;
    }

    bool IsAtEnd()
    {
        return (Next == nullptr ? true : false); 
    }

    static void MoveFwd(Node*& node)
    {
        
            if(node->Next != nullptr)
                node = node->Next;
            else throw "Node is at end! Can't Move forward";
        
    }

};


class LinkedList{
public:
    LinkedList(int data = 0)
        :m_Head(new Node(data = 0)), m_Traverser(m_Head), m_ListLength(1) {}

    // LinkedList(std::vector<int> vecData)
    //     :m_Head(new Node(vecData)), m_ListLength(0) {}

    int& GetValueAt(unsigned int index);

    inline unsigned int GetListLength() const { return m_ListLength; }

    void PrintAllValue();


    void AppendFirst(int intData);
        
    void AppendLast(int intData);

    void InsertAt(unsigned int index, int data);


    void PopFirst();

    void PopLast();

    void DeleteAt(unsigned int index);

    void Clear();


    int& operator[](unsigned int index)
    {
        return this->GetValueAt(index);
    }



private:
    Node* m_Head;
    Node* m_Traverser;

    unsigned int m_ListLength;
};


int& LinkedList::GetValueAt(unsigned int index)
{
    if(index > m_ListLength - 1)
    {
        throw "Index doesnot exist!";
    }
    // Ensure the list is not emmpty
    else if(m_Head != nullptr)
    {
        m_Traverser = m_Head;

        for(unsigned int i = 0; i != index; i++)
        {
            Node::MoveFwd(m_Traverser);
        }

        return m_Traverser->GetData();

    }

    m_Traverser = nullptr;
}


void LinkedList::PrintAllValue()
{
    // Ensure the list is not emmpty
    if(m_Head != nullptr)
    {
        m_Traverser = m_Head;
        while(!(m_Traverser->IsAtEnd()))
        {
            std::cout << m_Traverser->GetData() << '\t';
            Node::MoveFwd(m_Traverser);
        }

        std::cout << m_Traverser->GetData() << std::endl;
    }
    else std::cout << "List is empty!" << std::endl;

    m_Traverser = nullptr;
}


void LinkedList::AppendFirst(int intData)
{
    if(m_Head == nullptr)
        m_Head = new Node(intData);
    else
    {
        m_Traverser = m_Head;
        m_Head = new Node(intData);
        m_Head->Next = m_Traverser;
    }

    m_Traverser = nullptr;
    m_ListLength++;
}


void LinkedList::AppendLast(int intData)
{
    // Ensure the head is not emmpty
    if(m_Head == nullptr)
    {
        m_Head = new Node(intData);
    }
    else
    {
        m_Traverser = m_Head;

        // Loop till we are at the last index
        while(!(m_Traverser->IsAtEnd()))
        {
            Node::MoveFwd(m_Traverser);
        }

        // We are at the last index, so make a new node and insert there
        m_Traverser->Next = new Node(intData);
    }

    m_Traverser = nullptr;
    m_ListLength++;
}


void LinkedList::InsertAt(unsigned int index, int data)
{
    if(index > m_ListLength)
    {
        throw "Index doesnot exist!";
    }
    else if(index == 0)
    {
        AppendFirst(data);
    }
    else if(index == m_ListLength)
    {
        AppendLast(data);
    }
    else if(m_Head != nullptr)
    {
        m_Traverser = m_Head;

        // inserts after the current index, so loop ends 1 step before
        for(unsigned int i = 0; i < index - 1; i++)
        {
            Node::MoveFwd(m_Traverser);
        }

        Node* temp = new Node(data);
        temp->Next = m_Traverser->Next;
        m_Traverser->Next = temp;


        m_Traverser = nullptr;
        m_ListLength++;
    }
}


void LinkedList::PopFirst()
{
    if(m_Head == nullptr)
        throw "List is Empty!";
    else
    {
        m_Traverser = m_Head;
        Node::MoveFwd(m_Head);
        delete m_Traverser;
        m_Traverser = nullptr;
    }
    m_ListLength--;
}


void LinkedList::PopLast()
{
    if(m_Head == nullptr)
        throw "List is Empty!";
    else
    {
        m_Traverser = m_Head;
        while(!(m_Traverser->Next->IsAtEnd()))
            Node::MoveFwd(m_Traverser);

        delete m_Traverser->Next;
        m_Traverser->Next = nullptr;
        m_Traverser = nullptr;
    }
    m_ListLength--;
}


void LinkedList::DeleteAt(unsigned int index)
{
    if(index > m_ListLength - 1)
    {
        throw "Index doesnot exist!";
    }
    else if(index == 0)
    {
        PopFirst();
    }
    else if(index == m_ListLength - 1)
    {
        PopLast();
    }
    else if(m_Head != nullptr)
    {
        m_Traverser = m_Head;

        for(unsigned int i = 0; i < index - 1; i++)
        {
            Node::MoveFwd(m_Traverser);
        }

        Node* temp = m_Traverser->Next->Next;
        delete m_Traverser->Next;
        m_Traverser->Next = temp;

        m_Traverser = nullptr;
        m_ListLength--;
    }

}


void LinkedList::Clear()
{
    // Ensure the list is not already cleared
    if(m_Head != nullptr)
    {
        while(!(m_Head->IsAtEnd()))
        {
            m_Traverser = m_Head;
            Node::MoveFwd(m_Head);
            
            delete m_Traverser;
            m_Traverser = nullptr;
        }

        delete m_Head;
        m_Head = nullptr;
    }

    m_ListLength = 0;
}


int main()
{
    LinkedList t;
    t.AppendLast(1);

    t.AppendLast(2);

    t.PrintAllValue();

    unsigned int ind = 0;

    t.InsertAt(ind, 69);
    t.InsertAt(2, 269);

    ind = t.GetListLength();

    t.InsertAt(ind - 1, 469);

    t.PrintAllValue();

    t.PopFirst();

    std::cout << "Popped first!" << std::endl;

    t.PrintAllValue();

    t.PopLast();

    std::cout << "Popped Last!" << std::endl;

    t.PrintAllValue();

    ind = 2;
    t.DeleteAt(ind);
    t.DeleteAt(0);
    t.DeleteAt(t.GetListLength() - 1);


    std::cout << "Deleted at "<< ind << std::endl;

    t.PrintAllValue();

    std::cin.get();
}