//
// Created by Benjamin Celereau on 23/04/2020.
//

#include <sstream>
#include "console.h"

bool isNumber(string chaine)
{
    for (int i = 0; i < chaine.length(); i++)
        if (isdigit(chaine[i]) == false)
            return false;
    return true;
}

Console::Console(){
    cout << "Ouverture de la console" << endl;
    cout << "La mediatheque est vide" << endl << endl;
}

Console::Console(string filename) {
    cout << "Ouverture de la console" << endl;
    cout << "Chargement depuis le fichier " << filename << endl << endl;
    load(filename);
    clear();
}

Console::~Console(){
    reset();
}

void Console::add(string type, vector<string> data){
    if(type == "Ressource"){
        Ressource* a = new Ressource(data);
        cout << "Ajout de la ressource [ ID : " << a->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(a);
    }
    else if(type == "Livre"){
        Livre* b = new Livre(data);
        cout << "Ajout du livre [ ID : " << b->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(b);
    }
    else if(type == "Revue"){
        Revue* c = new Revue(data);
        cout << "Ajout de la revue [ ID : " << c->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(c);
    }
    else if(type == "Vhs"){
        Vhs* d = new Vhs(data);
        cout << "Ajout du VHS [ ID : " << d->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(d);
    }
    else if(type == "Dvd"){
        Dvd* e = new Dvd(data);
        cout << "Ajout du DVD [ ID : " << e->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(e);
    }
    else if(type == "Cd"){
        Cd* f = new Cd(data);
        cout << "Ajout du CD [ ID : " << f->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(f);
    }
    else if(type == "Numerique"){
        Numerique* g = new Numerique(data);
        cout << "Ajout du multimedia [ ID : " << g->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(g);
    }
}

