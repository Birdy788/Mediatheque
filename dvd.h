//
// Created by Benjamin Celereau on 23/04/2020.
//

#ifndef PROJET_DVD_H
#define PROJET_DVD_H

#include "vhs.h"

class Dvd : public Vhs {
private:
    int pistes;                                                                                     // Nombre de pistes

public:
    Dvd();                                                                                          // Constructeur de Dvd vide
    Dvd(string _titre, string _auteur, int _annee, int _duree, string _production, int _pistes);    // Constructeur de Dvd a partir de parametres precis
    Dvd(ifstream& stream);                                                                          // Constructeur de Dvd a partir d'un flux (fichier)
    Dvd(vector<string> data);                                                                       // Constructeur de Dvd partir d'une serie de strings
    ~Dvd();                                                                                         // Destructeur de Dvd

    void Pistes(int _pistes);                                                                       // Redefinit le nombre de pistes
    virtual int getPistes();                                                                        // Renvoie le nombre de pistes

    virtual void load(ifstream& stream);                                                            // Chargement a partir d'un fichier (acces au stream en lecture)
    virtual void save(ofstream& stream);                                                            // Sauvegarde dans un fichier (acces au stream en ecriture)
    virtual void show();                                                                            // Affiche les infos detaillees de la ressource de id
    virtual bool search(string chaine);                                                             // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_DVD_H