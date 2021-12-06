#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

// Variables globales

char tempInputChar;
std::string pseudonymePlayerOne;
bool difficulty(false); // FALSE --> Difficulté normale | TRUE --> Difficulté experte
bool isPlayingFirst(true);


// ------------------


void send(const std::string& Message) {
    std::cout << Message << std::endl;
}

// Comparer les deux options de choix afin de vérifier la validité de l'entrée utilisateur

char inputComparaison(const std::string& Label, char _charFirstMaj, char _charFirstMin, char _charSecondMaj, char _charSecondMin) {
    char tempInput;
    do {
        send(Label);
        std::cin >> tempInput;
        if (tempInput != _charFirstMaj && tempInput != _charFirstMin && tempInput != _charSecondMaj && tempInput != _charSecondMin) {
            send("Saisie incorrecte !");
        }
    } while(tempInput != _charFirstMaj && tempInput != _charFirstMin && tempInput != _charSecondMaj && tempInput != _charSecondMin);
    return tempInput;
}

// ------------------

// Annonce le vainqueur.

void end(bool Winner) {
    if(Winner) {
        std::cout << "Tu as perdu " << pseudonymePlayerOne << std::endl;
    } else {
        std::cout << "Tu as gagne " << pseudonymePlayerOne << std::endl;
    }
}

// ------------------

// Informe l'utilisateur du nombre d'Allumettes

void sendProgress(unsigned int _nbAllumette)
{
    std::cout << "Il y a " << _nbAllumette << " allumettes." << std::endl;

    int dividedByFive = _nbAllumette / 5;
    int moduledByFive = _nbAllumette % 5;

    for (int cpt(0); cpt < moduledByFive; cpt++) {
        std::cout << "! ";
    }

    if(moduledByFive != 0) {
        send("");
    }

    for (int cpt(0); cpt < dividedByFive; cpt++) {
        std::cout << "! ! ! ! ! " << std::endl;
    }



}

// ------------------

// Programme d'une partie en difficulté Normale

void gameNormal(bool PlayingOrder, unsigned int _nbAllumette) {

    unsigned int tempInputJoueur;
    unsigned int tempInputBot;
    bool lastPlayed(false); // Si = true signifie que le joueur à perdu avant le robot.

    send("Le jeu commence !");
    sendProgress(_nbAllumette);
    send("");

    if(!PlayingOrder) {
        do {
            // Tour de l'utilisateur

            send("");
            send("Choisit une nombre entre 1 et 3 :");
            do{
                std::cin >> tempInputJoueur;
                if (tempInputJoueur > 4) {
                    send("Nombre invalide !");
                } else if (tempInputJoueur > _nbAllumette) {
                    send("Nombre invalide !");
                }
            } while(tempInputJoueur > 4 || tempInputJoueur > _nbAllumette);
            _nbAllumette -= tempInputJoueur;
            sendProgress(_nbAllumette);
            send("");

            // Tour du robot

            do {
                srand (time(NULL));
                tempInputBot = rand() % 3 + 1;
            } while(tempInputBot == 0);
            if(_nbAllumette == 0) {
                lastPlayed = true;
                break;
            } else {
                send("L'ordinateur joue : ");
                _nbAllumette -= tempInputBot;
                sendProgress(_nbAllumette);
                send("");
            }
        } while(_nbAllumette > 0);
    } else {
        do {

            // Tour du robot

            do {
                srand (time(NULL));
                tempInputBot = rand() % 3 + 1;
            } while(tempInputBot == 0);
            send("L'ordinateur joue : ");
            _nbAllumette -= tempInputBot;
            sendProgress(_nbAllumette);
            send("");

            // Tour de l'utilisateur

            if(_nbAllumette == 0) {
                lastPlayed = false;
                break;
            } else {
                send("");
                send("Choisi une nombre entre 1 et 3 :");
                do{
                    std::cin >> tempInputJoueur;
                    if (tempInputJoueur > 4) {
                        send("Nombre invalide !");
                    } else if (tempInputJoueur > _nbAllumette){
                        send("Nombre invalide !");
                    }
                } while(tempInputJoueur > 4 || tempInputJoueur > _nbAllumette);
                _nbAllumette -= tempInputJoueur;
                sendProgress(_nbAllumette);
                send("");
            }
        } while(_nbAllumette > 0);

        // Fin de la partie
        if(lastPlayed) {
            end(false);
        } else {
            end(true);
        }

    }
}

// ------------------

// Programme d'une partie en difficulté Experte

