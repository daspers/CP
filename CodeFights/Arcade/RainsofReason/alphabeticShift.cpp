std::string alphabeticShift(std::string s) {
    int k;
    for(int i=0;i<s.size();i++){
        k=s[i]-'a'+1;
        s[i]=char(k%26+'a');
    }
        
    return s;
}
