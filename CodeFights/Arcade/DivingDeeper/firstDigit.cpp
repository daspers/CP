char firstDigit(std::string s) {
    for(auto x:s)
        if(x>='0'&&x<='9')
            return x;
}
