################################################################################
# -- The compiling process                                                     #
#                                                                              #
#   File.c                                                                     #
# -E  |    Preprocessor   Handles all #include and #define directives          #
#     V                                                                        #
# -S  |    Compiler       Translates to C assembly                             #
#     V                                                                        #
#   File.s                                                                     #
# -c  |    Assembler      Translates assembly to object file                   #
#     V                                                                        #
#   File.o                                                                     #
# -o  |    Linker         Brings together object files to create an executable #
#     V                                                                        #
#    File                                                                      #
################################################################################

FILENAME   = Base_Examples
COMPILER   = cc
CLANG      = clang
FLAGS      = -g -Wall -Wextra
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer
HEADERS    = ./src/*.h
SOURCES    = ./src/*.c
BINARIES   = ./bin/*.o

LINTFILTERS = $\
	-build/c++11,$\
	-build/header_guard,$\
	-build/include_subdir,$\
	-readability/casting,$\
	-runtime/references



# --- REGULAR COMPILATION DIRECTIVES --- #

$(FILENAME): clean Base_Examples.o Pointer_Basics.o Register_Basics.o File_Management_Basics.o ./src/Base_Examples.h
	$(CLANG) $(FLAGS) $(BINARIES) -o ./bin/$(FILENAME)

$(FILENAME).o:
	$(CLANG) -c ./src/Base_Examples.c -o ./bin/Base_Examples.o

Pointer_Basics.o:
	$(CLANG) -c ./src/Pointer_Basics.c -o ./bin/Pointer_Basics.o

Register_Basics.o:
	$(CLANG) -c ./src/Register_Basics.c -o ./bin/Register_Basics.o

File_Management_Basics.o:
	$(CLANG) -c ./src/File_Management_Basics.c -o ./bin/File_Management_Basics.o

clean:
	-rm -f ./bin/*.o ./bin/$(FILENAME)




# --- MEMORY SANITIZERS --- #

asan: clean Base_Examples.o Pointer_Basics.o Register_Basics.o File_Management_Basics.o ./src/Base_Examples.h
	$(CLANG) $(FLAGS) $(ASAN_FLAGS) ./bin/Base_Examples.o ./bin/Pointer_Basics.o ./bin/Register_Basics.o ./bin/File_Management_Basics.o -o ./bin/$(FILENAME)

memcheck_Pointer_Basics: $(FILENAME)
	valgrind ./bin/$(FILENAME) Pointer_Basics

memcheck_Register_Basics: $(FILENAME)
	valgrind ./bin/$(FILENAME) Register_Basics 20 12

memcheck_File_Management_Basics: $(FILENAME)
	valgrind ./bin/$(FILENAME) File_Management_Basics

lint:
	cpplint --filter=$(LINTFILTERS) $(HEADERS) $(SOURCES)




# --- RUNNING THE CODE ---#

Run_Pointer_Basics: $(FILENAME)
	./bin/$(FILENAME) Pointer_Basics

Run_Register_Basics: $(FILENAME)
	./bin/$(FILENAME) Register_Basics 20 12

Run_File_Management_Basics: $(FILENAME)
	./bin/$(FILENAME) File_Management_Basics ./test/File_Management_Basics_Example.txt
