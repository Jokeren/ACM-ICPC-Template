	
void 2sat()
{
	fscanf(fp,"%d",&vertices);

    for(int i = 0, a, b;i<vertices;i++){
        fscanf(fp,"%d %d",&a,&b);
        if(a<0&&b>0){
            a = -a;
            add_edge(a,b);
            add_edge(b+vertices,a+vertices);
        } else if(a<0&&b<0){
            a = -a;
            b = -b;
            add_edge(a,b+vertices);
            add_edge(b,a+vertices);
        } else if(a>0&&b>0){
            add_edge(a+vertices,b);
            add_edge(b+vertices,a);
        } else {
            b = -b;
            add_edge(a+vertices,b+vertices);
            add_edge(b,a);
        }
    }

    scc();

    for(int i = 1;i<=vertices;i++){
        if(cmp[i] == cmp[i+vertices]&&!((cmp[i]==0)&&cmp[i+vertices]==0)){
            printf("NO\n");
            return 0;
        }
    }

	printf("true\n");
	for (int i = 1; i <= vertices; i++) {
		if (cmp[i] > cmp[3 + i]) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	}
}