std::vector<int> b, sortByHeight(std::vector<int> a) {
    for(int i=0;i<a.size();i++){
        if(a[i]!=-1){
            b.push_back(a[i]);
            a[i]=-2;
        }
    }
    int k=b.size();
    while(k>1){
        for(int i=0;i<k-1;i++){
            if(b[i]>b[i+1]){
                int temp = b[i];
                b[i]=b[i+1];
                b[i+1]=temp;
            }
        }
        k--;
    }
    int j=0;
    for(int i=0; i<a.size();i++){
        if(a[i]==-2){
            a[i]=b[j];
            j++;
        }
    }
    return a;
}
