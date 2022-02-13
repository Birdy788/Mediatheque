//
// Created by Benjamin Celereau on 23/04/2020.
//

#ifndef PROJET_REVUE_H
#define PROJET_REVUE_H

#include "livre.h"

class Revue : public Livre {
private:
    string editeur;                                                                                                                             // Editeur de la revue
    vector<string> noms;                                                                                                                        // Noms des articles

public:
    Revue();                                                                                                                                    // Constructeur de Revue vide
    Revue(string _titre, string _auteur, int _annee, int _pages, string _collection, string _resume, string _editeur, vector<string> _noms);    // Constructeur de Revue a partir de parametres precis
    Revue(ifstream& stream);                                                                                                                    // Constructeur de Revue a partir d'un flux (fichier)
    Revue(vector<string> data);                                                                                                                 // Constructeur de Revue partir d'une serie de strings
    ~Revue();                                                                                                                                   // Destructeur de

    void Editeur(string _editeur);                                                                                                              // Redefinit l'editeur
    void newArticle(string _nom);                                                                                                               // Ajouter un article par son nom
    void delArticle(int _article);                                                                                                              // Supprimer article depuis numero d'article
    string getEditeur();                                                                                                                        // Renvoie l'editeur
    int getArticles();                                                                                                                          // Renvoie le nombre d'articles
    string getNom(int _article);                                                                                                                // Recuperer nom d'article depuis numero d'article

    void load(ifstream& stream);                                                                                                                // Chargement a partir d'un fichier (acces au stream en lecture)
    void save(ofstream& stream);                                                                                                                // Sauvegarde dans un fichier (acces au stream en ecriture)
    void show();                                                                                                                                // Affiche les infos detaillees de la ressource de id
    bool search(string chaine);                                                                                                                 // Renvoie la presence ou non de la string dans l'une des donnees
};

#endif //PROJET_REVUE_H