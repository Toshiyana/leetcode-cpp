#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;       // 配列の要素数
    int *a_heap; // int型のポインタ（後に配列として利用）

    cout << "配列の要素数を入力してください: ";
    cin >> n; // 配列の要素数をキーボードから打ち込む

    // new演算子で整数n個分のメモリを確保
    // 要素数n個の配列として使用可能
    a_heap = new int[n];

    // 以降、利用法は普通の配列と同じ（最後にdeleteでメモリ解放忘れずに）
    for (int i = 0; i < n; i++)
    {
        a_heap[i] = 2 * i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a_heap[i] << endl;
    }

    // new演算子で確保したメモリ領域は、deleteで必ず解放する！（しないと、メモリリーク発生）
    delete[] a_heap;
}