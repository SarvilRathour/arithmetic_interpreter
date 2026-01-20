#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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
bool is_operator(char c){
  return c=='+' || c=='-';
}
void parse(int type){
  
    if(current_token.type!=type){
      printf("Exected a different value");
      exit(-1);
    }
}
void identifying_type(char raw_token){
  if(is_digit(raw_token)){
    current_token.type=INTEGER;
    current_token.number_value=raw_token-'0';
    // printf("type=%d and value=%d\n",current_token.type,current_token.number_value);
  }else if(is_operator(raw_token)){
    current_token.type=OPERATOR;
    current_token.operator_value=raw_token;
    // printf("type=%d and value=%c\n",current_token.type,current_token.operator_value);
  }else{
    printf("You are either giving a wrong numberical number or giving a wrong operator. Numbers between 0-9 are only valid where as in operators only + and - are valid");
    exit(-1);
  }
  
}
void interpreter(char *text){
  // int length=sizeof(*text)/sizeof(text[0]);
  int length=strlen(text);
  for(int i=0;i<length-1;i++){//Here -1 is for \n given by fgets
    identifying_type(text[i]);//Here I need to identify wether the given char is a number or a operator
    if(i%2==0){
    parse(INTEGER);    
    }else{
      parse(OPERATOR);
    }
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
