bool variableName(std::string n) {
    if(n[0]>='0'&&n[0]<='9')
        return false;
    for(int i=0;i<n.size();i++){
        if(!((n[i]>='0'&&n[i]<='9')||(n[i]>='A'&&n[i]<='Z')||(n[i]>='a'&&n[i]<='z')||n[i]=='_'))
            return false;
    }
    return true;
}
