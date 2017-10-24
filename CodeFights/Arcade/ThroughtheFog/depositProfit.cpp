int depositProfit(int d, int r, int t) {
    int c=0;
    float k=d, m=float(r)/100;
    while(k<t){
        k*=(m+1);
        c++;
    }
    return c;
}
