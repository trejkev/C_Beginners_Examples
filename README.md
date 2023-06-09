# C_Beginners_Examples
This repository is intended to give a brief guidance to all C beginners, but now any beginners, beginners that are looking for a strong guide on the syntax and management of some of the most important topics, in regards to memory management and user input.

These examples are quite simple, they provide a brief introduction to pointers, registers, and files management, so that in the future, they can get used with best practices with dealing with this kind of coding structures.

All tests are passing through Base_Examples.c file, it contains the main method that calls every routine according to the user input. The execution is quite simple, it can be done by simply using the Makefile attached to this repository.

## Running the code

Running the code is quite symple, all the links are already in place, you just need to run `make Run_Pointer_Basics`, `make Run_Register_Basics`, or `make Run_File_Management_Basics` to clear the bin directory from any older build, create the output files required, and finally, create the executable file containing all the output files made before. Depending on the run you want to perform, there are some inputs required, these inptus are defaulted to be something to bring you a brief example of how to use each of these, but you can easily modify them. Each example and their outputs will be explained in further sections of this readme file.

## Makefiles

To start with this tutorial, it is important to talk about the most basic compile and usage of Makefiles, it is not intended to bring you a full explanation of any compiler, but to give you an idea of what every directive means and how you cam take advantage of them to create a simple but powerful Makefile.

Makefile directives are just like executing any of the commands included into it right from the terminal, with the difference that you can take advantage of many symbols into the Makefile to create a simplified and fully automated execution file.

### Makefile symbols
You can have many symbols into a Makefile, but the most useful and basic to come up with your Makefile are the following:
1. Hash (`#`): This symbol is used to start a comment in a Makefile. Which means that the text following the hash will be ignored by Make.
2. Dollar sign (`$`): The usage of this symbol is to use variables throughout your code, so that you can make your Makefile look more readable. The usage is by setting into the Makefile command `$(your_variable)`, where your variable is something you have defined before executing this command.
3. Colon (`:`): This symbol is used to define a target and its dependencies in a rule. It separates the target from its prerequisites. You can use it in a way that you define a rule name, type the colon, and then the dependencies to be run before running this rule. For example, to run the directive pointed by rule named Run_Pointer_Basics, you need to first run the rule pointed by variable `$(FILENAME)`, which can also have other dependencies, and so on, after all these dependencies are executed in a tree-shaped form, Run_Pointer_Basics rule will be executed, which runs the command `./bin/$(FILENAME) Pointer_Basics`.

<p align="center">
  <img src="https://github.com/trejkev/C_Beginners_Examples/assets/18760154/47b0d3dd-3c60-41f5-b1bc-294e6346950b" />
</p>

4. Equals sign (`=`): The equals sign is used to define variables with simple syntax, which means, bringing a value into the variable, just like line `SOURCES = ./src/*.c` do. 

### Tree-Structured Makefile execution

Lets see an example into the Makefile of this repository, lets say you want to execute `Run_File_Management_Basics` rule, thus, this is what will happen:
1. You need to execute first the rule `$(FILENAME)`, since it is a dependency of my rule of interest.
2. The rule `$(FILENAME)` also depends of a set of rules and files, in this case the rules `clean`, `Base_Examples.o`, `Pointer_Basics.o`, `Register_Basics.o`, and `File_Management_Basics.o`, and the header file `./src/Base_Examples.h`, reason why you need to execute them before executing `$(FILENAME)`'s command. Consider that the dependencies are executed from left to right, in order of appearance into the dependencies of the rule.
3. Once dependencies that contain commands to execute (because they are also rules), like clean, that runs `-rm -f ./bin/*.o ./bin/$(FILENAME)`, and other dependencies, like headers, are run, it will run the `$(FILENAME)` rule, that runs the command `$(CLANG) $(FLAGS) $(BINARIES) -o ./bin/$(FILENAME)`.
4. Finally, it will run the command contained by our rule of interest, which is `Run_File_Management_Basics`, and executes `./bin/$(FILENAME) File_Management_Basics ./test/File_Management_Basics_Example.txt` command. 

See how all the commands were able to execute only when all their dependencies were executed, so that this becomes a tree-structured execution problem, therefore, be careful of including only dependencies that you really need to execute your rule, otherwise you can end up with a lot of thrash files, a high pre-execution time, or an oversized executable file. See the following figure to graphically understand what is happening.

<p align="center">
  <img src="https://github.com/trejkev/C_Beginners_Examples/assets/18760154/554b9aa1-d68b-4b31-ae8c-6d4eb11e3319" />
</p>

