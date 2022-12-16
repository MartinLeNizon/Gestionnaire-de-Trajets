/*************************************************************************
                        			main
                             -------------------
    début                : 25 novembre
    copyright            : (C) 2022 par Aziza Ballahbib & Martin Nizon-Deladoeuille
    e-mails               : aziza.bellahbib@insa-lyon.fr ; martin.nizon-deladoeuille@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Maillon.h"
#include "ListeChainee.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

//------------------------------------------------------------- Constantes
#ifndef MAX_MOTS
#define MAX_MOTS 100
#endif

//----------------------------------------------------- Variables globales
Catalogue * c = new Catalogue();			// Variable globale -> Utilisable dans chaque méthode sans avoir à la passer en paramètre
											// Variable principale, à laquelle toute l'application gravite autour

//--------------------------------------------------------------- Méthodes

void afficherModeEmploi()
// Afficher le mode d'emploi
{
    cout << endl << "_____________________________________________" << endl;
    cout << "--------------- Mode d'emploi ---------------" << endl;
    cout << "Les villes contiennent au plus 100 caractères" << endl;
    cout << "Les espaces ne sont pas tolérés dans les noms des villes et moyens de transport" << endl;
    cout << "Toute erreur de saisie provoquera la fermeture de l'application" << endl;
}

int MenuPrincipal()
// Affiche le menu principal et retourne la sélection de l'utilisateur
{
    int choix;
    cout << endl << "_____________________________________________" << endl;
    cout << "----- Menu de manipulation du catalogue -----" << endl;
    cout << "1 : Affichage du catalogue" << endl;
    cout << "2 : Ajouter un trajet au catalogue" << endl;
    cout << "3 : Recherche de parcours" << endl;
    cout << "0 : Quitter" << endl << endl;
    cout << "Choix: ";
    cin >> choix;
    cout << endl;
    return choix;
}

void AjouterTrajetMenu()
// Menu d'ajout d'un trajet au catalogue
// Gère insertion trajets simples ou composés
// Fait appel aux méthodes du catalogue
{
	int choix;
    cout << "________________________________________" << endl;
    cout << "----- Menu de création d'un trajet -----" << endl;
    cout << "1 : Ajouter un trajet simple" << endl;
    cout << "2 : Ajouter un trajet composé" << endl;
    cout << "0 : Retourner au menu principal" << endl;
    cin >> choix;
    cout << endl;

	// Permet d'enregistrer les entrées de l'utilisateur pour les passer en paramètres des fonctions du catalogue
	char * depart = new char[MAX_MOTS+1];
	char * arrivee = new char[MAX_MOTS+1];
	char * transport = new char[MAX_MOTS+1];
	int nbTrajetsSimples;
	TrajetCompose *  tc = new TrajetCompose();

    switch(choix){
    	case 1:
    		delete tc;
		    cout << "_______________________________________" << endl;
		    cout << "----- Création d'un trajet simple -----" << endl;
    		cout << "Ville de départ : " << endl;
    		cin >> depart;
    		cout << "Ville d'arrivée : " << endl;
    		cin >> arrivee;
    		cout << "Moyen de transport : " << endl;
    		cin >> transport;
    		cout << endl;
    		c->AjouterTrajet(new TrajetSimple(depart, arrivee, transport));
    		cout << "Trajet ajouté" << endl;
    		break;
    	case 2:
		    cout << "________________________________________" << endl;
		    cout << "----- Création d'un trajet composé -----" << endl;
		    cout << "Nombre de trajets simples composants le trajet composé : " << endl;
		    cin >> nbTrajetsSimples;
		    cout << endl;
		    for(int i=1; i<=nbTrajetsSimples; i++){
		    	cout << "Trajet simple " << i << "/" << nbTrajetsSimples << endl;
		    	do{
			    	cout << "Ville de départ : " << endl;
		    		cin >> depart;
		    	}
		    	// Vérifie ville de départ correspond à l'arrivée du trajet précédent
		    	while(i>1 && strcmp(depart, arrivee)!=0 && cout << "La ville de départ doit être identique à la ville d'arrivée du trajet simple précédent" << endl);
	    		cout << "Ville d'arrivée : " << endl;
	    		cin >> arrivee;
	    		cout << "Moyen de transport : " << endl;
	    		cin >> transport;
	    		cout << endl;
		    	tc->Ajouter(new TrajetSimple(depart, arrivee, transport));
		    }
    		c->AjouterTrajet(tc);
    		cout << "Trajet composé ajouté" << endl;
    		break;
    	default:
    		delete tc;
    }

    // Libération mémoire des enregistrement des entrées de l'utilisateur
	delete [] depart;
	delete [] arrivee;
	delete [] transport;
}

void AfficherCatalogue()
// Affichage catalogue
{
	c->Afficher();
}

void RechercheTrajetMenu()
// Menu de recherche d'un trajet
// Fait appel aux méthodes du catalogue
{
	int typeRecherche;
    cout << "_____________________________________________" << endl;
    cout << "----- Menu de recherche d'un itinéraire -----" << endl;
   	cout << "1 : Recherche Simple" << endl;
   	cout << "2 : Recherche Avancée" << endl;
   	cout << "0 : Retourner au menu principal" << endl;
	cin >> typeRecherche;

	// Permet d'enregistrer les entrées de l'utilisateur pour les passer en paramètres des fonctions du catalogue
	char * depart = new char[50];
	char * arrivee = new char[50];
	switch(typeRecherche){
		case 1:
			cout << endl << "Ville de départ : " << endl;
			cin >> depart;
			cout << "Ville d'arrivée : " << endl;
			cin >> arrivee;
			c->RechercheSimple(depart, arrivee);
			break;
		case 2:
			cout << endl << "Ville de départ : " << endl;
			cin >> depart;
			cout << "Ville d'arrivée : " << endl;
			cin >> arrivee;
			c->RechercheAvancee(depart, arrivee);
			break;
		default:
			cout << "Retour au menu principal" << endl;
			return;
	}

	// Libération mémoire
	delete [] depart;
	delete [] arrivee;
}

//------------------------------------------------------------------- Main
int main(){

	afficherModeEmploi();					// Affichage mode d'emploi

	int choix;

    while(true){
    	choix = MenuPrincipal();			// choix de l'utilisateur
    	switch(choix){
	    case 1:
	    	AfficherCatalogue();
	        break;
	    case 2:
	    	AjouterTrajetMenu();
	        break;
	    case 3:
	    	RechercheTrajetMenu();
	        break;
	    default:
	    	// Fermeture de l'application dès qu'entrée incorrecte
	        cout << endl << "Fermeture de l'application" << endl;
	        delete c;
	        return 0;
		}
    }

    delete c;								// Libération mémoire du catalogue
	return 0;
}
