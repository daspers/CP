int sum(int a){
    int c=0;
    while(a){
        c+=a%10;
        a/=10;
    }
    return c;
}
bool isLucky(long n) {
    int l = 0;
    long s = n;
    while(s){
        s/=10;
        l++;
    }
    int k= l/2,j=l%2;
    return sum(n/(pow(10,k+j)))==sum(n%(int(pow(10,k+j))));
}
