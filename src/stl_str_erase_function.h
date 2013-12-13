void delete()
{
	while(gets(str)!=NULL){
        std::string tmp_str = str;
        for(int i = 0;i<tmp_str.size();i++){
            tmp_str[i] = tolower(tmp_str[i]);
        }
        while(gets(text)!=NULL){//因为这里用了gets，所以上一个输入不好用scanf，scanf本身不会读入空格和换行
            std::string text_lower = text, text_no_space = text;
            for(int i = 0;i<text_lower.size();i++){
                text_lower[i] = tolower(text_lower[i]);
            }

            int pos = text_lower.find(tmp_str,0);

            while(pos != std::string::npos){
                text_no_space.erase(pos,tmp_str.size());//erase的三种用法：erase(str,size),erase(str.begin(),str.end()),erase(position)
                text_lower.erase(pos,tmp_str.size());
                pos = text_lower.find(tmp_str,pos);//假如当前删除了某串，那么下一串的起始位置一定>=pos
            }

            pos = text_no_space.find(' ',0);

            while(pos != std::string::npos){
                text_no_space.erase(pos,1);
                pos = text_no_space.find(' ',pos);
            }

            std::cout<<text_no_space<<std::endl;
        }
    }
}