#include <iostream>
#include <string>
using namespace std;

const int maximum = 100;
typedef struct
{
	int aa;
	int mm;
	int jj;
}t_date;

typedef struct
{
	string nom;
	string prenom;
	string nationalite;
	t_date an_born;
	t_date an_death;

}t_auteur;

typedef struct
{
	string titre;
	int id_auteur;
	t_date parution;
	int nbpage;
}t_livre;

typedef struct
{
	t_auteur Auteur[maximum];
	int NbAut;
}t_auteur_liste;

typedef struct
{
	t_livre Biblio[maximum];
	int nblm;
}t_liste;
#pragma once

void boolDate(int jour, int mois, int annee, bool& bisextile, bool& mois30, bool& fevrier)
{
	if ((mois == 4) || (mois == 6) || (mois == 9) || (mois == 11)) 
	{
		mois30 = true;
	}
	else {
		mois30 = false;
	}

	if (((annee % 4 == 0) && (annee % 100 != 0)) || (annee % 400 == 0))
	{
		bisextile = true;
	}
	else {
		bisextile = false;
	}

	if (mois == 2) 
	{
		fevrier = true;
	}
	else {
		fevrier = false;
	}
}

bool verifDate(int jour, int mois, int annee)
{
	bool bisextile, mois30, fevrier, valide;
	void boolDate(int jour, int mois, int annee, bool& bisextile, bool& mois30, bool& fevrier);

	boolDate(jour, mois, annee, bisextile, mois30, fevrier);

	if (((mois == 2) && (jour >= 29) && (bisextile == false)) || ((mois == 2) && (jour >= 30) && (bisextile == true)) || ((mois30 == true) && (jour == 31))) // cas dans lesquels la date est valide
	{
		valide = false;
	}
	else {
		valide = true;
	}
	return(valide);
}


void checkBorne(string message, int borneinf, int bornesup, int& valeur)
{
	cout << message; 
	cin >> valeur; 

	while ((valeur < borneinf) || (valeur > bornesup))
	{ 
		cout << "Erreur, la valeur entre " << borneinf << " et " << bornesup << ".";
		cout << message;
		cin >> valeur;
	}
}

void saisie(liste maBib[MAX], int maxelem)
{
	if (maBib.nbelem < maxelem)
	{
		cin >> maBib.biblio[nb].titre;
		cin >> maBib.biblio[nb].nom;
		cin >> maBib.biblio[nb].an;
		cin >> maBib.biblio[nb].nbpage;
		maBib.nbelem = maBib.nbelem + 1;
	}
	else {
		cout << "Bibliothèque pleine.";
	}
}

void recherche(liste maBib[MAX]) return int
{
	int pos;
	string titre_rech;
	int i;
    i = 0;
	cin >> titre_rech;
	
	while ((i < maBib.nbelem) && (majuscule(maBib.biblio[i].titre) != majuscule(titre_rech)))
	{
		i = i + 1;
	}

	if ((majuscule(maBib.biblio[i].titre) == majuscule(titre_rech)))
	{
		pos = i;
	}
	else {
		pos = -1;
	}

return pos;
}

void ensemble(liste maBib[MAX]) return int
{
	int i, j, pasdedoublon;
	bool test;
	pasdedoublon = -1;
	test = 0;
	j = 0;
	i = 0;

	do
	{
		if (majuscule(maBib.biblio[j]) == majuscule(maBib.biblio[i]))
		{
			test = 1;
			pasdedoublon = -1;
		}
		else {
			i = i + 1;
		}

		if (i == maBib.nbelem)
		{
			i = j + 1;
		}
		
	} while (test != 1 && j < maBib.nbelem);
	return pasdedoublon;
}

void affichageLivre(livre monLivre)
{
	cout << "Titre : " << monLivre.titre << endl;
	cout << "Nom : " << monLivre.nom << endl;
	cout << "An : " << monLivre.an << endl;
	cout < "Nombre de pages : " << monLivre.nbpage << endl;
}

void affichage(liste maBib[MAX])
{
	int i;

	for (int i = 0; i < maBib.nbelem - 1; ++i)
	{
		cout << maBib.biblio[nb].titre;
		cout << maBib.biblio[nb].nom;
		cout << maBib.biblio[nb].an;
		cout << maBib.biblio[nb].nbpage;
	}
}

void supression(liste maBib[MAX])
{
	int ind;
	void recherche(liste maBib[MAX]) return int;

	ind = recherche(maBib)
		if (ind == -1)
		{
			cout << "Élément non trouvé."
		}
		else {
			maBib[ind].titre = maBib[ind - 1].titre;
			maBib[ind].nom = maBib[ind - 1].nom;
			maBib[ind].an = maBib[ind - 1].an;
			maBib[ind].nbpage = maBib[ind - 1].nbpage;
			nb = nb - 1;
		}
}




