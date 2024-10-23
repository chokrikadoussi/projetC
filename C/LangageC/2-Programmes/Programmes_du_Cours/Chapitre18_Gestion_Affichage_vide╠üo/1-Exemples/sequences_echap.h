//------------- Préfixe général -------------
#define ECHAP_CODE   "\033"
#define ECHAP_SEQ(sequence)   "\033[" sequence
//------------- Déplacement du curseur -------------
#define DEPLAC_CURSEUR_HAUT(n)   ECHAP_SEQ(#n "A")
#define DEPLAC_CURSEUR_BAS(n)    ECHAP_SEQ(#n "B")
#define DEPLAC_CURSEUR_DROITE(n) ECHAP_SEQ(#n "C")
#define DEPLAC_CURSEUR_GAUCHE(n) ECHAP_SEQ(#n "D")
#define DEPLAC_CURSEUR_POS(n,m)  ECHAP_SEQ(#n ";" #m "H")
//------------- Sauvegarde et restauration de la position du curseur -------------
#define SAUVE_POS      "\033" "7"
#define RESTAURE_POS   "\033" "8"
//------------- Effacements -------------
#define EFFACE_ECRAN(n)  ECHAP_SEQ(#n "J")
#define EFFACE_LIGNE(n)  ECHAP_SEQ(#n "K")
//------------- Attributs de texte -------------
#define TEXTE_ATTR(x)   ECHAP_SEQ(#x) "m"
// Couleur de texte
#define TEXTE_NOIR      TEXTE_ATTR(30)
#define TEXTE_ROUGE     TEXTE_ATTR(31)
#define TEXTE_VERT      TEXTE_ATTR(32)
#define TEXTE_JAUNE     TEXTE_ATTR(33)
#define TEXTE_BLUE      TEXTE_ATTR(34)
#define TEXTE_MAGENTA   TEXTE_ATTR(35)
#define TEXTE_CYAN      TEXTE_ATTR(36)
#define TEXTE_BLANC     TEXTE_ATTR(37)
// Couleur de l'arrière-plan
#define FOND_NOIR       TEXTE_ATTR(40)
#define FOND_ROUGE      TEXTE_ATTR(41)
#define FOND_VERT       TEXTE_ATTR(42)
#define FOND_JAUNE      TEXTE_ATTR(43)
#define FOND_BLUE       TEXTE_ATTR(44)
#define FOND_MAGENTA    TEXTE_ATTR(45)
#define FOND_CYAN       TEXTE_ATTR(46)
#define FOND_BLANC      TEXTE_ATTR(47)
// Effacement des attributs
#define EFFACE_ATTR     TEXTE_ATTR(0)
