#include <iostream>
using namespace std;

class Solution
{
public:
    int FibonacciRecursive(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1 || n == 2)
        {
            return 1;
        }
        else
        {
            return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
        }
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
            cout << "Fibonacci(" << n << ") = " << s.FibonacciRecursive(n) << endl;
        }
    }
    return 0;
}
