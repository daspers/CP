
bool almostIncreasingSequence(std::vector<int> s) {
    int shit=1;
    for(int i=0;i<s.size()-1;i+=1){
        if(s[i]-s[i+1]>=0) {
            if(!shit)return 0;
            shit=0;
        }
    }
    return 1;
}
