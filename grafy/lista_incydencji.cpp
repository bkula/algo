#include <iostream>
#include <vector>
using namespace std;

struct E // edge
{
    E(int _to, int _w)
    : to(_to)
    , w (_w)
    {
    }

    int to;
    int w; // weight
};

struct V // vertex
{
    vector<E> e;
};

int main()
{
    int n, m; // wierzchołki, krawędzie
    cin >> n >> m;

    V graf[n]; // skierowany, ważony

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graf[a].e.push_back(E(b, c));
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ":";
        for (int j = 0; j < graf[i].e.size(); j++) {
            cout << " " << graf[i].e[j].to + 1 << "(" << graf[i].e[j].w << ")";
        }
        cout << endl;
    }
}
