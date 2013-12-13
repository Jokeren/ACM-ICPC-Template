void haffman(int n)
{
	std::priority_queue<long long,std::vector<long long>,std::greater<long long> > pq;
	long long tmp;
	for(int i = 0;i<n;i++){
		scanf("%lld",&tmp);
		pq.push(tmp);
	}

	long long a,b,sum = 0;
	while(pq.size()!=1){
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum += (a+b);
		pq.push((a+b));
	}

	printf("%lld\n",sum);
}