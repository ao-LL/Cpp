#include<iostream>
#include<vector>
using namespace std;


bool cmp(vector<int> &A, vector<int> &B) // 判断A B的大小关系
{
    if (A.size() != B.size()) return A.size() > B.size(); // 位数不等可直接判断
    
    for (int i = A.size() - 1; i >= 0; i --)
        if (A[i] != B[i])  
            return A[i] > B[i];  // 判断高位之间的大小
            
    return true; // A == B 时 
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0; // 当前位的差值，以及是否向高位借1的标志
    for (int i = 0; i < A.size(); i ++)
    {
        t = A[i] - t; // 如果被 低位 借1，则对应高位需要减去1
        
        if (i < B.size())  t -= B[i]; // 判断 B 是否有 某个位(个十百千), 比如A有百位，B没有，就不用计算百位的减法
        
        C.push_back((t + 10) % 10); // 由A[i]和B[i]之间的关系可分两种情况，但可只用这一行代码表示
        
        if (t < 0) t = 1; // 由t -= B[i] 表明A[i]<B[i]，则需要向高一位借1
        else t = 0;
    }
    
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 去掉前导零，比如 解为 003 则只保留 3
    
    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;
    
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0');
    
    if (cmp(A, B))
    {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]); 
    }
    else
    {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]); 
    }
        
    return 0;
}