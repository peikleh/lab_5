/* 
 * File:   main.c
 * Author: nevin.leh
 *
 * Created on May 29, 2014, 11:18 AM
 */

#include <stdio.h>
#include <stdlib.h>
double problem_1(double mass_1, double mass_2, double distance_1);
void problem_2_input_output(int number_1);
void problem_2_shuffle_left(char *let_1,char *let_2 ,char *let_3);
void ex_credit_A(int true_false, int* value_1);
int ex_credit_B(int* val_1);
    

double problem_1(double mass_1, double mass_2, double distance_1){
    
    double gravity_f= mass_1;

    gravity_f *= mass_2;
   
    gravity_f *= 6.67384e-11;
   
    distance_1*= distance_1;
    
    gravity_f /= distance_1;
     ;
    return gravity_f;
}
void problem_2_input_output(int number_1){
    char letter_1, letter_2, letter_3;
    FILE *in_file=fopen("i_goes_last.txt", "r");
    fscanf(in_file, "%c",&letter_1 );
     fscanf(in_file, "%c",&letter_2 );
      fscanf(in_file, "%c",&letter_3 );
  
    int shuffle_times;
    for(shuffle_times=0; shuffle_times<number_1; shuffle_times++){
        problem_2_shuffle_left(&letter_1, &letter_2, &letter_3);
        printf("%c%c%c \n", letter_1, letter_2, letter_3);
    }
}
void problem_2_shuffle_left(char *let_1,char *let_2 ,char *let_3) {
    char temp_value;
    temp_value=*let_1;
    *let_1=*let_2;
    *let_2=*let_3;
    *let_3=temp_value;
}

/*
 * 
 */
void ex_credit_A(int true_false, int* value_1){
    int original_value=5;
    if(true_false){
        ex_credit_B(&original_value);
    }else{
        printf("Original value is %i \n", original_value);
        *value_1=6;
       printf("new value is %i \n", *value_1);
    }
   if(true_false) printf("value was changed to %i\n", original_value);
    
}
int ex_credit_B(int* val_1){
    ex_credit_A(0, val_1);
}

int main() {
    int* fill_pointer;
    printf("%e \n", problem_1(10, 10, 5));
    problem_2_input_output(4);
    ex_credit_A(1, fill_pointer);
    return (EXIT_SUCCESS);
}

