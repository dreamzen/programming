#include <iostream>
#include <stack>
using namespace std;

struct Element
{
    int n;//parameter
    int result;//f(n)'s value
    int status;//1 means back from left, 2 means back from right
    Element(int n1, int s) : n(n1), result(0), status(s) {}
};
/*
when comes a 'n'
if n >= 0, push it into stack
when reach the end, pick one from top
if e.n == 1 or 0, then give the value directly.(f(1) = 1, f(0) = 0)
else 
    if back from left,
    then update its value with r and update staus and push it into stack again
        and set num <-- num -2 to cal f(n-2) with the same method
    
    else(back from right), update its value with r and continue to pop
*/
class Solution
{
public:
    int FibonacciStack(int n)
    {
        stack<Element> s;
        int num = n;
        int r = 0;//save child-node's value (to plus to current f(n))
        while(!s.empty() || num == n)
        {
            if(num >= 0)
            {
                Element e(num, 1);//the first time pushed into stack
                s.push(e);
                num--;
            }
            else//reach the end of tree
            {
                Element e = s.top();
                s.pop();
                
                if(e.n == 0)
                {
                    e.result = 0;
                    r = e.result;
                }
                else if(e.n == 1)
                {
                    e.result = 1;
                    r = e.result;
                }
                else
                {
                    if(e.status == 1)//back from left: f(n-1) is ready --> r
                    {
                        e.result += r;
                        r = e.result;//update f(n)'s value
                        e.status = 2;
                        s.push(e);//push f(n)
                        num = e.n - 2;//continue to cal f(n-2)
                    }
                    else//back from right
                    {
                        e.result += r;//f(n) += f(n-2)
                        r = e.result;
                        num = -1;//continue to pop
                    }
                }
            }
        }
        return r;                
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
            cout << "Fibonacci(" << n << ") = " << s.FibonacciStack(n) << endl;
        }
    }
    return 0;
}
