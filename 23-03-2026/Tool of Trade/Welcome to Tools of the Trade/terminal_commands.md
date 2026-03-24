# Terminal Commands: Tools of the Trade

This document summarizes the essential terminal commands for navigating the file tree, creating/deleting files, and reading/writing content.

## 1. Navigating the File Tree
- `pwd`: **P**rint **W**orking **D**irectory (shows your current location).
- `ls`: **L**i**s**t (shows files and folders in the current directory).
- `cd`: **C**hange **D**irectory (move to a different folder).
- `..`: Go up one level (parent directory).

## 2. Creating & Deleting
- `touch <filename>`: Create a new empty file.
- `mkdir <foldername>`: Create a new directory (**M**a**k**e **Dir**ectory).
- `rm <filename>`: **R**e**m**ove a file.
- `rmdir <foldername>`: **R**e**m**ove an empty **dir**ectory.
- `rm -r <foldername>`: **R**e**m**ove a directory and all its contents **r**ecursively.

## 3. Writing to Files
- `echo 'Hello, world!'`: Prints "Hello, world!" to the terminal.
- `echo 'Hello, world!' > hello.txt`: Redirects the text into "hello.txt" (creates the file if it doesn't exist or overwrites it).

## 4. Reading from Files
- `cat <filename>`: Prints the contents of a file to the terminal.
- `cat hello.txt > hello_copy.txt`: Prints the contents of "hello.txt" and redirects it into "hello_copy.txt" (effectively copying the file).

## 5. Redirecting & Appending
- `>`: Redirect output (Overwrites the file).
- `>>`: Append output (Adds to the end of the file without deleting existing content).
