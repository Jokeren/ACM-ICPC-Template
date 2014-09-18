/*
 * complexity nloglogn，以e为底
 */
int prime_size;
bool is_prime[N];
bool marked[N];
int prime[N];

void init()
{
    memset(marked,false,sizeof(marked));
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 2; i * i < N;i++){
        if(marked[i] == false){
            marked[i] = true;
            prime[prime_size++] = i;
			if(i < sqrt(N)){
				for(int j = i*i; j < N; j+=i){
					marked[j] = true;
					is_prime[j] = false;
				}
			}
        }
    }
}

/*
 * 分解质因数，从2开始所有的质数，从大到小开始除
 */
void factor(int n)
{
    int ans[LEN];
    int prime_index = 0, ans_index = 0;
    while(n!=1){
        if(n%prime[prime_index] == 0){
            n = n/prime[prime_index];
            ans[ans_index] = 1;

            while(n!=1&&n%prime[prime_index]==0){
                n = n/prime[prime_index];
                ans[ans_index]++;
            }

            ans_index++;
        }
        prime_index++;
        if(prime_index>=prime_size){
            break;
        }
    }
    if(n!=1){
        ans[ans_index++] = 1;
    }

    int sum = 0;
    for(int i = 0;i<ans_index;i++){
        sum += ans[i];
    }

    printf("%d\n",sum);
}

/*
 * 整除问题。
 * 关于n!的一个定理，n!中出现某个因数k的个数为n/k，如n=6，k=3：那么其中因数为3的数字出现了两次，因为6=1*2*3*4*5*6。
 * 但是，这里还要注意的是我们计算出n!中出现k的个数以后，还要计算出n!中出现k*k，k*k*k…………k^p的个数，所以，用循环解决：
 * while(t){
 * 	ncount += t/prime;
 * 	t = t/prime;
 * }
 * 这样可以计算出n!中对应素数的幂级数。
 * 然后，简单归纳可得，如果需要a/b为整数，那么对于a的分解质因数a1a2a3……，b1b2b3必须与其对应，并且对应的幂级数小于对应位。
 * 所以，求最大k次方即求出最小的ai/bi。
 */
 
 void factor(int n, int a)
{
    int prime_count[N];
    memset(prime_count,0,sizeof(prime_count));

    for(int i = 0;i<prime_size;i++){
        int tmp = prime[i];
        int t = n;
        while(t){
            prime_count[i] += (t/prime[i]);
            t = (t/prime[i]);
        }
    }

    int ans[N];
    memset(ans,0,sizeof(ans));

    int prime_index = 0, ans_index = 0, k = MAX;
    while(a!=1){
        if(a%prime[prime_index] == 0){
            a = a/prime[prime_index];
            ans[ans_index] = 1;

            while(a!=1&&a%prime[prime_index]==0){
                a = a/prime[prime_index];
                ans[ans_index]++;
            }

            if(prime_count[prime_index]/ans[ans_index] < k){
                k = prime_count[prime_index]/ans[ans_index];
            }
            ans_index++;
        }
        prime_index++;
        if(prime_index>=prime_size){
            break;
        }
    }

    printf("%d\n",k);
}