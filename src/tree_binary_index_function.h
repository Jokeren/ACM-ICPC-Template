//查询的时候注意端点具体情况
//点修改，区间查询，直接用sum(r) - sum(l)，前缀和
//区间修改，点查询，计算的时候将右边序列都-d，左边序列都+d，因为modify以后前缀和首影响，所以右边的值多加了。
int binary_index[N];

int inline low_bit(int x)
{
    return x&(-x);
}

void modify(int x, int p, int n)
{
    while (x <= n) {
        binary_index[x] += p;
        x += low_bit(x);
    }
}

int sum(int x)
{
    int ret = 0;
    while (x) {
        ret += binary_index[x];
        x -= low_bit(x);
    }
    return ret;
}

void init(int n)
{
    int tmp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        modify(i, tmp, n);
    }
}