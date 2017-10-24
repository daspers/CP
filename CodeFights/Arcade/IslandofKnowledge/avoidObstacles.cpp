int avoidObstacles(std::vector<int> a) {
    int i,k,m,j;
    sort(a.begin(),a.end());
    for(int l=0;l<a.size();l++)
        cout<<a[l]<<" ";
    m=a[a.size()-1];
    bool w=true;
    for(k=1;k<=41;k++){
        w=true;
        for(i=0,j=0;j<a.size()&&w;){
            if(i==a[j])
                w=false;
            else if(i>a[j])
                j++;
            else
                i+=k;
        }
        if(w)
            break;
    }
    return k;
}
