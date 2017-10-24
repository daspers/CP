long adjacentElementsProduct(std::vector<int> a) {
    long k=-999;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]*a[i+1]>k)
            k=a[i]*a[i+1];
    }
    return k;
}
