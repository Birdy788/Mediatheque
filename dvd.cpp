//
// Created by Benjamin Celereau on 23/04/2020.
//

#include "dvd.h"

Dvd::Dvd() : Vhs(){
    Type("Dvd");
    pistes = 0;
}

Dvd::Dvd(string _titre, string _auteur, int _annee, int _duree, string _production, int _pistes) : Vhs(_titre, _auteur, _annee, _duree, _production){
    Type("Dvd");
    pistes = _pistes;
}

Dvd::Dvd(ifstream& stream) : Vhs(stream){
    string ligne;

    Type("Dvd");
    getline(stream, ligne);
    pistes = stoi(ligne);
}

Dvd::Dvd(vector<string> data) : Vhs(data){
    Type("Dvd");
    pistes = stoi(data[5]);
}

Dvd::~Dvd(){

}

void Dvd::Pistes(int _pistes){
    pistes = _pistes;
}

int Dvd::getPistes(){
    return pistes;
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 * duree
 * maison de production
 * nombre de pistes
 */

void Dvd::load(ifstream& stream){
    string ligne;

    Vhs::load(stream);

    Type("Dvd");
    getline(stream, ligne);
    pistes = stoi(ligne);
}

void Dvd::save(ofstream& stream){
    Vhs::save(stream);
    stream << pistes << endl;
}

void Dvd::show(){
    Vhs::show();
    cout << pistes << " piste(s)" << endl;
}

bool Dvd::search(string chaine){
    string _pistes = to_string(pistes);
    if(strstr(_pistes.c_str(), chaine.c_str()))
        return true;
    return Vhs::search(chaine);
}