void gameExpert(bool PlayingOrder, unsigned int _nbAllumette) {
    unsigned int tempInputJoueur;
    unsigned int tempInputBot;
    bool lastPlayed(false); // Si = true signifie que le joueur à perdu avant le robot.

    send("Le jeu commence !");
    sendProgress(_nbAllumette);
    send("");
    send("");

    if(!PlayingOrder) {
        do {

            // Tour de l'utilisateur
            send("");
            send("Choisi une nombre entre 1 et 3 :");
            do{
                std::cin >> tempInputJoueur;
                if (tempInputJoueur > 4) {
                    send("Nombre invalide !");
                } else if (tempInputJoueur > _nbAllumette){
                    send("Nombre invalide !");
                }
            } while(tempInputJoueur > 4 || tempInputJoueur > _nbAllumette);
            _nbAllumette -= tempInputJoueur;
            sendProgress(_nbAllumette);
            send("");

            // Tour du robot

            for(int cpt(1); cpt < 4; cpt++) {
                if((_nbAllumette - cpt) % 4 == 1) {
                    tempInputBot = cpt;
                }
            }
            if(_nbAllumette == 0) {
                lastPlayed = true;
                break;
            } else {
                send("L'ordinateur joue : ");
                _nbAllumette -= tempInputBot;
                sendProgress(_nbAllumette);
                send("");
            }
        } while(_nbAllumette > 0);

        // Fin de la partie

    } else {

        do {
            // Tour du robot

            for(int cpt(1); cpt < 4; cpt++) {
                if((_nbAllumette - cpt) % 4 == 1) {
                    tempInputBot = cpt;
                }
            }
            send("L'ordinateur joue : ");
            _nbAllumette -= tempInputBot;
            sendProgress(_nbAllumette);
            send("");

            // Tour de l'utilisateur

            if(_nbAllumette == 0) {
                lastPlayed = false;
                break;
            } else {
                send("");
                send("Choisi une nombre entre 1 et 3 :");
                do{
                    std::cin >> tempInputJoueur;
                    if (tempInputJoueur > 4) {
                        send("Nombre invalide !");
                    } else if (tempInputJoueur > _nbAllumette){
                        send("Nombre invalide !");
                    }
                } while(tempInputJoueur > 4 || tempInputJoueur > _nbAllumette);
                _nbAllumette -= tempInputJoueur;
                sendProgress(_nbAllumette);
                send("");
            }
        } while(_nbAllumette > 0);
    }

    // Fin de la partie
    if(lastPlayed) {
        end(false);
    } else {
        end(true);
    }
}

// ------------------

// Initialise et importe tous les paramètres de la partie

void gameInit(const std::string& PseudoPlayerOne, bool Difficulty, bool PlayingOrder) {

    std::string menuLabelAllu("Choisissez un nombre d'allumettes (minimum 5, maximum 30) :");
    unsigned int nbAllumette;

    do {
        send(menuLabelAllu);
        std::cin >> nbAllumette;
        if (nbAllumette < 5 || nbAllumette > 30) {
            send("Veuillez choisir un nombre entre 5 et 30");
        }
    } while (nbAllumette < 5 || nbAllumette > 30);

    if (!Difficulty) {
        gameExpert(PlayingOrder, nbAllumette);
    } else {
        gameNormal(PlayingOrder, nbAllumette);
    }
}

// ------------------

// Initialise le menu principal

int main() {

    send("Version: 1.4");
    send("");

    std::string menuLabelA("Entrez un pseudonyme :");
    std::string menuLabelD("Voulez vous jouez en mode expert (E) ou normal (N)");
    std::string menulabelF("Voulez-vous jouer en premier ? (O/N)");
    std::string menuLabelH("Souhaitez-vous abandonnez ? (O/N)");
    std::string menuSuccess("OK!");
    // ------------------------------

    // Sauvegarde du pseudonyme saisie

    send(menuLabelA);
    std::cin >> pseudonymePlayerOne;
    send(menuSuccess);

    // Sauvegarde de la difficulté saisie

    tempInputChar = inputComparaison(menuLabelD, 'N', 'n', 'E', 'e');
    if (tempInputChar != 'N' && tempInputChar != 'n') {
        difficulty = false;
    } else {
        difficulty = true;
    }
    send(menuSuccess);

    // ----------------------------------

    // Sauvegarde de l'ordre de passage des joueurs

    tempInputChar = inputComparaison(menulabelF, 'O', 'o', 'N', 'n');
    if (tempInputChar != 'O' && tempInputChar != 'o') {
        isPlayingFirst = true;
    } else {
        isPlayingFirst = false;
    }
    send(menuSuccess);

    // ----------------------------------

    gameInit(pseudonymePlayerOne, difficulty, isPlayingFirst);
}

// ------------------
