#define N 220
//if mat[i][j] == 1, means op[i]>op[j];
int pri[][5] = {
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
};

class calc
{
private:
    std::stack<int> op;
    std::stack<double> in;
    char str[N];

    void get_op(bool &reto, int &retn, int &i) {
        if(i == 0 && op.empty()==true) {
            reto = true;
            retn = 0;
            return;
        }
        if(str[i] == 0) {
            reto = true;
            retn = 0;
            return;
        }
        if(str[i] >= '0' &&str[i]<='9') {
            reto = false;
        } else {
            reto = true;
            switch(str[i]) {
            case '+':
                retn = 1;
                break;
            case '-':
                retn = 2;
                break;
            case '*':
                retn = 3;
                break;
            case '/':
                retn = 4;
                break;
            default:
                break;
            }
            i += 2;
            return ;
        }
        retn = 0;
        for(; str[i]!=' '&&str[i]!=0; i++) {
            retn *= 10;
            retn += str[i] - '0';
        }
        if(str[i] == ' ')
            i++;
        return ;
    }
public:
    int set_str() {
        std::cin.getline(str,N);
        return !(strlen(str) == 1 && str[0] == '0');
    }

    void compute() {
        int idx = 0;
        int retn;
        bool ret;
        while(!op.empty())op.pop();
        while(!in.empty())in.pop();
        while(true){
            get_op(ret,retn,idx);
            if(ret == false){
                in.push((double)retn);
            } else {
                double tmp;
                if(op.empty()== true || pri[retn][op.top()]==1){
                    op.push(retn);
                } else {
                    while(pri[retn][op.top()]==0){
                        int num = op.top();
                        op.pop();
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        switch(num){
                        case 1:
                            tmp = a+b;
                            break;
                        case 2:
                            tmp = a-b;
                            break;
                        case 3:
                            tmp = a*b;
                            break;
                        case 4:
                            tmp = a/b;
                            break;
                        default:
                            break;
                        }
                        in.push(tmp);
                    }
                    op.push(retn);
                }
            }
            if(op.size()==2&&op.top()==0)
                break;
        }
        printf("%.2f\n",in.top());
    }
};