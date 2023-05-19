// Copyright 2023 Kevin Trejos Vargas <kevin.trejosvargas@ucr.ac.cr>

#include <stdio.h>  // Input and output management
#include <string.h>
#include <stdlib.h>  // To work with calloc
#include <linux/limits.h>  // Brings limits to variables
#include <stdbool.h>  // To use booleans

#define TRUE  1
#define FALSE 0

typedef struct reg_example {
    int  reg_field_a;
    char reg_field_b[4];
    long reg_field_c;
} reg_example_t;

int pointer_basics(size_t value);
int register_basics(size_t reg_height, size_t reg_width);
int file_management_basics(size_t filename_len, char sFileName[filename_len]);
