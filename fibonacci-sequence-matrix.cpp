#include <iostream>
using namespace std;

//define Matrix
#define MAX 10
class Matrix
{
private:
    int row, col;
    int map[MAX][MAX];
public:
    Matrix(int r, int c) : row(r), col(c) {}
    friend Matrix operator *(const Matrix&, const Matrix&);
    void init()
    {
        map[0][0] = 1;
        map[0][1] = 1;
        map[1][0] = 1;
        map[1][1] = 0;
    }
    void Uinit()//Unit Matrix
    {
        map[0][0] = 1;
        map[0][1] = 0;
        map[1][0] = 1;
        map[1][1] = 0;
    }
    int result()
    {
        return map[0][1];
    }
};

Matrix operator *(const Matrix& M1, const Matrix& M2)
{
    Matrix M(M1.row, M2.col);
    for(int i = 0; i < M1.row; i++)
    {
        for(int j = 0; j < M2.col; j++)
        {
            M.map[i][j] = 0;
            for(int k = 0; k < M1.col; k++)
            {
                M.map[i][j] += M1.map[i][k] * M2.map[k][j];
            }
        }
    }
    return M;
}

class Solution
{
public:
    int FibonacciMatrix(int n)
    {
        Matrix M(2, 2);
        M.init();
        Matrix R(2, 2);
        R.Uinit();

        while(n)
        {
            if(n % 2)
            {
                R =  R * M;
            }
            M = M * M;
            n /= 2;
        }
        return R.result();
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
            cout << "Fibonacci(" << n << ") = " << s.FibonacciMatrix(n) << endl;
        }
    }
    return 0;
}
