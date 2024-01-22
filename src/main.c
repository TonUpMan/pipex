/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:50:22 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/22 10:50:26 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    int pid;
    int fdchild;
    int fdparent;

    pid = fork();
    if (pid == 0)
    {
        fdchild = open(argv[1], O_RDONLY); //open  file1
        execve(argv[2]); // exec cmd 1
    }
    else
    {
        wait(0); // parent wait child end

    }
    if (pid == 0)
    {
        dup2(fdchild, pipe(fd[0])); // enter pipe 
        close(fdchild);
    }
    else
    {
        dup2(pipe(fd[1]), fdparent); // end pipe
        close(pipe(fd[1])); 
        execve(argv[3]) //exec cmd 2
        //write in file 2
    }
}
