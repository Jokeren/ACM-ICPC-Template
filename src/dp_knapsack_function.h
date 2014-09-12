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
 * ˳���01�����෴����Ϊ��01�����У�����״̬����Ӱ����ǰ״̬����֤�޺�Ч�ԣ�������û��������⣬�����ӽṹҪ��˳����������
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
