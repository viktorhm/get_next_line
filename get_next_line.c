/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:11:56 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/09 12:50:45 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include"get_next_line.h"

void readed_line(int nb_read , int fd ,char liste );
int find_new_line(char *buf);


char *get_next_line(int fd)
	{
	static char *liste ;
	char line ;
	int nb_read;


	if (fd < 0 || 0 > read(fd , 0 , 0))
		return NULL;

	readed_line(nb_read , fd , liste );

	}

void readed_line(int nb_read , int fd ,char liste )
	{
	char *buf ;

	buf = malloc(sizeof(char)* BEFFER_SIZE);
	if(buf == NULL)
		return 0;
	while(find_newline(buf))
		{
		read(fd , buf , BEFFER_SIZE);
		}
	}

int find_new_line(char *buf)
	{
		int i = 0 ;
		if(buf == NULL)
			return 1 ;

		while(buf)
		{
		if(buf[i] == '/n')
		{
			i++;
			reuturn(buf);
		}
		}
	}

int main(void)
{
	char *line = NULL ;
	int fd = 0 ;
	fd = open("test.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			return 0 ;
		printf("%s" ,line);
		free(line) ;
	}
return 0;
}
