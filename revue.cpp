//
// Created by Yassine Amrani on 23/04/2021
//

#include "revue.h"

Revue::Revue() : Livre(){
    Type("Revue");
    editeur = "";
}

Revue::Revue(string _titre, string _auteur, int _annee, int _pages, string _collection, string _resume, string _editeur, vector<string> _noms) : Livre(_titre, _auteur, _annee, _pages, _collection, _resume){
    Type("Revue");
    editeur = _editeur;
    for (int i = 0 ; i < _noms.size() ; i++){
        noms.push_back(_noms[i]);
    }
}

Revue::Revue(ifstream& stream) : Livre(stream){
    string ligne;
    int i = 0, articles;

    Type("Revue");
    getline(stream, editeur);
    getline(stream, ligne);
    articles = stoi(ligne);
    while(i++ < articles){
        getline(stream, ligne);
        noms.push_back(ligne);
    }
}

Revue::Revue(vector<string> data) : Livre(data){
    Type("Revue");
    editeur = data[6];
    for (int i = 0 ; i < stoi(data[7]) ; i++)
        noms.push_back(data[8 + i]);
}

Revue::~Revue(){

}

void Revue::Editeur(string _editeur){
    editeur = _editeur;
}

void Revue::newArticle(string _nom){
    noms.push_back(_nom);
}

void Revue::delArticle(int _article){
    noms.erase(noms.begin() + _article);
}

string Revue::getEditeur(){
    return editeur;
}

int Revue::getArticles(){
    return noms.size();
}

string Revue::getNom(int _article) {
    return noms[_article];
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 * pages
 * collection
 * resume
 * editeur
 * article(s) /!\ sur plusieurs lignes
 */

void Revue::load(ifstream& stream){
    string ligne;
    int i = 0, articles;

    Livre::load(stream);

    Type("Revue");
    getline(stream, editeur);
    getline(stream, ligne);
    articles = stoi(ligne);
    while(i++ < articles){
        getline(stream, ligne);
        noms.push_back(ligne);
    }
}

void Revue::save(ofstream& stream){
    Livre::save(stream);
    stream << editeur << endl;
    stream << getArticles() << endl;
    for(int i = 0 ; i < getArticles() ; i++)
        stream << noms[i] << endl;
}

void Revue::show(){
    Livre::show();
    cout << "Editeur : " << editeur << endl;
    cout << getArticles() << " article(s)" << endl;
    for (int i = 0 ; i < getArticles() ; i++)
        cout << " - " << noms[i] << endl;
}

bool Revue::search(string chaine) {
    if (strstr(editeur.c_str(), chaine.c_str()))
        return true;
    for (int i = 0 ; i < noms.size() ; i++){
        if (strstr(noms[i].c_str(), chaine.c_str()))
            return true;
    }
    return Livre::search(chaine);
}