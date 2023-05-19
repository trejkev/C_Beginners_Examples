// Copyright 2023 Kevin Trejos Vargas <kevin.trejosvargas@ucr.ac.cr>

#include "Base_Examples.h"

// -- argc counts the number of inputs from command line, including executable
// -- argv contains all the inputs from command line, in a char * format
int main(int argc, char *argv[]) {
    size_t i_Variable = 456;
    if (argc > 2) {
        sscanf(argv[2], "%zu", &i_Variable);  // Asign arg[2] to i_Variable
    }

    // -- Run pointer basics
    if (strcmp(argv[1], "Pointer_Basics") == 0) {
        pointer_basics(i_Variable);
    }

    // -- Run register basics
    if (strcmp(argv[1], "Register_Basics") == 0) {
        size_t height, width;
        if (argc == 4) {
            sscanf(argv[2], "%zu", &height);
            sscanf(argv[3], "%zu", &width);
        } else {
            height = 20;
            width  = 10;
        }
        register_basics(height, width);
    }

    // -- Run file management basics
    if (strcmp(argv[1], "File_Management_Basics") == 0) {
        size_t filename_length = strlen(argv[2]);
        if (filename_length <= PATH_MAX) {
            char cFileName[strlen(argv[2]) + 1];
            printf("File name is %s\n", argv[2]);
            printf("File name size is %zu\n", filename_length);
            sscanf(argv[2], "%s", (char *)&cFileName);
            file_management_basics(filename_length, cFileName);
        } else {
            printf("File name is too long.\n");
            exit(1);
        }
    }

    return 0;
}
