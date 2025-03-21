#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i ++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];  // t = a[i]+b[i]+t;
        C.push_back(t % 10); // 小学加法 只保留个位
        t /= 10; // 判断是否有进位 逢十进一
    }

    if (t) C.push_back(1); // 如果最高位还有进位，则进1

    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;

    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0'); // Ascll表转化
    for (int i = b.size() - 1; i >= 0; i --) B.push_back(b[i] - '0'); // 低位保存在数组起始位

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]); // 高位保存在数组尾，所以要逆序输出

    system("pause");
    return 0;
}
