#include <iostream>
using namespace std;

const int N = 1e5+10;

int n, m;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) 
    {
        scanf("%d", &a[i]); // 输入序列
        
        b[i] = a[i] - a[i - 1]; // 构建差分数组
    }
    
    int l, r, c;
    while (m --)
    {
        scanf("%d%d%d", &l, &r, &c);
        
        b[l] += c; //将序列中[l, r]之间的每个数都加上c
        b[r + 1] -= c;
        
    }
    
    // 原数组a[]是(差分数组)b[]的前缀和 a[i] = b[i] + a[i - 1];
    for (int i = 1; i <= n; i ++) printf("%d ", (b[i] + a[i - 1]));
    // for (int i = 1; i <= n; i++)
    // {
    //     a[i] = b[i] + a[i - 1];    //前缀和运算
    //     printf("%d ", a[i]);
    // }
    system("pause");
    return 0;
}
