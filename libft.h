# ifndef libft_h
# define libft_h

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    void			*content;
    struct s_list	*next;
}					t_list;

typedef unsigned long size_t;

#endif