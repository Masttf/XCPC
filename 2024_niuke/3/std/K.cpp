#include <bits/stdc++.h>
using namespace std;
const char el = '\n';
typedef long long ll;
 
typedef long long flow_t;
const flow_t inf_flow = 1e18;
const int inf_dep = 1e9;
 
struct FlowEdge {
  int from, to;
  flow_t cap, low = 0, flow = 0;
};
 
int num_node(const std::vector<FlowEdge> &edges) {
  int n = 0;
  for (const auto &e : edges) n = std::max({n, e.from, e.to});
  return n;
}
 
flow_t get_flow(const std::vector<FlowEdge> &edges, int s) {
  flow_t flow = 0;
  for (const auto &e : edges) {
    if (e.from == s) flow += e.flow;
  }
  return flow;
}
 
struct MaxFlow {
  struct Edge {
    int from, to;
    flow_t cap;
  };
  int n;
  std::vector<std::vector<int>> eid;
  std::vector<Edge> edge;
  void build(const std::vector<FlowEdge> &edges) {
    n = num_node(edges);
    eid.assign(n + 1, {});
    edge.clear();
    int num_edges = 0;
    for (const auto &e : edges) {
      eid[e.from].push_back(num_edges++);
      edge.push_back({e.from, e.to, e.cap - e.flow});
      eid[e.to].push_back(num_edges++);
      edge.push_back({e.to, e.from, e.flow});
    }
  }
 
  std::vector<int> dis;
  std::vector<int> cur;
  bool bfs(int s, int t) {
    if (s > n || t > n) return false;
    dis.assign(n + 1, inf_dep);
    cur.assign(n + 1, 0);
    std::queue<int> que;
    dis[s] = 0;
    que.push(s);
    while (que.size()) {
      int u = que.front();
      que.pop();
      for (auto i : eid[u]) {
        const auto &e = edge[i];
        if (e.cap && dis[e.to] > dis[u] + 1) {
          dis[e.to] = dis[u] + 1;
          que.push(e.to);
        }
      }
    }
    return dis[t] < inf_dep;
  }
 
  flow_t dfs(int s, int t, flow_t flim) {
    if (s == t) return flim;
    flow_t flow = 0;
    for (int &i = cur[s]; i < eid[s].size() && flow < flim; i++) {
      auto &e = edge[eid[s][i]];
      if (dis[e.to] == dis[s] + 1 && e.cap) {
        auto detf = dfs(e.to, t, std::min(flim - flow, e.cap));
        flow += detf;
        e.cap -= detf;
        edge[eid[s][i] ^ 1].cap += detf;
      }
      if (flow == flim) break;
    }
    return flow;
  }
  flow_t maxflow(int s, int t) {
    flow_t flow = 0;
    while (bfs(s, t)) {
      flow += dfs(s, t, inf_flow);
    }
    return flow;
  }
 
  std::vector<FlowEdge> to_edge() {
    std::vector<FlowEdge> edges;
    for (int i = 0; i < edge.size(); i += 2)
      edges.push_back({
          .from = edge[i].from,
          .to = edge[i].to,
          .cap = edge[i].cap + edge[i ^ 1].cap,
          .low = 0,
          .flow = edge[i ^ 1].cap,
      });
    return edges;
  }
};
 
struct Processor {
  std::vector<bool> neg;
  std::vector<flow_t> low;
  std::vector<flow_t> excess;
  void init(std::vector<FlowEdge> &edges) {
    int n = num_node(edges);
    neg.clear();
    neg.reserve(edges.size());
    low.clear();
    low.reserve(edges.size());
    excess.assign(n + 1, 0);
  }
  void rmv_low(std::vector<FlowEdge> &edges) {
    for (auto &e : edges) {
      low.push_back(e.low);
      if (e.flow >= e.low) {
        e.flow -= e.low;
      } else {
        excess[e.from] -= e.low - e.flow;
        excess[e.to] += e.low - e.flow;
        e.flow = 0;
      }
      e.cap -= e.low;
      e.low = 0;
    }
  }
  void add_low(std::vector<FlowEdge> &edges) {
    reverse(low.begin(), low.end());
    for (auto &e : edges) {
      e.low = low.back();
      e.flow += e.low;
      e.cap += e.low;
      low.pop_back();
    }
  }
};
 
