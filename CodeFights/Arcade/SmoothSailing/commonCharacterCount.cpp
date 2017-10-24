int s[2][26]={{0}}, commonCharacterCount(std::string s1, std::string s2) {
    for(int i=0;i<s1.size();i++){
        s[0][s1[i]-'a']++;
    }
    for(int i=0;i<s2.size();i++){
        s[1][s2[i]-'a']++;
    }
    int c=0;
    for(int i=0;i<26;i++){
        c+=min(s[0][i],s[1][i]);
    }
    return c;
}
