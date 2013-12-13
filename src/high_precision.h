#define EPS 1e-8
double a,b;
//a<b, a<=b
if(a-b<-EPS){
}
//a>b, a>=b
if(a-b>EPS){
}
//a==b
if(fabs(a-b)<EPS){
}
//a!=b
if(fabs(a-b)>EPS){
}
//printf四舍五入
if(a>0)
printf("%.3lf\n",a+EPS);
else
printf("%.3lf\n",a-EPS);

//小数点后2位
printf("%.2f\n", floor(a * 100) / 100);