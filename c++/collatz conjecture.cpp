#include <iostream>
using namespace std;
long long int isEven(int n)
{
    if (n % 2 == 0)
    {
        return n / 2;
    }
    else
        return n * 3 + 1;
}
int main()
{
    long long int n, steps = 0;
    cout << "Enter the number\n";
    cin >> n;
    do
    {

        n = isEven(n);
        steps++;
        cout << n << endl;
    } while (n != 1);
    cout << "Total steps " << steps;
    return 0;
}