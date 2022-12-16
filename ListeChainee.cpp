/*************************************************************************
                        ListeChainee  -  Réalisation
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
#include "ListeChainee.h"
#include "Trajet.h"
#include "Maillon.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeChainee::Ajouter(Trajet * const t)
// Algorithme :
// Si liste vide : on insère le trajet dans un maillon pointé par la tête de liste ; MAJ de end pointeur du maillon de fin
// Si liste non vide : insertion à la suite du dernier maillon actuel ; MAJ de end
{
#ifdef MAP
    cout << "Appel a Ajouter de <ListeChainee>" << endl;
#endif

    if(head==NULL){
        head=new Maillon(t);
        end=head;
    }else{
        end->setSuivant(new Maillon(t));
        end=end->getSuivant();
    }
}

void ListeChainee::AjouterTrie(Trajet * const t)
// Algorithme :
// Si liste vide, insertion en tête
// Sinon si le Trajet à ajouter doit être inséré en premier, insertion en tête
// Sinon, parcours de la liste grâce à deux pointeur de maillons, pointant sur deux maillons consécutifs (precedent et suivant) de la liste actuelle
// Dès que le trajet actuel devrait être inséré avant le maillon pointé par suivant, on insère le trajet entre precedent et suivant
{
#ifdef MAP
    cout << "Appel a AjouterTrie de <ListeChainee>" << endl;
#endif

    Maillon * ajout;

    if(head == NULL){
        head=new Maillon(t);
        end=head;
        return;
    }

    if(strcmp(t->getDepart(), head->getValeur()->getDepart()) < 0 || (strcmp(t->getDepart(), head->getValeur()->getDepart()) == 0 && strcmp(t->getArrivee(), head->getValeur()->getArrivee()) < 0) ){
        ajout=new Maillon(t);
        ajout->setSuivant(head);
        head=ajout;
        return;
    }

    Maillon * precedent = head;
    Maillon * suivant = precedent->getSuivant();

    while(suivant!=NULL){
        if(strcmp(t->getDepart(), suivant->getValeur()->getDepart()) < 0 || (strcmp(t->getDepart(), suivant->getValeur()->getDepart()) == 0 && strcmp(t->getArrivee(), suivant->getValeur()->getArrivee()) < 0) ){
            precedent->setSuivant(new Maillon(t));
            ajout = precedent->getSuivant();
            ajout->setSuivant(suivant);
            return;
        }
        precedent = suivant;
        suivant = suivant->getSuivant();
    }

    end->setSuivant(new Maillon(t));
    end=end->getSuivant();
}

Maillon * ListeChainee::getHead() const{
#ifdef MAP
    cout << "Appel a getHead de <ListeChainee>" << endl;
#endif

    return head;
}


//-------------------------------------------- Constructeurs - destructeur

ListeChainee::ListeChainee(){
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
    head = NULL;
    end = NULL;
}


ListeChainee::~ListeChainee()
// Algorithme :
// Destruction en chaîne de tous les maillons
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif

    if(head!=NULL){
        delete head;
    }

}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
