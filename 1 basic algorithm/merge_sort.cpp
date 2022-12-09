#include<iostream>
using namespace std;

const int N = 1e5 + 10 ;

int q[N], tmp[N];


void meger_sort(int q[], int l, int r)
{
    if (l >= r ) return;

    int mid = l + r >> 1;   // 分界点

    meger_sort(q, l, mid), meger_sort(q, mid + 1, r);   // 递归排序

    int i = l, j = mid + 1, k = 0;  // 左起点，右起点，k 代表结果数组(中间状态)中合并了几个数

    while (i <= mid && j <= r)   // 左、右半部分没有归并完
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++];  // 比较左右部分中最小的
        else tmp[k ++ ] = q[j ++ ];
    
    while (i <= mid) tmp[k ++ ] = q[i ++ ];  // 左部分中有一段数据均大于右部分时，将这段数据归并
    while (j <= r) tmp[k ++ ] = q[j ++ ];    // 同理

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];   // 将结果复制回原数组

}


int main()
{
    int n;
    printf("input len: ");
    scanf("%d", &n);

    printf("input num: ");
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    meger_sort(q, 0, n-1);

    printf("output: ");
    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    system("pause");
    return 0;
}