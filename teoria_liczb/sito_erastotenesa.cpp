#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n++;

    int tab[n];
    tab[0] = tab[1] = 0; // 0 i 1 nie są liczbami pierwszymi
    for (int i = 2; i < n; i++) tab[i] = 1;

    for (int i = 2; i < n; i++) {
        if (tab[i]) { // jeśli i jest liczbą pierwszą
            for (int j = i * 2; j < n; j += i) { // wykreślanie wielokrotności
                tab[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) { // liczby pierwsze mniejsze do n
        if (tab[i]) cout << i << " ";
    }
    cout << endl;
}
