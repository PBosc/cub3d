/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:59:33 by ybelatar          #+#    #+#             */
/*   Updated: 2024/01/26 19:06:01 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


/*tu peux ajouter des arguments pour faire en sorte que ca free la mlx par exemple*/
void panic(char *message)
{
    ft_dprintf(2, "Error\n%s", message);
    gc(NULL, 0);
    exit(1);
}
