char arr[N];

void solve(int n)
{
    char str[2*N+1];
    str[0] = '#';

    int t = 1;
    for(int i = 0;i<n;i++){
        str[t++] = arr[i];
        str[t++] = '#';
    }
    str[t] = '\0';

    int mx = 0,id = 0,max = MIN;
    int p[2*N+1];
    for(int i = 0;i<2*n+1;i++){
        p[i] = (mx<i ? 1:std::min(p[2*id-i],mx-i));//三种情况：
		//1.最长伸展比当前坐标小，那么当前坐标只能一个个去匹配                                                    //2.最长伸展比当前坐标大，那么观察对称点，如果对称点左侧超出当前最长伸展，那么记为右侧的值。
        //3.否则，记为左侧的值
        while(i-p[i]>=0 && str[p[i]+i]==str[i-p[i]])//情况1.不断匹配
            p[i]++;                                 //情况2.匹配mx以后的值
        if(p[i]+i>mx){                              //情况3.不用匹配了，肯定不同
            id = i;
            mx = p[i]+i;
        }
        if(p[i]>max){
            max = p[i];
        }
    }
    printf("%d\n",max-1);
}