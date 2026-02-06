This project has been created as part of the 42 curriculum by memalli.

# Libft

## Description
`Libft` is a small static C library implemented as part of the 42 school curriculum. It re-implements a selection of standard C library routines and provides a few utility functions (strings, memory, I/O, and a simple linked list API) so students can learn manual memory management, function design, and simple data structures.

This repository contains the full source for the library, a public header (`libft.h`) and a `Makefile` that builds a static archive `libft.a` which can be linked into student projects or simple tests.

## Why this project exists
- To practice writing idiomatic C with manual memory management.
- To learn how to design a minimal public API (`libft.h`) and provide one-function-per-file implementations.
- To gain experience building and linking a static library using a `Makefile`.

## Library overview
- Public header: `libft/libft.h` — contains all function prototypes and the `t_list` struct.
- Implementations: one `ft_*.c` file per function in `libft/` (for example `ft_strdup.c`, `ft_split.c`).
- Build artifact: `libft.a` produced by the `Makefile`.

### Function categories
- Character checks and case conversion: `ft_isalpha`, `ft_isdigit`, `ft_toupper`, `ft_tolower`, etc.
- Memory routines: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`, `ft_bzero`.
- String routines: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`.
- File descriptor output helpers: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.
- Linked list helpers: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Instructions

Build the library (from the `libft/` directory):
```bash
make
```

Clean object files:
```bash
make clean
```

Remove the archive as well:
```bash
make fclean
```

Rebuild from scratch:
```bash
make re
```

Run the simple test runner included in the repo:
```bash
make run
```
This target compiles `ft_main.c` together with `libft.a` and executes the resulting `test` binary.

Manual compilation example (equivalent to `make run` behavior):
```bash
cc -Wall -Wextra -Werror ft_main.c libft.a -o test
./test
```

## Project-specific conventions and important notes
- Naming: Every function uses the `ft_` prefix and is implemented in its own file `ft_<name>.c`.
- Header-first: All public prototypes are declared in `libft/libft.h`; keep the header and implementations synchronized.
- Makefile: To add a new public function, 1) create `ft_<name>.c` in `libft/`, 2) add the prototype to `libft/libft.h`, and 3) append `ft_<name>.c` to the `SRCS` variable in `Makefile`.
- Compiler flags: the `Makefile` uses `-Wall -Wextra -Werror`. Warnings are treated as errors — code must compile cleanly.
- Signature deviation: in the provided `libft/libft.h`, `ft_lstadd_back` is declared to return `int` (not the common `void`) — respect this signature when using or changing it.
- Type definition: the header declares `typedef unsigned long size_t;` (a redefinition). Be cautious when modifying the header or including external headers that also declare `size_t`.

## Examples
Simple usage pattern to build and run the included main:
```bash
cd libft
make
make run
```

Add a new function example (high level):
1. Add `ft_newfunc.c` implementing `ft_newfunc`.
2. Add the prototype to `libft/libft.h`.
3. Append `ft_newfunc.c` to the `SRCS` list in `Makefile`.
4. Run `make` and fix compilation warnings/errors.

## Resources
- Standard C library documentation (man pages): `man strncpy`, `man malloc`, etc.
- 42 school project subject and examples (student materials supplied by your campus).

## Notes for maintainers / contributors
- Keep edits minimal and consistent with naming conventions.
- When adding non-trivial behavior, include a small test in `ft_main.c` or a temporary test file and use `make run` to verify link and runtime behavior.

If you want, I can also add a short example showing how to implement and test a new function end-to-end.
