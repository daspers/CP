void n(string &s, int &p, int l, int r){
    string y="";
    for(int i=l+1;i<r;i++){
        y=s[i]+y;
    }
    for(int i=l+1,j=0;i<r;i++,j++){
        s[i]=y[j];
    }
    s.erase(s.begin()+r);
    s.erase(s.begin()+l);
    p-=2;
}

void k(string &s, int &p, int i){
    for(int j=i+1;j<p;j++){
        if(s[j]=='('){
            k(s,p,j);
        }
        else if(s[j]==')'){
            n(s,p,i,j);
            return;
        }
    }
}

string  reverseParentheses(auto s){
    int p=s.size();
    for(int i=0;i<p;i++){
        if(s[i]=='('){
            k(s,p,i);
        }
    }
    return s;
}
