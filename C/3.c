#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * solve(char * s, int * roll, int n){
    int len = strlen(s);
    int f[len];
    memset(f, 0, sizeof(f));
    for(int i = 0; i<n; i++){
        f[0]++;
        if(roll[i]<len)
            f[roll[i]]--;
    }
    int pref = 0;
    char *res = (char*)malloc(sizeof(char)*len);
    // printf("%d\n", (int)sizeof(*res));

    for(int i = 0; i<len; i++){
        f[i] += pref;
        pref = f[i];
        res[i] = (char)('a'+(s[i]-'a'+f[i])%26);
        // printf("%c ", res[i]);
    }
    return res;
}

int main(){
    char s[] = "zczakaslasbhasdasdf";
    int roll[] = {1,1,3, 4};
    int n = sizeof(roll)/sizeof(roll[0]);
    
    char * ans = solve(s, roll, n);
    printf("%s\n", ans);
    return 0;
}