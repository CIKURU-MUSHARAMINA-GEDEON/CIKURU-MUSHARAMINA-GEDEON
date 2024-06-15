#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
// definition des mots cles
#define ENTER 13
#define TAB 9
#define BKSP 8
// LES FONCTIONS QUI CONCERNENT LE PROJET CAD LES FONCTIONS PRINCIPALES
void motdepasse(void);
void menu(void);
void partieutilisateur(void);
void partielivre(void);
void endScreen(void);
// LES FONCTIONS QUI CONCERNENT L'UTILISATEUR
void ajouterutlisateur(void); // CETTE FONCTION NOUS PERMET D'AJOUTER UN UTILISATEUR
void modifierutilisateur(void);// CETTE FONCTION NOUS PERMET DE MODIFIER UN UTILSATEUR
void listerutlisateur(void);// CELLE NOUS PERMET DE LISTER TOUS LES UTILISATEURS
int rechercheutilisateur(int);
void rentList(void);
void supprimerutlisateur(void);

// ces fonctions concernent la gestion de livre
void ajouterlivre(void);
int modifierlivre(int);
void listelivre(void);
void rentBook(void);
int searchBook(int);
void supprimerlivre(void);

// LA FONCTION MAIN
void main(){
    motdepasse();
}
// fonctios des systeme
    int terminateurpassage = 1;
    int bookStock = 0;
    char rentName[255], nomlivre[255];
