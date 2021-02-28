#include <iostream>
#include <cmath>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
    int doublon, NbAut;
    int poss;
    t_liste maBib;
    t_auteur_liste mesAut;
    maBib.nblm = 0;
    mesAut.NbAut = 0;
    int choix;
    void saisie_livre(t_auteur_liste & mesAut, t_liste & maBib, int maximum);
    void liste(t_liste maBib, t_auteur_liste mesAut);
    void liste_auteur(t_auteur_liste mesAut);
    void supp_livre(t_liste & maBib);
    int rech_livre(t_liste maBib);
    int ensemble(t_liste maBib);
    void afficheAuteur(t_auteur_liste mesAut, int i);

    do
    {
        cout << "Menu" << "\n" << "\n";
        cout << "1- Liste de livres" << "\n";
        cout << "2- Saisie d'un livre" << "\n";
        cout << "3- Supprimer un livre" << "\n";
        cout << "4- Recherche d'un livre" << "\n";
        cout << "5- Verification si la Bibliothèque est un ensemble" << "\n";
        cout << "6- Information d'un auteur" << "\n";
        cout << "7- Quitter" << "\n";
        cin >> choix;
        system("clear");

        switch (choix)
        {
        case 1:
            liste(maBib, mesAut);
            break;

        case 2:
            saisie_livre(mesAut, maBib, maximum);
            break;

        case 3:
            supp_livre(maBib);
            break;

        case 4:
            poss = rech_livre(maBib);
            if (poss >= 0) {
                cout << "livre rechercher : " << "\n";
                cout << "Livre " << poss + 1 << "\n";
                cout << "Titre : " << maBib.Biblio[poss].titre << "\n";
                cout << "L'auteur: " << maBib.Biblio[poss].id_auteur << "\n";
                cout << "Date parution : " << maBib.Biblio[poss].parution.jj << "/" << maBib.Biblio[poss].parution.mm << "/" << maBib.Biblio[poss].parution.aa << "\n";
                cout << "Nombre de page : " << maBib.Biblio[poss].nbpage << "\n";
                cout << "\n";
            }
            else
            {
                cout << "Aucun livre trouvé avec ce nom." << "\n";
            }
            break;

        case 5:
            doublon = ensemble(maBib);
            if (doublon = !- 1)
            {
                cout << "La bibliothèque n'est pas un ensemble" << "\n";
                cout << "Erreur sur la valeur du tableau Biblio : " << doublon << "\n";
            }
            else
            {
                cout << "La bibliothèque est bien un ensemble" << "\n";
            }
            break;
        case 6:
            cout << "Nom d'auteur par iD : " << "\n";
            liste_auteur(mesAut);
            cout << "iD de l'auteur : ";
            cin >> NbAut;
            cout << "\n";
            if (NbAut >= mesAut.NbAut) {
                afficheAuteur(mesAut, NbAut - 1);
            }
            break;
        case 7:
            system("clear");
            break;
        default:
            cout << "Erreur de saisie" << "\n";
        }
    } while (choix != 7);
    return(0);
}



