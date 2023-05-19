// Copyright 2023 Kevin Trejos Vargas <kevin.trejosvargas@ucr.ac.cr>

#include "Base_Examples.h"

int register_basics(size_t reg_height, size_t reg_width) {
    printf("-- REGISTER BASICS --\n");
    printf("-- Dealing with a single structure of r_RegExample\n");
    reg_example_t reg_example_single;
    reg_example_single.reg_field_a = 3;
    memcpy(reg_example_single.reg_field_b, "abc",
        sizeof(reg_example_single.reg_field_b)-1);
    reg_example_single.reg_field_c = 87654322345;
    printf("The size of reg_example_single is %li bytes\n",
        sizeof(reg_example_single));
    printf("    reg_field_a is an int of %li bytes\n",
        sizeof(reg_example_single.reg_field_a));
    printf("    reg_field_b is a char[4] of %li bytes\n",
        sizeof(reg_example_single.reg_field_b));
    printf("    reg_field_c is an long of %li bytes\n",
        sizeof(reg_example_single.reg_field_c));

    printf("-- Making a simple register of %zu times reg_example_t\n",
        reg_width);
    reg_example_t* reg_example_array = (reg_example_t*)
        calloc(reg_width, sizeof(reg_example_t));  // N*regtype RAM register
    for (size_t index = 0; index < reg_width; ++index) {
        reg_example_array[index].reg_field_a = 3;
        memcpy(reg_example_array[index].reg_field_b, "abc",
            sizeof(reg_example_array[index].reg_field_b)-1);
        reg_example_array[index].reg_field_c = index;
    }
    printf("There were created %zu reg_example_t in memory\n", reg_width);
    printf("The size of reg_example_array is %zu\n",
        sizeof(*reg_example_array)*reg_width);
    free(reg_example_array);  // Releasing the memory used

    printf("-- Making a matrix of size %zu*%zu - cell size = reg_example_t\n",
        reg_height, reg_width);
    reg_example_t **reg_example_matrix =
        (reg_example_t **)calloc(reg_height, sizeof(reg_example_t));
    // Allocate memory for the matrix
    for (size_t i_RegRow = 0; i_RegRow < reg_height; ++i_RegRow) {
        reg_example_matrix[i_RegRow] =
            (reg_example_t *)calloc(reg_width, sizeof(reg_example_t));
    }
    printf("I have created a matrix of %zu by %zu in memory\n",
        reg_height, reg_width);
    // Free memory matrix
    for (size_t i_RegRow = 0; i_RegRow < reg_height; ++i_RegRow) {
        free(reg_example_matrix[i_RegRow]);
    }
    free(reg_example_matrix);
    return TRUE;
}
