//ע��element��1��ʼ
std::pair<int, int> element[N];
std::map<int, int> hash;
std::set<int> value;
std::vector<int> sorted_array;

ll tree[4 * N], delta[4 * N];

ll inline modify(int a, int b, int l, int r, int x)
{
    return (std::min(b, r) - std::max(a, l)) * x;
}

void change_lazy_discrete(int a, int b, int x, int k, int l, int r)
{
    if (a == r || b == l)
        return;

	if (a <= l && b >= r) {
        //˵���������䶼Ҫ���޸ģ����Ҹ���֮ǰ��delta
        delta[k] = x;
        tree[k] = modify(a, b, l, r, x);
	}
	else if (l < b && a < r) {
        if (delta[k] != -1) {
            //˵�����û���·ţ���ô�����·��޸�
            delta[2 * k + 1] = delta[k];
            tree[2 * k + 1] = modify(l, (l + r) / 2, l, (l + r) / 2, delta[k]);

            delta[2 * k + 2] = delta[k];
            tree[2 * k + 2] = modify((l + r) / 2, r, (l + r) / 2, r, delta[k]);

            delta[k] = -1;
        }

		change_lazy_discrete(a, b, x, 2 * k + 1, l, (l + r) / 2);
		if (l != r)
			change_lazy_discrete(a, b, x, 2 * k + 2, (l + r) / 2, r);

        tree[k] = tree[2 * k + 1] + tree[2 * k + 2];
	}
}


ll query_lazy_discrete(int a, int b, int k, int l, int r)
{
	if (a >= r || b <= l) {
		return (ll)0;
	}

	if (a <= l && b >= r) {
        return tree[k];
	}
	else if (l < b && a < r) {
        if (delta[k] != -1) {
            //�·ű�ǲ����£���������»ᵼ���´β�ѯ��ʱ���޷��õ���ȷ���
            delta[2 * k + 1] = delta[k];
            tree[2 * k + 1] = modify(l, (l + r) / 2, l, (l + r) / 2, delta[k]);

            delta[2 * k + 2] = delta[k];
            if (l != r) {
                delta[2 * k + 2] = delta[k];
                tree[2 * k + 2] = modify((l + r) / 2, r, (l + r) / 2, r, delta[k]);
            }
            delta[k] = -1;
        }

		ll left = query_lazy_discrete(a, b, 2 * k + 1, l, (l + r) / 2);
		ll right = 0;
		if (l != r) {
			right = query_lazy_discrete(a, b, 2 * k + 2, (l + r) / 2, r);
		}
		return left + right;
	}
}

void init(int n)
{
    memset(delta, -1, sizeof(delta));
	for (int i = 1; i <= n; i++) {
		change_lazy_discrete(element[i].first, element[i].second, i,
                       0, 0, sorted_array.size() - 1);

	}
}

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