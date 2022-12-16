/*************************************************************************
                            Catalogue  -  Réalisation
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
#include "Catalogue.h"
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes
#ifndef MAX_MOTS
#define MAX_MOTS 100
#endif

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher() const
// Algorithme :
// Parcours de la liste et affichage au fur et à mesure
// Affiche le type du trajet et sa position dans la liste (par rapport aux autres du même type)
// ! ATTENTION ! Un trajet sera nommé différemment si sa position évolue
{
#ifdef MAP
    cout << "Appel a Afficher de <TrajetCompose>" << endl;
#endif

    if(listeCata.getHead()==NULL){
        cout << "Catalogue vide" << endl;
        return;
    }

    int compteur_ts=1;
    int compteur_tc=1;


    Maillon * courant=listeCata.getHead();

    while(courant!=NULL){
        cout << compteur_ts+compteur_tc-1 << " : ";
        if(courant->getValeur()->isSimple()) cout << "TS" << compteur_ts++ << " : ";
        else cout << "TC" << compteur_tc++ << " : ";
        courant->getValeur()->Afficher();
        courant=courant->getSuivant();
        cout << endl;
    }
}

void Catalogue::AjouterTrajet(Trajet * const t)
// Algorithme :
// Appel à l'ajout trié AjouterTrie() de la liste
{
#ifdef MAP
    cout << "Appel a Ajouter de <Catalogue>" << endl;
#endif

    listeCata.AjouterTrie(t);
    nbTrajets++;

}

void Catalogue::RechercheSimple(const char * depart, const char * arrivee) const
// Algorithme :
// Parcours la liste des trajets
// Enregistrement du nom du trajet dans un tableau, et compte les trajets reliant bien depart et arrivee
// Affichage à la fin du nombre de parcours possibles, et le nom des trajets le permettant
{
#ifdef MAP
    cout << "Appel a RechercheSimple de <Catalogue>" << endl;
#endif

    int compteur_ts=0;
    int compteur_tc=0;

    Maillon * courant=listeCata.getHead();
    int compteur=0;

    char ** tab = new char*[nbTrajets];
    int i;
    for(i=0; i<nbTrajets; i++) tab[i] = new char[MAX_MOTS+1];

    char memoire[MAX_MOTS+1];

    while(courant!=NULL){

        if(courant->getValeur()->isSimple()) compteur_ts++;
        else compteur_tc++;

        if(strcmp(depart, courant->getValeur()->getDepart()) == 0 && strcmp(arrivee, courant->getValeur()->getArrivee()) == 0){
            if(courant->getValeur()->isSimple()){
                strcpy(tab[compteur],"TS");
                sprintf(memoire, "%d", compteur_ts);
                strcat(tab[compteur], memoire);
            }else{
                strcpy(tab[compteur],"TC");
                sprintf(memoire, "%d", compteur_tc);
                strcat(tab[compteur], memoire);
            }
            compteur++;
        }
        courant=courant->getSuivant();

    }

    cout << endl << "Il y a " << compteur << " parcours possible(s)";
    if(compteur==0) return;
    cout << " : (" << tab[0] << ")";
    for(i=1; i<compteur; i++) cout << ", (" << tab[i] << ")";

    for(i=0; i<nbTrajets; i++) delete [] tab[i];
    delete [] tab;
}

void Catalogue::RechercheAvancee(const char * depart, const char * arrivee) const
// Algorithme :
// Affichage du nombre de Parcours possibles
// Fait appel à la methode RechercheAvanceeCompte()
{
#ifdef MAP
    cout << "Appel a RechercheAvancee de <Catalogue>" << endl;
#endif

    cout << endl << "Il y a " << RechercheAvanceeCompte(depart, arrivee) << " parcours possible(s)";
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue(){
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

    nbTrajets=0;
}


Catalogue::~Catalogue()
// Algorithme :
// Détruit la liste (pas de code, car pas de pointeur)
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
}

//----------------------------------------------------- Méthodes protégées

int Catalogue::RechercheAvanceeCompte(const char * depart, const char * arrivee) const
// Algorithme :
// Premier parcours du catalogue
// Si le trajet permet de relier depart et arrivee, ou depart égale arrivee, incrémentation du compteur
// Sinon, deuxième parcours de la liste
// Si la composition des deux trajets (de chaque parcours) permet de relier depart et arrivee, incrémentation du compteur (et trajets des 2 parcours de liste différents)
// Sinon si le trajet du premier parcours a le bon depart, et le trajet du deuxieme parcours la bonne arrivee (et trajets des 2 parcours de liste différents) -> appel recursif
// L'appel recursif permet de compter le nombre de trajets reliant les 2 trajets
{
#ifdef MAP
    cout << "Appel a RechercheAvanceeCompte de <Catalogue>" << endl;
#endif

    int compteur=0;

    Maillon * maillonDepart=listeCata.getHead();                    // Maillon pour vérifier si le départ est bon
    Maillon * maillonArrivee;                                       // Maillon pour vérifier si la fin est bonne


    while(maillonDepart!=NULL){
        if(!strcmp(depart, maillonDepart->getValeur()->getDepart()) && !strcmp(arrivee, maillonDepart->getValeur()->getArrivee())){
            compteur++;
        }else{
            maillonArrivee=listeCata.getHead();
            while(maillonArrivee!=NULL){
                if(!strcmp(maillonDepart->getValeur()->getDepart(), depart) && !strcmp(maillonArrivee->getValeur()->getArrivee(), arrivee) && !strcmp(maillonDepart->getValeur()->getArrivee(), maillonArrivee->getValeur()->getDepart()) && maillonArrivee != maillonDepart){
                    compteur++;
                }else if(!strcmp(maillonDepart->getValeur()->getDepart(), depart) && !strcmp(maillonArrivee->getValeur()->getArrivee(), arrivee) && maillonArrivee != maillonDepart){
                    compteur += RechercheAvanceeCompte(maillonDepart->getValeur()->getArrivee(), maillonArrivee->getValeur()->getDepart());
                }

                maillonArrivee=maillonArrivee->getSuivant();

            }

        }

        maillonDepart=maillonDepart->getSuivant();

    }

    return compteur;

}
