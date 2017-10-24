bool chessBoardCellColor(std::string a, std::string b) {
    return (a[0]-'a'+a[1]-'1')%2==(b[0]-'a'+b[1]-'1')%2;
}
