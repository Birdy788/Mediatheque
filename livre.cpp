//
// Created by Benjamin Celereau on 23/04/2020.
//

#include "livre.h"

Livre::Livre() : Ressource(){
    Type("Livre");
    pages = 0;
    collection = "";
    resume = "";
}

Livre::Livre(string _titre, string _auteur, int _annee, int _pages, string _collection, string _resume) : Ressource(_titre, _auteur, _annee){
    Type("Livre");
    pages = _pages;
    collection = _collection;
    resume = _resume;
}

Livre::Livre(ifstream& stream) : Ressource(stream){
    string ligne;

    Type("Livre");
    getline(stream, ligne);
    pages = stoi(ligne);
    getline(stream, collection);
    getline(stream, resume);
}

Livre::Livre(vector<string> data) : Ressource(data){
    Type("Livre");
    pages = stoi(data[3]);
    collection = data[4];
    resume = data[5];
}

Livre::~Livre(){

}

void Livre::Pages(int _pages){
    pages = _pages;
}

void Livre::Collection(string _collection){
    collection = _collection;
}

void Livre::Resume(string _resume){
    resume = _resume;
}

int Livre::getPages(){
    return pages;
}

string Livre::getCollection(){
    return collection;
}

string Livre::getResume(){
    return resume;
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 * pages
 * collection
 * resume
 */

void Livre::load(ifstream& stream){
    string ligne;

    Ressource::load(stream);

    Type("Livre");
    getline(stream, ligne);
    pages = stoi(ligne);
    getline(stream, collection);
    getline(stream, resume);
}

void Livre::save(ofstream& stream){
    Ressource::save(stream);
    stream << pages << endl;
    stream << collection << endl;
    stream << resume << endl;
}

void Livre::show(){
    Ressource::show();
    cout << "Nombre de pages : " << pages << endl;
    cout << "Collection : " << collection << endl;
    cout << "Resume : " << resume << endl;
}

bool Livre::search(string chaine){
    string _pages = to_string(pages);
    if(strstr(_pages.c_str(), chaine.c_str()))
        return true;
    if(strstr(collection.c_str(), chaine.c_str()))
        return true;
    if(strstr(resume.c_str(), chaine.c_str()))
        return true;
    return Ressource::search(chaine);
}