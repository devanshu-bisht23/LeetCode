int lengthOfLastWord(char* s) {

    int l = strlen(s);
    l=l-1;
    int i;
    int length=0;
    while (l >= 0 && s[l] == ' ') {
        l--;
    }
    for(i=l; i>=0 && s[i]!=' '; i--){
        length++;
    }
    return length;
}