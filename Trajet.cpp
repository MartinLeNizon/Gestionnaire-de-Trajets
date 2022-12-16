/*************************************************************************
                           Trajet  -  Réalisation
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mail               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes
#ifndef MAX_MOTS
#define MAX_MOTS 100
#endif

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char * Trajet::getDepart() const{
#ifdef MAP
    cout << "Appel a getDepart de <Trajet>" << endl;
#endif

    return depart;
}

char * Trajet::getArrivee() const{
#ifdef MAP
    cout << "Appel a getArrivee de <Trajet>" << endl;
#endif

    return arrivee;
}

//-------------------------------------------- Constructeurs - destructeur

Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

    delete [] depart;
    delete [] arrivee;
}

//------------------------------------------------------------------ PRIVE

//------------------------------------------------- Constructeurs protégés

Trajet::Trajet(const char * d, const char * a){
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

    depart = new char[MAX_MOTS+1];
    arrivee = new char[MAX_MOTS+1];
    strcpy(depart,d);
    strcpy(arrivee,a);
}
