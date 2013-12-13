inline long long trans_ten(char *str, int n, int m)
{
    long long num = 0;

    for(int i = n-1, c = 1;i>=0;i--,c*=m){
        int x;
        (str[i]>='0'&&str[i]<='9')?x = str[i]-'0':(str[i]>='a'&&str[i]<='z'?x=str[i]-'a'+10:x=str[i]-'A'+10);
        num += x*c;
    }
    return num;
}
inline void ten_trans(long long num, int m)
{
    int cnt = 0;
    char ans[50];
    long long tmp;
    do{
        tmp = num%m;
        ans[cnt++] = (tmp<10)?tmp+'0':tmp-10+'A';
        num /= m;
    }while(num!=0);

    for(int i = cnt-1;i>=0;i--){
        printf("%c",ans[i]);
    }
}