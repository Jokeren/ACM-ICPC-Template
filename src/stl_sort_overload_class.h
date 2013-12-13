struct student{
    char name[LEN];
    int age;
    int score;
    bool operator < (const struct student &t1) const
    {
        if(score != t1.score)
            return score < t1.score;
        int tmp = strcmp(name,t1.name);
        if(tmp != 0)
            return tmp < 0;
        return age < t1.age;
    }
}students[N];