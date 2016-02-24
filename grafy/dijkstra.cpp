// DIJKSTRA

// konwencja:
// C++98
// oddzielna klasa dla krawędzi i dla wierchołka
// jak najwięcej wskaźników, a jak najmniej id
// funktor porównujący dla kolejki
// nieskończoność do oznaczenia nieodwiedzonego wierzchołka

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

const int INF = numeric_limits<int>::max();

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
    int s; // street
    V* f; // father
    bool visited;

    V()
    : id(maxId++)
    , s(INF)
    , f(nullptr)
    , visited(false)
    {
    }

    static int maxId; // ilość wierzchołków
};

int V::maxId = 0; // 0 wierzchołków na starcie

struct Comp // copares V*
{
    bool operator()(V* a, V* b)
    {
        return a->s < b->s;
    }
};

int main()
{
    int n, m; // wierzchołki, krawędzie
    cin >> n >> m;

    vector<V> graf(n); // skierowany, ważony

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graf[a - 1].e.push_back(E(&graf[b - 1], c)); // wejście 1...n
    }

    V* root = &graf[0];
    root->s = 0;

    priority_queue<V*, vector<V*>, Comp> q;
    q.push(root);

    while (! q.empty())
    {
        V* v = q.top();
        q.pop();

        if (v->visited) continue; // pomijam wierzchołek jeśli już w nim byłem
        else v->visited = true;

        for (int i = 0; i < v->e.size(); i++)
        {
            V* v1 = v->e[i].to; // i-ty sąsiad v
            int s = v->s + v->e[i].w; // droga z root do v1 przez v

            if (s < v1->s) { // czy znalazłem lepszą drogę?
                v1->f = v;
                v1->s = s;
                q.push(v1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": " << graf[i].s << "\n";
    }
}
