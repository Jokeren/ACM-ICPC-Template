#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>

static const int N = 100 << 1;
static const int LEN = 1024;
static const int INF = 0x3f3f3f3f;

int source, sink;
int nnodes, nedges;
int k = INF;
bool query[N][N];

struct edge {
	int from, to, cap, flow, cost;
};

struct mcmf {
	int n, m, s, t, supply;
	std::vector<struct edge> edges;
	std::vector<int> g[N];
	bool inq[N];
	int d[N];
	int p[N];
	int a[N];

	void set_supply(int k)
	{
		supply = k;
	}

	void print()
	{
		printf("round\n");
		for (int i = 0; i < edges.size(); ++i) {
			if (query[edges[i].from][edges[i].to])
			printf("from %d, to %d, cap %d, flow %d, cost %d\n",
					edges[i].from,
					edges[i].to,
					edges[i].cap,
					edges[i].flow,
					edges[i].cost);
		}
	}
	void init(int n) 
	{
		this->n = n;
		for (int i = 0; i <= n; ++i) 
			g[i].clear();

		edges.clear();
	}

	void add_edge(int from, int to, int cap, int cost) 
	{
		edges.push_back((struct edge){from, to, cap, 0, cost});
		edges.push_back((struct edge){to, from, 0, 0, -cost});

		m = edges.size();
		g[from].push_back(m - 2);
		g[to].push_back(m - 1);
	}

	bool spfa(int s, int t, int& flow, int& cost) 
	{
		for (int i = 0; i <= n; ++i) 
			d[i] = INF;

		memset(inq, false, sizeof(inq));
		d[s] = 0; 
		inq[s] = 1; 
		p[s] = 0; 
		a[s] = INF;

		std::queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			inq[u] = false;
			for (int i = 0; i < g[u].size(); ++i) {
				struct edge& e = edges[g[u][i]];
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
					d[e.to] = d[u] + e.cost;
					p[e.to] = g[u][i];
					a[e.to] = std::min(a[u], e.cap - e.flow);
					if (!inq[e.to]) {
						q.push(e.to);
						inq[e.to] = true;
					}

				}
			}
		}

		if (d[t] == INF)
			return false;

		//terminate when it reaches supply

		int aug = a[t];
		bool ret = true;

		if (aug + flow >= supply) {
			aug = supply - flow;
			flow = supply;
			ret = false;
		} else {
			flow += aug;
		}

		cost += d[t] * aug;

		int u = t;
		while (u != s) {
			edges[p[u]].flow += aug;
			edges[p[u] ^ 1].flow -= aug;
			u = edges[p[u]].from;
		}

		return ret;
	}

	int min_cost(int s, int t) 
	{
		int flow = 0, cost = 0;
		while (spfa(s, t, flow, cost));
		return cost;
	}
} min_cost_flow;

