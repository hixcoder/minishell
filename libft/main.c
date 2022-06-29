/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:08:12 by hboumahd          #+#    #+#             */
/*   Updated: 2021/11/13 17:03:34 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


  /*****************************************************************\
 /~~~~~~~~~~~~~~~~~~~~~~\                        /~~~~~~~~~~~~~~~~~~~\
/~~~~~~~~~~~~~~~~~~~~~~~~\       Libc fun       /~~~~~~~~~~~~~~~~~~~~~\
(__/\__/\__/\____/\__/\__/\____________________/\____/\__/\__/\__/\___/\)
*/



// ft_isalpha.c
/*
int main()
{
	char c;
	
	c = '9';
	// return 1 if alpha && 0 if not alpha 
	printf("ft_alpha(%c)= %d\n", c, ft_isalpha(c));
	printf("isalpha(%c)= %d\n", c, isalpha(c));
}
*/

// ft_isdigit.c
/*
int main()
{
	char c;
	
	c = 'f';
	// return 1 if digit && 0 if not digit 
	printf("ft_digit(%c)= %d\n", c, ft_isdigit(c));
	printf("isdigit(%c)= %d\n", c, isdigit(c));
}
*/

// ft_isalnum.c
/*
int main()
{
	char c;
	
	c = '}';
	// return 1 if alphanumeric && 0 if not alphanumeric 
	printf("ft_isalnum(%c)= %d\n", c, ft_isalnum(c));
	printf("isalnum(%c)= %d\n", c, isalnum(c));
}
*/

// ft_isascii.c
/*
int main()
{
	char c;
	
	c = '8';
	// (man isascii ;) octal 0177 ==> decimal 127
	// return 1 if (0 <= c <= 127) && 0 if not  
	printf("ft_isascii(%c)= %d\n", c, ft_isascii(c));
	printf("isascii(%c)= %d\n", c, isascii(c));
}
*/

// ft_isprint.c
/*
int main()
{
	char c;
	
	c = '8';
	// return 1 if (32 <= c <= 127) && 0 if not  
	printf("ft_isprint(%c)= %d\n", c, ft_isprint(c));
	printf("isprint(%c)= %d\n", c, isprint(c));
}
*/

// ft_strlen.c
/*
int main()
{
	const char *s = NULL;
	printf("ft_strlen(\"%s\") = %lu\n", s,ft_strlen(s));
	printf("strlen(\"%s\") = %lu\n", s,strlen(s));
}
*/

//ft_memset.c
/*
int main(void)
{
	char s[50] = "hello man";
	char s2[50] = "12345hello man";
	char c = '+';
	int len = 5;
	

    printf("ft_memset('s',%c,%d) = ",c,len);
	ft_memset(s, c,len * sizeof(char));
	printf("%s\n", s);
    
    printf("memset('s2',%c,%d) = ",c,len);
	memset(s2, c,len * sizeof(char));
	printf("%s\n", s2);
    return 0;
}
*/

// ft_bzero.c
/*
int main(void)
{
	char s1[6] = "hello";
	char s2[6] = "hello";
	int n = 0;

	printf("ft_bzero(\"%s\", %d) = ",s1 ,n);
	ft_bzero(s1, n * sizeof(char));
	printf("\"%s\"\n", s1);

	printf("bzero(\"%s\", %d) = ",s2 ,n);
	bzero(s2, n * sizeof(char));
	printf("\"%s\"\n", s2);
    return 0;
}
*/

// ft_memcpy.c
/*
int main(void)
{
	char *s = NULL;
	char dst1[50] = "sdsd";
	char dst2[50] = "sdsd";
	
	ft_memcpy(dst1, s, 5 * sizeof(char));
	printf("%s\n",dst1);
	
	memcpy(dst2, s, 5 * sizeof(char));
	printf("%s\n",dst2);
	return (0);
}
*/

// ft_memmove.c
/*
int main(void)
{
	char s[50] = "hello world";
	char s2[50] = "hello world";
	
	// if pdst > psrc (when dst comes after src with overlap)
	printf("ft_memmove(s,s+5, 3) = %s\n",ft_memmove(s, s+5, 3*sizeof(char)));
	printf("memmove(s,s+5, 3) = %s\n",memmove(s2, s2+5, 3*sizeof(char)));
	
	return (0);
}
*/


// ft_strlcpy.c
/*
int main()
{
	char s[6] = "hello";
	char dst1[6];
	char dst2[6];

	printf("%zu ==> %s\n", ft_strlcpy(dst1, s, 6), dst1);
	printf("%zu ==> %s\n", strlcpy(dst2, s, 6), dst2);	
}
*/

