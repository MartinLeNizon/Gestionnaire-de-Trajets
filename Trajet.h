/*************************************************************************
                           Trajet  -  Interface
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mail               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

#ifndef Trajet_H
#define Trajet_H
#include <cstring>

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe abstraite mere des classes TrajetSimple et TrajetCompose
//------------------------------------------------------------------------

class Trajet{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Affichage du trajet
    // Méthode abstraite

    virtual bool isSimple() const = 0;
    // Mode d'emploi :
    // S'applique directement sur un trajet
    // Méthode abstraite
    // Retour : true -> Trajet Simple ; false -> Trajet Composé

    // Retour attribut depart
    char * getDepart() const;

    // Retour attribut arrivee
    char * getArrivee() const;

//-------------------------------------------- Constructeurs - destructeur

    virtual ~Trajet();

//------------------------------------------------------------------ PRIVE

protected:
//------------------------------------------------- Constructeurs protégés

    // Protected car classe abstraite
    Trajet(const char * d, const char * a);
    // Mode d'emploi :
    // d chaîne de caractère correspondant au départ, a à l'arrivée
    // Constructeur abstrait
    // Contrat :
    // Longueur maximale des chaînes de caractères : 100 (101 en comptant le caractère '\0')

//----------------------------------------------------- Attributs protégés
    char * depart;      // Départ du trajet
    char * arrivee;     // Arrivée du trajet

};

#endif // Trajet_H
