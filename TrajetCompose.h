/*************************************************************************
                        TrajetCompose  -  Interface
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

#ifndef TrajetCompose_H
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeChainee.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Classe fille de Trajet
// Un trajet composé est un trajet composé de n trajets (ici réalisable seulement avec des trajets simples)
// La liste des trajets le composant est ordonnée dans l'ordre d'insertion
// Dans les trajets le composant, l'arrivée d'un trajet doit être égale au départ du suivant
//------------------------------------------------------------------------

class TrajetCompose : public Trajet{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Afficher() const;

    void Ajouter(Trajet * const ts);
    // Mode d'emploi :
    // ts pointeur vers le trajet à ajouter au trajet composé
    // Ajout en queue de liste
    // Contrat :
    // Le départ du trajet doit être identique à l'arrivée du dernier trajet déjà présent

    virtual bool isSimple() const;
    // Mode d'emploi :
    // S'applique directement sur le trajet
    // true : Trajet Simple ; false : Trajet Composé

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose();

    virtual ~TrajetCompose();

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    ListeChainee liste;

};

#endif // TrajetCompose_H
