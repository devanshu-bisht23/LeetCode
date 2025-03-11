int strStr(char* haystack, char* needle) {
    
    int l = strlen(needle),count=0;
    int length = strlen(haystack), i=0,j=0;

    for(i=0;i<length;i++){ //iterate across haystack
        for(j=0;j<l;j++){ //iterate across needle

            if(haystack[i+j]!=needle[j]){
                count=0;
                break;
            }else{
                count++;
                if(count==l){
                    return i;
                }
            }

        }
    }
    return -1;
}