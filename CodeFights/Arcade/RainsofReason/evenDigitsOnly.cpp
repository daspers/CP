bool evenDigitsOnly(int n) {
    if(n%2)
        return false;
    else if(n)
        return evenDigitsOnly(n/10);
    else
        return true;
}
