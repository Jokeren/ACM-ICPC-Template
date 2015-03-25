ll element[N];

ll tree[4 * N], delta_set[4 * N], delta_add[4 * N];

ll inline modify(int a, int b, ll x, int l, int r)
{
    //���������ֵ�޸�Ϊ��
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
        //˵���������䶼Ҫ���޸ģ����Ҹ���֮ǰ��delta
		//��㲻��Ҫ�·ţ���Ϊ����ֵ���޸Ĺ��ˣ��´�����鵽��㣬��ô����ֵ
		//����������ȷ�ġ�
        if (update) {
            delta_add[k] = 0;
            delta_set[k] = x;
            tree[k] = modify(a, b, x, l, r);
        } else {
            delta_add[k] += x;
            tree[k] += modify(a, b, x, l, r);
        }
	} else {
        //˵�����û���·ţ���ô�����·��޸�
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
        //�·ű�ǲ����£���������»ᵼ���´β�ѯ��ʱ���޷��õ���ȷ���
        push_down(l, r, k);

		int left = query_lazy(a, b, 2 * k + 1, l, (l + r) / 2);
		int right = 0;
		if (l != r)
			right = query_lazy(a, b, 2 * k + 2, (l + r) / 2 + 1, r);

        //����query�������޸��߶�����ֵ
        return left + right;
	}
}

void init(int n)
{
    //delta��ʼ��
    memset(delta_set, -1, sizeof(delta_set));
    memset(delta_add, 0, sizeof(delta_add));
    //tree�����ʼ��
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