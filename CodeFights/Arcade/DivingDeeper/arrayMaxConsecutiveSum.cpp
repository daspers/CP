int arrayMaxConsecutiveSum(std::vector<int> a, int k) {
    int h,t,ma=0,s;
    for(h=0;h<k;h++)
        ma+=a[h];
    s=ma;
    for(t=0,h=k;h<=a.size();h++){
        s-=a[t++];
        s+=a[h];
        ma=max(ma,s);
    }
    return ma;
}
