class big_int
{
public:
    int digit[N];
    int next;

    big_int(){
        memset(digit,0,sizeof(digit));
        next = 0;
    }

    void init(){
        memset(digit,0,sizeof(digit));
        next = 0;
    }

    void set_int(const char *str, int len){//用字符串初始化
        for(int i = len-1,j=0,t=0,c=1;i>=0;i--){
            t += (str[i]-'0')*c;
            j++;
            c *= 10;
            if (j==4||i==0){
                digit[next++] = t;
                j = 0;
                t = 0;
                c = 1;
            }
        }
    }

    big_int operator + (const big_int &a) const{//大整数加法思想：每四位相加，因为之前有memset(..,0,..)，所以这里在后面的时候还是会继续加没有问题。
        big_int ret;
        ret.init();
        int carry = 0;
        for(int i = 0,tmp;i<a.next||i<next;i++){
            tmp = a.digit[i] + digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.next++] = tmp;
        }
        if(carry != 0){
            ret.digit[ret.next++] = carry;
        }

        return ret;
    }

    big_int operator * (int &a) const{//大整数乘小整数：每四位相乘，然后计算溢出位，这里要保证的是小整数小于等于10000，所以最好是把小整数也控制在四位以内
        big_int ret;
        ret.init();
        int carry = 0;
        for(int i = 0, tmp;i<next;i++){
            tmp = a*digit[i] + carry;
            carry = tmp/10000;
            tmp %= 10000;
            ret.digit[ret.next++] = tmp;
        }
        if(carry != 0){
            ret.digit[ret.next++] = carry;
        }

        return ret;
    }

    big_int operator / (int a) const{//大整数除小整数：每四位相除，最好保证除数也是四位数，最后用一个循环找出商的最高位在哪里。
        big_int ret;
        ret.init();
        int remain = 0,t,r;
        for(int i = next - 1;i>=0;i--){
            t = (remain*10000+digit[i])/a;
            r = (remain*10000+digit[i])%a;
            ret.digit[i] = t;
            remain = r;
        }
        ret.next = 0;
        for(int i = 0;i<=next;i++){
            if(digit[i] != 0)
                ret.next = i;
        }

        ret.next++;
        return ret;
    }

    int operator % (int a) const{//大整数和小整数的余数：除法简化版
        int ret = 0, t, r;
        for(int i = next-1;i>=0;i--){
            t = (ret*10000+digit[i])/a;
            r = (ret*10000+digit[i])%a;
            ret = r;
        }
        return ret;
    }

    void output(){
        for(int i = next-1;i>=0;i--){
            if(i!=next-1)
                printf("%04d",digit[i]);
            else
                printf("%d",digit[i]);
        }
        printf("\n");
    }
};