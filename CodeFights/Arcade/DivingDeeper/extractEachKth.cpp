std::vector<int> w, extractEachKth(std::vector<int> a, int k) {
    for(int i =0 ;i <a.size();i++){
        if((i+1)%k)
            w.push_back(a[i]);
    }
    return w;
}
