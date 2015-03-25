ll element[N];

ll tree[4 * N], delta_set[4 * N], delta_add[4 * N];

ll inline modify(int a, int b, ll x, int l, int r)
{
    //如果是区间值修改为：
    //(std::min(b, r) - std::max(a, l)) * x;
    return (std::min(b, r) - std::max(a, l) + 1) * x;
}

void inline push_down(int l, int r, int k)
{
    if (delta_set[k] != -1) {
        delta_set[2 * k + 1] = delta_set[k];
        tree[2 * k + 1] = modify(l, (l + r) / 2,  delta_set[k], l, (l + r) / 2);

        if (l != r) {
            delta_set[2 * k + 2] = delta_set[k];
            tree[2 * k + 2] = modify((l + r) / 2 + 1, r, delta_set[k], (l + r) / 2 + 1, r);
        }

        delta_add[2 * k + 1] = delta_add[2 * k + 2] = 0;
        delta_set[k] = -1;
    }

    if (delta_add[k] != 0) {
        delta_add[2 * k + 1] += delta_add[k];
        tree[2 * k + 1] += modify(l, (l + r) / 2,  delta_add[k], l, (l + r) / 2);

        if (l != r) {
            delta_add[2 * k + 2] += delta_add[k];
            tree[2 * k + 2] += modify((l + r) / 2 + 1, r, delta_add[k], (l + r) / 2 + 1, r);
        }

        delta_add[k] = 0;
    }
}

void change_lazy(int a, int b, ll x, int k, int l, int r, bool update)
{
    if (a > r || b < l) {
        return ;
    } else if (a <= l && b >= r) {
        //说明整个区间都要被修改，并且覆盖之前的delta
		//这层不需要下放，因为这层的值被修改过了，下次如果查到这层，那么这层的值
		//本来就是正确的。
        if (update) {
            delta_add[k] = 0;
            delta_set[k] = x;
            tree[k] = modify(a, b, x, l, r);
        } else {
            delta_add[k] += x;
            tree[k] += modify(a, b, x, l, r);
        }
	} else {
        //说明标记没有下放，那么就先下放修改
        push_down(l, r, k);

		change_lazy(a, b, x, 2 * k + 1, l, (l + r) / 2, update);
		if (l != r)
			change_lazy(a, b, x, 2 * k + 2, (l + r) / 2 + 1, r, update);

        tree[k] = tree[2 * k + 1] + tree[2 * k + 2];
	}
}

ll query_lazy(int a, int b, int k, int l, int r)
{
    if (a > r || b < l) {
        return 0;
    } else if (a <= l && b >= r) {
        return tree[k];
	} else {
        //下放标记并更新，如果不更新会导致下次查询的时候无法得到正确结果
        push_down(l, r, k);

		int left = query_lazy(a, b, 2 * k + 1, l, (l + r) / 2);
		int right = 0;
		if (l != r)
			right = query_lazy(a, b, 2 * k + 2, (l + r) / 2 + 1, r);

        //所有query本身都不修改线段树的值
        return left + right;
	}
}

void init(int n)
{
    //delta初始化
    memset(delta_set, -1, sizeof(delta_set));
    memset(delta_add, 0, sizeof(delta_add));
    //tree自身初始化
    memset(tree, LGMAX, sizeof(tree));

	for (int i = 0; i <= n; i++) {
		change_lazy(i, i, element[i], 0, 0, n, true);
	}
}
/*
std::pair<int, int> element[N];
std::map<int, int> hash;
std::set<int> value;
std::vector<int> sorted_array;
void discrete(int n)
{
    std::sort(sorted_array.begin(), sorted_array.end());
    for (int i = 0; i < sorted_array.size(); ++i) {
        hash[sorted_array[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        element[i].first = hash[element[i].first];
        element[i].second = hash[element[i].second];
    }
}
*/