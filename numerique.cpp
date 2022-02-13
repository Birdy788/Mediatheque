//
// Created by Benjamin Celereau on 23/04/2020.
//

#include "numerique.h"

Numerique::Numerique() : Ressource(){
    Type("Numerique");
    extension = "";
    taille = 0;
    path = "";
}

Numerique::Numerique(string _titre, string _auteur, int _annee, string _extension, int _taille, string _path) : Ressource(_titre, _auteur, _annee){
    Type("Numerique");
    extension = _extension;
    taille = _taille;
    path = _path;
}

Numerique::Numerique(ifstream& stream) : Ressource(stream){
    string ligne;

    Type("Numerique");
    getline(stream, extension);
    getline(stream, ligne);
    taille = stoi(ligne);
    getline(stream, path);
}

Numerique::Numerique(vector<string> data) : Ressource(data){
    Type("Numerique");
    extension = data[3];
    taille = stoi(data[4]);
    path = data[5];
}

Numerique::~Numerique(){

}

void Numerique::Extension(string _extension){
    extension = _extension;
}

void Numerique::Taille(int _taille){
    taille = _taille;
}

void Numerique::Path(string _path){
    path = _path;
}

string Numerique::getExtension(){
    return extension;
}

int Numerique::getTaille(){
    return taille;
}

string Numerique::getPath(){
    return path;
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 * extension
 * taille
 * chemin d'acces
 */

void Numerique::load(ifstream& stream){
    string ligne;

    Ressource::load(stream);

    Type("Numerique");
    getline(stream, extension);
    getline(stream, ligne);
    taille = stoi(ligne);
    getline(stream, path);
}

void Numerique::save(ofstream& stream){
    Ressource::save(stream);
    stream << extension << endl;
    stream << taille << endl;
    stream << path << endl;
}

void Numerique::show(){
    Ressource::show();
    cout << "Extension : " << extension << endl;
    cout << "Taille : " << taille << " octets" << endl;
    cout << "Chemin d'acces : " << path << endl;
}

bool Numerique::search(string chaine){
    string _taille = to_string(taille);
    if(strstr(extension.c_str(), chaine.c_str()))
        return true;
    if(strstr(_taille.c_str(), chaine.c_str()))
        return true;
    if(strstr(path.c_str(), chaine.c_str()))
        return true;
    return Ressource::search(chaine);
}