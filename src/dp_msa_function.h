long long arr[N];
long long f[N];
//dp version
void msa(int n)
{
    bool first = true;
    long long ans = 0,max_num = 0;
    f[0] = arr[0];
    /*dp function:
        if(f[i-1]<0)
            f[i] = arr[i];
        else
            f[i] = std::max(f[i-1]+arr[i],arr[i]);
    */
    for(int i = 1; i<n; i++) {
        if(arr[i]>arr[max_num])
            max_num = i;
        if(f[i-1]<0)
            f[i] = arr[i];
        else
            f[i] = std::max(f[i-1]+arr[i],arr[i]);
        if(f[i]>ans) {
            ans = f[i];
        }
    }

    if(ans == 0){
        printf("%lld\n",arr[max_num]);
    } else
        printf("%lld\n",ans);

    memset(f,0,sizeof(f));
}
/* special cases: 0 1 -1 5
                : -1 -2 0 5
*/
//not dp version
void msa(int n)
{
    bool first = true;
    long long max = 0,add = 0,ans = MIN,max_num = 0;
 
    for(int i = 0; i<n; i++) {
        if(arr[i]>arr[max_num])
            max_num = i;
        if(arr[i]>0&&first==true) {
            max = arr[i];
            add = arr[i];
            first = false;
        } else if (arr[i]>0&& first == false) {
            add += arr[i];
            if(add>max) {
                max = add;
            }
        } else if (arr[i]<0&&first == false) {
            add += arr[i];
            if(add<0) {
                add = 0;
            }
        }
        if(max>ans) {
            ans = max;
        }
    }
 
    if(first==true){
        printf("%lld\n",arr[max_num]);
    } else {
        printf("%lld\n",max);
    }
}