#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node *Insert(Node *&root, int x)
{
    if (!root)
        return new Node(x);
    else if (x < root->val)
        root->left = Insert(root->left, x);
    else if (x > root->val)
        root->right = Insert(root->right, x);
    return root;
}

Node *Search(Node *&root, int x)
{
    if (!root)
        return nullptr;
    if (root->val == x)
        return root;
    if (x < root->val)
        return Search(root->left, x);
    return Search(root->right, x);
}

void Clear(Node *&root)
{
    if (!root)
        return;
    Clear(root->left);
    Clear(root->right);
    delete root;
    root = nullptr;
}

int GetHeight(Node *&root)
{
    if (!root)
        return 0;
    return 1 + max(GetHeight(root->left), GetHeight(root->right));
}

void InorderTraversal(Node *&root)
{
    if (!root)
        return;
    InorderTraversal(root->left);
    cout << root->val << " ";
    InorderTraversal(root->right);
}

Node *Remove(Node *&root, int x)
{
    if (!root)
        return root;
    if (x < root->val)
        root->left = Remove(root->left, x);
    else if (x > root->val)
        root->right = Remove(root->right, x);
    else
    {
        if (!root->left)
        {
            Node *res = root->right;
            delete root;
            return res;
        }
        if (!root->right)
        {
            Node *res = root->left;
            delete root;
            return res;
        }
        if (!root->left->right)
        {
            root->left->right = root->right;
            Node *res = root->left;
            delete root;
            return res;
        }
        Node *rightMin = root->right;
        while (rightMin->left)
            rightMin = rightMin->left;
        root->val = rightMin->val;
        root->right = Remove(root->right, rightMin->val);
    }
    return root;
}

void DisplayLeaves(Node *&root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        cout << root->val << " ";
    else
    {
        DisplayLeaves(root->left);
        DisplayLeaves(root->right);
    }
}

void DisplayPath(Node *&root, int x)
{
    if (!root || !Search(root, x))
        return;
    Node *cur = root;
    while (cur->val != x)
    {
        cout << cur->val << " ";
        if (x < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }
    cout << x;
}

void DisplayLevel(Node *&root, int k)
{
    if (!root)
        return;
    if (k)
    {
        DisplayLevel(root->left, k - 1);
        DisplayLevel(root->right, k - 1);
    }
    else
        cout << root->val << " ";
}

Node *LowestCommonAncestor(Node *&root, int x, int y)
{
    if (!root || !Search(root, x) || !Search(root, y))
        return nullptr;
    Node *cur = root;
    while (true)
        if (x < cur->val && y < cur->val)
            cur = cur->left;
        else if (x > cur->val && y > cur->val)
            cur = cur->right;
        else
            return cur;
}

void LeftView(Node *&root, stack<int> &leftView, int left)
{
    if (!root)
        return;
    if (left == -leftView.size())
        leftView.push(root->val);
    LeftView(root->left, leftView, left - 1);
    LeftView(root->right, leftView, left + 1);
}

void RightView(Node *&root, int &rightSize, int right)
{
    if (!root)
        return;
    if (right == rightSize)
    {
        cout << root->val << " ";
        ++rightSize;
    }
    RightView(root->left, rightSize, right - 1);
    RightView(root->right, rightSize, right + 1);
}

void DisplayTopView(Node *&root)
{
    if (!root)
        return;
    stack<int> leftView;
    int rightSize = 0;
    LeftView(root->left, leftView, 0);
    while (!leftView.empty())
    {
        cout << leftView.top() << " ";
        leftView.pop();
    }
    cout << root->val << " ";
    RightView(root->right, rightSize, 0);
}

bool IsSameTree(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2 || root1->val != root2->val)
        return false;
    return IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right);
}

bool IsSubTree(Node *&root, Node *&subRoot)
{
    if (!root && !subRoot)
        return true;
    if (!subRoot)
        return true;
    return IsSameTree(subRoot, Search(root, subRoot->val));
}

void DisplayLongestPath(Node *&root)
{
    if (!root)
        return;
    cout << root->val << " ";
    if (GetHeight(root->left) > GetHeight(root->right))
        DisplayLongestPath(root->left);
    else
        DisplayLongestPath(root->right);
}

int SumDifferent(Node *&root, int level)
{
    if (!root || level == 0)
        return 0;
    if (level % 2 == 0)
        return root->val + SumDifferent(root->left, level - 1) + SumDifferent(root->right, level - 1);
    return -root->val + SumDifferent(root->left, level - 1) + SumDifferent(root->right, level - 1);
}

bool IsPrime(int x)
{
    if (x <= 1)
        return false;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;
    for (int i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

int BiggestPrimeNumber(Node *&root)
{
    if (!root)
        return 0;
    int biggestChildPrime = max(BiggestPrimeNumber(root->left), BiggestPrimeNumber(root->right));
    if (IsPrime(root->val))
        return max(root->val, biggestChildPrime);
    return biggestChildPrime;
}

bool IsFull(Node *&root)
{
    if (!root)
        return false;
    return IsFull(root->left) && IsFull(root->right);
}