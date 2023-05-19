// Copyright 2023 Kevin Trejos Vargas <kevin.trejosvargas@ucr.ac.cr>

#include "Base_Examples.h"
#include <unistd.h>  // Bring current working directory

int file_management_basics(size_t filename_len, char sFileName[filename_len]) {
    printf("-- FILE MANAGEMENT BASICS --\n");
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("Current working directory is %s, and its size is %zu\n",
        cwd, strlen(cwd));
    printf("Current file is %s\n", sFileName);

    FILE *fptr;
    if ((fptr = fopen(sFileName, "r")) == NULL) {
        printf("Error opening the file.\n");
        return FALSE;
    } else {
        printf("File opened!\n");
        char sStringTest[PATH_MAX];
        printf("Doc reading is:\n");
        bool bEndOfDoc = FALSE;
        while (bEndOfDoc == FALSE) {
            fscanf(fptr, "%[^\n]\n", (char *)&sStringTest);
            if (feof(fptr)) {  // Reached end of a file
                printf("%s\n", sStringTest);
                bEndOfDoc = TRUE;
            } else {
                printf("%s\n", sStringTest);
            }
        }
        fclose(fptr);
    }
    return TRUE;
}
