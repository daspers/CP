int i, growingPlant(int u, int d, int h) {
    for(i=1;1;i++){
        if(u*i - d*(i-1)>=h)
            break;
    }
    return i;
}
