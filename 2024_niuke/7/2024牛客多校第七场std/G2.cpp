#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;
const long long INF = 1LL << 60;
const int LB = 0, RB = 1e9 + 10;

struct Line
{
    int id, l, r;
    long long val;

    Line() = default;

    Line(int _id, int _l, int _r, long long _val)
            : id(_id),
              l(_l),
              r(_r),
              val(_val)
    {
    }
};

class DSU
{
private:
    vector<int> fa;

public:
    DSU(int n)
    {
        fa.resize(n + 1);
        for (int i = 0; i <= n; ++i)
        {
            fa[i] = i;
        }
    }

    int operator[](int x)
    {
        return x == fa[x] ? x : fa[x] = this->operator[](fa[x]);
    }

    void operator()(int x, int y)
    {
        if (this->operator[](x) != this->operator[](y))
        {
            fa[this->operator[](x)] = this->operator[](y);
        }
    }

    bool test(int x, int y)
    {
        return this->operator[](x) == this->operator[](y);
    }
};

class Graph
{
private:
    struct EdgeInner
    {
        int from;
        int to;
        long long val;

        EdgeInner() = default;

        EdgeInner(int _from, int _to, long long _val)
                : from(_from),
                  to(_to),
                  val(_val)
        {
        }
    };

    struct Edge
    {
        int to;
        long long weight;
    };

    class Dijkstra
    {
    public:
        Dijkstra(int n) : n(n), adj(n), dist(n, INF), visited(n, false)
        {}

        void addEdge(int u, int v, long long w)
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        void run(int source)
        {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            dist[source] = 0;
            pq.push({0, source});

            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();

                if (visited[u]) continue;
                visited[u] = true;

                for (const Edge &edge: adj[u])
                {
                    int v = edge.to;
                    long long weight = edge.weight;

                    if (dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        long long getDistance(int target) const
        {
            return dist[target];
        }

    private:
        int n;
        vector<vector<Edge>> adj;
        vector<long long> dist;
        vector<bool> visited;
    };


    vector<EdgeInner> GI;
    Dijkstra dij;
    vector<int> idx;
    int s;

public:
    Graph(int _s, int n) : s(_s), dij(n + 1)
    {
        idx.resize(n + 1);
    }

    void emplace_back(int from, int to, long long val)
    {
        GI.emplace_back(from, to, val);
    }

    template<typename T>
    void build(T &mp)
    {
        for (int i = 0; i < idx.size(); ++i)
        {
            idx[i] = mp[i];
        }
        s = idx[s];
        /*
        cout << "build ---------------- " << endl;
        for (int i = 0; i < idx.size(); ++i)
        {
            cout << idx[i] << " ";
        }
        cout << endl;
        */
        for (auto &i: GI)
        {
            if (idx[i.to] == idx[i.from])
                continue;
            // G[idx[i.to]].emplace_back(idx[i.from], i.val);
            dij.addEdge(idx[i.from], idx[i.to], i.val);
        }
        GI.clear();
        GI.shrink_to_fit();
        dij.run(s);
    }

    long long operator()(int id)
    {
        id = idx[id];
        return dij.getDistance(id);
    }
};

struct ANS_NODE
{
    int id, u, v;

    ANS_NODE() = default;

    ANS_NODE(int _id, int _u, int _v) : id(_id), u(_u), v(_v)
    {}
};

vector<ANS_NODE> ans;
vector<Line> ln[MAXN], lnw[MAXN];

int main()
{
    //freopen("1.txt","r",stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, l;
        long long v;
        scanf("%d %d %d %lld", &x, &y, &l, &v);
        ln[x].emplace_back(i, y, y + l - 1, v);
    }
    if (
            [&]()
            {
                for (int i = 1; i <= n; ++i)
                {
                    if (ln[i].empty())
                    {
                        return true;
                    }
                }
                return false;
            }())
    {
        for (int i = 0; i < m; ++i)
        {
            printf("0\n");
        }
        return 0;
    }
    //-------------------
    int s = 1;
    int t = 2;
    Graph g(s, n + m + 2), ig(t, n + m + 2);
    DSU dsu(n + m + 2);

    int id = 2;
    long long SP = INF;

    for (int i = 1; i <= n; ++i)
    {
        sort(ln[i].begin(), ln[i].end(), [](const Line &A, const Line &B)
        {
            return A.l < B.l;
        });
        lnw[i].emplace_back(++id, LB, ln[i][0].l - 1, 0);
        g.emplace_back(id, id + 1, ln[i][0].val);
        ig.emplace_back(id + 1, id, ln[i][0].val);
        ans.emplace_back(ln[i][0].id, id, id + 1);
        for (int j = 1; j < ln[i].size(); ++j)
        {
            lnw[i].emplace_back(++id, ln[i][j - 1].r + 1, ln[i][j].l - 1, 0);
            g.emplace_back(id, id + 1, ln[i][j].val);
            ig.emplace_back(id + 1, id, ln[i][j].val);
            ans.emplace_back(ln[i][j].id, id, id + 1);
        }
        lnw[i].emplace_back(++id, ln[i][ln[i].size() - 1].r + 1, RB, 0);
        if (i != 1)
        {
            auto p1 = lnw[i - 1].begin(), p2 = lnw[i].begin();
            while (p1 != lnw[i - 1].end() && p2 != lnw[i].end())
            {
                if (max(p1->l, p2->l) <= min(p1->r, p2->r) + 1)
                {
                    dsu(p1->id, p2->id);
                }
                if (p1->r <= p2->r)
                    ++p1;
                else
                    ++p2;
            }
        }

        dsu(lnw[i].begin()->id, s);
        dsu(lnw[i].rbegin()->id, t);
    }
    assert(id == n + m + 2);
    g.build(dsu);
    ig.build(dsu);

    //------------------
    /*
    cout << "black" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " ----" << endl;
        for (auto& j : ln2[i])
        {
            cout << j.id << " " << j.l << " " << j.r << " " << j.val << endl;
        }
    }
    cout << "end black" << endl;
    cout << "white" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " ----" << endl;
        for (auto& j : lnw[i])
        {
            cout << j.id << " " << j.l << " " << j.r << endl;
        }
    }
    cout << "end white" << endl;
    */
    //-------------------
    SP = g(t);
    sort(ans.begin(), ans.end(),
         [](const ANS_NODE &A, const ANS_NODE &B)
         {
             return A.id < B.id;
         });
    assert(ans.begin()->id == 1);
    assert(ans.rbegin()->id == m);
    for (auto &i: ans)
    {
        //cout << "t " << i.u << " " << i.v << endl;
        //cout << "test " << g(i.u) << " " << ig(i.v) << endl;
        //cout << "e id " << i.id << endl;
        long long temp = min(g(i.u) + ig(i.v), g(i.v) + ig(i.u));
        printf("%lld\n", min(temp, SP));
    }
    return 0;
}