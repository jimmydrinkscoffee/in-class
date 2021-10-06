#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

void inputList(node *&head)
{
    node *cur = head;
    int t;
    cout << "Input val: ";
    cin >> t;
    while (t != 0)
    {
        if (head == nullptr)
        {
            head = new node;
            cur = head;
        }
        else
        {
            cur->next = new node;
            cur = cur->next;
        }
        cur->val = t;
        cur->next = nullptr;
        cout << "Input val: ";
        cin >> t;
    }
}

void displayList(node *&head)
{
    node *cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    if (head)
        cout << endl;
}

void deleteList(node *&head)
{
    while (head)
    {
        node *deletedNode = head;
        head = head->next;
        delete deletedNode;
    }
}

int myStomach(node *&hRtr, int w)
{
    if (hRtr)
    {
        int m = 0;
        for (int i = 0; i < int(w / hRtr->val); ++i)
        {
            int tmp = i * hRtr->val + myStomach(hRtr->next, w - i * hRtr->val);
            if (tmp > m && tmp <= w)
                m = tmp;
        }
        return m;
    }
    return 0;
}

int main()
{
    int w;
    cout << "Enter your stomach: ";
    cin >> w;
    node *hRtr = nullptr;
    cout << "Enter all your dishes:\n";
    inputList(hRtr);
    cout << "You can eat maximum " << myStomach(hRtr, w) << "g of food.\n";
    deleteList(hRtr);
    return 0;
}
