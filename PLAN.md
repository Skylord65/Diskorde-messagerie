## Specifications

### Langage

Le langage de programmation choisi est le C pour sa rapidité d'exécution et sa portabilité. Il permettra de développer un serveur et un client multi-plateformes.

### Architecture

ECB (Entity-Control-Boundary) semble être une architecture adaptée à notre projet. Elle permet de séparer les différentes parties de l'application de manière claire et efficace tout en permettant une portable et une évolutivité du code.

### Interface

L'interface utilisateur sera développée en GTK pour Linux et en Qt pour Windows. Une interface en TUI (Text User Interface) pourra être développée en option. Une electron-app pourrait être envisagée pour une version web et une version mobile.

### Protocole

Le protocole de communication sera basé sur des sockets TCP/IP. Il devra être sécurisé par un chiffrement robuste (RSA, Diffie-Hellman) et une authentification sécurisée (multi-facteurs, tokens).

## Liste des tâches

| Nom          | Libellé                                                                                             |
|--------------|-----------------------------------------------------------------------------------------------------|
|              | **Phase 0 : Préparation**                                                                           |
| Spec         | Analyse des spécifications et conception de l'architecture (ECB)                                    |
| Proto        | Définition du protocole de communication (formats, commandes, sécurité, échanges de clés)           |
| Planif       | Planification et répartition des tâches / choix des technologies (GTK, Qt, TUI)                     |
|              | **Phase 1 : Communication de base**                                                                 |
| Sockets      | Mise en place de la gestion des sockets (client/server)                                             |
| ChiffBase    | Intégration d'un chiffrement de base (RSA, certificats auto-signés)                                 |
| ClientCLI    | Développement d’un client en ligne de commande pour tests et débogage                               |
| MsgSimple    | Implémentation d’une gestion simple des messages (envoi/réception)                                  |
| Serveurs     | Création et gestion de serveurs                                                                     |
|              | **Phase 2 : Gestion des utilisateurs et des salons**                                                |
| Utilisateurs | Gestion des utilisateurs (inscription, création de compte, connexion, rôles)                        |
| Salons       | Gestion et catégorisation des salons (textuels, vocaux, vidéos)                                     |
| Contacts     | Gestion des connaissances (ajout, suppression, blocage, statuts : amis, collègue, etc.)             |
| Status       | Statuts personnalisés (en ligne, occupé, invisible, etc.)                                           |
| Profil       | Profil utilisateur avec avatar (pdp simple) et bio                                                  |
| Invits       | Gestion des invitations et des liens d’invitation                                                   |
| DM           | Messages privés                                                                                     |
|              | **Phase 3 : Gestion avancée des messages**                                                          |
| MsgMod       | Envoi et modification de messages                                                                   |
| MsgDel       | Suppression de messages (pour soi ou pour tous)                                                     |
| Reacts       | Réactions aux messages avec emojis                                                                  |
| Pinned       | Messages épinglés                                                                                   |
| Fichiers     | Envoi de fichiers et images                                                                         |
| MediaAff     | Lecture et affichage des vidéos, GIFs et images intégrées                                           |
| History      | Historique des messages et notifications                                                            |
| MsgSearch    | Recherche de messages (avancée, éventuellement regex)                                               |
|              | **Phase 4 : Sécurisation et intégrité des données**                                                 |
| ChiffRob     | Mise en place d’un chiffrement robuste (RSA, Diffie-Hellman)                                        |
| AuthSec      | Sécurisation de l’authentification (multi-facteurs, tokens)                                         |
| MsgSig       | Validation de l’intégrité des messages (signatures numériques)                                      |
| Report       | Signalement d’utilisateurs ou de messages                                                           |
| AuditLog     | Journaux d’audit pour les serveurs                                                                  |
|              | **Phase 5 : Interaction et automatisation**                                                         |
| MiniLang     | Développement d’un mini-langage de commandes (admin & modération, intégrant le système de mentions) |
| Markdown     | Implémentation d’un compilateur markdown pour affichage enrichi                                     |
| Notifs       | Gestion des notifications (messages, mentions, alertes)                                             |
| Logging      | Système de logging et débogage                                                                      |
| RolesAdv     | Gestion des rôles et permissions avancées                                                           |
| Threads      | Citations et fils de discussion (threads)                                                           |
| Polls        | Sondages et formulaires via bots                                                                    |
| API          | API                                                                                                 |
| Bots         | Bots et automatisation                                                                              |
| Plugins      | Plugins et intégrations tierces (YouTube, Twitch, Spotify, etc.)                                    |
|              | **Phase 6 : Communication en temps réel**                                                           |
| AVCall       | Appels vocaux et vidéo en groupe                                                                    |
| ScreenShare  | Partage d’écran                                                                                     |
| AudioOpt     | Suppression du bruit et réglage du gain automatique                                                 |
| TempSal      | Salons temporaires                                                                                  |
| ServerSearch | Recherche de serveurs publics                                                                       |
| Fav          | Système de favoris ou raccourcis vers des messages/serveurs                                         |
|              | **Phase 7 : Interfaces utilisateur**                                                                |
| GTK          | Conception de l’interface graphique avec GTK                                                        |
| Qt           | Portage/adaptation pour Qt (Windows)                                                                |
| TUI          | Développement d’une interface en TUI (optionnelle)                                                  |
| UIAdmin      | Intégration des contrôles d’administration et modération                                            |
| ElecApp      | Electron-app pour une version web et mobile                                                         |
|              | **Phase 8 : Finalisation et déploiement**                                                           |
| Tests        | Mise en place des tests unitaires et d’intégration                                                  |
| Docs         | Rédaction de la documentation technique et utilisateur                                              |
| Deploy       | Déploiement du serveur central et configuration                                                     |
| Monitor      | Système de monitoring et d’alertes                                                                  |
|              | **Phase SEC continue : Sécurité**                                                                   |
| Audit        | Audit de sécurité initial & revue des meilleures pratiques (open source)                            |
| SecAudit     | Audit de sécurité continu et revue du code                                                          |
| PatchSec     | Système de gestion et déploiement des mises à jour de sécurité                                      |
| 2FA          | Authentification à deux facteurs (2FA)                                                              |
| SecTests     | Tests de sécurité approfondis (pentests, vulnérabilités)                                            |

