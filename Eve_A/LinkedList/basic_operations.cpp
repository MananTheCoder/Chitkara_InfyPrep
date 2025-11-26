#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forLL(temp) for (Node *temp = head; temp != nullptr; temp = temp->next)

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

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = '\0';
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
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

    void insertNodeTail(int val);
    void deleteNode(int pos);
    void print();
    bool search(int target);
    int length();
};

void LinkedList::insertNodeTail(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }
    Node *curr = head;
    while (curr != nullptr && curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = new Node(val);
}

void LinkedList::print()
{
    // Node *temp = head;
    // while (temp != nullptr)
    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        cout << temp->data << "\t";
        // temp = temp->next;
    }
    cout << "\n";
}

int LinkedList::length()
{
    int _length = 0;
    forLL(temp)
    {
        _length++;
    }
    return _length;
}

bool LinkedList::search(int target)
{
    forLL(temp)
    {
        if (temp->data == target)
        {
            return true;
        }
    }
    return false;
}

void LinkedList::deleteNode(int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }
    if (pos < 1)
    {
        cout << "Index can't be < 1.\n";
    }
    Node *temp = head;
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    for (int i = 0; i < pos - 2; i++)
    {
        if (temp == nullptr)
        {
            cout << "Pos doesn't exist in the list.\n";
            return;
        }
        temp = temp->next;
    }
    Node *dummy = temp->next;
    temp->next = temp->next->next;
    delete dummy;
}

void playing_with_linked_lists()
{
    LinkedList list1;
    forn(i, 5)
    {
        list1.insertNodeTail(i + 1);
    }
    list1.print();
    cout << list1.search(3) << "\n";
    list1.deleteNode(3);
    list1.print();
}

void solve()
{
    playing_with_linked_lists();
}

int main()
{
    solve();
}