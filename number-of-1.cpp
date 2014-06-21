#include <iostream>
using namespace std;

class Solution
{
public:
	int numberOf1(int n)
	{
		int num = 0;
		while(n)
		{
			num++;
			n = (n - 1) & n;
		}
		return num;
	}
};

int main()
{
	int n;
	cin >> n;
	Solution s;
	cout << s.numberOf1(n) << endl;
	return 0;
}
