/*
 * 适用于无向图求桥和割点，求桥只要找到pre[i] == lowu[i]的次数
 */
struct tarjan_t {
    std::vector<int> g[N];
    int pre[N];
    int iscut[N];
    int low[N];
    int dfs_clock;

    void start(int v)
    {
        memset(pre, 0, sizeof(pre));
        memset(iscut, 0, sizeof(iscut));
        memset(low, 0, sizeof(low));
        dfs_clock = 1;
        dfs(v, -1);
        for (int i = 0; i < N; ++i) {
            g[i].clear();
        }
    }

    void add(int x, int y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int dfs(int u, int fa)
    {
        int lowu = pre[u] = ++dfs_clock;

        int child = 0;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (!pre[v]) {
                ++child;
                int lowv = dfs(v, u);
                lowu = std::min(lowu, lowv);
                if (lowv >= pre[u]) {
                    ++iscut[u];
                }
            } else if (pre[v] < pre[u] && v != fa) {
                lowu = std::min(lowu, pre[v]);
            }
        }

        if (fa < 0 && child == 1) {
            iscut[u] = 0;
        }
        low[u] = lowu;
        return lowu;
    }
}tarjan;