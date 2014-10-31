int parent[N];
int rank[N];

int find_root(int x)
{
    if(parent[x] != x){
        return parent[x] = find_root(parent[x]);
    } else {
        return x;
    }
}

void inline root_union(int x, int y)
{
    if(rank[x]>rank[y]){
        parent[y] = x;
    } else {
        parent[x] = y;
        if(rank[x] == rank[y]){
            rank[y]++;
        }
    }
}

Find_Set(x)
{
	r = x;
	while r != parent[r] do
		r = parent[r]; // now r is the root node
	while r != parent[x] do {
		p = parent[x];
		parent[x] = r;
		x = p;
	}
	return r;
}
