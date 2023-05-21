# C_Beginners_Examples
This repository is intended to give a brief guidance to all C beginners, but now any beginners, beginners that are looking for a strong guide on the syntax and management of some of the most important topics, in regards to memory management and user input.

These examples are quite simple, they provide a brief introduction to pointers, registers, and files management, so that in the future, they can get used with best practices with dealing with this kind of coding structures.

All tests are passing through Base_Examples.c file, it contains the main method that calls every routine according to the user input. The execution is quite simple, it can be done by simply using the Makefile attached to this repository.

## Makefiles

To start with this tutorial, it is important to talk about the most basic compile and usage of Makefiles, it is not intended to bring you a full explanation of any compiler, but to give you an idea of what every directive means and how you cam take advantage of them to create a simple but powerful Makefile.

Makefile directives are just like executing any of the commands included into it right from the terminal, with the difference that you can take advantage of many symbols into the Makefile to create a simplified and fully automated execution file.

You can have many symbols into a Makefile, but the most useful and basic to come up with your Makefile are the following:
1. Hash (#): This symbol is used to start a comment in a Makefile. Which means that the text following the hash will be ignored by Make.
2. Dollar sign ('$'): The usage of this symbol is to use variables throughout your code, so that you can make your Makefile look more readable. The usage is by setting into the Makefile command $(your_variable), where your variable is something you have defined before executing this command.
3. Colon (:): This symbol is used to define a target and its dependencies in a rule. It separates the target from its prerequisites. You can use it in a way that you define a rule name, type the colon, and then the dependencies to be run before running this rule. For example, to run the directive pointed by rule named Run_Pointer_Basics, you need to first run the rule pointed by variable '$'(FILENAME), which can also have other dependencies, and so on, after all these dependencies are executed in a tree-shaped form, Run_Pointer_Basics rule will be executed, which runs the command './bin/$(FILENAME) Pointer_Basics'.
<p align="center">
  <img src="https://github.com/trejkev/C_Beginners_Examples/assets/18760154/47b0d3dd-3c60-41f5-b1bc-294e6346950b" />
</p>
4. Equals sign (=): The equals sign is used to define variables with simple syntax, which means, bringing a value into the variable, just like line 'SOURCES = ./src/*.c' do. 
