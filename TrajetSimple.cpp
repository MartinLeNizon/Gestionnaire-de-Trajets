/*************************************************************************
                        TrajetSimple  -  Réalisation
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const{
#ifdef MAP
    cout << "Appel a Afficher de <TrajetSimple>" << endl;
#endif

    cout << "de "<<depart<<" à "<<arrivee<< " en "<<moytrans;
}

bool TrajetSimple::isSimple() const{
#ifdef MAP
    cout << "Appel a isSimple de <TrajetSimple>" << endl;
#endif

    return true;
}


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char * d, const char * a, const char * mt) : Trajet(d,a){
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    moytrans=new char[strlen(mt)+1];
    strcpy(moytrans,mt);
}


TrajetSimple::~TrajetSimple(){
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete [] moytrans;
}
