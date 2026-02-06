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

## Function Reference

### Character Classification and Case Conversion
- `ft_isalpha(int c)` — Returns true if `c` is an alphabetic character (A–Z, a–z).
- `ft_isdigit(int c)` — Returns true if `c` is a decimal digit (0–9).
- `ft_isalnum(int c)` — Returns true if `c` is alphanumeric (letter or digit).
- `ft_isascii(int c)` — Returns true if `c` is a valid ASCII character (0–127).
- `ft_isprint(int c)` — Returns true if `c` is a printable character (space through ~).
- `ft_toupper(int c)` — Returns the uppercase equivalent of `c`; non-letters are unchanged.
- `ft_tolower(int c)` — Returns the lowercase equivalent of `c`; non-letters are unchanged.

### Memory Manipulation
- `ft_memset(void *b, int c, size_t len)` — Fills the first `len` bytes of memory area `b` with the constant byte `c`.
- `ft_bzero(void *s, size_t n)` — Fills the first `n` bytes of memory area `s` with zeros. Equivalent to `ft_memset(s, 0, n)`.
- `ft_memcpy(void *dst, const void *src, size_t n)` — Copies `n` bytes from memory area `src` to `dst`. Assumes areas do not overlap.
- `ft_memmove(void *dst, const void *src, size_t len)` — Copies `len` bytes from `src` to `dst`; handles overlapping areas safely.
- `ft_memchr(const void *s, int c, size_t n)` — Searches the first `n` bytes of memory area `s` for the byte `c`. Returns a pointer to the match or `NULL`.
- `ft_memcmp(const void *s1, const void *s2, size_t n)` — Compares the first `n` bytes of `s1` and `s2`. Returns negative if `s1 < s2`, zero if equal, positive if `s1 > s2`.
- `ft_calloc(size_t count, size_t size)` — Allocates memory for an array of `count` elements, each `size` bytes. Returns initialized to zero.

### String Length and Safe Copy
- `ft_strlen(const char *s)` — Returns the length of string `s` (excluding the terminating null byte).
- `ft_strlcpy(char *dst, const char *src, size_t dstsize)` — Copies at most `dstsize - 1` bytes from `src` to `dst`, null-terminating the result. Returns the length of `src`.
- `ft_strlcat(char *dst, const char *src, size_t dstsize)` — Appends `src` to `dst`, ensuring the result fits in `dstsize` bytes (including null terminator). Returns the total length of the resulting string.

### String Search
- `ft_strchr(const char *s, int c)` — Returns a pointer to the first occurrence of character `c` in string `s`, or `NULL` if not found.
- `ft_strrchr(const char *s, int c)` — Returns a pointer to the last occurrence of character `c` in string `s`, or `NULL` if not found.
- `ft_strncmp(const char *s1, const char *s2, size_t n)` — Compares at most `n` characters of `s1` and `s2`. Returns negative if `s1 < s2`, zero if equal, positive if `s1 > s2`.
- `ft_strnstr(const char *haystack, const char *needle, size_t len)` — Locates substring `needle` within the first `len` bytes of `haystack`. Returns a pointer to the start of the match or `NULL`.

### String Duplication and Conversion
- `ft_strdup(const char *s1)` — Allocates and returns a copy of string `s1`. The caller is responsible for freeing the returned pointer.
- `ft_atoi(const char *str)` — Converts a string to an integer, skipping leading whitespace and optional sign.
- `ft_itoa(int n)` — Allocates and returns a string representation of integer `n`. The caller must free the result.

### String Manipulation and Splitting
- `ft_substr(char const *s, unsigned int start, size_t len)` — Allocates and returns a substring of `s` starting at index `start` with maximum length `len`.
- `ft_strjoin(char const *s1, char const *s2)` — Allocates and returns a new string that is the concatenation of `s1` and `s2`.
- `ft_strtrim(char const *s1, char const *set)` — Allocates and returns a copy of `s1` with leading and trailing characters found in `set` removed.
- `ft_split(char const *s, char c)` — Allocates and returns an array of strings obtained by splitting `s` using the delimiter `c`. The array is null-terminated.

### String Iteration and Mapping
- `ft_striteri(char *s, void (*f)(unsigned int, char*))` — Applies function `f` to each character in string `s`, passing the index and character pointer.
- `ft_strmapi(char const *s, char (*f)(unsigned int, char))` — Allocates and returns a new string where each character is the result of applying function `f` to the corresponding character in `s`.

### File Descriptor Output
- `ft_putchar_fd(char c, int fd)` — Writes the character `c` to file descriptor `fd`.
- `ft_putstr_fd(char *s, int fd)` — Writes string `s` to file descriptor `fd` (without newline).
- `ft_putendl_fd(char *s, int fd)` — Writes string `s` to file descriptor `fd` followed by a newline.
- `ft_putnbr_fd(int n, int fd)` — Writes the integer `n` to file descriptor `fd`.

### Linked List Manipulation
- `ft_lstnew(void *content)` — Creates a new list node with content `content` and sets `next` to `NULL`.
- `ft_lstadd_front(t_list **lst, t_list *new)` — Inserts node `new` at the beginning of list `lst`.
- `ft_lstsize(t_list *lst)` — Returns the number of nodes in list `lst`.
- `ft_lstlast(t_list *lst)` — Returns a pointer to the last node of list `lst`.
- `ft_lstadd_back(t_list **lst, t_list *new)` — Inserts node `new` at the end of list `lst`. Returns the total count of nodes.
- `ft_lstdelone(t_list *lst, void (*del)(void*))` — Frees node `lst`; calls function `del` on the node's content before freeing.
- `ft_lstclear(t_list **lst, void (*del)(void*))` — Frees all nodes in list `lst` and its contents (using `del`), then sets `lst` to `NULL`.
- `ft_lstiter(t_list *lst, void (*f)(void *))` — Applies function `f` to the content of each node in list `lst`.
- `ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` — Creates a new list where each node's content is the result of applying function `f` to the nodes of `lst`. Uses `del` to free content on failure.

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
