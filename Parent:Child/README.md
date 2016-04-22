# ITCS-3146-Parent/Child Program
What this program is meant to accomplish is a basic operation that allows a
program to create a child process, the child will then run its function and
and then terminate leading back to the parent.

The program first prints its process ID and its parent process ID. then it
displays the menu for the user.

Each option invokes a function call. When a function is called it will fork()
the program and the child will run its part of the code. After the code has
been executed, the child will be terminated. The parent process will wait until
the child is finished executing.
