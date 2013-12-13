/*
 * 二分幂原理：
 * 将a^b中的b转换成二进制形式，那么a^b就可以看成a^b1*a^b2………又因为其中每迭代一次就相当于把原来的值翻倍，所以，复杂度为logn，只需5次就可以计算出
 * 2^32大数。
 */
long long binary_power(long long a, long long b)
{
    long long ans = 1;
    while(b!=0){
        if(b%2 == 1){
            ans *= a;
            ans %= 200907;
        }
        b /= 2;
        a *= a;
        a %= 200907;
    }
    return ans;
}