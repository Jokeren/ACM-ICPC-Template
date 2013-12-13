bool hash[N];
char str[N];
int char_to_num[257];

void inline rabin_karp(int n, int nc, int len)
{
    memset(hash,false,sizeof(hash));

    int seed = 0;
    for(int i = 0;i<len;i++){
        if(char_to_num[str[i]] == 0){
            char_to_num[str[i]] = ++seed;
        }
    }

    int t = 1;

    for(int i = 0;i<n;i++)
        t*=nc;

    int ah = 0;

    for(int i = 0;i<n;i++)
        ah = ah*nc + char_to_num[str[i]];

    int ncount = 0;
    for(int i = 0;i+n<=len;i++){
        if(hash[ah] == false){
            hash[ah] = true;
            ncount++;
        }
        if(i+n<len){
            ah = ah*nc + char_to_num[str[i+n]] - char_to_num[str[i]]*t;
        }
    }

    printf("%d\n",ncount);
}