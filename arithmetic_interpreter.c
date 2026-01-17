#include <stdio.h>
#include <stdbool.h>
#define INPUT_LENGTH 1000
typedef struct {
  int type;
  char value;
}Token;
void interpreter(char *text){
  int length=sizeof(text)/sizeof(text[0]);
  for(int i=0;i<length-1;i++){
    
  }
}
int main(){
  while(true){
  printf(">>>");
  char buf[INPUT_LENGTH];
  fgets(buf,INPUT_LENGTH,stdin);
  interpreter(buf);
  };
  
  return 0;
}
