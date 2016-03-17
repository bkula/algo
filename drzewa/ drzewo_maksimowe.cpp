/*

Drzewo maksimowe

IN
    n liczb (dodatnie i ujemne)
    q zapytań:
    - MODIFY indeks wartość
    - MAXIMUM od do

OUT
    dla każdego zapytania MAXIMUM:
    maksimum na przedziale <od,do>

EXAMPLE

    in:
    5
    2 1 3 -1 8
    4
    MAXIMUM 4 4
    MAXIMUM 1 5
    MAXIMUM 2 4
    MODIFY 5 -2
    MAXIMUM 1 5

    out:
    -1
    8
    3
    3

TIME
    x = ilość zapytań o maksimum
    O(x * log n)

MEMORY
    ~ 2*n
*/

#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

int INF = numeric_limits<int>::max(); // nieskończoność

class Tree // statyczne, binarne, przedziałowe, maksimowe
{
public:

    Tree(int n)
    {
        leafs = 1;
        while (leafs < n) leafs *= 2;

        tab.resize(leafs * 2, -INF); // root = 1

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            modify(i, x);
        }
    }

    void modify(int i, int val)
    {
        tab[leafs + i] = val;

        int v = (leafs + i) / 2;

        while (v >= 1) {
            tab[v] = max(tab[v * 2], tab[v * 2 + 1]);
            v /= 2;
        }
    }

    // przedział <l,r>
    // liście numerujemy do 0 do leafs-1
    int maximum(int l, int r)
    {
        base.clear();
        fillBase(1, l, r, 0, leafs - 1); // od korzenia w dół

        int result = -INF; // maximum z przedziałów bazowych
        for (int i = 0; i < base.size(); i++) {
            result = max(result, tab[base[i]]);
        }

        return result;
    }

    // v - vertex w którym jesteśmy
    // l, r - docelowy przedział
    // a, b - przedział wierzchołka v
    void fillBase(int v, int l, int r, int a, int b)
    {
        int mid = (a + b) / 2;
        // przedziały synów:
        // v*2: a, mid
        // v*2+1: mid+1, b

        if (a == l && b == r) // mamy przedział bazowy
        {
            base.push_back(v);
        }
        else if (r <= mid) // l,r znajduje się w lewym potomku
        {
            fillBase(v * 2, l, r, a, mid);
        }
        else if (l >= mid + 1) // l,r znajduje się w prawym potomku
        {
            fillBase(v * 2 + 1, l, r, mid + 1, b);
        }
        else // l, r znajduje się i w lewym i w prawym potomku
        {
            fillBase(v * 2, l, mid, a, mid);
            fillBase(v * 2 + 1, mid + 1, r, mid + 1, r);
        }
    }

private:

    int leafs; // liczba liści & indeks pierwszego liścia

    vector<int> tab; // maxima

    vector<int> base; // zbiór przedziałów bazowych (fillBase)
};

int main()
{
    int n;
    cin >> n;

    Tree tree(n); // tworzymy drzewo n-liściowe

    int q;
    cin >> q;

    while (q-- > 0)
    {
        string str;
        cin >> str;

        if (str == "MODIFY")
        {
            int index, value;
            cin >> index >> value;
            tree.modify(index - 1, value);
        }
        else if (str == "MAXIMUM")
        {
            int from, to;
            cin >> from >> to;
            cout << tree.maximum(from - 1, to - 1) << '\n';
        }
    }
}
