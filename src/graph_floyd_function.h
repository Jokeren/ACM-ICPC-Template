int g[N][N];

void init(int n)
{
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j){
                g[i][j] = 0;
            } else {
                g[i][j] = MAX;
            }
        }
    }
}

void floyd(int n)
{
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(g[i][k] == MAX||g[k][j] == MAX)
                    continue;
                if(g[i][k]+g[k][j]<g[i][j])
                    g[i][j] = g[i][k]+g[k][j];
            }
        }
    }
}

/*
 * 判断是否存在负环
 */
bool negative_cycle (int n)
{
    for (int i = 1;i <= n;i++)
        if (d[i][i] < 0)
            return true ;
    return false ;
}