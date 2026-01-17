#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define INPUT_LENGTH 1000
#define INTEGER 0
#define OPERATOR 1
typedef struct {
  int type;
  int number_value;
  char operator_value;
} Token;
Token current_token;//global variable with no initialisation
bool is_digit(char c){
  return c>='0'&& c<='9';
}
void identifying_type(char raw_token){
  if(is_digit(raw_token)){
    current_token.type=INTEGER;
    current_token.number_value=raw_token-'0';
  }else{
    current_token.type=OPERATOR;
    current_token.operator_value=raw_token;
  }
  
}
void interpreter(char *text){
  // int length=sizeof(*text)/sizeof(text[0]);
  int length=strlen(text);
  for(int i=0;i<length-1;i++){//Here -1 is for \n given by fgets
    identifying_type(text[i]);//Here I need to identify wether the given char is a number or a operator
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
