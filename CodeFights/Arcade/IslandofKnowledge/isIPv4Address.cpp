bool isIPv4Address(std::string s) {
    int k=0, c=0;
    bool b=true, z=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            if(b)
                return false;
            else
                b=true;
            if(k>255)
                return false;
            k=0;
            c++;
            if(c>3)
                return false;
            z=false;
        }
        else if (s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0'){
                if(b&&s[i+1]>='0')
                    return false;
                if(z)
                    return false;
                else
                    z=true;
            }
            else
                z=false;
            b=false;
            k=k*10+s[i]-'0';
        }
        else
            return false;
    }
    if(c<3)
        return false;
    if(s[s.size()-1]=='.')
        return false;
    return k<=255;
}
