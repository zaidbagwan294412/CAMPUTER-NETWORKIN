
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    char buff[512], str1[512];
    int SocketFD, connectFD, len, i, k;
    struct sockaddr_in stSockAddr, cli_addr;
    socklen_t a;

    SocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (SocketFD < 0)
    {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(stSockAddr));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(1504);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(SocketFD, (struct sockaddr *)&stSockAddr,
             sizeof(stSockAddr)) < 0)
    {
        perror("Cannot bind");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    listen(SocketFD, 2);

    printf("Server waiting for client...\n");

    a = sizeof(cli_addr);

    connectFD = accept(SocketFD,
                       (struct sockaddr *)&cli_addr, &a);

    if (connectFD < 0)
    {
        perror("Cannot accept connection");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    memset(buff, 0, sizeof(buff));

    read(connectFD, buff, sizeof(buff) - 1);

    printf("\nReceived String: %s", buff);

    len = strlen(buff);

    for (i = len - 1, k = 0; i >= 0; i--, k++)
    {
        str1[k] = buff[i];
    }

    str1[k] = '\0';

    printf("\nReversed String: %s\n", str1);

    write(connectFD, str1, strlen(str1) + 1);

    close(connectFD);
    close(SocketFD);

    return 0;
}