bool excess_flow(std::vector<FlowEdge> &edges,
                 const std::vector<flow_t> &excess) {
  int n = num_node(edges), m = edges.size();
  for (int i = 1; i <= n; i++) {
    if (excess[i] > 0)
      edges.push_back({.from = n + 1, .to = i, .cap = excess[i]});
    if (excess[i] < 0)
      edges.push_back({.from = i, .to = n + 2, .cap = -excess[i]});
  }
  MaxFlow g;
  g.build(edges);
  g.maxflow(n + 1, n + 2);
  edges = g.to_edge();
  for (int i = m; i < edges.size(); i++)
    if (edges[i].flow != edges[i].cap) return false;
  edges.resize(m);
  return true;
}
 
std::optional<flow_t> feasible_flow(std::vector<FlowEdge> &edges, int s = 0,
                                    int t = 0) {
  if (s && t) edges.push_back({.from = t, .to = s, .cap = inf_flow});
  Processor p;
  p.init(edges);
  p.rmv_low(edges);
  if (!excess_flow(edges, p.excess)) return std::nullopt;
  if (s && t) edges.pop_back();
  p.add_low(edges);
  return get_flow(edges, s);
}
 
std::optional<flow_t> maximum_flow(std::vector<FlowEdge> &edges, int s, int t) {
  edges.push_back({.from = t, .to = s, .cap = inf_flow});
  Processor p;
  p.init(edges);
  p.rmv_low(edges);
  if (!excess_flow(edges, p.excess)) return std::nullopt;
  edges.pop_back();
  MaxFlow g;
  g.build(edges);
  g.maxflow(s, t);
  edges = g.to_edge();
  p.add_low(edges);
  return get_flow(edges, s);
}
 
std::optional<flow_t> minimum_flow(std::vector<FlowEdge> &edges, int s, int t) {
  edges.push_back({.from = t, .to = s, .cap = inf_flow});
  Processor p;
  p.init(edges);
  p.rmv_low(edges);
  if (!excess_flow(edges, p.excess)) return std::nullopt;
  edges.pop_back();
  MaxFlow g;
  Processor q;
  excess_flow(edges, q.excess);
  g.build(edges);
  g.maxflow(t, s);
  edges = g.to_edge();
  p.add_low(edges);
  return get_flow(edges, s);
}
const ll inf = 1e9;
struct graph2 {
  vector<vector<int>> e;
  graph2(int n) : e(n + 1) {}
  void adde(int u, int v) { e[u].push_back(v); }
  void dfs(int u, vector<bool> &vis) {
    vis[u] = true;
    for (auto v : e[u])
      if (!vis[v]) dfs(v, vis);
  }
  vector<bool> spread(int src) {
    vector<bool> vis(e.size());
    dfs(src, vis);
    return vis;
  }
};
struct graph {
  int n, k;
  vector<FlowEdge> ed;
  const int src = 1, sink = 2;
  vector<int> din, dout;
  int id(int u, int i, int j) { return 3 + 2 * k * u + 2 * i + j; }
  int vtx(int id) { return (id - 3) / 2 / k; }
  graph(int n, int k) : n(n), k(k), din(n + 1), dout(n + 1) {
    for (int u = 1; u <= n; u++) {
      for (int i = 0; i < k; i++) ed.push_back({id(u, i, 0), id(u, i, 1), 1});
      for (int i = 1; i < k; i++)
        ed.push_back({id(u, i - 1, 0), id(u, i, 1), inf});
    }
  }
  void adde(int u, int v) {
    dout[u]++, din[v]++;
    for (int i = 0; i < k; i++) ed.push_back({id(u, i, 1), id(v, i, 0), inf});
  }
  void solve() {
    for (int i = 1; i <= n; i++) {
      if (!din[i])
        // cout << "in " << i << el,
        ed.push_back({src, id(i, 0, 1), inf});
      if (!dout[i])
        // cout << "out " << i << el,
        ed.push_back({id(i, k - 1, 0), sink, inf});
    }
    for (auto e : ed)
      if (e.flow) {
      }
    auto v = *maximum_flow(ed, src, sink);
    if (v > inf / 2) {
      cout << -1 << el;
      return;
    }
    int n2 = 0;
    for (auto e : ed) n2 = max(n, e.from);
    graph2 g(n2);
    for (auto e : ed) {
      if (e.flow < e.cap) g.adde(e.from, e.to);
      if (e.flow) g.adde(e.to, e.from);
    }
    vector<bool> vis = g.spread(src);
    vector<int> ans;
    for (auto e : ed)
      if (vis[e.from] && !vis[e.to] && e.to != sink && e.from != src) {
        ans.push_back(vtx(e.from));
      }
    cout << ans.size() << el;
    for (auto &v : ans) cout << v << ' ';
    cout << el;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15);
  int n, m, k;
  cin >> n >> m >> k;
  graph g(n, k);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g.adde(u, v);
  }
  g.solve();
  return 0;
}