
# Get Next Line (GNL)

The `Get Next Line` project is a function that reads a file line by line. This project is designed to help you learn how to use static variables, memory allocation, and file input/output in C programming.

## Mandatory Part

The mandatory part of the project requires you to implement the following function:
`char *get_next_line(int fd);`

This function should read the file descriptor `fd` one line at a time, and return a pointer to a string containing the line. The function should return `NULL` if it reaches the end of the file or an error occurs.
You can switch the BUFFER_SIZE using this flag with compiling:
`gcc -D BUFFER_SIZE=any_size get_next_line.c get_next_line_uils.c`

## Bonus Part


Here are the bonus part requirements: 
• Develop get_next_line() using only one static variable. 
• Your get_next_line() can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd. It means that you should be able to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.

## Usage

To use the `get_next_line` function, you'll need to include the appropriate header file:

`#include "get_next_line.h"`

Then, you can call the function in your program:
`
char *line; `
`line = get_next_line(fd); `

If the function returns a non-null pointer, the line has been successfully read and stored in `line`. You can continue calling the function to read subsequent lines until it returns `NULL` (end of file) or an error occurs.

## Contributing

If you find a bug in `get_next_line` or would like to contribute a new feature, please feel free to submit a pull request. We welcome contributions from anyone, regardless of their level of experience.

## Contact

If you have any questions or concerns, please feel free to reach out to us at our email address, `hovakimyan29@gmail.com`.