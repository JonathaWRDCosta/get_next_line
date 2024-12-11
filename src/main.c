/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:32 by jonathro          #+#    #+#             */
/*   Updated: 2024/12/11 10:55:56 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define FILE_1 "src/test.txt"

int main() {
    int fd1;
    char *line;

    fd1 = open(FILE_1, O_RDONLY);
    if (fd1 == -1) {
        perror("Failed to open file 1");
        return (1);
    }

    printf("Reading from %s:\n", FILE_1);
    while ((line = get_next_line(fd1)) != NULL) {
        printf("%s", line);
        free(line);
        usleep(100000);
    }

    close(fd1);
    return 0;
}