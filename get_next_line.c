/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:11:56 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/09 16:39:09 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include"get_next_line.h"
#define BUFFER_SIZE 5

char *get_next_line(int fd)
	{
	if(BUFFER_SIZE < 0 )
		return("pb_file ");
	// 	return("FAIL");

	read_line(fd);
	//lire le fichier par rapport a la taille du buffer
	//revoiyer le tableau

	return(0);
	}

int read_line(int fd )
	{
	int nb_read = 0;
	char *buf = NULL;
	static char *liste = NULL;

	if(!(buf = malloc(sizeof(char)*BUFFER_SIZE)))
		return(0);


	//lire le buffer  , malloc
	while(seach_new_line(buf , liste))//nb_read != BUFFER_SIZE
		{
		nb_read = read(fd ,buf , BUFFER_SIZE); // lis la ligne stock dans la liste
		}
	}

int  seach_new_line(char *buf , char *liste )
	{
	liste = buf;
	char *t_liste;

	int i = 0 ;
	liste = ft_strjoin(buf , liste );
	printf("|--{%s}--|",t_liste);


	}

//??




// main

int main(void)
{
	char *line = NULL ;
	int fd = 0 ;
	fd = open("test", O_RDONLY);
	char *buf = NULL ;
	buf = malloc(4);
	read(fd, buf , 4);
	printf("%s", buf);
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			return 0 ;
		printf("%s" ,line);
		//free(line) ;
	}
return 0;
}
