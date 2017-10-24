int coun(string a, string b){
    int c=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])
            c++;
    }
    return c;
}

int m,n,i,j, stringsRearrangement(std::vector<std::string> a) {
    sort(a.begin(), a.end());
   do{
        for(i=0, n=0;i+1<a.size();i++){
            if(coun(a[i],a[i+1])!=1){
                n++;
                break;
            }
        }
    }
    while(next_permutation(a.begin(), a.end())&&n);
    return n==0;
}
