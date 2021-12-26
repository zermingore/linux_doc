// Une des déclaration de main() les plus fréquentes avec 2 arguments

/*
   Extrait de la page de manuel de gcc
   (le compilateur qui lit ton programme pour générer un binaire):

   >> "main" should be a function [...] returning int,
   >> taking either zero arguments, two, or three arguments of appropriate types

   En gros, un programme C ou C++ bien formé
   - renvoie un int (abréviation de 'integer'; nombre entier)
   - prend 0 2 ou 3 arguments. Courrament:
     pas d'arguments
     2: leur nombre et liste

   Attention: ouvrir le manuel de gcc est une bonne idée mais fait peur.
   Je l'ouvre régulièrement mais en sachant ce que je cherche sinon je me noie
   Voir: Compilateur et Warnings
*/



// On va avoir besoin de ça pour afficher du texte
// (STanDard Input Output): entrées / sorties standards
#include <stdio.h>

int main(int arguments_count, char *arguments_vector[])
{
  // On a toujours au moins 1 argument: le nom du programme lui-même
  if (arguments_count <= 1)
  {
    printf("Erreur: pas d'arguments\n"); // '\n' Newline (saut de ligne)
    return 1; // 0 -> OK; quelque-chose d'autre (ici 1) -> erreur
  }

  // Note: pas besoin d'écrire "else": si le test précédent est vrai.
  // "return" est dit débranchant: on se casse de la fonction et basta
  // Ici vu que la fonction est main, on retourne du programme


  // "for" == "pour" => pour "index" entre 0 (inclus) et le nombre d'arguments
  // en détails:
  //   int index = 0: on déclare une variable "index" initialisée à 0
  //   index < arguments_count: test éffectué à chaque passe de boucle
  //   index = index + 1: Après chaque passe de boucle, on incrémente index
  for (int index = 0; index < arguments_count; index = index + 1)
  {
    // printf: afficher du texte (PRINT Format)
    // "Format" parceque:
    // - %i: on veut afficher un int
    // - %s: on veut afficher une string (chaine de charactères)
    // Note: les crochets, espace et saut de ligne sont juste là pour faire joli
    printf("[%i] [%s]\n", index, arguments_vector[index]); // '\n' Newline
  }
  // note: ici "index" n'est plus défini.
  // On a pas le droit d'écrire "index = 0"
  // par contre "int index = 0" est valide: On défini une *nouvelle* variable
  // C'est plutôt pratique:
  // - Si, par exemple, dans la même fonction t'as 2 boucles de ce type
  //   (t'as pas le droit de définir une "nouvelle" variable... qui éxiste déjà)
  // - Pour débugger: si t'utilise index après,
  //     ton compilateur va gentillement te rappeler que t'es hors de ta boucle

  return 0;
}



/* Possible output:
// Compilation et execution avec quelques arguments pour tester
$> gcc -o exe args.c && ./exe a b c un argument? "un avec espace" "\"oh lol des guillements\""
[0] [./exe]
[1] [a]
[2] [b]
[3] [c]
[4] [un]
[5] [argument?]
[6] [un avec espace]
[7] ["oh lol des guillements"]
*/
