/*************************************************************************
                            Catalogue  -  Interface
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

#ifndef Catalogue_H
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeChainee.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet d'avoir une liste ordonnée de Trajets (Simples ou Composés)
// Liste ordonnée par ville de départ, puis ville d'arrivée
//------------------------------------------------------------------------

class Catalogue{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher() const;
    // Mode d'emploi :
    // Affiche le catalogue
    // Chaque trajet est nommé en fonction de son type et de sa position dans le catalogue A L'ETAT ACTUEL -> succeptible d'évoluer lors d'ajouts

    void AjouterTrajet(Trajet * const t);
    // Mode d'emploi :
    // t pointeur de trajet à ajouter

    void RechercheSimple(const char * depart, const char * arrivee) const;
    // Objectif :
    // Affiche le nombre de parcours possible (sans composition de trajets), et donne le nom des trajets
    // Mode d'emploi :
    // depart et arrive ville de départ et d'arrivée du parcours à rechercher
    // Recherche tous les trajets permettant de relier le départ à l'arrivée
    // Ne fait pas de composition de trajets
    // Contrat :
    // Longueur maximale des chaînes de caractère : 100 (101 en comptant le caractère '\0')

    void RechercheAvancee(const char * depart, const char * arrivee) const;
    // Objectif :
    // Affiche le nombre de parcours possible (avec compositions de trajets)
    // Mode d'emploi :
    // depart et arrive ville de départ et d'arrivée du parcours à rechercher
    // Recherche le nombre de trajets permettant de relier le départ à l'arrivée
    // Compte les parcours possibles par composition de trajets
    // Ne prends pas en compte les étapes intermédiaires d'un Trajet Compose
    // Contrat :
    // Longueur maximale des chaîne de caractères : 100 (101 en comptant le caractère '\0')

//-------------------------------------------- Constructeurs - destructeur

    Catalogue();

    virtual ~Catalogue();

//------------------------------------------------------------------ PRIVE

protected:


//---------------------------------------------------- Méthodes protégées
    int RechercheAvanceeCompte(const char * depart, const char * arrivee) const;
    // Mode d'emploi :
    // Retourne le nombre de parcours possibles reliant depart et arrive
    // Compte les compositions de plusieurs trajets
    // Ne prends pas en compte les étapes intermédiaires d'un Trajet Compose
    // Contrat :
    // Longueur maximale des chaîne de caractères : 100 (101 en comptant le caractère '\0')

//----------------------------------------------------- Attributs protégés
    ListeChainee listeCata;     // Liste des trajets du catalogue
    int nbTrajets;              // Nombre de trajets présents dans le catalogue

};

#endif // Catalogue_H
