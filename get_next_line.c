/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktor <viktor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:11:56 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/10 01:20:35 by viktor           ###   ########.fr       */
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
	static char *liste;
	char *line;


	if(BUFFER_SIZE < 0 || fd < 0 || read(fd , 0 , 0) < 0 )
		return(0);


	liste = read_line(fd , liste);
	if(!line)
		return(NULL);
	line = get_line(liste); //renvoie correctement la ligne
	liste = stay_str(liste); //retourne le reste dans la varialbe static


	//lire le fichier par rapport a la taille du buffer
	//revoiyer le tableau

	return(line);
	}

char *stay_str(char *liste)
{
int i = 0 ;
int j = 0 ;
char *remains;
	if(liste != NULL)
		return(NULL);
	while(liste[i] != '\n')
	{
		i++;
	}
	while(liste[i+j] != '\0')
	{
		j++;
	}
	remains = malloc(sizeof(char)*j);
	if(!remains)
		return(NULL);
	j = 0 ;
	while(liste[i] != '\0')

	{
		remains[j] = liste[i];
		i++; j++ ;
	}
	remains[j] = '\0';
	free(liste);
	return(remains);
}

char *get_line(char *liste)
{
	int i = 0;
	char *line;
	if(line == NULL)
		return(NULL);

	while(liste[i] != '\n' || liste[i] != '\0')
	{
	i++;
	}
	line = malloc(sizeof(char)*i);
	 i = 0 ;
	while(liste[i]!= '\n' || liste[i] != '\0')
	{
	line[i]=liste[i];
	i++ ;
	}
	if(liste[i] == '\n')
	{
	line[i]='\n';
	i++;
	}
	line[i]='\0';
	return(line);


}

char *read_line(int fd , char *liste )
{
	int nb_read;
	char *buf ;

	nb_read = 1 ;
	buf = malloc((BUFFER_SIZE + 1)*sizeof(char));
	if(!buf)
		return(NULL);

	while( seach_new_line(buf) && nb_read != 0)
	{
		//printf("%s",buf);
		nb_read = read(fd ,buf , BUFFER_SIZE); // lis la ligne stock dans la liste
		if(nb_read == -1) //+ verifier les eurreur
		{
			free(buf);
			return(NULL);
		}
	buf[nb_read] = '\0' ;
	liste = ft_strjoin(liste , buf ); //fuite de memoir possible
	}

	//printf("%s", liste);
	free(buf) ; //+ libere la memoire
	return(liste);
}

int  seach_new_line(char *liste )
{
	unsigned int	i;

	i = 0;
	while (liste[i] != '\0')
	{
		if (liste[i] == '\n')
		{
			//printf("d");
			return (0);
		}
		i++;
	}
	if ( '\n' == liste[i])
		return (0);
	return (1);
}

//??




// main

int main(void)
{
	char *line = NULL ;
	int fd = 0 ;
	fd = open("test", O_RDONLY);
	int i = 0;
	while(i != 5)
	{
		i++;
		line = get_next_line(fd);
		if(line == NULL)
			return 0 ;
		printf("%s" ,line);
		free(line) ;
	}
close(fd);
return 0;
}
