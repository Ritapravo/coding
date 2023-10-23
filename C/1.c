#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int gcd(int a, int b){
    if(a<b)
        return gcd(b, a);
    if(a%b==0)
        return b;
    else return gcd(b, a%b);
}

char * solve(char *s){
    
    int i = 0, j = 0, num = 0;
    int nums[4];
    while(s[i]!='\0'){
        if(s[i]=='+' || s[i]=='/'){
            nums[j++] = num;
            num = 0;
        }
        else{
            int t = (int)(s[i]-'0');
            num = num*10+t;
        }
        i++;
    }
    nums[j] = num;
    int nu = nums[0]*nums[3] + nums[1]*nums[2];
    int de = nums[1]*nums[3];
    int g = gcd(nu, de);
    nu = nu/g;
    de = de/g;
    char *ans = (char*)malloc(sizeof(char)*100);
    snprintf(ans, sizeof(ans)*100, "%d/%d", nu, de);
    return ans;
}

int main(){
    int t; 
    scanf("%d", &t);
    while(t--){
        char s[50];
        scanf("%s", s);
        char * res = solve(s);
        printf("\n%s\n", res);
    }
    return 0;
}
// 5
// 722/148+360/176
// 978/1212+183/183
// 358/472+301/417
// 780/309+684/988
// 258/840+854/686