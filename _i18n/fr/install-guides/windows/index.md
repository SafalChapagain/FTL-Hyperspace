## Mise à jour

Remplacez simplement `Hyperspace.dll` (et toutes les autres DLLs incluses dans le ZIP d'hyperspace) par la nouvelle version dans votre répertoire d'installation FTL.
La mise à jour de `Hyperspace.dll` est **cruciale** pour les mises à jour du Multiverse car elles sont toujours construites avec la dernière version d'hyperspace

Patchez le nouveau `Hyperspace.ftl` avec Slipstream si vous utilisez un mod qui le nécessite (*ne patchez pas `Hyperspace.ftl` pour Multiverse*).

## Première installation

Hyperspace ne fonctionne qu'avec FTL 1.6.9, ce qui suit vous guidera à la fois pour l'installation et la mise à jour de votre installation de FTL en fonction de l'endroit où vous avez acheté FTL :

### Quelle est votre installation de FTL ?

- [Steam](./steam-install)
- [GoG](./gog-install)
- [Humble Bundle](./humble-install)
- [Epic Games](./other-install#epic)
- [Origin](./other-install#origin)
- [Microsoft Store/Xbox Game Pass](./other-install#microsoft-storexbox-game-pass)

## Dépannage

#### Mon jeu se plaint de `-opengl`
- Arrêtez d'utiliser le flag `-opengl`, il a été supprimé dans Hyperspace 1.5.0 et n'est plus nécessaire.

#### Mon jeu se plante avant le chargement du Multiverse
- Assurez-vous que vous êtes sur la dernière version d'Hyperspace, l'installateur de Multiverse n'est souvent pas à jour !
- Ce problème devrait être pratiquement éliminé à moins que votre fichier de sauvegarde ne soit corrompu, mais il y a quelques cas où cela peut encore se produire sur les ***ordinateurs portables uniquement***
- Si vous n'utilisez pas d'ordinateur portable, **votre fichier de sauvegarde est corrompu** et c'est la raison pour laquelle le jeu ne se lance pas, voir ci-dessous.
- Si votre ordinateur portable n'a pas de carte graphique dédiée (c'est-à-dire un GPU AMD ou Nvidia, pas celui intégré dans le CPU), **votre fichier de sauvegarde est corrompu** et c'est là le problème.
- Si votre ordinateur portable **A EFFECTIVEMENT** un GPU dédié, vous devrez peut-être forcer FTL à fonctionner soit sur le GPU dédié, soit sur le GPU interne, car l'un d'entre eux peut être à l'origine du problème.

#### Mon jeu se bloque au chargement du dernier `E` de multiverse
- [Vous avez un fichier de sauvegarde corrompu](#resolving-a-corrupt-save-file)

#### Mon jeu se bloque au chargement mais ne plante pas et j'entends de la musique.
- [Vous avez un fichier de sauvegarde corrompu](#resolving-a-corrupt-save-file)

#### Réparer un fichier de sauvegarde corrompu
Pour éventuellement réparer une sauvegarde corrompue :
1. Allez dans `Documents/Mes Jeux/FasterThanLight`, vous devriez avoir un `hs_mv_prof.sav` et un `hs_mv_version.sav`.
2. Supprimez le `hs_mv_version.sav`
3. Déplacez le `hs_mv_prof.sav` dans un autre dossier (**ne le supprimez pas**)
4. Lancez le jeu et une fois qu'il s'est chargé sur le menu principal, fermez-le à nouveau.
5. Déplacez votre `hs_mv_prof.sav` original là où il était avant, en remplaçant celui qui a été créé par le jeu.