// la structure de saisir le mot de passe valide 5 fois.
void motdepasse(){

    system("cls");
    fflush(stdin);

    char pwd[255];
    char code[255] = {"123456789"};
    int i = 0;
	char ch;

    printf("--------------------\n");
    printf(">>> BIENVENUE !!!! <<\n");
    printf("--------------------\n\n");

	printf("Entrer ton mot de passe.puis confirmer en tapant sur la touche enter \n");
	printf("Mot de passe");

	while(1)
    {
		ch = getch(); // Obtenir la cle
		if(ch == ENTER || ch == TAB)
        {
			pwd[i] = '\0';
			break;
		}
        else if(ch == BKSP)
        {
			if(i > 0)
            {
				i--;
				printf("\b \b"); // pour le retour en arriere
			}
		}
        else
        {
			pwd[i++] = ch;
			printf("* \b");	// pour remplace le caractere de mot de passe par*
		}
	}
    fflush(stdin);
    // verifié le mot de passe
    if(strcmp(code, pwd) == 0)
    {
        printf("\nmot de passe correct!");
        Sleep(2000);
        menu();
    }
    else
    {
        printf("\nmot de passe invalide");
        (terminateurpassage == 5) ? exit(0) : terminateurpassage++;
        Sleep(2000);
        motdepasse();
    }
}
// Main Selection menu between User & Book Panel
void menu(){
    system("cls");
    fflush(stdin);
    int number;
    printf("=========================================\n");
    printf(">>> GESTION DE BIBLIOTHEQUE KINGAKATI <<< \n");
    printf("==========================================\n\n");
    printf("> 1. paneau de gestion des utilisateurs  \n");
    printf("> 2. paneau de gestion des livres \n\n");
    printf("> Entrez le numero & appuyez sur ENTREE: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            partieutilisateur();
            break;
        case 2:
            partielivre();
            break;
        default:
            printf("\n>>> Mauvais choix! <<<");
            Sleep(2000);
            menu();
    }
}
// SOUS FONCTION DU PENNEAU UTILISATEUR
void partieutilisateur(){

    system("cls");
    fflush(stdin);
    int number;
    printf("***********************************************\n");
    printf(">>> PARTIE MANAGER BIBLIOTHECAIRE <<< \n");
    printf("***********************************************\n\n");
    printf("> 1. Ajouter un utilisateur \n");
    printf("> 2. Modifier un utilisateur \n");
    printf("> 3. Lister tous les utilisateurs \n");
    printf("> 4. Listes emprunts \n");
    printf("> 5. Rechercher un utilisateur \n");
    printf("> 6. Supprimer un utilisateur\n");
    printf("> 7. ouvrir le Menu principal \n");
    printf("> 8. Quitter le programme.. \n\n");

    printf("> Entrer votre choix,puis confirmez-le en appuyant sur la touche enter: ");
    scanf("%d",&number);
    fflush(stdin);
    switch(number)
    {
        case 1:
            ajouterutlisateur();
            break;
        case 2:
            modifierutilisateur();
            break;
        case 3:
            listerutlisateur();
            break;
        case 4:
            rentList();
            break;
        case 5:
            rechercheutilisateur(0);
            break;
        case 6:
            supprimerutlisateur();
            break;
        case 7:
            menu();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("Mauvais choix");
            Sleep(2000);
            partieutilisateur();
    }
}
// NOUS APPELONS LA FONCTION PARTIELIVRE EN LA DONNANT DES VALEURS
void partielivre(){

    system("cls");
    fflush(stdin);

    int number;

    printf("-----------------------------------------------\n");
    printf(">>> panneau de livre du systeme de gestion de bibliotheque <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Ajouter un livre \n");
    printf("> 2. modifier le livre\n");
    printf("> 3. Liste du livre \n");
    printf("> 4.Emprunter un livre  \n");
    printf("> 5. Rechercher un  livre \n");
    printf("> 6. Supprimer un livre\n");
    printf("> 7. Ouvrez le menu principal \n");
    printf("> 8. Fermez le programme... \n");

    printf("\nEntrez le numero & appuyez sur entree: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            ajouterlivre();
            break;
        case 2:
            modifierlivre(0);
            break;
        case 3:
            listelivre();
            break;
        case 4:
            rentBook();
            break;
        case 5:
            searchBook(0);
            break;
        case 6:
            supprimerlivre();
            break;
        case 7:
            menu();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("Entree invalide!");
            Sleep(2000);
            partielivre();
    }
}
// Ecran de credit de fin du programme
void endScreen(){

    system("cls");
    fflush(stdin);
    printf("----------------------------------------------\n");
    printf(">>> CE PROJET A ETE REALISE PAR: <<< \n");
    printf("----------------------------------------------\n\n");

    printf("> CIKURU MUSHARAMINA GEDEON\n");
    printf("> DIBWE GEORGE STEPHANE\n");
    printf("> DIMUMBE KITENGE MARDORCHEE\n");
    printf("> DJUMA MUSSA RODRIGUE\n\n");
    exit(0);
}
// Fonctions utilisateur
// Cree un nouveau fichier si l'ancien fichier n'existe pas et enregistre les enregistrements utilisateur dans le tableau
void ajouterutlisateur(){
label1:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255];
    char gender;
    double sid, phone, balance;

    FILE *pF = fopen("user_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Entrer ton nom: ");
        gets(fname) ;

        printf("Entrer ton prenom: ");
        gets(lname);

        printf("choisi ton sexe [M/F]: ");
        scanf("%c",&gender);

        printf("entrer ton matricule ou tonID: ");
        scanf("%lf",&sid);

        printf("Entrer ton numero de telephone: ");
        scanf("%lf",&phone);

        fprintf(pF, "%s %s %c %.0lf %.0lf \n", fname, lname, gender, sid, phone);

        printf("\n>>> vous etes abonne ou ajoute <<< \n");
    }
    else
    {
        printf("Impossible d'ouvrir/localiser le fichier.");
    }

    fclose(pF);

    fflush(stdin);

    //ecran de nouvelle tentative
    char input;
    printf("\n Voulez-vous saisir plus d'enregistrements ");
    scanf("%c",&input);
    if(input == 'y' || input=='Y')
    {
        goto label1;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nRedirection vers le panneau  utilisateur.");
        Sleep(2000);
        partieutilisateur();
    }
    else
    {
        printf("\nEntree invalide.Redirection vers le panneau utilisateur.");
        Sleep(2000);
        partieutilisateur();
    }
}
// Modifie les details de l'utilisateur et les enregistre
void modifierutilisateur(){
    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;
    char find[255];
    printf("Entrez le nom de la personne que tu veux modifier ainsi que certains details: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Enregistrement trouve, autorisant les modifications<<<\n");
            printf("-----------------------------------------------\n\n");

            printf("> Entrer ton nom: ");
            gets(fname1);

            printf("> Entrez votre prenom: ");
            gets(lname1);

            printf("> Entrez votre sexe: ");
            gets(gender1);

            printf("> Entrez le ID OU le matricule: ");
            scanf("%lf",&sid1);

            printf("> Entrez votre numero telephone ");
            scanf("%lf",&phone1);

            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname1, lname1, gender1, sid1, phone1);
            printf("\n\nTraitement de  modifications....");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Enregistrement introuvable<<<\n");
        printf("-------------------------------\n\n");
        printf("Redirection vers le panneau utilisateur...");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    partieutilisateur();

}

