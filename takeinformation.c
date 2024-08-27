#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "base.txt"

	//lire les données depuis QUERY_STRING
void lire_donnees(char *nom, char *cle) {
    char *get = getenv("QUERY_STRING");
    //if (get != NULL) {
        sscanf(get, "nom=%99[^&]&cle=%17[^&]", nom, cle);
    //} else {
      //  nom[0] = prenom[0] = genre[0] = '\0';
	}

	// Fonction pour ajouter ou mettre à jour des données dans le fichier 
void ajouter_ou_mettre_a_jour_donnees(const char *nom, const char *cle) {
    FILE *fichier = fopen(FILENAME, "r+");
    if (fichier == NULL) {
        fichier = fopen(FILENAME, "w");
        if (fichier == NULL) {
            printf("<html><body><h>erreur de l'ouverture du fichier\n\tverifier si le fichier existe</h></body></html>");
        }
    }

    // Vérifier si les informations existe déjà dans notre fichier d'inscription
    char ligne[256];
    char nom_fichier_temporaire[] = "temp_l.txt";
    FILE *fichier_temporaire = fopen(nom_fichier_temporaire, "w");
    if (fichier_temporaire == NULL) {
        fclose(fichier);
          printf("<html><body><h>erreur de l'ouverture du fichier\n\tverifier si le fichier existe</h></body></html>");
    }

    int nouveau = 0;
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, nom) == NULL) {
            fprintf(fichier_temporaire, "%s", ligne);
        } else {
            nouveau = 1; // Entrée trouvée et ignorée
        }
    }

    if (!nouveau) {
        fprintf(fichier_temporaire, "%s\t%s\n", nom,cle);
    } else {
        fprintf(fichier_temporaire, "%s\t%s\n", nom, cle);
    }

    fclose(fichier);
    fclose(fichier_temporaire);

    // Remplacer le fichier original par le fichier temporaire
    remove(FILENAME);
    rename(nom_fichier_temporaire, FILENAME);
}
	// Fonction pour supprimer une entrée du fichier CSV
void supprimer_donnees(const char *nom) {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) {
     printf("<html><body><h>erreur de l'ouverture du fichier\n\tverifier si le fichier existe</h></body></html>");
 
    }

    char temp_filename[] = "temp_l.txt";
    FILE *temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        fclose(fichier);
       printf("<html><body><h>erreur de l'ouverture du fichier\n\tverifier si le fichier existe</h></body></html>");

    }

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strstr(ligne, nom) == NULL) {
            fprintf(temp_file, "%s", ligne);
        }
    }

    fclose(fichier);
    fclose(temp_file);

    // Remplacer le fichier original par le fichier temporaire
    remove(FILENAME);
    rename(temp_filename, FILENAME);
}


// Fonction pour afficher les données dans le tableau HTML
void afficher_donnees_html( ) {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) {
            printf("<html><body><h>erreur de l'ouverture du fichier pour lire </h></body></html>");
    }
    
    
    printf("<!DOCTYPE html>");
    printf("	<head>");
    printf("		<title>Notre Liste</title>");
    printf("	<style>");
    printf("	table{border-collapse: collapse;");
    printf("			} ");
    
    printf("		td {border: 2px solid black;"); 
    printf("			  padding: 8px;");
    printf("			}");
    printf("body{background-color:rgb(23, 27 ,51);}");
    printf("#present{color:white;}");
	printf("#tete{font-size: 40px;color:green;}");
    printf("	</style>");
    printf("	</head>");
    printf("<body>");
    printf("<h2 id='tete'>Myconnect</h2>");
 //printf("<table >"); 
//printf("<tr> <strong>");
//printf("<td>Numero</td>");
//printf("		<td>Nom</td>");
//printf("		<td>mot de passe</td>");
//printf("		<td>Date d'inscription</td>");
//printf("</strong></tr>");
	printf("<h2 id='present'>Votre compte est enregistrer successivement ,Vous pouvez utiliser cette compte pour beneficie de l'opportunite dans cette progrmme</h2>");
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le caractère de nouvelle ligne
       // char *nom = strtok(ligne, "\t");
        //char *cle = strtok(NULL, "\t");
        
//printf("<tr>");
//printf("<td>%d</td>",numero);
//printf("<td>%s</td> ",nom );
//printf("<td>%s</td>",cle);
//printf("<td>%s</td>",__DATE__);
//printf("</tr>");
    }

//printf("</table>");
    printf("<a href=\"affiche.html\">Connectez</a></td></tr>");
    printf("</body></html>");

    fclose(fichier);
}

int main() {
    char nom[100], cle[18];

    lire_donnees(nom, cle);
    // Ajouter ou mettre à jour les données
    ajouter_ou_mettre_a_jour_donnees(nom, cle);
    // Afficher toutes les données du fichier
    printf("Content-Type: text/html\n\n");
    afficher_donnees_html( );

    return 0;
}
