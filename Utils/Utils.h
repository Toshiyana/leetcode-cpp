#pragma once

#include <bits/stdc++.h>

using namespace std;

//----------------------------------------------------------------------------
// Definition
//----------------------------------------------------------------------------
// Vector
template <typename T>
void print1dVector(vector<T> vec);

template <typename T>
void print2dVector(vector<vector<T>> vec);

// Set
template <typename T>
void printUnorderedSet(unordered_set<T> set);

// Map
template <typename T>
void printUnorderedMap(unordered_map<T, T> mp);

// ListNode
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
template <typename T>
void printListNode(T *head);

//----------------------------------------------------------------------------

template <typename T>
void print1dVector(vector<T> vec)
{
    int length = vec.size();
    // cout << "Length: " << length << endl;
    // cout << endl;

    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << vec[i];
        if (i == (length - 1))
            cout << " ";
        else
            cout << ", ";
    }
    cout << "}" << endl;
}

template <typename T>
void print2dVector(vector<vector<T>> vec)
{
    int height = vec.size();
    // int width = vec[0].size(); // 全ての行で, 列数が同じ場合

    // cout << "Height: " << height << endl;
    // cout << "Width: " << width << endl;

    cout << endl;

    cout << "{" << endl;

    for (int y = 0; y < height; y++)
    {
        int width = vec[y].size(); // 行ごとに、列数が異なる場合
        cout << "   { ";
        for (int x = 0; x < width; x++)
        {
            cout << vec[y][x];
            if (x == (width - 1))
                cout << " ";
            else
                cout << ", ";
        }
        cout << "}," << endl;
    }

    cout << "}" << endl;
}

template <typename T>
void printUnorderedSet(unordered_set<T> set)
{
    cout << "{ ";
    for (auto x : set)
    {
        cout << x << ", ";
    }
    cout << "}" << endl;
}

template <typename T>
void printUnorderedMap(unordered_map<T, T> mp)
{
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        cout << "key = " << it->first << ", val = " << it->second << endl;
    }
}

// ListNode
template <typename T>
void printListNode(T *head)
{
    cout << head->val << endl;
    while (head->next)
    {
        head = head->next;
        cout << head->val << endl;
    }
}