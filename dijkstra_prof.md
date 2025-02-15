\=== Programme principal ===
Programme dijkstra

// Déclarations des constantes

Constante NBSOMMETS          = 1000
Constante TAILLE_NOM_FICHIER = 100
Constante TAILLE_NOM         = 50
Constante NB_COLONNES        = 2
Constante NON_TROUVE         = -1
Constante INCONNU            = -1
Constante INFINI             = 99999

// Des  types communs

Type global Type_couleur en énumération
                                blanc, noir 
                        Fin énumération

Type global Sommet en Enregistrement
                            champ nom      en Chaîne
                            champ pere     en Entier
                            champ poids    en Entier
                            champ couleur  en Type_couleur
                Fin d’Enregistrement

// Tableau des sommets
Variable globale tab_sommets en Tableau[NBSOMMETS] de Sommet
// Tableau des arcs valués
Variable globale tab_arcs    en Tableau[NBSOMMETS][NBSOMMETS] d’Entiers
// Tableau des noms des arcs
Variable globale tab_arcs_noms en Tableau[NBSOMMETS][NBSOMMETS] de Chaînes

// Déclaration des variables globales
Variable globale nbsommets  en Entier
Variable globale NomFichier en Chaînes

// Déclaration des variables du programme
Variables sommet_depart, sommet_arrivee         en Chaînes
Variables num_sommet_depart, num_sommet_arrivee en Entiers
Variable  num_sommet_poids_min                  en Entier

Début
    nbsommets ← 0
    Si (chargement_sommets() <> NON_TROUVE) Alors
        Si (chargement_arcs() <> NON_TROUVE) Alors
            num_sommet_depart ← choix_sommet("de départ")
                Si (num_sommet_depart <> NON_TROUVE) Alors
                    num_sommet_arrivee ← choix_sommet("d'arrivée")
                    Si (num_sommet_arrivee <> NON_TROUVE) Alors
                        // === Algorithme de Dijkstra ===
                        // -- Initialisation des sommets -- //
                        dijkstra_initialise(num_sommet_depart)
                        // --- Recherche du sommet de poids minimal ---
                        Tant Que ((num_sommet_poids_min ← dijkstra_recherche_sommet_poids_min()) <> NON_TROUVE) Faire
                        // Ce sommet est colorié en noir
                            dijkstra_colorier_sommet(num_sommet_poids_min)
                        // On met à jour le poids des sommets adjacents
                            dijkstra_calcule_poids_sommets_adjacents(num_sommet_poids_min)
                        FinTantQue
                        // Affiche le plus court chemin à partir           
                        // du sommet d'arrivée 
                        dijkstra_affiche_plus_court_chemin(num_sommet_arrivee)
                    FinSi
                FinSi
        FinSi
    FinSi
    Fin

// === Sous-programmes ===

// Chargement du tableau des sommets
Fonction chargement_sommets()
Déclarations
    Variable fsommets en Fichier
    Variables NomFichierSommets, nom en Chaînes
    Variable code_retour en Entier
Début
    code_retour ← 0
    Écrire("Nom du graphe : ")
    Lire(NomFichier)
    fsommets ← ouvrir(NomFichierSommets, "lecture")
    Si (fsommets = PAS_OUVERT) Alors
        code_retour ← NON_TROUVE
        Écrire("fichier ", NomFichierSommets, " non trouvé !")
    Sinon
        Tant Que (NON Fin_de_fichier(fsommets)) Faire
            Si (Lire(fsommets, nom) <> FIN_DE_FICHIER) Alors
                tab_sommets[nbsommets].nom ← nom
                nbsommets ← nbsommets + 1
            FinSi
        FinTantQue
    FinSi
    fermer(fsommets)
    retourner code_retour
Fin

// Sélection d'un sommet
Fonction choix_sommet(texte)
Déclarations
    Paramètre texte en Chaînes
    Variables i, choix en Entiers
Début
    Pour i variant de 0 à nbsommets-1 Faire
        Écrire(i + 1, tab_sommets[i].nom)
    FinPour
    Écrire("Saisissez le numéro du sommet : ")
    Écrire(texte)
    Lire(choix)
    choix ← choix - 1
    Si ((choix >= nbsommets) OU (choix < 0)) Alors
        Écrire("Choix erroné !")
        choix ← NON_TROUVE
    FinSi
    retourner choix
Fin

// Chargement du tableau des arcs
Fonction chargement_arcs()
Déclarations
    Variables farcs, farcsnoms en Fichiers
    Variables NomFichierArcs, NomFichierNomsArcs en Chaînes
    Variable nomarcs en Chaînes
    Variables code_retour, i, j en Entiers
