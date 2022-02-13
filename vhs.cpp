//
// Created by Benjamin Celereau on 23/04/2020.
//

#include "vhs.h"

Vhs::Vhs() : Ressource(){
    Type("Vhs");
    duree = 0;
    production = "";
}

Vhs::Vhs(string _titre, string _auteur, int _annee, int _duree, string _production) : Ressource(_titre, _auteur, _annee){
    Type("Vhs");
    duree = _duree;
    production = _production;
}

Vhs::Vhs(ifstream& stream) : Ressource(stream){
    string ligne;

    Type("Vhs");
    getline(stream, ligne);
    duree = stoi(ligne);
    getline(stream, production);
}

Vhs::Vhs(vector<string> data) : Ressource(data){
    Type("Vhs");
    duree = stoi(data[3]);
    production = data[4];
}

Vhs::~Vhs(){

}

void Vhs::Duree(int _duree){
    duree = _duree;
}

void Vhs::Production(string _production){
    production = _production;
}

int Vhs::getDuree(){
    return duree;
}

string Vhs::getProduction(){
    return production;
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 * duree
 * maison de production
 */

void Vhs::load(ifstream& stream){
    string ligne;

    Ressource::load(stream);

    Type("Vhs");
    getline(stream, ligne);
    duree = stoi(ligne);
    getline(stream, production);
}

void Vhs::save(ofstream& stream){
    Ressource::save(stream);
    stream << duree << endl;
    stream << production << endl;
}

void Vhs::show(){
    Ressource::show();
    cout << "Duree : " << duree/60 << " heure(s) " << duree%60 << endl;
    cout << "Maison de production : " << production << endl;
}

bool Vhs::search(string chaine){
    string _duree = to_string(duree);
    if(strstr(_duree.c_str(), chaine.c_str()))
        return true;
    if(strstr(production.c_str(), chaine.c_str()))
        return true;
    return Ressource::search(chaine);
}