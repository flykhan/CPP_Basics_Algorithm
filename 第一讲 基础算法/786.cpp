#include <iostream>

using namespace std;

const int N = 100010;

int q[N];

int quick_sort(int q[], int l, int r, int k)
{
    if (l >= r)
        return q[l]; // l=r 表示只有一个值进行排序，则直接返回这个位置的值

    int i = l - 1, j = r + 1;
    int x = q[l + r >> 1]; // 移位运算符 >> 表示 l+r 除以了 2
    while (i < j)          // i 索引位置在 j 索引位置的前面，则循环
    {
        do
            i++;
        while (q[i] < x); // i++ 表示索引 i 向后移动一位，如果 q[i] 的值此时依然小于 x 的值，则继续向后移动索引 i，直到找到比 x 大的值
        do
            j--;
        while (q[j] > x); // j-- 表示索引 j 向前移动一位，如果 q[j] 的值此时依然大于 x 的值，则继续向前移动索引 j， 知道找到比 x 小的值
        if (i < j)
            swap(q[i], q[j]); // 当找到了比 x 大的 q[i] ，以及比 x 小的 q[j] 值；且满足这个时候 i 依然在 j 索引的前面位置时，交换 i j 索引位置的值
    }

    // 每次都排序好一半
    if (j - l + 1 >= k)
        return quick_sort(q, l, j, k);
    else
        return quick_sort(q, j + 1, r, k - (j - l + 1));
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    cout << quick_sort(q, 0, n - 1, k) << endl;
    return 0;
}
