#include <stdio.h>
#include <stdlib.h>
#include "message.h"
#include <string.h>
#include <sys/socket.h>

#define LG_MAX 1000

void RemplirMessage(t_message *Bmessage, char *message){
    Bmessage->lg_message = strlen(message);
    if (Bmessage->lg_message > LG_MAX) {
        fprintf(stderr, "Erreur : le message dépasse la longueur maximale.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(Bmessage->message, message);
}

void EnvoyerMessage(t_message *Bmessage, int socket){

    // Envoi de la longueur du message
    if (send(socket, Bmessage, sizeof(t_message), 0) == -1) {
        perror("Erreur lors de l'envoi de la longueur du message.");
        exit(EXIT_FAILURE);
    }
}

void RecevoirMessage(t_message *Bmessage, int socket){
    // Réception de la longueur du message
    if (recv(socket, Bmessage, sizeof(t_message), 0) == -1) {
        perror("Erreur lors de la réception de la longueur du message.");
        exit(EXIT_FAILURE);
    }
}

void AfficherMessage(t_message Bmessage){
    printf("Message : %s\n", Bmessage.message);
    printf("Longueur du message : %d\n", Bmessage.lg_message);
}