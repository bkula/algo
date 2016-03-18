/*

Pole wielokąta

IN
    n wierzchołków o współrzędnych x, y

OUT
    pole wielokąta opisanego tymi wierzchołkami

EXAMPLE

    in:
    4
    0 3
    4 5
    3 4
    5 1

    out:
    6.5

*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

float FINF = numeric_limits<float>::max();

struct P // punkt
{
    float x, y;
};

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    P wielokat[n + 1];

    float podloga = FINF; // prosta na równoległa do OX zawierająca ścian wszystkich trapezów

    for (int i = 0; i < n; i++) {
        cin >> wielokat[i].x >> wielokat[i].y;
        podloga = min(podloga, wielokat[i].y);
    }

    wielokat[n] = wielokat[0];

    float pole = 0.0f;

    // dzielimy wielokąt na trapezy
    // jeśli x1 > x2 to h < 0 więc trapez będzie odejmowany od pola całkowitego
    // w przeciwnym wypadku pole trapezu będzie dodawane do pola całkowitego

    for (int i = 0; i < n; i++) {
        float a = wielokat[i].y - podloga;
        float b = wielokat[i + 1].y - podloga;
        float h = wielokat[i + 1].x - wielokat[i].x;
        pole += (a + b) * h / 2.0f;
    }

    cout << pole << "\n";
}
