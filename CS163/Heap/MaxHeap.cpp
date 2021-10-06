#include <iostream>
#include <vector>
using namespace std;

void UpHeap(vector<int> &tree, int i)
{
    int parent = i / 2;
    if (tree[parent] < tree[i])
    {
        swap(tree[i], tree[parent]);
        UpHeap(tree, parent);
    }
}

void Insert(vector<int> &tree, int x)
{
    tree.push_back(x);
    UpHeap(tree, tree.size() - 1);
}

void DownHeap(vector<int> &tree, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left > tree.size() || right > tree.size())
        return;
    if (tree[i] > tree[left] && tree[i] > tree[right])
        return;
    if (tree[i] < tree[left] && tree[i] < tree[right])
    {
        if (tree[left] < tree[right])
        {
            swap(tree[i], tree[left]);
            return DownHeap(tree, left);
        }
        swap(tree[i], tree[right]);
        DownHeap(tree, right);
    }
    if (tree[left] < tree[right])
    {
        swap(tree[i], tree[right]);
        return DownHeap(tree, right);
    }
    swap(tree[i], tree[left]);
    DownHeap(tree, left);
}