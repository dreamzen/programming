#include <iostream>
using namespace std;

class Solution
{
public:
    int FibonacciIterative(int n)
    {
        int result;
        int tmp1;
        int tmp2;
        tmp1 = 0;
        tmp2 = 1;
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        //n=2, Iterate one time
        for(int i = 1; i < n; i++)
        {
            result = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = result;
        }
        return result;
    }
};

int main()
{
    int n;
    Solution s;
    while(cin >> n)
    {
        if(n < 0)
        {
            break;
        }
        else
        {
            cout << "Fibonacci(" << n << ") = " << s.FibonacciIterative(n) << endl;
        }
    }
    return 0;
}
