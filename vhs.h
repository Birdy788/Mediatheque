//
// Created by Benjamin Celereau on 23/04/2020.
//

#ifndef PROJET_VHS_H
#define PROJET_VHS_H

#include "ressource.h"

class Vhs : public Ressource {
private:
    int duree;                                                                      // Duree de lecture
    string production;                                                              // Maison de production

public:
    Vhs();                                                                          // Constructeur de Vhs vide
    Vhs(string _titre, string _auteur, int _annee, int _duree, string _production); // Constructeur de Vhs a partir de parametres precis
    Vhs(ifstream& stream);                                                          // Constructeur de Vhs a partir d'un flux (fichier)
    Vhs(vector<string> data);                                                       // Constructeur de Vhs partir d'une serie de strings
    ~Vhs();                                                                         // Destructeur de Vhs

    void Duree(int _duree);                                                         // Redefinit la duree
    void Production(string _production);                                            // Redefinit la maison de production
    int getDuree();                                                                 // Renvoie la duree
    string getProduction();                                                         // Renvoie la maison de production

    virtual void load(ifstream& stream);                                            // Chargement a partir d'un fichier (acces au stream en lecture)
    virtual void save(ofstream& stream);                                            // Sauvegarde dans un fichier (acces au stream en ecriture)
    virtual void show();                                                            // Affiche les infos detaillees de la ressource de id
    virtual bool search(string chaine);                                             // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_VHS_H