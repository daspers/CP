bool palindromeRearranging(std::string s) {
    int c[256]={0},d=0;
    for(int i=0;i<s.size();i++){
        c[s[i]]++;
    }
    for(int i='a';i<='z';i++){
        d+=c[i]%2;
    }
    if(d>1)
        return false;
    else if(d==1)
        return s.size()%2;
    else
        return true;
}
