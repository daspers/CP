int c[300], dc=0, differentSymbolsNaive(std::string s) {
    memset(c, 0, sizeof c);
    for(auto x : s){
        if(c[x]++ == 0)
            dc++;
    }
    return dc;
}
