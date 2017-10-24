int c=0,s, arrayChange(std::vector<int> a) {
    for(int i=1;i<a.size();i++){
        if(a[i]<=a[i-1]){
            s=a[i-1]-a[i]+1;
            c+=s;
            a[i]+=s;
        }
    }
    return c;
}
