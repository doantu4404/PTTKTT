#include <iostream>
using namespace std;

int CalculateFactorial_1(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        int subproblem = CalculateFactorial_1(n - 1);
        int result = n * subproblem;
        return result;
    }
}

int CalculateFactorial_2(int n)
{
    int Factorial = 1;
    if (n == 0 || n == 1)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        Factorial = i * Factorial;
    }
    return Factorial;
}

int main()
{
    cout << "n: ";
    int n;
    cin >> n;

    cout << "Chia de tri:" << endl;
    cout << "\t" << n << "! = " << CalculateFactorial_1(n) << endl;

    cout << "Quy hoach dong:" << endl;
    cout << "\t" << n << "! = " << CalculateFactorial_2(n) << endl;

    return 0;
}
