/*************************************************************************
                        ListeChainee  -  Interface
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

#ifndef ListeChainee_H
#define ListeChainee_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Maillon.h"

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// Permet de construire une liste chaînée de trajets
// Pointe sur un premier maillon, qui pointe vers le suivant etc.
// Le dernier maillon a un pointeur NULL
//------------------------------------------------------------------------

class ListeChainee{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode(liste des paramètres);
    // Mode d'emploi :
    //
    // Contrat :
    //


    void Ajouter(Trajet * const t);
    // Mode d'emploi :
    // Ajouter trajet t a la fin de la liste

    void AjouterTrie(Trajet * const t);
    // Mode d'emploi :
    // Ajouter trajet t a la liste de manière triée
    // Tri par ville de départ, puis ville d'arrivée (arrivée finale pour les trajets composés)
    // En cas de ville de départ et d'arrivée identique, le trajet est inséré après celui existant

    Maillon * getHead() const;

//-------------------------------------------- Constructeurs - destructeur

    ListeChainee();

    virtual ~ListeChainee();


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Maillon * head;
    Maillon * end;

};

//-------------------------------- Autres définitions dépendantes de <ListeChainee>

#endif // ListeChainee_H

