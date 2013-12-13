int arr[N];
int dp[N];
int s[N];
void solve(int n)
{
    int sum = 0;
    for(int i = 1;i<=n;i++){
        dp[i] = 1;
        for(int j = 1;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = std::max(dp[j]+arr[i],dp[i]);
            }
        }
        if(sum<dp[i]){
            sum = dp[i];//very important!!!
        }
    }

    printf("%d\n",sum);
}