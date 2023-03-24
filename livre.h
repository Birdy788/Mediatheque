//
// Created by Yassine Amrani on 23/04/2021
//

#ifndef PROJET_LIVRE_H
#define PROJET_LIVRE_H

#include "ressource.h"

class Livre : public Ressource {
private:
    int pages;                                                                                          // Nombre de pages
    string collection;                                                                                  // Collection du livre
    string resume;                                                                                      // Resume du livre

public:
    Livre();                                                                                            // Constructeur de Livre vide
    Livre(string _titre, string _auteur, int _annee, int _pages, string _collection, string _resume);   // Constructeur de Livre a partir de parametres precis
    Livre(ifstream& stream);                                                                            // Constructeur de Livre a partir d'un flux (fichier)
    Livre(vector<string> data);                                                                         // Constructeur de Livre a partir d'une serie de strings
    ~Livre();                                                                                           // Destructeur de Livre

    void Pages(int _pages);                                                                             // Redefinit le nombre de pages
    void Collection(string _collection);                                                                // Redefinit la collection
    void Resume(string _resume);                                                                        // Redefinit le resume
    int getPages();                                                                                     // Renvoie le nombre de pages
    string getCollection();                                                                             // Renvoie la collection
    string getResume();                                                                                 // Renvoie le resume

    virtual void load(ifstream& stream);                                                                // Chargement a partir d'un fichier (acces au stream en lecture)
    virtual void save(ofstream& stream);                                                                // Sauvegarde dans un fichier (acces au stream en ecriture)
    virtual void show();                                                                                // Affiche les infos detaillees de la ressource de id
    virtual bool search(string chaine);                                                                 // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_LIVRE_H