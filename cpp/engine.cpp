// 1. Dijkstra: Returns path and total distance
json runDijkstra(const Graph& g, int source, int target) {
    int n = g.n;
    vector<double> dist(n, numeric_limits<double>::infinity());
    vector<int> parent(n, -1);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& e : g.adj[u]) {
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    json result;
    if (dist[target] == numeric_limits<double>::infinity()) {
        result["found"] = false;
    } else {
        result["found"] = true;
        result["distance"] = dist[target];
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        result["path"] = path;
    }
    return result;
}

// 2. Dinic: Helper BFS/DFS needed
bool bfs(Graph& g, int s, int t, vector<int>& level) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& e : g.adj[u]) {
            if (e.cap - e.flow > 0 && level[e.to] == -1) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

long long dfs(Graph& g, int u, int t, long long pushed, vector<int>& level, vector<int>& ptr) {
    if (pushed == 0 || u == t) return pushed;
    for (int& i = ptr[u]; i < g.adj[u].size(); ++i) {
        auto& e = g.adj[u][i];
        if (level[u] + 1 != level[e.to] || e.cap - e.flow == 0) continue;
        long long tr = dfs(g, e.to, t, min(pushed, e.cap - e.flow), level, ptr);
        if (tr == 0) continue;
        e.flow += tr;
        g.adj[e.to][e.rev].flow -= tr;
        return tr;
    }
    return 0;
}

json runDinic(Graph& g, int source, int target) {
    long long flow = 0;
    vector<int> level(g.n);
    while (bfs(g, source, target, level)) {
        vector<int> ptr(g.n, 0);
        while (long long pushed = dfs(g, source, target, 1e18, level, ptr)) flow += pushed;
    }
    json result;
    result["found"] = (flow > 0);
    result["max_flow"] = flow;
    return result;
}

// 3. Min-Cut: Perform a reachable BFS from source in the residual graph
json runMinCut(Graph& g, int source, int target) {
    // Run flow first to get the residual graph
    runDinic(g, source, target);
    
    vector<bool> reachable(g.n, false);
    queue<int> q;
    q.push(source);
    reachable[source] = true;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& e : g.adj[u]) {
            if (e.cap - e.flow > 0 && !reachable[e.to]) {
                reachable[e.to] = true;
                q.push(e.to);
            }
        }
    }

    json cut_edges = json::array();
    for (int u = 0; u < g.n; ++u) {
        if (reachable[u]) {
            for (auto& e : g.adj[u]) {
                if (!reachable[e.to] && e.cap > 0) {
                    cut_edges.push_back({{"from", u}, {"to", e.to}});
                }
            }
        }
    }
    json result;
    result["found"] = true;
    result["cut_edges"] = cut_edges;
    return result;
}
