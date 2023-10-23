#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
char* solve(char *s)
{

   int i=0,k=0;
   int nums[4];
   int num=0;
   while(s[i]!='\0'){
       if(s[i]=='/' || s[i]=='+'){
           nums[k++] = num; 
           num = 0;
       }
       else{
           int t = s[i]-'0';
           num = num*10+t;
       }
       i++;
   }
   nums[k] = num;
   int a = nums[0];
   int b = nums[1];
   int c = nums[2];
   int d = nums[3];
 
   int gcddr = gcd(b,d);
   int t = b*d;
   int lcmdr = t/gcddr;
   a = a*(lcmdr/b);

   c = c*(lcmdr/d);
   int nr = a+c;
   int dr = lcmdr;
   
   int newgcd = gcd(nr,dr);
   int newnr= (nr/newgcd); 
   int newdr= (dr/newgcd);
//   char ans[20];
   char ans = (char) malloc(sizeof(char)*20);

   snprintf(ans, sizeof(ans), "%lld/%lld", nr / newgcd, dr / newgcd);
//   printf("%s\n", ans);

   return ans;
}

int main(){
    char s[50];
    scanf("%s",s);
    // char * u=solve(s);
    printf("%s", solve(s));
    return 0;
}