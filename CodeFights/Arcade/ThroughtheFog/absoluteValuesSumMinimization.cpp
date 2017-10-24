int absoluteValuesSumMinimization(std::vector<int> a) {
    long b = -1e6-1, mi = 2e8+1,c, x;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b){
            c=0;
            for(int j=0;j<a.size();j++){
                c+=abs(a[j]-a[i]);
            }
            if(c<mi){
                mi = c;
                x=i;
            }
            b = a[i];
        }
    }
    return a[x];
}
