/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:16:53 by ejanssen          #+#    #+#             */
/*   Updated: 2022/11/08 17:23:06 by ejanssen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

/// @brief check if char is alphanum
/// @param c
/// @return
int		ft_isalpha(int c);

/// @brief check if char is digit number
/// @param c
/// @return
int		ft_isdigit(int c);

/// @brief check if char is alphanumeric
/// @param c
/// @return
int		ft_isalnum(int c);

/// @brief check if char is ascii char
/// @param c
/// @return
int		ft_isascii(int c);

/// @brief check if char is printable
/// @param c
/// @return
int		ft_isprint(int c);

/// @brief calculate length of char
/// @param c
/// @return
size_t	ft_strlen(const char *c);

/// @brief fill a bte string with a byte value
/// @param b
/// @param c
/// @param len
void	*ft_memset(void *s, int c, size_t n);

/// @brief copy memory area
/// @param dst
/// @param src
/// @param n
/// @return
void	*ft_memcpy(void *dst, const void *src, size_t n);

/// @brief copy byte string
/// @param dst
/// @param src
/// @param len
/// @return
void	*ft_memmove(void *dst, const void *src, size_t len);

/// @brief write zeroes to a byte string
/// @param s
/// @param n
void	ft_bzero(void *s, size_t n);

/// @brief size bounded string copying and concatenation
/// @param dst
/// @param src
/// @param dstsize
/// @return
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/// @brief size bounded string copying and concatenation
/// @param dst
/// @param src
/// @param dstsize
/// @return
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/// @brief lower case to upper case letter conversion
/// @param c
/// @return
int		ft_toupper(int c);

/// @brief upper case to lower case letter conversion
/// @param c
/// @return
int		ft_tolower(int c);

/// @brief locate character in string
/// @param s
/// @param c
/// @return
char	*ft_strchr(const char *s, int c);

/// @brief locate character in string
/// @param s
/// @param c
/// @return
char	*ft_strrchr(const char *s, int c);

/// @brief compare strings
/// @param s1
/// @param s2
/// @param n
/// @return
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/// @brief locate byte in byte string
/// @param s
/// @param c
/// @param n
/// @return
void	*ft_memchr(const void *s, int c, size_t n);

/// @brief compare byte string
/// @param s1
/// @param s2
/// @param n
/// @return
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/// @brief locate a substring in a string
/// @param haystack
/// @param needle
/// @param len
/// @return
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/// @brief convert ASCII string to integer
/// @param str
/// @return
int		ft_atoi(const char *str);

/// @brief memory allocation
/// @param count
/// @param size
/// @return
void	*ft_calloc(size_t count, size_t size);

/// @brief save a copy of a string
/// @param s1
/// @return
char	*ft_strdup(const char *s1);

/// @brief Allocates and returns a substring from the string 's'
/// @param s
/// @param start
/// @param len
/// @return substring NULL if allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len);

/// @brief Allocates and returns a new string wich is the result of
/// of the concatenation of s1 and s2
/// @param s1
/// @param s2
/// @return new string NULL if the allocation fails
char	*ft_strjoin(char const *s1, char const *s2);

/// @brief Allocates and returns a copy of s1 with characters specified in set
/// removed from the beginning and end of the string
/// @param s1
/// @param set
/// @return the trimmed string NULL if the allocation fails
char	*ft_strtrim(char const *s1, char const *set);

/// @brief Allocates and returns an array of string split by s and by NULL
/// @param s
/// @param c
/// @return the array of new strings resulting from the split
/// NULL if the allocation fails
char	**ft_split(char const *s, char c);

/// @brief Allocates and returns a string representing
/// the integer(negatives includeds)
/// @param n
/// @return the string representing the integer, NULL if allocation fails
char	*ft_itoa(int n);

/// @brief Applies function f to each char of s, passing index as first argument
/// to create new string with malloc
/// @param s
/// @param f
/// @return string created of successive application of f
/// NULL  if allocation fails
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/// @brief Applies function f to each char of s char of f passed
/// by address
/// @param s
/// @param f
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/// @brief output c to given fd
/// @param c
/// @param fd
void	ft_putchar_fd(char c, int fd);

/// @brief output s to given fd
/// @param s
/// @param fd
void	ft_putstr_fd(char *s, int fd);

/// @brief outputs a string followed by a new line to the given fd
/// @param s
/// @param fd
void	ft_putendl_fd(char *s, int fd);

/// @brief outputs a given integer to the given fd
/// @param n
/// @param fd
void	ft_putnbr_fd(int n, int fd);

/// @brief Calculates the power of a certain number
/// @param nb
/// @param power
/// @return
long	ft_pow(long nb, int power);

/// @brief linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

/// @brief Allocates and return new node, the member variable content
/// is initialized with the value aprameter content, the variable next
/// is initialized to NULL
/// @param content
/// @return new node
t_list	*ft_lstnew(void *content);

/// @brief Adds the node  new at the beginning of the list
/// @param lst
/// @param new
void	ft_lstadd_front(t_list **lst, t_list *n);

/// @brief Counts the number of nodes in the list
/// @param lst
int		ft_lstsize(t_list *lst);

/// @brief Returns the last node of the list
/// @param lst
/// @return last node of the list
t_list	*ft_lstlast(t_list *lst);

/// @brief add the new node to the back of the list
/// @param lst
/// @param  new
void	ft_lstadd_back(t_list **lst, t_list *n);

/// @brief takes as a parameter a node and frees the memory of the nodes
/// content using the function del given as a parameter and free the node
/// the memory of next must not be freed
/// @param lst
/// @param del
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/// @brief Deltes and frees the given node and every succesor of that node
/// the pointer to the list must be set to NULL
/// @param lst
/// @param del
void	ft_lstclear(t_list **lst, void (*del)(void *));

/// @brief Iterates the list lst and applies the function f on the content
/// of the node
/// @param lst
/// @param f
void	ft_lstiter(t_list *lst, void (*f)(void*));

/// @brief iterates the list lst and applies the function f on the content
/// of each node. Creates a newlist resulting of the successive application
/// of the function f. The  del function is used to delete the
/// content of a node if needed
/// @param lst address of a pointer to a node
/// @param f address to the function used to iterate on the list
/// @param del the address of the function used to delete
/// @return new list NULL if allocation fails
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif
