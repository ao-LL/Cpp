#include<iostream>
using namespace std;

const int N = 10;

int n, q[N];
bool b[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++)
            printf("%d ", q[i]);
        puts("");
    }
    for (int i = 1; i <= n; i ++)
    {
        if (! b[i]) 
        {
            q[u] = i;  // 注意 
            b[i] = true;
            dfs(u + 1);
            b[i] = false;
            // 当i == 3, u == 2 时，dfs(3)输出 1 2 3; 回来执行b[3] = false;
            // 此时回溯到 i == 2，u == 1, dfs(2), 执行b[2] = false；
            // 则进入for(i = 3), q[u == 1] = 3; b[3] = true; 进入dfs(1 + 1);
            // 到f(i == 2), q[2] = 2; ...
        }
    }
    
}


int main()
{
    // scanf("%d", &n);
    n = 3;
    
    dfs(0);
    
    return 0;
}