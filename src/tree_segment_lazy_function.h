/*
test:
10
1 1 1 1 1 1 1 1 1 1
7
1 5 10 8
1 6 10 7
1 9 10 5
0 9 10
0 8 9
0 7 8
0 5 7
*/
int element[N];

ll tree[4 * N], delta[4 * N];

ll inline modify(int a, int b, int l, int r, int x)
{
    return (std::min(b, r) - std::max(a, l) + 1) * x;
}

void change(int a, int b, int x, int k, int l, int r)
{
	if (a <= l && b >= r) {
		tree[k] = x * (b - a + 1);
	}
	else if (l <= b && a <= r) {
		tree[k] += modify(a, b, l, r, x);
		change(a, b, x, 2 * k + 1, l, (l + r) / 2);
		if (l != r)
			change(a, b, x, 2 * k + 2, (l + r) / 2 + 1, r);
	}
}

void change_lazy(int a, int b, int x, int k, int l, int r)
{
	if (a <= l && b >= r) {
        //说明整个区间都要被修改，并且覆盖之前的delta
        delta[k] = x;
        tree[k] = modify(a, b, l, r, x);
	}
	else if (l <= b && a <= r) {
        if (delta[k] != -1) {
            //说明标记没有下放，那么就先下放修改
            delta[2 * k + 1] = delta[k];
            tree[2 * k + 1] = modify(l, (l + r) / 2, l, (l + r) / 2, delta[k]);

            if (l != r) {
                delta[2 * k + 2] = delta[k];
                tree[2 * k + 2] = modify((l + r) / 2 + 1, r, (l + r) / 2 + 1, r, delta[k]);
            }

            delta[k] = -1;
        }

		change_lazy(a, b, x, 2 * k + 1, l, (l + r) / 2);
		if (l != r)
			change_lazy(a, b, x, 2 * k + 2, (l + r) / 2 + 1, r);

        tree[k] = tree[2 * k + 1] + tree[2 * k + 2];
	}
}


ll query_lazy(int a, int b, int k, int l, int r)
{
	if (a > r || b < l) {
		return 0;
	}

	if (a <= l && b >= r) {
        return tree[k];
	}
	else {
        if (delta[k] != -1) {
            //下放标记并更新，如果不更新会导致下次查询的时候无法得到正确结果
            delta[2 * k + 1] = delta[k];
            tree[2 * k + 1] = modify(l, (l + r) / 2, l, (l + r) / 2, delta[k]);

            delta[2 * k + 2] = delta[k];
            if (l != r) {
                delta[2 * k + 2] = delta[k];
                tree[2 * k + 2] = modify((l + r) / 2 + 1, r, (l + r) / 2 + 1, r, delta[k]);
            }
            delta[k] = -1;
        }

		ll left = query_lazy(a, b, 2 * k + 1, l, (l + r) / 2);
		ll right = 0;
		if (l < r) {
			right = query_lazy(a, b, 2 * k + 2, (l + r) / 2 + 1, r);
		}
		return left + right;
	}
}

void init(int n)
{
	for (int i = 1; i <= n; i++) {
		change(i, i, element[i], 0, 1, n);
	}
}