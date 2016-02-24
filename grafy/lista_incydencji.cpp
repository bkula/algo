#include <iostream>
#include <vector>
using namespace std;

struct V;

struct E // edge
{
    V* to;
    int w; // weight

    E(V* _to, int _w)
    : to(_to)
    , w (_w)
    {
    }
};

struct V // vertex
{
    int id;
    vector<E> e; // lista krawędzi

    V()
    : id(maxId++)
    {
    }

    static int maxId; // ilość wierzchołków
};

int V::maxId = 0;

int main()
{
    int n, m; // wierzchołki, krawędzie
    cin >> n >> m;

    vector<V> graf(n); // skierowany, ważony

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graf[a - 1].e.push_back(E(&graf[b - 1], c));
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ":";
        for (int j = 0; j < graf[i].e.size(); j++) {
            cout << " " << graf[i].e[j].to->id + 1 << "(" << graf[i].e[j].w << ")";
        }
        cout << endl;
    }
}
