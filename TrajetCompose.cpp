/*************************************************************************
                        TrajetCompose  -  Réalisation
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
#include "Trajet.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "ListeChainee.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const
// Algorithme :
// Parcours de la liste des trajets composant le trajet composé
// Affichage au fur et à mesure
{
#ifdef MAP
    cout << "Appel a Afficher de <TrajetCompose>" << endl;
#endif

    Maillon * courant=liste.getHead();

    while(courant!=NULL){
        if(courant!=liste.getHead())  cout << " - ";
        courant->Afficher();
        courant=courant->getSuivant();
    }
}

void TrajetCompose::Ajouter(Trajet * const ts)
// Algorithme :
// Mise à jour du depart et arrivee (globaux) lors de l'insertion
// Fait appel à la fonction ajouter de la liste
{
#ifdef MAP
    cout << "Appel a Ajouter de <TrajetCompose>" << endl;
#endif


    if(liste.getHead()==NULL) strcpy(depart,ts->getDepart());
    strcpy(arrivee,ts->getArrivee());
    liste.Ajouter(ts);

}

bool TrajetCompose::isSimple() const{
#ifdef MAP
    cout << "Appel a isSimple de <TrajetCompose>" << endl;
#endif

    return false;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose() : Trajet("",""){
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
}


TrajetCompose::~TrajetCompose()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
}
