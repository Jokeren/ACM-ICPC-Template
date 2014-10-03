int vertices;
std::vector<int> g[2*N];
std::vector<int> rg[2*N];
std::vector<int> vs;
bool used[2*N];
int cmp[2*N];

void inline add_edge(int from, int to)
{
    g[from].push_back(to);
    rg[to].push_back(from);
}

void dfs(int v)
{
    used[v] = true;
    for(int i = 0;i < [v].size(); i++){
        if(!used[g[v][i]])
            dfs(g[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v] = true;
    cmp[v] = k;
    for(int i = 0;i < rg[v].size(); i++){
        if(!used[rg[v][i]])
            rdfs(rg[v][i],k);
    }
}

int scc()
{
    memset(used,false,sizeof(used));
    vs.clear();
    for(int i = 1;i <= vertices; i++){
        if(!used[i])
            dfs(i);
    }

    memset(used,false,sizeof(used));
    int k = 1;
    for(int i = vs.size() - 1; i >= 0; i--){
        if(!used[vs[i]])
            rdfs(vs[i],k++);
    }

    return k;
}

//Tarjan算法