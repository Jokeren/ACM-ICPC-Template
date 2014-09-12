/*
 * 01 knapsack
 * f[i] = max(f[i - cost[j]] + value[i], f[i]);
 */
 
int weight[N];
int value[N];
int dp[M];

void solve(int n, int m)
{
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= weight[i]; j--) {
			dp[j] = std::max(dp[j - weight[i]] + value[i], dp[j]);
		}
	}

	printf("%d\n", dp[m]);
}

/*
 * complete knapsack
 * f[i] = max(f[i - cost[j]] + value[i], f[i]);
 * 顺序和01背包相反，因为在01背包中，后续状态不能影响先前状态，保证无后效性；而这里没有这个问题，最优子结构要求顺序是这样。
 */
 
int weight[N];
int value[N];
int dp[M];

void solve(int n, int m)
{
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++) {
		for (int j = weight[i]; j <= m; j++) {
			dp[j] = std::max(dp[j - weight[i]] + value[i], dp[j]);
		}
	}

	printf("%d\n", dp[m]);
}
