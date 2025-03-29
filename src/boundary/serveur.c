#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "message.h"

int main(void)
{
    int sid;

    sid = socket(AF_INET, SOCK_STREAM, 0);
    if (sid==-1){
        perror("Erreur dans la création de socket.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in cli_addr;
    socklen_t cli_addr_len = sizeof(cli_addr);

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5555);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sid, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1){
        perror("Erreur dans le bind.");
        close(sid);
        return EXIT_FAILURE;
    }

    if(listen(sid, 15)==-1){
        perror("Erreur dans le lancement de l'écoute de connexions.");
        close(sid);
        return EXIT_FAILURE;
    }
    printf("Serveur en attente de connexions...\n");
    while (1)
    {
        int client_sock = accept(sid, (struct sockaddr *)&cli_addr,&cli_addr_len);
        if (client_sock<0){
            perror("Erreur dans l'accord de connexion");
            close(client_sock);
            return EXIT_FAILURE;
        }
        printf("Connexion acceptée.\n");

        if (client_sock>0 && fork()==0){
            while (1)
            {
                t_message message;

                RecevoirMessage(&message, client_sock);
                printf("(client) :");
                AfficherMessage(message);
                RemplirMessage(&message, "bien reçu");
                printf("(server) :");
                EnvoyerMessage(&message, client_sock);
            }
            
        }
    }
    
    return 0;
}
