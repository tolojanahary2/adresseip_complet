#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "base.txt"

// Fonction pour vérifier les informations de connexion
int verifier_connexion(const char *nom, const char *cle)
 {
    FILE *fichier = fopen(FILENAME, "r");
    if (fichier == NULL) 
    {
        printf("<html><body><h>Erreur de l'ouverture du fichier</h></body></html>");
        return 0;
    }

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier))
     {
        char *nom_fichier = strtok(ligne, "\t");
        char *cle_fichier = strtok(NULL, "\t");

        if (nom_fichier != NULL && cle_fichier != NULL)
         {
            // Enlever les caractères de nouvelle ligne
            cle_fichier[strcspn(cle_fichier, "\n")] = '\0';
            if (strcmp(nom, nom_fichier) == 0 && strcmp(cle, cle_fichier) == 0) 
            {
                fclose(fichier);
                return 1; // Connexion réussie
            }
        }
    }

    fclose(fichier);
    return 0; // Connexion échouée
}

// Fonction pour afficher le formulaire de connexion et traiter les données
void traiter_connexion()
 {
    char nom[100], cle[18];

    // Lire les données depuis QUERY_STRING
    char *get = getenv("QUERY_STRING");
    if (get != NULL) {
        sscanf(get, "nom=%99[^&]&cle=%17[^&]", nom, cle);

        // Vérifier les informations de connexion
        if (verifier_connexion(nom, cle))
         {
            // Connexion réussie
            printf("Content-Type: text/html\n\n");
            printf("			<!DOCTYPE html>");
            printf("<head>");
            printf("<title>connection_sans_fil</title>");
            printf("	<style>");
             printf("body{background-color:rgb(23, 27 ,51);}");
            
            printf(" #connexion{");
            printf("top:4px;");
            printf("color:white;");
            printf("right:2px;");
            printf("bottom:3cm;");
            printf("}");
            
            printf("	</style>");
            
            printf("</head>");
            
            printf("<html>");
            printf("<body><h1>Connexion reussie !</h1>");
			printf("<div> <a id='connexion' href=\"affiche.html\">Connectez</a></div>");
        
			printf("</body>");
			printf("</html>");
        }
         
        else 
        {
            // Connexion échouée
            printf("Content-Type: text/html\n\n");
            
            printf("<!DOCTYPE html>");
            printf("<head>");
            printf("<style>");
            
            printf("#tout{");
            printf("text-decoration:none;");
            printf("border:1px solid black;border-radius:11px;");
            printf("height : 1cm ; width: 11cm;");
            printf("font-size:20px;");
            
            printf("background-color:blue;");
            printf("color:white;");
            
            printf("}");
            
            printf("#message{");
            printf("color:white");
            printf("}");
            
            printf("body{background-color:rgb(23, 27 ,51);}");
            
            printf("</style>");
            printf("<title>en_cas_de_deffaillance</title>");
            printf("</head>");
            printf("<body>");
            printf("<h id='message'>Il y a des erreurs survenu lors de votre connexion dans cette plateforme,donc soit votre Compte n'exitez pas ou votre mot de passe est incorreecte alors je vous conseiller de creer un nouveau compte pour que vous pouvez utiliser cette programme</h><br>");
            printf("<a id='tout'  href='login.html'>Quittez </a>");
            
            printf("</body>");
            printf("</html>");
        }
 
	}
}

int main() {
    
    traiter_connexion();
    return 0;
}
