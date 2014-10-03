struct m{
    int v;
    int dist;
};

/* dijkstra不能求最长距离，
 * dijkstra算法把所有顶点分成两组：
 * 一组为已求的最短距离的顶点集合，设为S
 * 另一组为剩下的未求的顶点集合，设为U
 * 每次都从U中取出一个顶点放入S，同时更新该顶点的对应邻接点的最短距离。但是如果某个点不会被之后的U中点更新到，其最短距离就不会改变，所以如果变成最长距离，就错了。
 */
void dijkstra(std::vector<std::vector<struct m> > g, int g_size, int start, int end)
{
    bool vs[N];
    int path[N];
    bool disjoint=false;
    memset(vs,false,sizeof(vs));
    
    for(int i = 0;i<=g_size;i++){
        path[i] = MAX;
    }

    path[start]=0;
//    for(int i=0;i<=g_size;i++){
//        printf("%d\n",path[i]);
//    }
    for(int i=0;i<g_size;i++){
        int min_dist=MAX;
        int tmp_u=-1;
        for(int j=1;j<=g_size;j++){
            if(vs[j]==false&&min_dist>path[j]){
                tmp_u=j;
                min_dist=path[j];
            }
        }
        if(tmp_u!=-1){
    //        printf("%d %d\n",tmp_u,min_dist);
            vs[tmp_u]=true;
            for(int j=0;j<g[tmp_u].size();j++){
                struct m tmp = g[tmp_u][j];
                if(path[tmp.v]>(path[tmp_u]+tmp.dist)){
                    path[tmp.v]=path[tmp_u]+tmp.dist;
                }
            }
        }
    }
    printf("%d",path[end]);
}

/*
 * dijkstra扩展，判定某个点是否在最短路上，正向遍历一遍，然后反向遍历一边，如果两端加起来的值等于最短路的值，那么一定在最短路上（证明？）
 */
int sum = 0;
int path[N];
dijkstra(g,n,n,1,path);
int rpath[N];
dijkstra(g,n,1,n,rpath);
if(path[i]+rpath[i]==path[1]){
	sum++;
}

/* 堆优化，存edge为边效率要高很多
*/
#define _USE_MATH_DEFINES

#ifdef ONLINE_JUDGE
#define FINPUT(file) 0
#define FOUTPUT(file) 0
#else
#define FINPUT(file) freopen(file,"r",stdin)
#define FOUTPUT(file) freopen(file,"w",stdout)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

typedef long long ll;
static const int N = 50010;
static const int M = 10010;
static const int LEN = 1000010;
static const int MAX = 0x7fffffff;
static const int GMAX = 0x3f3f3f3f;
static const ll LGMAX = 3276865536;
static const int MIN = ~MAX;
static const double EPS = 1e-7;
static const int BASE = 10;

struct t_edge {
    int from, to, cost;
};

struct t_heap_node {
	int v, u;
	bool operator < (const struct t_heap_node& node) const {
		return v > node.v;
	}
};


int vertices[N];

struct t_dijkstra {
	int nvertice, m;
	std::vector<struct t_edge> edges;
	std::vector<int> g[N];
	bool visit[N];
	ll dist[N];
	int prev[N];

	void init(int n) {
	    nvertice = n;
		for (int i = 0; i <= nvertice; i++) {
			g[i].clear();
		}
		edges.clear();
		memset(visit, false, sizeof(visit));
		for (int i = 0; i <= nvertice; i++) {
			dist[i] = LGMAX;
		}
	}

	void add_edge(int from, int to, ll cost) {
		edges.push_back((struct t_edge){from, to, cost});
		m = edges.size();
		g[from].push_back(m - 1);
	}

    inline bool relax(ll &w, ll v)
    {
        return w>v ? (w=v,true) : false;
    }

	void dijkstra(int start) {
		std::priority_queue<struct t_heap_node> pq;

		pq.push((struct t_heap_node){0, start});

		dist[start] = 0;
		while (!pq.empty()) {
			struct t_heap_node x = pq.top();
			pq.pop();

			int u = x.u;
			if (visit[u])
				continue;
			visit[u] = true;

			for (int i = 0; i < g[u].size(); i++) {
				struct t_edge e = edges[g[u][i]];
				if (relax(dist[e.to], dist[u] + e.cost)) {
					prev[e.to] = g[u][i];
					pq.push((struct t_heap_node){dist[e.to], e.to});
				}
			}
		}

		ll sum = 0;

		for (int i = 1; i <= nvertice; i++) {
            if (dist[i] == LGMAX) {
                printf("No Answer\n");
                return;
            } else {
                sum += dist[i] * (ll)vertices[i];
            }
		}

		printf("%I64d\n", sum);
	}
} dij;

/*
 * example usage
 */
int main()
{
    FINPUT("in.txt");
	FOUTPUT("out.txt");

    int t;

    while(scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; i++) {
            int v, e;
            scanf("%d %d", &v, &e);
            for (int j = 1; j <= v; j++) {
                scanf("%d", &vertices[j]);
            }

            dij.init(v);
            int from, to, cost;
            for (int j = 1; j <= e; j++) {
                scanf("%d %d %d", &from, &to, &cost);
                dij.add_edge(from, to, cost);
                dij.add_edge(to, from, cost);
            }

            if (v == 0 || v == 1) {
                printf("0\n");
            } else {
                dij.dijkstra(1);
            }
        }
    }

    return 0;
}













