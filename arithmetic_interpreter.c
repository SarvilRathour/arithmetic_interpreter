#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_LENGTH 1000
#define INTEGER 0
#define OPERATOR 1
#define MAX_CAPACITY 1000
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
      printf("Syntax Error: Value passed doesn't follow the grammar");
      exit(-1);
    }
}
void remove_whitespace(char *white_text){
  int count=0;
  for (int i=0;white_text[i];i++){
    if(white_text[i]!=' '){
      white_text[count++]=white_text[i];
    }
  }
   white_text[count]='\0';
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
int interpreter(char *text){
  // int length=sizeof(*text)/sizeof(text[0]);
  remove_whitespace(text);
  int nums[MAX_CAPACITY]={};
  int current_number_size=0;
  char operators[MAX_CAPACITY]={};
  int current_operator_size=0;
  int length=strlen(text);
  for(int i=0;i<length-1;i++){//Here -1 is for \n given by fgets
    identifying_type(text[i]);//Here I need to identify wether the given char is a number or a operator
    if(i%2==0){
    parse(INTEGER);  
    nums[current_number_size]=current_token.number_value;
    current_number_size++;
    }else{
      parse(OPERATOR);
      operators[current_operator_size]=current_token.operator_value;
      current_operator_size++;
    }
  }
  int result=nums[0];
  for(int i=0;i<current_number_size;i++){
    if(operators[i]=='+'){
      result+=nums[i+1];
    }else if(operators[i]=='-'){
      result-=nums[i+1];
    }
  }
  return result;
}
int main(){
  while(true){
  printf(">>>");
  char buf[INPUT_LENGTH];
  fgets(buf,INPUT_LENGTH,stdin);
  int answer=interpreter(buf);
  printf("%d\n",answer);
  };
  
  return 0;
}