void saisie_livre(t_auteur_liste& mesAut, t_liste& maBib, int maximum)
{
    void liste_auteur(t_auteur_liste mesAut);
    void saisieAut(t_auteur_liste & mesAut, int maximum, int& nb);
    void afficheAuteur(t_auteur_liste mesAut, int i);
    int nb, RAS, NumAut;
    RAS = 0;
    NumAut = -1;
    liste_auteur(mesAut);
    cout << "Entrer numéro auteur ou -1";
    cin >> nb;
    nb = nb - 1;
    if (nb == -2 || nb == -1)
    {
        saisieAut(mesAut, maximum, RAS);
        NumAut = RAS;
    }
    else
    {
        NumAut = nb;
    }
    if (RAS != -1)
    {
        maBib.Biblio[maBib.nblm].id_auteur = NumAut;
        cout << "Ajout du nouveau livre : " << "\n";
        cout << "Titre du livre : ";
        cin >> maBib.Biblio[maBib.nblm].titre;
        cout << "\n" << "Date de parution : ";
        do {

            checkBorne("Entrer le jour : ", 1, 31, maBib.Biblio[maBib.nblm].parution.jj);
            checkBorne("Entrer le mois : ", 1, 12, maBib.Biblio[maBib.nblm].parution.mm);
            checkBorne("Entrer le l'année : ", -2000, 9999, maBib.Biblio[maBib.nblm].parution.aa);
        } while (verifDate(maBib.Biblio[maBib.nblm].parution.jj, maBib.Biblio[maBib.nblm].parution.mm, maBib.Biblio[maBib.nblm].parution.aa) != true);
        cout << "\n" << "Nombre de Page : ";
        cin >> maBib.Biblio[maBib.nblm].nbpage;
        maBib.nblm++;
    }
    else
    {
        cout << " Bibliothèque ou auteur plein " << "\n";
        system("PAUSE");
    }
    system("cls");
}

void saisieAut(t_auteur_liste& mesAut, int maximum, int& nb)
{
    char deces;
    if (mesAut.NbAut == maximum)
    {
        nb = -1;
    }
    else
    {
        cout << "Nouveau Auteur : " << "\n";
        cout << "Nom : ";
        cin >> mesAut.Auteur[mesAut.NbAut].nom;
        cout << "\n" << "Prenom : ";
        cin >> mesAut.Auteur[mesAut.NbAut].prenom;
        cout << "\n" << "Nationalité : ";
        cin >> mesAut.Auteur[mesAut.NbAut].nationalite;
        do
        {
            cout << "Date de naissance : " << "\n";
            checkBorne("Entrer le jour : ", 1, 31, mesAut.Auteur[mesAut.NbAut].an_born.jj);
            checkBorne("Entrer le mois : ", 1, 12, mesAut.Auteur[mesAut.NbAut].an_born.mm);
            checkBorne("Entrer l'année : ", -2000, 9999, mesAut.Auteur[mesAut.NbAut].an_born.aa);
        } while (verifDate(mesAut.Auteur[mesAut.NbAut].an_born.jj, mesAut.Auteur[mesAut.NbAut].an_born.mm, mesAut.Auteur[mesAut.NbAut].an_born.aa) != true); //info boucle
        cout << "Il y a t'il une date de décès ? o/n :";
        cin >> deces;
        if (deces == 'o')
        {
            do
            {
                do
                {
                    cout << "Date de mort : " << "\n";
                    checkBorne("Entrer le jour : ", 1, 31, mesAut.Auteur[mesAut.NbAut].an_death.jj);
                    checkBorne("Entrer le mois : ", 1, 12, mesAut.Auteur[mesAut.NbAut].an_death.mm);
                    checkBorne("Entrer l'année : ", -2000, 9999, mesAut.Auteur[mesAut.NbAut].an_death.aa);
                } while (mesAut.Auteur[mesAut.NbAut].an_death.aa <= mesAut.Auteur[mesAut.NbAut].an_born.aa); //info boucle utilisateur
            } while (verifDate(mesAut.Auteur[mesAut.NbAut].an_death.jj, mesAut.Auteur[mesAut.NbAut].an_death.mm, mesAut.Auteur[mesAut.NbAut].an_death.aa) != true); //info boucle
        }
        else
        {
            mesAut.Auteur[mesAut.NbAut].an_death.jj = NULL;
            mesAut.Auteur[mesAut.NbAut].an_death.jj = NULL;
            mesAut.Auteur[mesAut.NbAut].an_death.jj = NULL;
        }
        nb = mesAut.NbAut;
        mesAut.NbAut = mesAut.NbAut + 1;
    }
}

