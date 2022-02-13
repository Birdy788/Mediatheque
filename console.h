//
// Created by Benjamin Celereau on 23/04/2020.
//

#ifndef PROJET_CONSOLE_H
#define PROJET_CONSOLE_H

#include "numerique.h"
#include "revue.h"
#include "cd.h"
#include <stdio.h>
#include <sstream>
#include <iostream>

bool isNumber(string chaine);                   // Verifie que la chaine est un nombre

class Console {
private:
    vector<Ressource*> Mediatheque;             // Bibliotheque integrale
    vector<Ressource*> Recherche;               // Base de donnees pour la recherche

    int searchId(int _id);                      // Cherche la position de la ressource repérée id dans la mediatheque
    void nombreMediatheque();                   // Renvoie le nombre d'elements de la mediatheque
    void nombreRecherche();                     // Renvoie le nombre d'elements de la recherche

public:
    Console();                                  // Constructeur de Console vide
    Console(string filename);                   // Constructeur de Console, generation de la mediatheque a partir du fichier filename
    ~Console();                                 // Desctructeur de Console

    void add(string type, vector<string> data); // Ajouter ressource de type "type" avec details
    void add(Ressource* media);                 // Ajouter ressource du type du media
    void add(string filename);                  // Ajouter ressource depuis le fichier filename
    void search(string chaine);                 // Recherche le contenu de chaine dans le vecteur Recherche
    void clear();                               // Remise a zero de Recherche (recharge Mediatheque)
    void delet(int id);                         // Supprimer la ressource de id
    void reset();                               // Supprime toutes les ressources de Mediatheque
    void load(string filename);                 // Charger un fichier
    void save(string filename);                 // Sauver un fichier
    void list();                                // Affiche les infos de Recherche en compact
    void show(int id);                          // Affiche les infos detaillees de la ressource de id
    void run();                                 // Lance l'application
};

#endif //PROJET_CONSOLE_H