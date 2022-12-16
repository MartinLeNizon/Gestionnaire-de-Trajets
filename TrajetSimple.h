/*************************************************************************
                        TrajetSimple  -  Interface
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mail               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

#ifndef TrajetSimple_H
#define TrajetSimple_H
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Classe fille de Trajet
// Un Trajet Simple est composé d'un point de départ, d'arrivee et un moyen de transport
//------------------------------------------------------------------------

class TrajetSimple : public Trajet{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;
    // Affichage

    virtual bool isSimple() const;
    // Mode d'emploi :
    // S'applique directement sur le trajet
    // true : Trajet Simple ; false : Trajet Composé

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const char * d, const char * a, const char * mt);
    // Mode d'emploi :
    // d depart du trajet, a arrivee, mt moyen de transport
    // Contrat :
    // Longueur maximale des chaînes de caractères : 100 (101 en comptant le caractère '\0')

    virtual ~TrajetSimple();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    char * moytrans;

};

#endif // TrajetSimple_H
