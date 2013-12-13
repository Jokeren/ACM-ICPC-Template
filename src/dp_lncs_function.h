void lncs(char *arr, int n)
{
    int visit[256];
    memset(visit, -1, sizeof(visit));
    int maxlen = 0, maxindex = 0;
    int curlen = 1;
    int last_start = 0;
    visit[arr[0]] = 0;
 
    for(int i = 1; i < n; ++i) {
        if(visit[arr[i]] == -1) {//charactor is not visited before
            ++curlen;
            visit[arr[i]] = i;
        } else {
            if(last_start <= visit[arr[i]]) {//the last visited position is after the lncs start index, then current lncs is over
                curlen = i - visit[arr[i]];
                last_start = visit[arr[i]] + 1;
                visit[arr[i]] = i;
            } else {//the last visited position is before the lncs index, do not interfere
                ++curlen;
                visit[arr[i]] = i;
            }
        }
        if(curlen > maxlen) {
            maxlen = curlen;
            maxindex = i + 1 - maxlen;
        }
    }
 
    printf("%d\n",maxlen);
}