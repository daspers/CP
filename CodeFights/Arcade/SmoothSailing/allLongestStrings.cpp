std::vector<std::string> a, allLongestStrings(auto z) {
    int lg = 0;
    for(int i=0;i<z.size();i++){
        if(z[i].size()>lg) lg=z[i].size();
    }
    for(int i=0;i<z.size();i++){
        if(z[i].size()<lg) z.erase(z.begin()+i), i--;
    }
    return z;
}
