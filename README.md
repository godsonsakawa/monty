# monty


## The Monty Language
Monty 0.98 is a __scripting language__ that is first compiled into Monty byte codes (Just like _Python_). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before the opcode and its argument:

	julien@ubuntu:~/monty$ cat -e bytecodes/000.m
	push 0$
	push 1$
	push 2$
	   push 3$
			   pall		$
	push 4$
	    push 5	$
		push	6	$
	pall$
	julien@ubuntu:~/monty$

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account:

	julien@ubuntu:~/monty$ cat -e bytecodes/001.m
	push 0 Push 0 onto the stack$
	push 1 Push 1 onto the stack$
	$
	push 2$
	   push 3$
			  pall		$
	$
	$
					$
	push 4$
	$
	     push 5	$
		push	6	$
	pall$
	julien@ubuntu:~/monty$

__The monty program__

> * Usage: `monty file`
> > - where `file` is the path to the file containing Monty byte code
> * If the user does not give any file or more than one argument to u=your program, print the error message
  `USAGE: monty file`, fo;;owed by a new line, and exit with the status `EXIT_FAILURE`
> * If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
> > - where `<file>` is the name of the file
> * If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
> > - where is the line number where the instruction appears.
> > - Line numbers always start at 1
> * The monty program runs the bytecodes line by line and stop if either:
> > - it executed properly every line of the file
> > - it finds an error in the file
> > - an error occured
> * If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE.`
> * You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

## Compilation & Output
* The code is compiled in the following manner:

	$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

* Any output must be printed on `stdout`
* Any error message must be printed on `sterr`
> * [Here is a link to a GitHub repository](https://github.com/godsonsakawa/stderred) that could help you making sure your errors are printed on stderr
