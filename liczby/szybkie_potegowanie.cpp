#include <iostream>
using namespace std;

int potega(int a, int n)
{
    if (n == 0) return 1;

    if (n == 1) return a;

    if (n % 2 == 0) {
        int x = potega(a, n / 2);
        return x * x;
    }

    return potega(a, n - 1) * a;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << potega(a, n) << "\n";
}
