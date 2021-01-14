#include <stdio.h> 
int count(int,int);int main(){count(1,10);return 0;}int count(int i,int max){if(i==max){printf("%d",i);return 0;}else{printf("%d\n",max);return count(i,max-1);}}