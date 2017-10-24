bool areEquallyStrong(int yl, int yr, int fl, int fr) {
    int m1,m2;
    m1=yl>yr?yl:yr;
    m2=fl>fr?fl:fr;
    return (yl+yr==fl+fr)&&m1==m2;
}
