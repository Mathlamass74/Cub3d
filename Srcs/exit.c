/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlepesqu <mlepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:35:57 by mlepesqu          #+#    #+#             */
/*   Updated: 2024/07/11 10:46:43 by mlepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	exit_game(int option)
{
	if (option == 0)
		printf("Error\nFile not found\n");
	else if (option == 1)
		printf("Error\nFile malloc failed\n");
	else if (option == 2)
		printf("Error\nMap malloc failed\n");
	else if (option == 3)
		printf("Error\nMap must be surrounded by walls!\n");
	else if (option == 4)
		printf("Error\nInitialization failed!\n");
	else if (option == 5)
		printf("Error\nToo mutch players in map!\n");
	else if (option == 6)
		printf("Error\nInvalid char in map!\n");
	else if (option == 7)
		printf("Error\nMust have at least 1 player in map!\n");
	else if (option == 8)
		printf("Error\nTexture not loaded!\n");
	return (0);
}
