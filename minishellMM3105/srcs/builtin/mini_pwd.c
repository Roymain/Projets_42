/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <mathmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:39:54 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/30 17:39:54 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_builtin.h"

void	builtin_pwd(void)
{
	char	path[4096];

	printf("%s\n", getcwd(path, 4096));
}
