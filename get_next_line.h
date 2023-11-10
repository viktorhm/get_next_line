/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:22:43 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/10 10:55:45 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NETXT_LINE_H
# define GET_NETXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#include<unistd.h>
#include<stdlib.h>

char *get_line(char *liste);
char *stay_str(char *liste);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char *read_line(int fd , char *liste);
int  seach_new_line(char *liste );

#endif
