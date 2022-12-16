/*************************************************************************
                        	Maillon  -  Interface
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

#ifndef Maillon_H
#define Maillon_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
// Maillon d'une liste chaînée de Trajet
// Contient un élément de type trajet, et un pointeur sur le maillon suivant de la liste
// Le pointeur vaut NULL si le Maillon est le dernier
//------------------------------------------------------------------------

class Maillon{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher() const;

	Trajet * getValeur() const;

	void setSuivant(Maillon * const s);

	Maillon * getSuivant() const;


//-------------------------------------------- Constructeurs - destructeur

	Maillon(Trajet * const v);
	// Mode d'emploi :
	// v pointe vers le trajet (simple ou composé) contenu dans le maillon

	virtual ~Maillon();
	// Mode d'emploi :
	// Détruit le maillon actuel, ainsi que tous les suivants

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
	Trajet * valeur;
	Maillon * suivant;

};

#endif // Maillon_H

