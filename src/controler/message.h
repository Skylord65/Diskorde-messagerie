#ifndef MESSAGE_H
#define MESSAGE_H

#define LG_MAX 1000

typedef struct s_message{
    int lg_message;
    char message[LG_MAX];
    t_User user_dest;
    t_User user_src;

}t_message;

typedef struct s_User{
    int socket;
    char pseudo[LG_MAX];
}t_User;

extern void RemplirMessage(t_message *Bmessage, char *message);

extern void AfficherMessage(t_message Bmessage);

extern void EnvoyerMessage(t_message *Bmessage, int socket);

extern void RecevoirMessage(t_message *Bmessage, int socket);

#endif