//
// Created by Yassine Amrani on 23/04/2021
//

#ifndef PROJET_CD_H
#define PROJET_CD_H

#include "dvd.h"

class Cd : public Dvd {
private:
    vector<string> noms;                                                                                    // Noms des pistes

public:
    Cd();                                                                                                   // Constructeur de Cd vide
    Cd(string _titre, string _auteur, int _annee, int _duree, string _production, vector<string> _noms);    // Constructeur de Cd a partir de parametres precis
    Cd(ifstream& stream);                                                                                   // Constructeur de Cd a partir d'un flux (fichier)
    Cd(vector<string> data);                                                                                // Constructeur de Cd partir d'une serie de strings
    ~Cd();                                                                                                  // Destructeur de Cd

    void newNom(string _nom);                                                                               // Ajouter une piste par son nom
    void delNom(int _piste);                                                                                // Supprimer une piste par son numéro
    string getNom(int _piste);                                                                              // Recuperer nom de piste depuis numero de piste

    void load(ifstream& stream);                                                                            // Chargement a partir d'un fichier (acces au stream en lecture)
    void save(ofstream& stream);                                                                            // Sauvegarde dans un fichier (acces au stream en ecriture)
    void show();                                                                                            // Affiche les infos detaillees de la ressource de id
    bool search(string chaine);                                                                             // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_CD_H