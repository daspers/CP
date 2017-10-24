int makeArrayConsecutive2(std::vector<int> s) {
    std::sort(s.begin(), s.end());
    int a=0;
    for(int i=0;i<s.size()-1;i++){
        a+=s[i+1]-s[i]-1;
    }
    return a;
}
