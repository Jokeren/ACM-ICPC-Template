int day_of_month[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
};

class date{
public:
    int day,month,year;

    date(int d,int m,int y):day(m),month(m),year(y){
    }

    int is_yeap(int x){
        return x%100!=0?(x%4==0?1:0):(x%400==0?1:0);
    }

    void next_day(){
        day++;
        if(day>day_of_month[month][is_yeap(year)]){
            day = 1;
            month++;
            if(month>12){
                month = 1;
                year++;
            }
        }
    }
};

int arr[10001][13][32];

void inline init()
{
    int cnt = 0;
    date *m_date = new date(1,1,0);

    while(m_date->year!=10001){
        arr[m_date->year][m_date->month][m_date->day] = cnt;
        m_date->next_day();
        cnt++;
    }
}