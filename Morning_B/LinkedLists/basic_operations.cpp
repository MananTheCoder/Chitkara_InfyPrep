#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forLL(temp) for (Node *temp = head; temp != nullptr; temp = temp->next)

struct Node
{
    int data;
    Node *next;

    Node()
    {
        this->data = '\0';
        this->next = nullptr;
    }

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = nullptr;
    }

    LinkedList(Node *head)
    {
        this->head = head;
    }

    void insertNodeTail(int data);
    void deleteNode_vaishanvi(int pos);
    void deleteNode_arshad(int pos);
    bool searchNode(int data);
    int length();
    void print();
};

int LinkedList::length()
{
    Node *temp = head;
    int _length = 0;
    while (temp != nullptr)
    {
        _length++;
        temp = temp->next;
    }
    return _length;
}

bool LinkedList::searchNode(int val)
{
    // 1 case missing
    // int counter = 0;
    Node *temp = head;
    // while (temp->next != nullptr)
    // for (Node *temp = head; temp->next != nullptr; temp = temp->next)
    forLL(temp)
    {
        // counter++;
        // if (counter < val)
        if (temp->data == val)
        {
            return true;
        }
        // temp = temp->next;
    }
    return false;
}

void LinkedList::insertNodeTail(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void LinkedList::print()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

vector<int> input_vi()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void print_vi(vector<int> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\t";
    }
    cout << "\n";
    v[0] = 10;
}

void LinkedList::deleteNode_vaishanvi(int pos)
{
    if (head == nullptr)
    {
        return;
    }
    Node *prev = nullptr, *temp = head;
    // deleting head
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == pos)
        {
            prev->next = temp->next;
            delete temp;
            // prev->next = prev->next->next; // show that these 2 are identical
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (pos > count)
    {
        cout << "Pos > length of list.\n";
    }
}

void playing_with_linked_lists()
{
    LinkedList list1;
    // forn(i, 5)
    // {
    //     list1.insertNodeTail(i + 1);
    // }
    // list1.print();
    list1.deleteNode_vaishanvi(1);
    list1.print();
    // cout << list1.searchNode(5) << "\n";
}

void solve()
{
    // Node *head = new Node();
    playing_with_linked_lists();
}

int main()
{
    solve();
}