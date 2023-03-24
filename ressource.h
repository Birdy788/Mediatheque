//
// Created by Yassine Amrani on 23/04/2021
//

#ifndef PROJET_RESSOURCE_H
#define PROJET_RESSOURCE_H

using namespace std;

#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

class Ressource {
private:
    string type;                                            // Type de media
    string titre;                                           // Titre du media
    string auteur;                                          // Auteur du media
    int annee;                                              // Annee de creation du media
    int id;                                                 // ID du media
    static int fid;                                         // Nombre de medias crees : s'incremente pour chaque nouveau media (evite deux medias de meme ID)

public:
    Ressource();                                            // Constructeur de Ressource vide
    Ressource(string _titre, string _auteur, int _annee);   // Constructeur de Ressource a partir de parametres precis
    Ressource(ifstream& stream);                            // Constructeur de Ressource a partir d'un flux (fichier)
    Ressource(vector<string> data);                         // Constructeur de Ressource a partir d'une serie de strings
    ~Ressource();                                           // Destructeur de Ressource

    void Type(string _type);                                // Redefinit le type
    void Titre(string _titre);                              // Redefinit le titre
    void Auteur(string _auteur);                            // Redefinit l'auteur
    void Annee(int _annee);                                 // Redefinit l'annee
    string getType();                                       // Renvoie le type
    string getTitre();                                      // Renvoie le titre
    string getAuteur();                                     // Renvoie l'auteur
    int getAnnee();                                         // Renvoie l'annee
    int getId();                                            // Renvoie l'ID

    virtual void load(ifstream& stream);                    // Chargement a partir d'un fichier (acces au stream en lecture)
    virtual void save(ofstream& stream);                    // Sauvegarde dans un fichier (acces au stream en ecriture)
    void list();                                            // Affiche les infos du media en compact
    virtual void show();                                    // Affiche les infos detaillees de la ressource de id
    virtual bool search(string chaine);                     // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_RESSOURCE_H