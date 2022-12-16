/*************************************************************************
                            Maillon  -  Réalisation
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Maillon.h"
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Maillon::Afficher() const{
#ifdef MAP
    cout << "Appel a Afficher de <Maillon>" << endl;
#endif
    valeur->Afficher();
}

Trajet * Maillon::getValeur() const{
#ifdef MAP
    cout << "Appel a getValeur de <Maillon>" << endl;
#endif

    return valeur;
}

void Maillon::setSuivant(Maillon * const s){
#ifdef MAP
    cout << "Appel a setSuivant de <Maillon>" << endl;
#endif

    suivant=s;
}

Maillon * Maillon::getSuivant() const{
#ifdef MAP
    cout << "Appel a getSuivant de <Maillon>" << endl;
#endif

    return suivant;
}

//-------------------------------------------- Constructeurs - destructeur

Maillon::Maillon(Trajet * const v){
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif

    valeur = v;
    suivant = NULL;
}


Maillon::~Maillon()
// Algorithme :
// Libération de la mémoire allouée pour trajet pointé par valeur
// Libération du maillon suivant -> destruction en chaîne
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif

    delete valeur;
    if(suivant!=NULL) delete suivant;
}
