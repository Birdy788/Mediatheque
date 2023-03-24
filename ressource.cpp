//
// Created by Yassine Amrani on 23/04/2021
//

#include "ressource.h"

int Ressource::fid = 0; // Initilisation du compteur d'ID

Ressource::Ressource(){
    type = "Ressource";
    titre = "";
    auteur = "";
    annee = 0;
    id = fid++;
    cout << "[ID : " << id << " ] Creation d'un media inconnu" << endl << endl;
}

Ressource::Ressource(string _titre, string _auteur, int _annee){
    type = "Ressource";
    titre = _titre;
    auteur = _auteur;
    annee = _annee;
    id = fid++;
    cout << "[ID : " << id << " ] Creation d'un media" << endl << endl;
}

Ressource::Ressource(ifstream& stream){
    type = "Ressource";
    load(stream);
    id = fid++;
    cout << "[ID : " << id << " ] Creation d'un media" << endl << endl;
}

Ressource::Ressource(vector<string> data){
    type = "Ressource";
    titre = data[0];
    auteur = data[1];
    annee = stoi(data[2]);
    id = fid++;
    cout << "[ID : " << id << " ] Creation d'un media" << endl << endl;
}

Ressource::~Ressource(){
    cout << "[ID : " << id << " ] Destruction d'un media" << endl << endl;
}

void Ressource::Type(string _type){
    type = _type;
}

void Ressource::Titre(string _titre){
    titre = _titre;
}

void Ressource::Auteur(string _auteur){
    auteur = _auteur;
}

void Ressource::Annee(int _annee){
    annee = _annee;
}

string Ressource::getType(){
    return type;
}

string Ressource::getTitre(){
    return titre;
}

string Ressource::getAuteur(){
    return auteur;
}

int Ressource::getAnnee(){
    return annee;
}

int Ressource::getId(){
    return id;
}

/* Structure du fichier :
 * type
 * titre
 * auteur
 * annee
 */

void Ressource::load(ifstream& stream){
    string ligne;

    type = "Ressource";
    getline(stream, titre);
    getline(stream, auteur);
    getline(stream, ligne);
    annee = stoi(ligne);
}

void Ressource::save(ofstream& stream){
    stream << type << endl;
    stream << titre << endl;
    stream << auteur << endl;
    stream << annee << endl;
}

void Ressource::list(){
    cout << "[" << id << "] " << type << "  ~  " << titre << endl;
}

void Ressource::show(){
    cout << "  [ ID : " << id << " ]" << endl;
    cout << "Type : " << type << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;
    cout << "Annee de creation : " << annee << endl;
}

bool Ressource::search(string chaine){
    string _annee = to_string(annee);
    if(strstr(type.c_str(), chaine.c_str()))
        return true;
    if(strstr(titre.c_str(), chaine.c_str()))
        return true;
    if(strstr(auteur.c_str(), chaine.c_str()))
        return true;
    if(strstr(_annee.c_str(), chaine.c_str()))
        return true;
    return false;
}