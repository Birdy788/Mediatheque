//
// Created by Yassine Amrani on 23/04/2021
//

#include "cd.h"

Cd::Cd() : Dvd(){
    Type("Cd");
}

Cd::Cd(string _titre, string _auteur, int _annee, int _duree, string _production, vector<string> _noms) : Dvd(_titre, _auteur, _annee, _duree, _production, _noms.size()){
    Type("Cd");
    for (int i = 0 ; i < _noms.size() ; i++){
        noms.push_back(_noms[i]);
    }
}

Cd::Cd(ifstream& stream) : Dvd(stream){
    string ligne;
    int i = 0;

    Type("Cd");
    while(i++ < getPistes()){
        getline(stream, ligne);
        noms.push_back(ligne);
    }
}

Cd::Cd(vector<string> data) : Dvd(data){
    Type("Cd");
    for (int i = 0 ; i < getPistes() ; i++)
        noms.push_back(data[6 + i]);
}

Cd::~Cd(){

}

void Cd::newNom(string _nom){
    noms.push_back(_nom);
    Pistes(getPistes() + 1);
}

void Cd::delNom(int _piste){
    noms.erase(noms.begin() + _piste);
    Pistes(getPistes() - 1);
}

string Cd::getNom(int _piste){
    return noms[_piste];
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 * duree
 * maison de production
 * nombre de pistes
 * pistes(s) /!\ sur plusieurs lignes
 */

void Cd::load(ifstream& stream){
    string ligne;
    int i = 0;

    Dvd::load(stream);

    Type("Cd");
    getline(stream, ligne);
    Pistes(stoi(ligne));
    while(i++ < getPistes()){
        getline(stream, ligne);
        noms.push_back(ligne);
    }
}

void Cd::save(ofstream& stream){
    Dvd::save(stream);
    for(int i = 0; i < noms.size(); i++)
        stream << noms[i] << endl;
}

void Cd::show(){
    Dvd::show();
    for (int i = 0; i < noms.size(); i++)
        cout << " - " << noms[i] << endl;
}

bool Cd::search(string chaine) {
    for (int i = 0 ; i < noms.size() ; i++){
        if (strstr(noms[i].c_str(), chaine.c_str()))
            return true;
    }
    return Dvd::search(chaine);
}