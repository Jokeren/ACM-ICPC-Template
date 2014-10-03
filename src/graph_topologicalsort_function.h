/*
 * 判断在有向图中是否存在环
 */
 
std::vector<std::vector<int> > g(N);

int indegree[N];
void topologic_sort(int m, int n)
{
    int x,y;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        indegree[y]++;
        g[x].push_back(y);
    }

    std::queue<int> cur;

    for(int i = 0; i < n; i++){
        if(indegree[i]==0){
            cur.push(i);
        }
    }

    int ncount = 0;
    while(cur.empty()==false){
        int tmp = cur.front();
        cur.pop();
        ncount++;
        for(int i = 0;i<g[tmp].size();i++){
            if(--indegree[g[tmp][i]] == 0){
                cur.push(g[tmp][i]);
            }
        }
    }

    memset(indegree,0,sizeof(indegree));
    for(int i = 0;i<n;i++){
        g[i].clear();
    }

    printf("%s\n",ncount==n?"YES":"NO");
}
