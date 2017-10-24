std::vector<std::vector<int>> z, boxBlur(std::vector<std::vector<int>> m) {
    std::vector<int> y;
    int a=m.size()-3, b=m[0].size()-3, sum;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            sum=0;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    sum+=m[k][l];
                }
            }
            y.push_back(sum/9);
        }
        z.push_back(y);
        y.clear();
    }
    return z;
}
