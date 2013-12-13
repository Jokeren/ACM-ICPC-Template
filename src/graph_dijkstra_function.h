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