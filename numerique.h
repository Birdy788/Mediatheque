//
// Created by Yassine Amrani on 23/04/2021
//

#ifndef PROJET_NUMERIQUE_H
#define PROJET_NUMERIQUE_H

#include "ressource.h"

class Numerique : public Ressource {
private:
    string extension;                                                                                   // Extension du fichier (*.txt, *.mp4 ...)
    int taille;                                                                                         // Taille du fichier
    string path;                                                                                        // URL du fichier sur le serveur Web

public:
    Numerique();                                                                                        // Constructeur de Numerique vide
    Numerique(string _titre, string _auteur, int _annee, string _extension, int _taille, string _path); // Constructeur de Numerique a partir de parametres precis
    Numerique(ifstream& stream);                                                                        // Constructeur de Numerique a partir d'un flux (fichier)
    Numerique(vector<string> data);                                                                     // Constructeur de Numerique a partir d'une serie de strings
    ~Numerique();                                                                                       // Destructeur de Numerique

    void Extension(string _extension);                                                                  // Redefinit l'extension
    void Taille(int _taille);                                                                           // Redefinit la taille
    void Path(string _path);                                                                            // Redefinit le chemin d'acces
    string getExtension();                                                                              // Renvoie l'extension
    int getTaille();                                                                                    // Renvoie la taille
    string getPath();                                                                                   // Renvoie le chemin d'acces

    void load(ifstream& stream);                                                                        // Chargement a partir d'un fichier (acces au stream en lecture)
    void save(ofstream& stream);                                                                        // Sauvegarde dans un fichier (acces au stream en ecriture)
    void show();                                                                                        // Affiche les infos detaillees de la ressource de id
    bool search(string chaine);                                                                         // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_NUMERIQUE_H