// ft_strlcat.c
/*
 *>> Return Value:
	The length of the string that strlcat tried to create is returned, whether or not strlcat could store it in dest. If all of src was concatenated to dst, the return value will be less than size.

If dest is not nul-terminated, then strlcat will consider dest to be size in length and return size plus the length of src.
*
*
int main()
{
	char s[6] = "hello";
	char dst1[9] = "hi 12345";
	char dst2[9] = "hi 12345";

	int dstsize = 5;

	printf("%zu ==> %s\n", ft_strlcat(dst1, s, dstsize), dst1);
	printf("%zu ==> %s\n", strlcat(dst2, s, dstsize), dst2);	
}
*/

//ft_strchr.c
/*
int main(void)
{
	char c = '8';
	char s[] = "I'm looking for 8 in this string";
	//char *s = NULL;

	printf("ft_strchr ==> %s\n", ft_strchr(s,c));
	printf("strchr ==> %s\n", strchr(s,c));
}
*/

// ft_strrchr.c
/*
int main(void)
{
	char s[] = "I'm looking for the last f in this string | ffff is here";
	char *s2 = NULL;
	printf("%s\n",ft_strrchr(s2,'t'));
	printf("%s\n",strrchr(s2,'t'));
}
*/

// ft_strncmp.c
/*
int main(void)
{
	//char s1[] = "compare s1";
	//char s2[] = "compare s2";
	char	*s1 = "1235";
	char	*s2 = "1234";
	printf("%d\n",ft_strncmp(s1,s2,5));
	printf("%d\n",strncmp(s1,s2,5));
	return (0);
}
*/

// ft_memchr.c
/*
int main(void)
{
	char a[] = "I'm looking for h in this string";
	//char *a = NULL;
	printf("%s\n",ft_memchr(a,'h',19));
	printf("%s\n",memchr(a,'h',19));
}
*/

// ft_memcmp.c 
/*
int main(void)
{
	//char a[] = "abc";
	//char b[] = "abd";
	
	char *a = NULL;
	char *b = NULL;
	
	printf("%d\n",ft_memcmp(a,b,5));
	printf("%d\n",memcmp(a,b,5));
	return (0);
}
*/

// ft_strnstr.c
/*
int main()
{
    //char haystack[100] = "hello man how are jiji can't hide from me";
    //char needle[10] = "jili";
    char haystack[10] = "hello";
	char *needle = "";
	printf("ft_strnstr = %s\n", ft_strnstr(haystack,needle,8));
	printf("strnstr = %s\n", strnstr(haystack,needle,8));
    return 0;
}
*/

// ft_atoi.c
/*
int main (void)
{
	char	s[100] = "9999";
	int		i1 = ft_atoi(s);	
	int		i2 = atoi(s);
	printf("%d\n",i1);
	printf("%d\n",i2);
}
*/

//ft_calloc.c
/*
int main()
{
	int size = 852;
	char *s1 = ft_calloc(size, sizeof(char));
	char *s2 = calloc(size, sizeof(char));
	printf("%s\n", s1);
	printf("%s\n", s2);
}
*/

// ft_strdup.c
/*
int main(void)
{
	const char s[89] = "im trying here hh";
	//const char *s = NULL; 
	
	printf("%s\n",  ft_strdup(s));
	printf("%s\n",  strdup(s));
	return (0);
}
*/

  /*****************************************************************\
 /~~~~~~~~~~~~~~~~~~~~~~\                        /~~~~~~~~~~~~~~~~~~~\
/~~~~~~~~~~~~~~~~~~~~~~~~\     Additional fun   /~~~~~~~~~~~~~~~~~~~~~\
(__/\__/\__/\____/\__/\__/\____________________/\____/\__/\__/\__/\___/\)
*/




// ft_substr.c
/*
int main(void)
{
    char s[] = "take 6chars from the string s";
    char *dst = ft_substr(s,5,6);
    printf("%s\n", dst);
}
*/

// ft_strjoin.c
/*
int main(void)
{
	char s1[] = "hello man ";
	char s2[] = "how are you?";
	char *dst;

	dst = ft_strjoin(s1,s2);
    printf("result: %s\n",dst);
}
*/

//ft_strtrim.c
/*
 * we use this to return an empty string in case we have a string that contain only
 * things that need to be trimed (ex: s ="*++*-+-*-+-" && set = "+-*").
 * why? the test 1 show me the error && (i guess the allocation will fail? ...). 
 *
 * if (inds >= inde)
		return (ft_strdup(""));
 */
 /*
int main(void)
{
	char s[] = "**#$#$***#$#$#$***";
	char set[] = "&#$*";

	printf("%s\n", ft_strtrim(s,set));
}
*/


