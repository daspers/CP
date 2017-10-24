int arrayMaximalAdjacentDifference(std::vector<int> a) {
    int m=0,s;
    for(int i=1;i<a.size();i++){
        m=max(abs(a[i]-a[i-1]),m);
    }
    return m;
}
