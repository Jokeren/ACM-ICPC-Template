struct student{
    char name[LEN];
    int age;
    int score;
}students[N];

bool cmp_score(const struct student &t1, const struct student &t2)
{
    if(t1.score<t2.score){
        return true;
    } else if (t1.score == t2.score){
        int tmp = strcmp(t1.name,t2.name);
        if (tmp<0)
            return true;
        else if(tmp == 0){
            if (t1.age<t2.age){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}