//ft_split.c
/*
int main(void)
{
	char s[]= "Tripouille ";
	char c = ' ';

	char **arr = ft_split(s,c);
    for (int i = 0;i < 2;i++)
         printf("%s\n", arr[i]);
}
*/

//ft_itoi.c
/*
 * we use this to count the mines(-) in the len
 * if (n < 0)
       len++;
 *
int main(void)
{
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(555));
	printf("%s\n",ft_itoa(-5845));
	printf("%s\n",ft_itoa(9));
	printf("%s\n",ft_itoa(INT_MIN));
	printf("%s\n",ft_itoa(INT_MAX));
}
*/

//ft_strmapi.c
/*
char    f(unsigned int i, char a)
{
	// i dont know when we can use the index i since we dont have a string to index.
    char c;
    c = a - 1;
    return (c);
}

 int main(void)
{
	char s[]= "bcdef";

	char *dst = ft_strmapi(s, f);
    printf("after Applies the function ’f’ to each character of the string ’s’ ==> %s\n",dst);
}
*/

//ft_striteri.c
/*
 void    f(unsigned int i, char *a)
{
     *a = *a + 1;
}

int main(void)
{
	char s[] = "abcde";
    printf("%s ===> ",s);
    ft_striteri(s, f);
    printf("%s\n",s);
}
*/

  /*****************************************************************\
 /~~~~~~~~~~~~~~~~~~~~~~\                    /~~~~~~~~~~~~~~~~~~~~~~~\
/~~~~~~~~~~~~~~~~~~~~~~~~\     Bonus part   /~~~~~~~~~~~~~~~~~~~~~~~~~\
\___()__/\__/\____/\__/\__/\_______________/\__/\____/\__/\__/\__()___/
*/


//ft_lstnew.c
/*
void printlist(t_list *node)
{
	while (node != NULL)
	{
		printf("%s\n", node->content);
		node = node -> next;
	}
}

int main(void)
{
	t_list *head,*n1,*n2,*n3;

	head = ft_lstnew("hello");
	n1 = ft_lstnew("hi 1");
	n2 = ft_lstnew("hey 2");
	n3 = ft_lstnew("salam 3");

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	printlist(head);
}
*/

// ft_lstadd_front.c
/*
void printlist(t_list *node)
{
	while (node != NULL)
	{
		printf("%s\n", node->content);
		node = node -> next;
	}
}

int main(void)
{
	t_list *head,*n1,*n2,*n3;
	t_list **lst;

	head = ft_lstnew("hello");
	n1 = ft_lstnew("hi 1");
	n2 = ft_lstnew("hey 2");
	n3 = ft_lstnew("salam 3");

	head->next = n1;
	n1->next = n2;
	n2->next = NULL;

	lst = &head;
	ft_lstadd_front(lst, n3);

	printlist(head);
}
*/

// ft_lstsize.c
/*
int main(void)
{
	t_list	*head,*n1,*n2,*n3;
	int		size;

	head = ft_lstnew("hello");
	n1 = ft_lstnew("hi 1");
	n2 = ft_lstnew("hey 2");
	n3 = ft_lstnew("salam 3");

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	size = ft_lstsize(head);
	printf("%d\n", size);
}
*/

// ft_lstlast.c
/*
int main(void)
{
	t_list	*head,*n1,*n2,*n3;
	t_list	*last;

	head = ft_lstnew("hello");
	n1 = ft_lstnew("hi 1");
	n2 = ft_lstnew("hey 2");
	n3 = ft_lstnew("salam 3");

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;

	last = ft_lstlast(head);
	printf("%s\n", last->content);
}
*/
// ft_lstadd_back;
/*
void printlist(t_list *node)
{
	while (node != NULL)
	{
		printf("%s\n", node->content);
		node = node -> next;
	}
}

int main(void)
{
	t_list	*head,*n1,*n2,*n3,*n4;
	t_list	**lst;

	head = ft_lstnew("head");
	n1 = ft_lstnew("hey1");
	n2 = ft_lstnew("hey2");
	n3 = ft_lstnew("hey BOTTOM");

	head->next = n1;
	n1->next = n2;
	n2->next = NULL;

	lst = &head;
	ft_lstadd_back(lst, n3);
	printlist(head);

}
*/

// ft_lstdelone.c
/*
void ft_del(void *content)
{
	memset(content, 'i', 3);
}

int main()
{
	t_list *head,*n1;

	head = (t_list *)malloc(sizeof(t_list));
	n1 = (t_list *)malloc(sizeof(t_list));
	head -> content = "hello";
	head -> next = n1;
	n1 -> content = "hey 1";
	n1 -> next = NULL;

	printf("%s\n", head->content);
	ft_lstdelone(head, &ft_del);
	printf("%s\n", head->content);
}
*/
