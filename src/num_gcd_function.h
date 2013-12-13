/*
首先：
	a = g*l;
	b = g*m;
	a = b*k+r;
代入(1)(2)至(3)；
	g*l = g*m*k+r;
	r = g*(l-m*K);
因此：
	a与b的公约数g同时也是b，a mod b的公约数
最大公约数，可以用反证法证明，首先假设g为a,b最大公约数，但是并不是b,a mod b的最大公约数。
推导：
	b = g'*m';
	r = g'*x;
	a = b*k+r;
	a = g'*m'k+g'*x;
	a = g'(m'k+x);
因为g'>g，但是a,b最大公约数为g，所以矛盾。
*/
inline int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

inline int gcd(int a, int b)
{
    int tmp;
    while(b!=0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}