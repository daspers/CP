bool areSimilar(std::vector<int> a, std::vector<int> b) {
    int c=0, m[1001], n=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i])
            c++;
        else
            m[n++]=i;
    }
    if(n==2){
        return a[m[0]]==b[m[1]]&&a[m[1]]==b[m[0]];
    }
    else if(n==0){
        return true;
    }
    else
        return false;
}
