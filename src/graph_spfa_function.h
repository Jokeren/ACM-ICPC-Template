struct edge{
    int from, to, cost;
};

std::vector<int> g[N];//这种存法比前向星更直观，并且比vector<vector>效率高很多，比vector<edge>效率也要高
std::vector<struct edge> edges;

inline bool relax(int &w, int v)//差分约束的时候要注意，如果是>，那么找最小中的最大，relax条件是w < v
{
    return w>v ? (w=v,true) : false;
}

void inline add_edge(int from, int to, int cost)
{
    edges.push_back((struct edge){from, to, cost});
    int m = edges.size();
    g[from].push_back(m - 1);
}

void spfa(int n, int start, int end)
{
    ll dist[N];
    int in_queue_count[N];
    bool in_queue[N];
    std::queue<int> q;

    for (int i = 0; i <= n; i++) {
        dist[i] = LGMAX;//差分约束的时候要注意，修改为最小值
    }
    memset(in_queue, false, sizeof(in_queue));
    memset(in_queue_count, 0, sizeof(in_queue_count));

    int now = start;
    for(dist[now]=0,q.push(now),in_queue[now]=true,in_queue_count[now]=1;
    q.empty()==false;in_queue[now]=false,q.pop()){
        now = q.front();
        for(int i=0; i<(int)g[now].size();i++){
            struct edge e = edges[g[now][i]];
            if(relax(dist[e.to], dist[now]+e.cost)){
                if(in_queue[e.to]==false){
                    q.push(e.to);
                    in_queue[e.to]=true;
                    if(++in_queue_count[e.to]>n){//其实应该是>=，不过多转一圈也没事
                        printf("No Answer\n");
                        return;
                    }
                }
            }
        }
    }

    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == LGMAX) {
            printf("No Answer\n");
            return ;
        } else
            sum += vertice[i] * dist[i];
    }

    printf("%I64d\n", sum);
}