struct edge{
    int y;
    int v;
};

std::vector<std::vector<struct edge> > g(N);

inline bool relax(int &w, int v)
{
    return w>v ? (w=v,true) : false;
}

void spfa(int n)
{
    int dist[N];
    int in_queue_count[N];
    bool in_queue[N];
    std::queue<int> q;

    memset(dist,INF,sizeof(dist));
    memset(in_queue,false,sizeof(in_queue));
    memset(in_queue_count,0,sizeof(in_queue_count));

    int now = 1;
    for(dist[now]=0,q.push(now),in_queue[now]=true,in_queue_count[now]=1;q.empty()==false;in_queue[now]=false,q.pop()){
        now = q.front();
        for(int i=0; i<(int)g[now].size();i++){
            struct edge *e = &g[now][i];
            if(relax(dist[e->y],dist[now]+e->v)){
                if(in_queue[e->y]==false){
                    q.push(e->y);
                    in_queue[e->y]=true;
                    if(++in_queue_count[e->y]>n){
                        printf("YES\n");
                        return ;
                    }
                }
            }
        }
    }

    printf("NO\n");

    return;
}