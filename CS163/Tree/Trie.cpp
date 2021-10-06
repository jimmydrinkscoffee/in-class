#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 36;

struct Node
{
    bool isEnd;
    Node *nexts[ALPHABET_SIZE];
    Node() : isEnd(false)
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            nexts[i] = nullptr;
    }
};

bool Search(Node *&root, string s)
{
    Node *cur = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int index = s[i] - 'a';
        if (!cur->nexts[index])
            return false;
        cur = cur->nexts[index];
    }
    return cur->isEnd;
}

void Insert(Node *&root, string s)
{
    Node *cur = root;
    for (int i = 0; i < s.length(); ++i)
    {
        int index = s[i] - 'a';
        if (!cur->nexts[index])
            cur->nexts[index] = new Node;
        cur = cur->nexts[index];
    }
    cur->isEnd = true;
}

bool IsEmpty(Node *&root)
{
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        if (root->nexts[i])
            return false;
    return true;
}

Node *Remove(Node *&root, string s, int i)
{
    if (!root)
        return nullptr;
    if (i == s.length())
    {
        if (root->isEnd)
            root->isEnd = false;
        if (IsEmpty(root))
        {
            delete root;
            root = nullptr;
        }
        return root;
    }
    int index = s[i] - 'a';
    root->nexts[index] = Remove(root->nexts[index], s, i + 1);
    if (IsEmpty(root) && !root->isEnd)
    {
        delete root;
        root = nullptr;
    }
    return root;
}

void Clear(Node *&root)
{
    if (!root)
        return;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        Clear(root->nexts[i]);
    delete root;
    root = nullptr;
}