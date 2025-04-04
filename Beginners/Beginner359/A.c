#include <stdio.h>
#include <string.h>

int main(){
 int N;
 char input[100];
 scanf("%d", &N);

 int count=0;
 for(int i=0; i<N; i++) {
  scanf("%s", input);
  if(strcmp(input, "Takahashi")==0){
   count++;
  }
 }

 printf("%d", count);

 return 0;

}
