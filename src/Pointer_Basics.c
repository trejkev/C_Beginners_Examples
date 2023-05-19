// Copyright 2023 Kevin Trejos Vargas <kevin.trejosvargas@ucr.ac.cr>

#include "Base_Examples.h"

int pointer_basics(size_t i_Value) {
    printf("-- POINTER BASICS --\n");
    size_t* pi_Variable = &i_Value;
    printf("My variable is %zi\n", i_Value);
    printf("--------\n");
    printf("The direction stored by pointer is %p\n", (void *)pi_Variable);
    printf("The direction where my file is %p\n", (void *)&i_Value);
    printf("--------\n");
    printf("The content of my variable, directly from it is %zi\n", i_Value);
    printf("The content of my variable, taken from pointer is %zi\n",
        *pi_Variable);
    printf("--------\n");
    *pi_Variable *= 2;
    printf("Variable modified to be one 2 times bigger from pointer %zi\n",
        *pi_Variable);
    printf("Value modified right from my variable %zu\n", i_Value);
    printf("--------\n");
    printf("The direction of my pointer is %p\n", (void *)&pi_Variable);
    printf("-- End of pointer basics --\n");
    return TRUE;
}
