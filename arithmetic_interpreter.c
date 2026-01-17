#include <stdio.h>
#include <stdbool.h>
#define INPUT_LENGTH 1000
int main(){
  while(true){
  printf(">>>");
  char buf[INPUT_LENGTH];
  fgets(buf,INPUT_LENGTH,stdin);
  printf(buf);
  };
  
  return 0;
}
