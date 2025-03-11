/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int flag=0, i;
    if(digits[digitsSize-1]<=8){
            digits[digitsSize-1]+=1;
            *returnSize = digitsSize;
            return digits;
        }else{
            digits[digitsSize-1]=0;
            flag=1;//least place is a 9
        }

    if(flag==1){
        for(i=digitsSize-2; i>=0; i--){ 
            if(digits[i]<=8){
            digits[i]+=1;
            *returnSize = digitsSize;
            return digits;
        }else{
            digits[i]=0;
            }
        }
           flag=2; //tells us all are 9
    }

    if(flag==2){ //handles if all are 9 so malloc
    int *p = (int*)malloc((digitsSize+1) * sizeof(int));
    p[0]=1;
    for(i=1; i<=digitsSize; i++){
        p[i]=0; 
    }
    *returnSize = digitsSize + 1;
    return p;
    } 
    return NULL;
}