std::vector<int> arrayReplace(std::vector<int> a, int r, int s) {
    for(int i=0;i<a.size();i++){
        if(a[i]==r)
            a[i]=s;
    }
    return a;
}
