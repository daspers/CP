int C(std::vector<std::vector<bool>> m,int a, int b, int i, int j){
    int c=0;
    if(i>0){
        c+=m[i-1][j];
        if(j>0)
            c+=m[i-1][j-1];
        if(j<b-1)
            c+=m[i-1][j+1];
    }
    if(j>0)
        c+=m[i][j-1];
    if(i<a-1){
        c+=m[i+1][j];
        if(j<b-1)
            c+=m[i+1][j+1];
        if(j>0)
            c+=m[i+1][j-1];
    }
    if(j<b-1)
        c+=m[i][j+1];
    return c;
}

std::vector<std::vector<int>> z, minesweeper(std::vector<std::vector<bool>> m) {
    std::vector<int> y;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[0].size();j++){
            y.push_back(C(m,m.size(),m[0].size(),i,j));
        }
        z.push_back(y);
        y.clear();
    }
    return z;
}
