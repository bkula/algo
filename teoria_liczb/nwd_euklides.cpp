#include <iostream>
#include <algorithm>
using namespace std;

int nwd(int a, int b)
{
    if (b != 0) return nwd(b, a % b);
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << nwd(a, b) << "\n";
}