// repertoire de tous les enregistrements
void listerutlisateur(){

    system("cls");
    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");

    char fname[255], lname[255], gender[5];
    double sid, phone;
    int counter=0;

    printf("-------------------------------\n");
    printf(">>> Liste des utilisateurs enregistre<<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
       strcat(fname, " ");
       strcat(fname, lname);

        printf("-------------------------------\n");
        printf("> Nom complet: %s \n", fname);
        printf("> sexe: %s \n", gender);
        printf("> ID etudiant: %.0lf \n", sid);
        printf("> numero telephone.: %.0lf \n", phone);
        printf("-------------------------------\n\n\n");

        counter++;
    }
    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("aucun enregistrement utilisateur n'a encore ete ajoute...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Appuyez sur n'importe quelle touche pour revenir au penneau utilisateur.\n");
    getch();
    partieutilisateur();
}

// cela verfie si l'utilisateur speficie existe ou non dans les enregistrements
int rechercheutilisateur(int nameSearcher){

label2:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    double sid, phone;

    int flag=0;
    int compare;
    char find[255];
    (nameSearcher != 3) ? printf("Recherche par le nom de l'eleve: ") : printf(":Recherche par le nom de l'etudian qui souhqite louer le livre ");
    gets(find);

    FILE *pF = fopen("user_Records.txt", "r");

     while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);

        if(compare == 0)
        {
            if(nameSearcher != 3)
            {
                strcat(fname, " ");
                strcat(fname, lname);

                printf("\n---------------------\n");
                printf(">>> enregistrement trouve <<< \n");
                printf("---------------------\n\n");

                printf("-------------------------------\n");
                printf("> Nom complet: %s \n", fname);
                printf("> sexe: %s \n", gender);
                printf("> ID etudiant: %.0lf \n", sid);
                printf("> Numero de telephone: %.0lf \n", phone);
                printf("-------------------------------\n\n");

            }
            strcpy(rentName, fname);
            flag=1;
        }
    }
    fclose(pF);

    if(flag == 0)
    {
        printf("\n>>> enregistrement introuvable <<< \n\n");
    }
    fflush(stdin);

    if(nameSearcher != 3)
    {
        printf("Appuyez sur n'importe quelle touche pour revenir au panneau.");
        getch();
        partieutilisateur();
    }
    else if(nameSearcher == 3 && flag == 1)
    {
        return 5;
    }
}

