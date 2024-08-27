#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void entre_ip (char *nom)
{ 
	int premierePartie;
	 char *get ;
	 get=getenv("QUERY_STRING");
        sscanf(get, "nom=%99[^&]", nom);
   	
		sscanf(get,"nom=%d",&premierePartie);
		
		printf("Content-Type: text/html\n\n");
		    printf("<!DOCTYPE html>\n<html><head>\n<title>Ipadresse</title>");
		    printf("<style>");
		    printf("body{background-color:rgb(23, 27, 51);}");
		    
		    printf("h3{color:white;}");
		    
		    printf("footer{ ");
		    printf(" 	border: 1px solid black; ");
		    printf("		border-radius: 12px ;");
		    printf("		color: white;");
		    
		    printf("		width: 5cm; ");
		    printf("		height: 5cm;"); 
			printf("		margin:130px ;");
			
			printf("		text-decoration:none;");
		    printf("		text-align: center; ");
		    printf(" 	place-content:center;");
		    printf("  	place-items: center; ");
		    printf("		background-color: green;");
		    printf("						}");
		    
		
		    printf("</style>");
		    
		    printf("</head>");
		    
		    printf("<body>");

		if(premierePartie>=0  && premierePartie<=127)
		{
		printf("<h3>IP inclure au classe A</h3></body></html>");
		}
		else if ( premierePartie>=128 && premierePartie<=191)
		{
		printf("<h3>IP inclure  au classe B</h3></body></html>");
		
			}
			else if ( premierePartie>=192 && premierePartie<=223)
			{
			printf("<html><body><h3>IP inclure au classe C</h3></body></html>");
				}
				else if ( premierePartie>=224 && premierePartie<=240)
			{
			printf("<html><body><h3>IP inclure au classe D</h3></body></html>");
				}
				else if ( premierePartie>=240&& premierePartie<=255)
			{
			printf("<html><body><h3>IP inclure au classe E</h3></body></html>");
				}
			else {
			printf("<html><body><h3>Adresse IP introuvable</h3></body></html>");
				}
				
				printf("<footer>");
		        
		        printf("<br><a href=\"affiche.html\">Tester d'autre IP </a></td>");
		        printf("<br><div><a  href='login.html'>Deconnectez-vous</a><div>");		
		        
				printf("</footer>");
	}
int main()
{
	char nom[16];
	
	fgets(nom,sizeof(nom),stdin);
	
	nom[strcspn(nom,"\n")] = '\0';
		
	entre_ip (nom);

	return 0;
	}
