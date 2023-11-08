/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:22:43 by vharatyk          #+#    #+#             */
/*   Updated: 2023/11/08 10:59:22 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NETXT_LINE_H
# define GET_NETXT_LINE_H

typedef struct s_liste
{
	char	*content ;
	struct	s_liste *next;
}t_liste;


#define BEFFER_SIZE 5

#endif
