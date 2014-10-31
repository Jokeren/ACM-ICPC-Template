#define _USE_MATH_DEFINES

#ifdef ONLINE_JUDGE
#define FINPUT(file) 0
#define FOUTPUT(file) 0
#else
#define FINPUT(file) freopen(file,"r",stdin)
#define FOUTPUT(file) freopen(file,"w",stdout)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

typedef long long ll;
static const int N = 100010;
static const int M = 128;
static const int LEN = 1010;//>=128
static const int MAX = 0x7fffffff;
static const int GMAX = 0x3f3f3f3f;
static const int MIN = ~MAX;
static const double EPS = 1e-7;
static const int BASE = 10007;
static const int CH = 200;//改字符数

char word[LEN];
int s[LEN], sa[LEN], t[LEN], t2[LEN], c[LEN];
int rank[LEN], height[LEN];

void build_sa(int m, int n)
{
	int i, *x = t, *y = t2;

	for (i = 0; i < m; i++)
		c[i] = 0;

	for (i = 0; i < n; i++)
		c[x[i] = s[i]]++;
	for (i = 1; i < m; i++)
		c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--)
		sa[--c[x[i]]] = i;

	for (int k = 1; k <= n; k <<= 1) {

		int p = 0;
		for (i = n - k; i < n; i++)
			y[p++] = i;

		for (i = 0; i < n; i++) {
			if (sa[i] >= k) {
				y[p++] = sa[i] - k;
			}
		}

		for (i = 0; i < m; i++)
			c[i] = 0;

		for (i = 0; i < n; i++)
			c[x[y[i]]]++;

		for (i = 0; i < m; i++)
			c[i] += c[i - 1];

		for (i = n - 1; i >= 0; i--)
			sa[--c[x[y[i]]]] = y[i];

		std::swap(x, y);
		p = 1;
		x[sa[0]] = 0;

		for (i = 1; i < n; i++)
			x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;

		if (p >= n)
			break;
		m = p;
	}
}

int inline cmp_suffix(char* pattern, int pattern_len, int p)
{
	return strncmp(pattern, word + sa[p], pattern_len);
}

int find(char* pattern, int pattern_len, int temp_len)
{
	if (cmp_suffix(pattern, pattern_len, 0) < 0)
		return -1;

	if (cmp_suffix(pattern, pattern_len, temp_len - 1) > 0)
		return -1;

	int l = 0, r = temp_len - 1;

	while (r >= l) {
		int m = l + (r - l) / 2;

		int res = cmp_suffix(pattern, pattern_len, m);

		if (!res)
			return m;

		if (res < 0) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return -1;
}

void get_height(int n)
{
	int i, j, k = 0;

	for (i = 1; i <= n; i++)
		rank[sa[i]] = i;

	for (i = 0; i < n; height[rank[i++]] = k) {
		if (k) k--;

		int j = sa[rank[i] - 1];
		while (s[i + k] == s[j + k])
			k++;
	}
}

void solve(int n)
{
	build_sa(CH, n + 1);//实际排序有n + 1个元素

	get_height(n);//因为插入的数为0，字典序肯定最小，所以只要考虑rank[1 - n]

    int ans = 0;
	for (int i = 1; i <= n; i++) {
        //printf("i%d sa[i] %d\n", i, sa[i]);
        ans += (n - sa[i] - height[i]);
	}

	printf("%d\n", ans);
}

int main()
{
    FINPUT("in.txt");
    FOUTPUT("out.txt");

	int t;
	while (scanf("%d", &t) != EOF) {
		for (int i = 0; i < t; i++) {
			scanf("%s", word);
			int len = strlen(word);
			for (int j = 0; j < len; j++) {
                s[j] = word[j] + 1;
			}
			s[len] = 0;
			solve(len);
		}
	}
	return 0;
}
