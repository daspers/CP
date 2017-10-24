int s=0, matrixElementsSum(auto m) {
    bool x[10];
    for(int i=0;i<10;i++)
        x[i]=0;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            if(m[i][j]>0){
                if(!x[j]){
                    s+=m[i][j];
                }
            }
            else{
                if(!x[j]) x[j]=1;
            }
        }
    }
    return s;
}
