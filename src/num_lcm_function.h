void multi_lcm()
{
	for(int i = 0;i<n;i++){
		int t;
		long long lcm,tmp;
		scanf("%d%lld",&t,&lcm);
		for(int j = 1;j<t;j++){
			scanf("%lld",&tmp);
			long long incr = std::max(lcm,tmp);
			for(long long k = incr;k<=lcm*tmp;k+=incr){
				if(k%tmp==0&&k%lcm==0){
					lcm = k;
					break;
				}
			}
		}
		printf("%lld\n",lcm);
	}
}