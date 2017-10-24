std::vector<int> alternatingSums(std::vector<int> a) {
    int b=0,c=0;
    for(int i=0;i<a.size();i++){
        if(i%2)
            c+=a[i];
        else
            b+=a[i];
    }
    return {b,c};
}
