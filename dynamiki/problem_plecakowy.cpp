#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int pojemnosc, przedmioty;
    cin >> pojemnosc >> przedmioty;

    int plecak[pojemnosc];
    for (int i = 0; i < pojemnosc; i++) {
        plecak[i] = 0;
    }

    for (int i = 0; i < przedmioty; i++)
    {
        int waga, wartosc;
        cin >> waga >> wartosc;

        int nowyPlecak[pojemnosc];

        for (int j = 0; j < pojemnosc; j++)
        {
            if (j - waga >= 0) {
                nowyPlecak[j] = max(plecak[j], plecak[j - waga] + wartosc);
            } else {
                nowyPlecak[j] = plecak[j];
            }
        }

        for (int j = 0; j < pojemnosc; j++) {
            plecak[j] = nowyPlecak[j];
            // cout << plecak[j] << " ";
        }
        // cout << endl;
    }

    cout << plecak[pojemnosc - 1] << '\n';
}