### Dépendances des tâches

```mermaid
flowchart-elk TD
subgraph P0["Phase 0 : Préparation"]
  T0_0(Spec)
  T0_1(Proto)
  T0_2(Planif)
end

subgraph P1["Phase 1 : Communication de base"]
  T1_0(Sockets)
  T1_1(ChiffBase)
  T1_2(ClientCLI)
  T1_3(MsgSimple)
  T1_4(Serveurs)
end

subgraph P2["Phase 2 : Gestion des utilisateurs et des salons"]
  T2_0(Utilisateurs)
  T2_1(Salons)
  T2_2(Contacts)
  T2_3(Status)
  T2_4(Profil)
  T2_5(Invits)
  T2_6(DM)
end

subgraph P3["Phase 3 : Gestion avancée des messages"]
  T3_0(MsgMod)
  T3_1(MsgDel)
  T3_2(Reacts)
  T3_3(Pinned)
  T3_4(Fichiers)
  T3_5(MediaAff)
  T3_6(History)
  T3_7(MsgSearch)
end

subgraph P4["Phase 4 : Sécurisation et intégrité des données"]
  T4_0(ChiffRob)
  T4_1(AuthSec)
  T4_2(MsgSig)
  T4_3(Report)
  T4_4(AuditLog)
end

subgraph P5["Phase 5 : Interaction et automatisation"]
  T5_0(MiniLang)
  T5_1(Markdown)
  T5_2(Notifs)
  T5_3(Logging)
  T5_4(RolesAdv)
  T5_5(Threads)
  T5_6(Polls)
  T5_7(API)
  T5_8(Bots)
  T5_9(Plugins)
end

subgraph P6["Phase 6 : Communication en temps réel"]
  T6_0(AVCall)
  T6_1(ScreenShare)
  T6_2(AudioOpt)
  T6_3(TempSal)
  T6_4(ServerSearch)
  T6_5(Fav)
end

subgraph P7["Phase 7 : Interfaces utilisateur"]
  T7_0(GTK)
  T7_1(Qt)
  T7_2(TUI)
  T7_3(UIAdmin)
  T7_4(ElecApp)
end

subgraph P8["Phase 8 : Finalisation et déploiement"]
  T8_0(Tests)
  T8_1(Docs)
  T8_2(Deploy)
  T8_3(Monitor)
end

subgraph SEC["Phase SEC continue : Sécurité"]
  SEC_0(Audit)
  SEC_1(SecAudit)
  SEC_2(PatchSec)
  SEC_3(2FA)
  SEC_4(SecTests)
end

T0_0 --> T0_1
T0_0 --> T0_2
T0_1 --> T1_0
T0_2 --> T1_0
T1_0 --> T1_1
T1_0 --> T1_2
T1_0 --> T1_3
T1_0 --> T1_4
T1_1 --> T4_0
T1_3 --> T3_0
T1_3 --> T3_6
T1_3 --> T4_2
T1_4 --> T2_1
T2_0 --> T2_2
T2_0 --> T2_4
T2_0 --> T2_5
T2_4 --> T2_2
T2_1 --> T2_6
T2_5 --> T2_6
T2_6 --> T3_0
T2_6 --> T3_1
T2_6 --> T3_2
T2_6 --> T3_3
T2_6 --> T3_4
T2_6 --> T3_5
T2_6 --> T3_6
T3_0 --> T3_1
T3_0 --> T3_2
T3_0 --> T3_3
T3_4 --> T3_5
T3_6 --> T3_7
T3_6 --> T5_2
T3_6 --> T5_5
T3_6 --> T6_5
T4_0 --> T4_2
T4_1 --> SEC_3
T4_2 --> T3_1
T4_2 --> T3_3
T4_2 --> T3_6
T4_3 --> T4_4
T5_0 --> T5_5
T5_1 --> T5_7
T5_2 --> T6_4
T5_2 --> T6_5
T5_4 --> T5_5
T5_7 --> T5_8
T5_7 --> T5_9
T6_0 --> T6_1
T6_0 --> T6_2
T6_3 --> T6_5
T7_0 --> T7_3
T7_1 --> T7_3
T7_2 --> T7_3
T8_0 --> T8_2
T8_0 --> T8_3
T8_1 --> T8_2
SEC_0 --> SEC_1
SEC_1 --> SEC_2
SEC_1 --> SEC_4
SEC_3 --> SEC_4
SEC --> P8
P6 --> P7
P7 --> P8
```