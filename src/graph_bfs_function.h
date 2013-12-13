/*
 * bfs扩展，判定层数。
 * 用std::pair来存储，其中first为标记，second为层数（从0开始）
 */
 
 void bfs(std::vector<std::vector<struct e> > g, int iter,int end)
{
    bool vs[N];
    int ncount = 0;
    int sum = 0;
    memset(vs,false,sizeof(vs));

    std::queue<std::pair<int,int> > q;
    q.push(std::make_pair(end,0));
    vs[end]=true;

    while(q.empty()==false) {
        std::pair<int,int> tmp = q.front();
        q.pop();

        if(tmp.second>=iter)//所有层数大于限制的不再遍历
            continue;
        int next;
        for(int i = 0; i<g[tmp.first].size(); i++) {
            next = g[tmp.first][i].v;
            if(vs[next]==false) {
                vs[next] = true;
                q.push(std::make_pair(next,tmp.second+1));
            }
        }
    }
}

/*
 * bfs扩展，方向数组存储
 */
 
bool vs[N][N][N];
bool g[N][N][N];

struct m{
    int x,y,z;
    int t;
};

int pos[][3] = {
    0,0,1,
    0,0,-1,
    0,1,0,
    0,-1,0,
    1,0,0,
    -1,0,0
};

int bfs(int iter, struct m start, struct m target)
{
    std::queue<struct m> q;
    q.push(start);

    while(q.empty()==false) {
        struct m tmp = q.front();
        q.pop();
        int cur_x = tmp.x;
        int cur_y = tmp.y;
        int cur_z = tmp.z;
        int cur_time = tmp.t;

        if(cur_time>=iter)//所有层数大于限制的不再遍历
            continue;
        struct m next;
        for(int i = 0; i<6; i++) {
            next.x = cur_x+pos[i][0];
            next.y = cur_y+pos[i][1];
            next.z = cur_z+pos[i][2];

            if(next.x>=0&&next.x<=target.x&&next.y>=0&&next.y<=target.y&&next.z>=0&&next.z<=target.z){
                if(vs[next.x][next.y][next.z]==false&&g[next.x][next.y][next.z]==0) {
                    vs[next.x][next.y][next.z] = true;
                    next.t = cur_time+1;
                    q.push(next);

                    if(next.x == target.x&&next.y == target.y&&next.z == target.z){
                        return next.t;
                    }
                }
            }
        }
    }

    return -1;
}