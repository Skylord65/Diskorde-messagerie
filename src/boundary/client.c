#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "message.h"

#define LG_MAX 1000


int main(int argc, char const *argv[]){
    t_message message_recu, message;

    RemplirMessage(&message, "message");

    if (argc!= 3){
        perror("Problème sur le nombre de paramètres.");
        return EXIT_FAILURE;
    }
    int sid;
    sid = socket(AF_INET, SOCK_STREAM, 0);
    if (sid==-1){
        perror("Erreur dans la création de socket.");
        return EXIT_FAILURE;
    }
    struct sockaddr_in dst_serv_addr;
    memset(&dst_serv_addr,0,sizeof(dst_serv_addr));
    dst_serv_addr.sin_family = AF_INET;
    dst_serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &dst_serv_addr.sin_addr);

    if (connect(sid, (struct sockaddr*) &dst_serv_addr, sizeof(dst_serv_addr))==-1){
        perror("Erreur lors de la connection.");
        close(sid);
        return EXIT_FAILURE;
    }

    pid_t pid=fork();

    switch (pid)
        {
        case -1:
            perror("Erreur de la création de fils receptioniste des messages.");
            return EXIT_FAILURE;
        case 0:
            do {
                RecevoirMessage(&message_recu, sid);
                if (message_recu.lg_message == 0) {
                    printf("Le serveur a fermé la connexion.\n");
                    close(sid);
                    exit(EXIT_FAILURE);
                }
                printf("(server) :");
                AfficherMessage(message_recu);
                
            } while (1);
            break;
        default:
            break;
        }

    do {
        /* code du buffer pour entrer le message (temporairement le message envoyé sera "0123456")*/

        EnvoyerMessage(&message, sid);

        printf("(client) :");
        AfficherMessage(message);
        
        
    } while (1);
    
    close(sid);

    return 0;
}

