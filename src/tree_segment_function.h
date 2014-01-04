int element[N];

ll tree[2 * N], delta[2 * N];

void change(int a, int b, int x, int k, int l, int r)
{
	if (a <= l && b >= r) {
		delta[k] += x;
	}
	else if (l <= b && a <= r) {
		tree[k] += (std::min(b, r) - std::max(a, l) + 1) * x;
		change(a, b, x, 2 * k + 1, l, (l + r) / 2);
		if (l != r) 
			change(a, b, x, 2 * k + 2, (l + r) / 2 + 1, r);
	}
}

void init(int n)
{
	for (int i = 1; i <= n; i++) {
		change(i, i, element[i], 0, 1, n);
	}
}

ll query(int a, int b, int k, int l, int r)
{
	if (a > r || b < l) {
		return 0;
	}

	if (a <= l && b >= r) {
		return (r - l + 1) * delta[k] + tree[k];
	}
	else {
		ll sum = (std::min(r, b) - std::max(l,a) + 1) * delta[k];
		ll left = query(a, b, 2 * k + 1, l, (l + r) / 2);
		ll right = 0;
		if (l < r) {
			right = query(a, b, 2 * k + 2, (l + r) / 2 + 1, r);
		}
		return left + right + sum;
	}
}