void liste(t_liste maBib, t_auteur_liste mesAut)
{
    for (int i = 0; i <= maBib.nblm - 1; i++)
    {
        cout << "Livre " << i + 1 << "\n";
        cout << "Titre : " << maBib.Biblio[i].titre << "\n";
        cout << "Auteur Id: " << maBib.Biblio[i].id_auteur + 1 << "\n";
        cout << "Date parution : " << maBib.Biblio[i].parution.jj << "/" << maBib.Biblio[i].parution.mm << "/" << maBib.Biblio[i].parution.aa << "\n";
        cout << "Nombre de page : " << maBib.Biblio[i].nbpage << "\n";
        cout << "\n";
    }
}

void liste_auteur(t_auteur_liste mesAut)
{
    for (int i = 0; i <= mesAut.NbAut - 1; i++)
    {
        cout << "iD : " << i + 1 << "\n";
        cout << "Nom : " << mesAut.Auteur[i].nom << "\n";
    }
}


void supp_livre(t_liste& maBib)
{
    int ind = 0;
    int rech_livre(t_liste maBib);

    ind = rech_livre(maBib);
    if (ind == -1)
    {
        cout << "Suppression impossible, élément non trouvé";
    }
    else
    {
        maBib.Biblio[ind].titre = maBib.Biblio[maBib.nblm].titre;
        maBib.nblm = maBib.nblm - 1;
        cout << "Livre supprimé";

    }
}

int rech_livre(t_liste maBib)
{
    int poss, i;
    string titre_rech;
    string maj1;
    string maj2;
    i = 0;
    poss = 0;
    string majuscule(string nom);
    cout << "Titre du livre rechercher : ";
    cin >> titre_rech;
    maj1 = majuscule(titre_rech);
    maj2 = majuscule(maBib.Biblio[i].titre);
    while ((i <= maBib.nblm) && maj2.compare(maj1) != 0)
    {
        i = i + 1;
    }

    if (maj2.compare(maj1) == 0)
    {
        poss = i;
    }
    else
    {
        poss = -1;
    }
    return(poss);
}

string majuscule(string nom)
{
    int i, longueur;
    longueur = nom.size();
    for (i = 0; i <= longueur - 1; i = i + 1)
    {
        if (nom[i] >= 'a')
        {
            nom[i] = nom[i] + 'A' - 'a';
        }
    }
    return(nom);
}

int ensemble(t_liste maBib)
{
    int i, j, pasdoublon;
    bool test;

    pasdoublon = -1;
    test = 0;
    j = 0;
    i = 0;
    do
    {
        if (majuscule(maBib.Biblio[j].titre) != majuscule(maBib.Biblio[i].titre))
        {
            test = 1;
            pasdoublon = i;
            i = i + 1;
            if (i == maBib.nblm)
            {
                j = j + 1;
                i = j;
            }
        }
        else
        {
            test = 1;
            pasdoublon = i;
        }

    } while (test != 1 && j < maBib.nblm);
    return pasdoublon;
}

void afficheAuteur(t_auteur_liste mesAut, int i) {
    cout << "Info de l'auteur : ";
    cout << "Id : " << i + 1 << "\n";
    cout << "Nom : " << mesAut.Auteur[i].nom << "\n";
    cout << "Prenom : " << mesAut.Auteur[i].prenom << "\n";
    cout << "Nationalité : " << mesAut.Auteur[i].nationalite << "\n";
    cout << "Date de naissance : " << mesAut.Auteur[i].an_born.jj << "/" << mesAut.Auteur[i].an_born.mm << "/" << mesAut.Auteur[i].an_born.aa << "\n";
    if (mesAut.Auteur[i].an_death.jj != NULL)
    {
        cout << "Date de mort : " <<
            mesAut.Auteur[i].an_death.jj << "/" << mesAut.Auteur[i].an_death.mm << "/" << mesAut.Auteur[i].an_death.aa;
    }
    else
    {
        cout << "Toujours en vie." << "/n";
    }
}