Début
    code_retour ← 0
    NomFichierArcs ← Concaténer(NomFichier, "_arcs.txt")
    NomFichierNomsArcs ← Concaténer(NomFichier, "_noms.txt")

    farcs ← ouvrir(NomFichierArcs, "lecture")
    
    Si (farcs = PAS_OUVERT) Alors
        code_retour ← NON_TROUVE
        Écrire("fichier ", NomFichierArcs, " non trouvé")
    
    SinonSi ((farcsnoms ← ouvrir(NomFichierNomsArcs, "lecture")) = PAS_OUVERT) Alors
        code_retour ← NON_TROUVE
        Écrire("fichier ", NomFichierNomsArcs, " non trouvé")
    
    Sinon
        Pour i variant de 0 à nbsommets-1 Faire
            Pour j variant de 0 à nbsommets-1 Faire
                Lire(farcs, tab_arcs[i][j])
                Lire(farcsnoms, nomarcs)
                tab_arcs_noms[i][j] ← nomarcs
            FinPour
        FinPour
    FinSi

    fermer(farcs)
    retourner code_retour
Fin


// --- DIJKSTRA : Procédure d'initialisation (couleurs, pondérations, pères) ---

// Initialisation des sommets
Procédure dijkstra_initialise(num_sommet_depart)
Déclarations
    Paramètre num_sommet_depart en Entier
    Variables i, ponderation en Entiers
Début
    Pour i variant de 0 à nbsommets-1 Faire
        Si (i = num_sommet_depart) Alors
            ponderation ← 0
        Sinon
            ponderation ← INFINI
        FinSi
        tab_sommets[i].poids ← ponderation
        tab_sommets[i].pere ← INCONNU
        tab_sommets[i].couleur ← blanc
    FinPour
Fin

// --- DIJKSTRA : Fonction de recherche du sommet de poids minimal ---
Fonction dijkstra_recherche_sommet_poids_min()
Déclarations
    Variables i, num_sommet, poids_min en Entiers
Début
    num_sommet ← NON_TROUVE
    poids_min  ← INFINI

    Pour i variant de 0 à nbsommets-1 Faire
        Si ((tab_sommets[i].couleur = blanc) ET (tab_sommets[i].poids < poids_min)) Alors
            poids_min   ← tab_sommets[i].poids
            num_sommet  ← i
        FinSi
    FinPour

    retourner num_sommet
Fin



// --- DIJKSTRA : Procédure de coloriage en noir d'un sommet ---
Procédure dijkstra_colorier_sommet(num_sommet)
Déclaration
    Paramètre num_sommet en Entier
Début
    tab_sommets[num_sommet].couleur ← noir
Fin

// --- DIJKSTRA : Procédure de calcul du poids des sommets adjacents ---
Procédure dijkstra_calcule_poids_sommets_adjacents(num_sommet)
Déclaration
    Paramètre num_sommet en Entier
    Variables num_adjacent, nouveau_poids en Entiers
Début
    Pour num_adjacent variant de 0 à nbsommets-1 Faire
        nouveau_poids ← tab_sommets[num_sommet].poids + tab_arcs[num_sommet][num_adjacent]

        Si ((tab_sommets[num_adjacent].couleur = blanc) ET (nouveau_poids < tab_sommets[num_adjacent].poids)) Alors
            tab_sommets[num_adjacent].poids ← nouveau_poids
            tab_sommets[num_adjacent].pere  ← num_sommet
        FinSi
    FinPour
Fin

// --- DIJKSTRA : Procédure d'affichage du plus court chemin ---
Procédure dijkstra_affiche_plus_court_chemin(sommet_arrive)
Déclarations
    Paramètre sommet_arrive en Entier
    Variables num_s, nbsommets, i en Entiers
    Variables num_s1, num_s2, sommet_depart en Entiers
    Variables tab_chemin_inverse en Tableau[NBSOMMETS+1] d’Entiers
Début
    num_s ← sommet_arrive
    nbsommets ← 1

    Si (tab_sommets[sommet_arrive].poids = INFINI) Alors
        Écrire("Aucun chemin n'existe !")
    Sinon
        tab_chemin_inverse[0] ← sommet_arrive

        Tant Que (num_s <> INCONNU) Faire
            tab_chemin_inverse[nbsommets] ← num_s
            nbsommets ← nbsommets + 1
            sommet_depart ← num_s
            num_s ← tab_sommets[num_s].pere
        FinTantQue

        Écrire("Plus court chemin pour aller")
        Écrire("   de ", tab_sommets[sommet_depart].nom)
        Écrire("   à  ", tab_sommets[sommet_arrive].nom)

        Pour i variant de nbsommets-1 à 1 par pas de -1 Faire
            num_s1 ← tab_chemin_inverse[i]
            
            Si (num_s1 = sommet_arrive) Alors
                Écrire("Vous êtes arrivé à ", tab_sommets[num_s1].nom)
                Écrire("Vous avez parcouru ", tab_sommets[sommet_arrive].poids, " mètres")
            Sinon
                num_s2 ← tab_chemin_inverse[i-1]
                Écrire("De     ", tab_sommets[num_s1].nom)
                Écrire("Suivre ", tab_arcs_noms[num_s1][num_s2])
                Écrire("Vers   ", tab_sommets[num_s2].nom)
                Écrire("Sur    ", tab_arcs[num_s1][num_s2], " mètres")
            FinSi
        FinPour
    FinSi
Fin
