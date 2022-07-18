# <p align='center'> **ft_containers**


>### **Fiche technique:**
#### &emsp;&emsp;&bull; 42 cursus -> Tronc commun -> Cercle level: 5
#### &emsp;&emsp;&bull; Langage: C++
#### &emsp;&emsp;&bull; Difficulté: 6/7

#  <p align='center'> Partie obligatoire

Ce projet vise à recoder les containers: vector, stack et map du C++98, mais pour cela il faut aussi recoder d'autres utilitaires du C++. Les performances de ces containers ne doivent pas être plus de 20 fois plus lentes que les containers originaux.


## Containers:


### Vector:

### Stack:

### Map:


## Utilitaires:


### Iterators_traits:



### Reverse_iterator:



### Enable_if:

Enable_if se compose de deux structures template prenant en argument un booléen et un type quelconque. La différence entre les deux structures est que l'une prend seulement "true". Ces structures font un typedef sur le deuxième élément si le booléen est true sinon elle ne fait rien. L'utilité de ces structures est qu'elles permettent d'orienter le compilateur en utilisant la règle SFINAE (Substitution Failure Is Not An Error) pour utiliser les bonnes fonctions, classes ou structures pouvant avoir les mêmes types en argument.

### Is_integral:

Is_integral se décompose en plusieurs structures nécessitant un type à chaque fois, chacune d'elles hérite de false_type ou de true_type (on peut savoir lequel en mettant "::value" qui nous donne le type en booléen). Is_integral hérite de true_type pour des éléments de type bool, tous types de char ou tous types de int sinon elle hérite de false_type. 

### Equal:

Equal compare les éléments entre first1(compris) et last1(non compris) aux éléments debutant à first2(compris). Pour comparer elle peut soit utiliser l'opérateur de comparaison, soit utiliser une fonction de comparaison si un parametre en plus est ajouté.

### Lexicographical_compare:

Lexicographical_compare compare deux plages d'itrateurs est renvoie true si la premiere plage est inferrieur à la premiere en suivant la méthode de rangemenet des dictionaires. La fonction se divise en deux fonctions l'une comparent avec "a < b" si 4 arument sont passé. La fonction second fonction est appelé avec 5 arguments, celle-ci utilise le cinquiéme argument comme fonction de comapaison, celle-ci est binaire, accepte deux argument pointé par les iterateurs et renvoi true si le premier est consideré comme devant le second.

### Pair:

Pair est une structure qui regroupe une paire de valeur qui peuvent être de différents types. Elle se compose d'un contructeur par défaut, un constructeur prenant deux arguments pour les mettre dans ses variables membres first et second, un constructeur par copie, un overload de l'opérateur "=" et l'overload des opérateurs de comparaison. Elle typedef également les types des deux arguments en first_type et second_type qui peuvent donc être récupéré en ajoutant "::first_type" ou "::second_type" apres l'élément pair.

### Make_pair:

Make_pair construit un éléments de type pair avec comme premier élément x et le second y. Il convertit implictement les element.

# <p align='center'> Partie bonus

La partie bonus vise à recoder le container set du c++98 avec obligatoirement un arbre rouge et noir.


## Containers:


### Set:

# <p align='center'> *Annexes*

## Règle de compilation SFINAE (C++):

Cette règle signifie: *Substitution Failure Is Not An Error*. Cela veut dire que si lors du choix des fonctions les types ne sont pas bon le compilateur ne retournera pas d'erreur sauf si il n'y a plus de possibilité. Cette règle permet de créer plusieurs fonctions, structures ou classes avec des prérequis de type différents. Le compilateur choisira en priorité les fonctions ne nécesitant pas de cast.

## Mot clé: inline

Le mot clé "inline" se place avant la déclaration d'une fonction. Il permet de dire au compilateur que lorsqu'il rencontre une fonction comme celle-ci il doit inseret une copie de la fonction. Cepandant le compilateur peut ne pas le faire pour proteger la compilatiom pour deux cas: les fonctions recursives et les fonctions referencées par un pointeur.

## Mot clé: explicit

Mot clé "explicit" permet, lorsqu'il est mit devant un constructeur, que le compilateur ne puisse utiliser celui-ci seulement si les types sont bon, et donc qu'il ne fasse pas de converssion implicite potentiellement toxique.