void Console::add(Ressource* media){
    if(media->getType() == "Ressource"){
        cout << "Ajout de la ressource [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
    else if(media->getType() == "Livre"){
        cout << "Ajout du livre [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
    else if(media->getType() == "Revue"){
        cout << "Ajout de la revue [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
    else if(media->getType() == "Vhs"){
        cout << "Ajout du VHS [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
    else if(media->getType() == "Dvd"){
        cout << "Ajout du DVD [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
    else if(media->getType() == "Cd"){
        cout << "Ajout du CD [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
    else if(media->getType() == "Numerique"){
        cout << "Ajout du multimedia [ ID : " << media->getId() << " ] a la mediatheque" << endl << endl;
        Mediatheque.push_back(media);
    }
}

void Console::add(string filename){
    if (fopen(filename.c_str(), "r") != NULL) {
        ifstream stream(filename.c_str());
        string ligne;
        cout << "Ajout a la mediatheque depuis le fichier " << filename << endl << endl;
        while (!stream.eof()){
            getline(stream, ligne);
            if(ligne == "Ressource"){
                Ressource* a = new Ressource(stream);
                cout << "Ajout de la ressource [ ID : " << a->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(a);
            }
            else if(ligne == "Livre"){
                Livre* b = new Livre(stream);
                cout << "Ajout du livre [ ID : " << b->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(b);
            }
            else if(ligne == "Revue"){
                Revue* c = new Revue(stream);
                cout << "Ajout de la revue [ ID : " << c->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(c);
            }
            else if(ligne == "Vhs"){
                Vhs* d = new Vhs(stream);
                cout << "Ajout du VHS [ ID : " << d->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(d);
            }
            else if(ligne == "Dvd"){
                Dvd* e = new Dvd(stream);
                cout << "Ajout du DVD [ ID : " << e->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(e);
            }
            else if(ligne == "Cd"){
                Cd* f = new Cd(stream);
                cout << "Ajout du CD [ ID : " << f->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(f);
            }
            else if(ligne == "Numerique"){
                Numerique* g = new Numerique(stream);
                cout << "Ajout du multimedia [ ID : " << g->getId() << " ] a la mediatheque" << endl << endl;
                Mediatheque.push_back(g);
            }
        }
        cout << "Fin de lecture" << endl << endl;
    }
    else
        cout << "Le fichier " << filename << " n'a pas ete trouve" << endl << endl;
}

void Console::search(string chaine){
    int i = 0;
    cout << "Recherche de tous les elements contenant << " << chaine << " >> dans les resultats precedents" << endl << endl;
    while (i < Recherche.size()) {
        if ((Recherche[i]->search(chaine)) == false)
            Recherche.erase(Recherche.begin() + i);
        else i++;
    }
}

void Console::clear(){
    Recherche.clear();
    for (int i = 0 ; i < Mediatheque.size() ; i++){
        Recherche.push_back(Mediatheque[i]);
    }
    cout << "La recherche a ete reinitialisee" << endl << endl;
}

void Console::delet(int id){
    int i;
    if ((i = searchId(id)) == -1)
        cout << "Pas de correspondance avec l'ID : " << id << endl << endl;
    else
        Mediatheque.erase(Mediatheque.begin() + i);
}

void Console::reset(){
    Mediatheque.clear();
    cout << "La mediatheque est vide" << endl << endl;
    clear();
}

void Console::load(string filename){
    cout << "Chargement du fichier " << filename << " dans la mediatheque" << endl << endl;
    reset();
    add(filename);
}

void Console::save(string filename){
    ofstream stream(filename.c_str());
    cout << "Sauvegarde de la mediatheque dans le fichier " << filename << endl << endl;
    if (stream.is_open())
    {
        for (int i = 0 ; i < Mediatheque.size() ; i++){
            Mediatheque[i]->save(stream);
        }
        stream.close();
    } else
    cout << "Probleme a l'ouverture de " << filename << endl;
}

void Console::list(){
    cout << "Affichage des " << Recherche.size() << " resultats la recherche :" << endl;
    cout << "[ID] Type de media  ~  Titre du media" << endl;
    for(int i = 0; i < Recherche.size(); i++)
        Recherche[i]->list();
        cout << endl;
}

void Console::show(int id) {
    int i;
    if ((i = searchId(id)) == -1)
        cout << "Pas de correspondance avec l'ID : " << id << endl << endl;
    else {
        Mediatheque[i]->show();
        cout << endl;
    }
}

int Console::searchId(int id){
    int i = 0;
    while ((Mediatheque[i]->getId() != id) && (i < Mediatheque.size()))
        i++;
    if (Mediatheque[i]->getId() == id){
        return i;
    }
    else
        return -1;
}

void Console::nombreMediatheque(){
    cout << "Il y a actuellement " << Mediatheque.size() << " elements dans la mediatheque" << endl << endl;
}

void Console::nombreRecherche(){
    cout << "La recherche comporte " << Recherche.size() << " elements" << endl << endl;
}

void Console::run() {
    string ligne, type, cmd = "START";
    vector<string> commande;

    cout << "Rentrez le nom du fichier comportant la mediatheque a charger :";

    cin >> ligne;
    cin.ignore();

    cout << endl;

    cout << "Chargement depuis le fichier " << ligne << endl << endl;
    load(ligne);
    clear();

/*  Liste des commandes :
 *  BYE
 *  ADD type (+ details) / filename
 *  LOAD filename
 *  SAVE filename
 *  SEARCH chaine
 *  CLEAR
 *  LIST
 *  SHOW id
 *  DELETE id
 *  RESET
 *  HELP
 */

    while (cmd != "BYE") {

        commande.clear();

        cout << "En attente d'une nouvelle commande (taper HELP pour la liste des commandes) :";
        getline(cin, ligne);
        istringstream stream(ligne);
        while (getline(stream, ligne, ' ')) {
            commande.push_back(ligne);
        }
        cmd = commande[0];

        if ((cmd == "ADD") && (commande.size() > 1)) {
            cout << "Ajout d'un element a la mediatheque";
            type = commande[1];
            commande.clear();
            if ((type == "Ressource") || (type == "Livre") || (type == "Revue") || (type == "Numerique") ||
                (type == "Vhs") || (type == "Dvd") || (type == "Cd")) {
                cout << ", merci de fournir les informations relatives" << endl << "Titre :";
                getline(cin, ligne);
                commande.push_back(ligne);
                cout << "Auteur :";
                getline(cin, ligne);
                commande.push_back(ligne);
                cout << "Annee de sortie :";
                cin >> ligne;
                cin.ignore();
                while (!isNumber(ligne)) {
                    cout << "Ce n'est pas un entier :";
                    cin >> ligne;
                    cin.ignore();
                }
                commande.push_back(ligne);

                if (type == "Numerique") {
                    cout << "Extension :";
                    getline(cin, ligne);
                    commande.push_back(ligne);
                    cout << "Taille du fichier (octets) :";
                    cin >> ligne;
                    cin.ignore();
                    while (!isNumber(ligne)) {
                        cout << "Ce n'est pas un entier :";
                        cin >> ligne;
                        cin.ignore();
                    }
                    commande.push_back(ligne);
                    cout << "Chemin d'acces :";
                    getline(cin, ligne);
                    commande.push_back(ligne);
                }
                if ((type == "Livre") || (type == "Revue")) {
                    cout << "Nombre de pages :";
                    cin >> ligne;
                    cin.ignore();
                    while (!isNumber(ligne)) {
                        cout << "Ce n'est pas un entier :";
                        cin >> ligne;
                        cin.ignore();
                    }
                    commande.push_back(ligne);
                    cout << "Collection :";
                    getline(cin, ligne);
                    commande.push_back(ligne);
                    cout << "Resume :";
                    getline(cin, ligne);
                    commande.push_back(ligne);

                    if (type == "Revue") {
                        cout << "Editeur :";
                        getline(cin, ligne);
                        commande.push_back(ligne);
                        cout << "Liste des articles (saisir le caractere * quand fini) :";
                        getline(cin, ligne);
                        while (ligne != "*") {
                            commande.push_back(ligne);
                            cout << "Nouvel article :";
                            getline(cin, ligne);
                        }
                        cout << " * FINI *" << endl;
                        commande.insert(commande.begin() + 7, to_string(commande.size() - 7));
                    }
                }
                if ((type == "Vhs") || (type == "Dvd") || (type == "Cd")) {
                    cout << "Duree (minutes) :";
                    cin >> ligne;
                    cin.ignore();
                    while (!isNumber(ligne)) {
                        cout << "Ce n'est pas un entier :";
                        cin >> ligne;
                        cin.ignore();
                    }
                    commande.push_back(ligne);
                    cout << "Maison de production :";
                    getline(cin, ligne);
                    commande.push_back(ligne);

                    if (type == "Dvd") {
                        cout << "Nombre de pistes :";
                        cin >> ligne;
                        cin.ignore();
                        while (!isNumber(ligne)) {
                            cout << "Ce n'est pas un entier :";
                            cin >> ligne;
                            cin.ignore();
                        }
                        commande.push_back(ligne);
                    }

                    if (type == "Cd") {
                        cout << "Liste des pistes (saisir le caractere * quand fini) :";
                        getline(cin, ligne);
                        while (ligne != "*") {
                            commande.push_back(ligne);
                            cout << "Nouvelle piste :";
                            getline(cin, ligne);
                        }
                        cout << " * FINI *" << endl;
                        commande.insert(commande.begin() + 5, to_string(commande.size() - 5));
                    }
                }

                cout << endl;
                add(type, commande);
            } else {
                cout << " depuis le fichier " << type << endl << endl;
                add(type);
            }
            clear();
        } else {
            if ((cmd == "LOAD") && (commande.size() > 1)) {
                load(commande[1]);
                clear();
            } else {
                if ((cmd == "SAVE") && (commande.size() > 1)) {
                    save(commande[1]);
                } else {
                    if ((cmd == "SEARCH") && (commande.size() > 1)) {
                        search(commande[1]);
                    } else {
                        if (cmd == "CLEAR") {
                            cout << "Reinitialisation de la recherche" << endl << endl;
                            clear();
                        } else {
                            if (cmd == "LIST") {
                                list();
                            } else {
                                if ((cmd == "SHOW") && (commande.size() > 1)) {
                                    if (isNumber(commande[1])) {
                                        show(stoi(commande[1]));
                                    } else
                                        cout << "L'ID fournit n'est pas un nombre" << endl << endl;
                                } else {
                                    if ((cmd == "DELETE") && (commande.size() > 1)) {
                                        if (isNumber(commande[1])) {
                                            cout << "Suppression de l'element [ ID : " << commande[1]
                                                 << " ] de la mediatheque" << endl << endl;
                                            delet(stoi(commande[1]));
                                        } else
                                            cout << "L'ID fournit n'est pas un nombre" << endl << endl;
                                    } else {
                                        if (cmd == "RESET") {
                                            cout << "Suppression de tous les elements de la mediatheque" << endl
                                                 << endl;
                                            reset();
                                        } else {
                                            if (cmd == "BYE") {
                                                cout << "Fermeture de la console" << endl << endl;
                                            } else {
                                                if (cmd == "HELP") {
                                                    cout << " - BYE : Fermer l'application" << endl;
                                                    cout
                                                            << " - ADD type / filename : Ajoute un media, preciser le type de media ou le fichier de donnees"
                                                            << endl;
                                                    cout
                                                            << " - LOAD filename : Remplace le contenu de la mediatheque par celui du fichier de donnees"
                                                            << endl;
                                                    cout
                                                            << " - SAVE filename : Sauve le contenu de la mediatheque dans le fichier de donnees"
                                                            << endl;
                                                    cout
                                                            << " - SEARCH chaine : Recherche la chaine dans tout le contenu de la mediatheque"
                                                            << endl;
                                                    cout << " - CLEAR : Reinitialise la recherche" << endl;
                                                    cout
                                                            << " - LIST : Affiche le type et le titre des medias de la recherche"
                                                            << endl;
                                                    cout
                                                            << " - SHOW id : Affiche les infos detaillees du media repere par l'ID"
                                                            << endl;
                                                    cout << " - DELETE id : Supprime le media repere par l'ID" << endl;
                                                    cout << " - RESET : Supprime tous les medias de la mediatheque"
                                                         << endl;
                                                    cout << " - HELP : Fournit la liste des commandes" << endl << endl;
                                                } else {
                                                    cout << "La commande n'a pas de correspondance" << endl << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}