// supprime les informations utilisateur du fichier
void supprimerutlisateur(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    printf("Entrez le nom de la personne dont vous souhaitez supprimer les details: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Enregistrement supprime <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirection vers le panneau  utilisaateur...");


            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Enregistrement introuvable<<<\n");
        printf("-------------------------------\n\n");
        printf("Redirection vers le panneau utilisateur..");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    partieutilisateur();
}
// FONCTIONS DU LIVRE
void ajouterlivre(){

label3:

    system("cls");
    fflush(stdin);

    char nom[255], auteur[255], editeur[255];
    double bookid, quantite;

    FILE *pF = fopen("book_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Entrez le nom du livre: ");
        gets(nom);

        printf("Entrez l'auteur du livre: ");
        gets(auteur);

        printf("Enter l'editeur du livre: ");
        gets(editeur);

        fflush(stdin);

        printf("Enter L'ID du livre : ");
        scanf("%lf",&bookid);

        printf("Entrez la qualite du livre : ");
        scanf("%lf",&quantite);

        fprintf(pF, "%s %s %s %.0lf %.0lf \n", nom, auteur, editeur, bookid, quantite);

        printf("\n>>> Enregistrement du livre ajoutee avec succes <<< \n");
    }
    else
    {
        printf("impossible d'ouvrir/localiser le fichier.");
    }

    fclose(pF);

    fflush(stdin);

    char input;
    printf("\nVoulez-vous saisir plus d'enregistrements: ");
    scanf("%c",&input);

    if(input == 'O' || input=='o')
    {
        goto label3;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nredirection vers le panneau livre.");
        Sleep(2000);
        partielivre();
    }
    else
    {
        printf("\nEntree non valide. redirection vres le panneau de lecture.");
        Sleep(2000);
        partielivre();
    }
}
// modifier les details du livre selon vous et enregistrer a nouveau
int modifierlivre(int rentModifier){
    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;

    int flag=0;
    int compare;
    char find[255];
    if (rentModifier != 5)
    {
        printf("Entrez le nom du livre dont vous souhaitez voir le detail: ");
        gets(find);
        fflush(stdin);
    }
    else
    {
        strcpy(find, nomlivre);
    }
    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);

        if(compare == 0)
        {
            if(rentModifier != 5)
            {
                printf("\n---------------------------------------------\n");
                printf(">>> Enregistrement trouve, permettant les modifications <<<\n");
                printf("-----------------------------------------------\n\n");

                printf("> Entrez le nom du livre: ");
                gets(name1);

                printf("> Entrez l'auteur: ");
                gets(author1);

                printf("> Entrez editeur: ");
                gets(publisher1);

                fflush(stdin);

                printf("> Entrez le ID livre: ");
                scanf("%lf",&bookid1);

                printf("> Entrez la quantite: ");
                scanf("%lf",&quantity1);

                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name1, author1, publisher1, bookid1, quantity1);
                printf("\n\ntraitement vos modifications....");
            }
            else
            {
                quantity = bookStock;
                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
            }
            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }

    fclose(pF);
    fclose(pT);
    fflush(stdin);
    pF = fopen("book_Records.txt", "w");
    fclose(pF);
    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Enregistrement introuvable <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirection vres le panneau livre...");
    }

    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    if(rentModifier != 5)
    {
        Sleep(2000);
        partielivre();
    }
}

// repertorie tous les enregistrements du livre du fichier records
void listelivre(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double quantity, bookid;
    int counter=0;

    FILE *pF = fopen("book_Records.txt", "r");

    printf("-------------------------------\n");
    printf(">>> Liste des enregistrements de livres<<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        printf("-------------------------------\n");
        printf("> Nom: %s \n", name);
        printf("> auteur: %s \n", author);
        printf("> Editeur: %s\n", publisher);
        printf("> ID livre: %.0lf \n", bookid);
        printf("> Quantite: %.0lf \n", quantity);
        printf("-------------------------------\n\n\n");
        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("Aucune notice de livre n'a encore  ete ajoutee...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Appuyez sur n'importe quelle touche pour revenir au panneau livre.\n");
    getch();
    partielivre();
}
/* cette fonction verficie si l'utilisateur est deja enregistre dans le fichier mac records puis li verficie si le livre existe dans le stock
enfin ca envo un message d'erreur si le livre est en rupture de stock
*/
void rentBook(){

    int terminator=1, nameFound, bookFound;

label5:

    fflush(stdin);

    // permet a verficie si l'utilisateur existe
    nameFound = rechercheutilisateur(3);

    if(nameFound != 5 && terminator != 4)
    {
        printf("appuyez sur n'importe quelle touche pour saisir a nouveau le nom \n");
        getch();
        (terminator == 3) ? partielivre() : terminator++;
        goto label5;
    }
    else if(nameFound == 5)
    {
        printf("\nUtilisateur dans les enregistrements... \n veuillez patienter");
        terminator = 1;
        Sleep(2000);
    }

label6:

    fflush(stdin);

    // choisir les livres existants
    bookFound = searchBook(3);

    if(bookFound != 5 && terminator != 4)
    {
        printf("appuyez sur n'importe quelle touche pour saiair a nouveau le nom. \n");
        getch();
        (terminator == 3) ? partielivre() : terminator++;
        goto label6;
    }
    else if(bookFound == 5)
    {
        // cette partie nous permet de verficier si la quqntite des livres > 0
        if(bookStock > 0)
        {
            printf("\nlivre trouve et en stock\n...\n");
        }
        else
        {
            printf("\ndesole, en rupture de stock \nveuillez patienter... ");
            Sleep(2000);
            (terminator == 3) ? partielivre() : terminator++;
            goto label6;
        }
    }

    fflush(stdin);

    if(nameFound == 5 && bookFound == 5)
    {
        // Ajout d'un enregistrement dans
        FILE *pF = fopen("rent_Records.txt", "ab+");

        if(pF != NULL)
        {
            fprintf(pF, "%s %s \n", rentName, nomlivre);
        }
        else
        {
            printf("impossible d'ouvrir/locoliser le fichier.");
        }
        fclose(pF);
        // reduction de la quantite de livre 1
        bookStock--;
        modifierlivre(5);
        printf("---------------------------------------------\n");
        printf(">>> Enregistrement de loyer ajoute avec succes <<< \n");
        printf("---------------------------------------------\n");

        printf("\nRedirection vers le panneau livre...\n");
        Sleep(3500);
        partielivre();
    }
}
// repertorie tous les noms de dechets et de bask qui sont loues a quelqu'un dans lle fichiers enregistres
void rentList(){

    system("cls");
    fflush(stdin);

    char rentListUser[255], rentListBook[255];
    int counter = 0;

    FILE *pF = fopen("rent_Records.txt", "r");
    printf("-------------------------------\n");
    printf(">>> Liste des livres en location <<< \n");
    printf("-------------------------------\n\n");
    while(fscanf(pF, "%s %s \n", rentListUser, rentListBook) != EOF)
    {
        printf("> Louer un utilisateur: %s \n", rentListUser);
        printf("> Louer un()des livres(s): %s \n\n", rentListBook);

        counter++;
    }
    fclose(pF);
    fflush(stdin);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("Aucun enregistrement de loyer n'a encore ete ajoute...\n");
        printf("--------------------------------------\n\n");
    }

    printf("\nAppuyez sur n'importe quellle touche pour revenir au panneau utilisateur.\n");
    getch();
    partieutilisateur();
}

