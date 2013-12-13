/*
	f(n,m) = 0				--	n==1
	f(n,m) = (f(n-1,m)+m)%n	--	n>1
*/
void solve(int n, int m)
{
    int last = 0;

    for(int i = 2;i<=n;i++){
        last = (last+m)%i;
    }

    printf("%d\n",last+1);
}