
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
    char buff[512];
    int SocketFD;
    struct sockaddr_in stSockAddr;

    SocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if (SocketFD < 0)
    {
        perror("Cannot create socket");
        exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(stSockAddr));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(1504);
    stSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(SocketFD, (struct sockaddr *)&stSockAddr,
                sizeof(stSockAddr)) < 0)
    {
        perror("Cannot connect");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    printf("\nEnter String to be sent: ");

    fgets(buff, sizeof(buff), stdin);

    buff[strcspn(buff, "\n")] = '\0';

    write(SocketFD, buff, strlen(buff) + 1);

    memset(buff, 0, sizeof(buff));

    read(SocketFD, buff, sizeof(buff) - 1);

    printf("\nReversed String = %s\n", buff);

    close(SocketFD);

    return 0;
}
