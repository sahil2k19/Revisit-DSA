#include <bits/stdc++.h>

using namespace std;

int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int a = fibo(n - 1);
    int b = fibo(n - 2);

    return a + b;
}
int fibo_helper(int n, int *ans)
{
    // base case
    if (n <= 1)
    {
        return n;
    }
    // check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);

    // save output and return;
    return ans[n] = a + b;
}

int fibo2(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fibo_helper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << fibo2(n) << endl;
}