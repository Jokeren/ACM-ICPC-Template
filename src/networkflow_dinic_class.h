#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>

static const int LEN = 1024;
static const int N = 100 << 1;
static const int INF = 0x3f3f3f3f;

int nnodes, nedges;
int source, sink;
bool query[N][N];

struct edge {
	int from, to, cap, flow;
};

struct dinic {
	int n, m, s, t;
	std::vector<struct edge> edges;
	std::vector<int> g[N];
	bool vis[N];
	int d[N];
	int cur[N];

	void init(int n, int s, int t)
	{
		this->n = n;
		this->s = s;
		this->t = t;
	}

	void print()
	{
		printf("round\n");
		for (int i = 0; i < edges.size(); ++i) {
			if (query[edges[i].from][edges[i].to])
			printf("from %d, to %d, cap %d, flow %d\n",
					edges[i].from,
					edges[i].to,
					edges[i].cap,
					edges[i].flow);
		}
	}

	void add_edge(int from, int to, int cap)
	{
		edges.push_back((struct edge){from, to, cap, 0});
		edges.push_back((struct edge){to, from, 0, 0});

		m = edges.size();
		g[from].push_back(m - 2);
		g[to].push_back(m - 1);
	}

	bool bfs()
   	{
		memset(vis, false, sizeof(vis));
		std::queue<int> q;
		q.push(s);
		
		d[s] = 0;
		vis[s] = true;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < g[x].size(); ++i) {
				struct edge& e = edges[g[x][i]];

				//only consider residual edges
				if (!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					q.push(e.to);
				}
			}
		}

		return vis[t];
	}

	int dfs(int x, int a)
	{
		if (x == t || a == 0)
			return a;

		int flow = 0, f;
		for (int& i = cur[x]; i < g[x].size(); ++i, cur[x] = i) {
			struct edge& e = edges[g[x][i]];
			if (d[x] + 1 == d[e.to] && 
					(f = dfs(e.to, std::min(a, e.cap - e.flow))) > 0) {
				e.flow += f;
				edges[g[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}

		return flow;
	}

	int max_flow()
	{
		int flow = 0;
		while (bfs()) {
			flow += dfs(s, INF);
			print();
		}

		return flow;
	}
} dinic_flow;