// recherche les details du livre  par nom dans le fichier
int searchBook(int bookSearcher){

label4:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;
    int flag=0;
    int compare;
    char find[255];
    (bookSearcher != 3) ? printf("Recherchez le livre par  nom d'auteur ou par nom livre: ") : printf("Definissez le livre par nom d'auteur ou noms de livre: ");
    gets(find);

    FILE *pF = fopen("book_Records.txt", "r");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        compare = strcmp(find, author);
        if(compare == 0)
        {
            if(bookSearcher != 3)
            {
                printf("\n-------------------------\n");
                printf(">>> Enregistrement trouve <<< \n");
                printf("-------------------------\n\n");
                printf("-------------------------------\n");
                printf("> Nom livre: %s \n", name);
                printf("> Auteur: %s \n", author);
                printf("> editeur: %s\n", publisher);
                printf("> Id livre: %.0lf \n", bookid);
                printf("> Quantite: %.0lf \n", quantity);
                printf("-------------------------------\n\n");
            }
            strcpy(nomlivre, name);
            bookStock = quantity;
            flag=1;
        }
    }
    fclose(pF);
    fflush(stdin);
    if(flag == 0)
    {
        printf("\n>>> Enregistrement introuvable <<< \n\n");
    }
    if(bookSearcher != 3)
    {
        printf("Appuyez sur n'importe quelle touche pour rediriger vers le panneau de lecture.");
        getch();
        partielivre();
    }
    else if(bookSearcher == 3 && flag == 1)
    {
        return 5;
    }
}
// supprime les enregistrement du livre
void supprimerlivre(){
    system("cls");
    fflush(stdin);
    char name[255], author[255], publisher[255];
    double bookid, quantity;
    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;
    int flag=0;
    int compare;
    char find[255];
    printf("Entrez le nom du livre dont vous sohaitez supprimer le detail: ");
    gets(find);
    fflush(stdin);
    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");
    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Enregistrement supprime <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirection vers le panneau livre...");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }
    fclose(pF);
    fclose(pT);
    fflush(stdin);
    pF = fopen("book_Records.txt", "w");
    fclose(pF);
    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>>Enregistrement introuvable  <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirection vers le panneau livre...");
    }
    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");
    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }
    fclose(pF);
    fclose(pT);
    pT = fopen("temporary.txt", "w");
    fclose(pT);
    Sleep(2000);
    partielivre();
}
// le programme se termine ici au revoir
