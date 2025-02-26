# 🐚 Minishell  
## Aussi beau qu'un shell  

---

## 📌 Résumé  
Ce projet consiste à créer un **shell simple**, un mini Bash que tu développeras toi-même.  
Tu apprendras énormément sur la gestion des **processus** et des **descripteurs de fichiers**.  

---

## 📖 Règles générales du projet  

### 🔹 Langage et Norme
- Le projet doit être **codé en C**.
- Il doit respecter la **Norme** (aucune erreur de norme tolérée, même dans les fichiers bonus).
- Aucun **segmentation fault**, **bus error**, **double free**, etc., ne doit se produire (sauf en cas de comportement indéfini).
- **Aucune fuite mémoire** n'est tolérée : toute allocation dynamique doit être libérée correctement.

### 🔹 Makefile
- Un **Makefile** doit être fourni avec les règles suivantes :
  - `$(NAME)`, `all`, `clean`, `fclean`, `re`.
- Il doit utiliser **cc** et les flags :  
  `-Wall -Wextra -Werror`.
- Il ne doit pas **relinker** inutilement les fichiers.

### 🔹 Libft
- Si l'utilisation de **libft** est autorisée, les sources et le Makefile doivent être inclus dans un dossier **libft/**.
- Le Makefile du projet doit compiler la **libft** avant de compiler le shell.

### 🔹 Tests
- Il est conseillé de créer des **programmes de test**, même si ce n'est pas obligatoire.
- Ces tests seront utiles pour vérifier ton travail et celui de tes pairs lors de l'évaluation.

### 🔹 Évaluation et dépôt
- Le projet doit être **poussé sur le dépôt Git** assigné.
- Seul le contenu du dépôt Git sera évalué.
- **Deepthought** (l'outil de correction) effectuera une évaluation après celle de tes pairs.
- Si une erreur se produit dans ton code lors de la correction automatique, l'évaluation **s'arrêtera immédiatement**.

---

## 🛠 Partie Obligatoire  

### **Détails du projet**
- **Nom du programme** : `minishell`
- **Fichiers à rendre** : `Makefile`, `*.h`, `*.c`
- **Fonctions autorisées** :
  - `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history`
  - `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`
  - `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`
  - `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`
  - `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`
  - `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

---

### **Fonctionnalités requises**
#### 1️⃣ Affichage et gestion de commandes
- Afficher un **prompt** en attente d’une commande.
- Gérer **l’historique** des commandes.
- Rechercher et exécuter la bonne commande via :
  - Une **commande absolue** (`/bin/ls`).
  - Une **commande relative** (`./a.out`).
  - Une **commande trouvée via `$PATH`** (`ls`).

#### 2️⃣ Gestion des signaux
- **Une seule variable globale** est autorisée pour stocker un **numéro de signal reçu**.
- Cette variable ne doit pas contenir d’autres données.

#### 3️⃣ Gestion des caractères spéciaux
- **Ne pas interpréter** les caractères non demandés (`\` backslash, `;` point-virgule...).
- Gérer les **guillemets simples `'`** : empêchent toute expansion.
- Gérer les **guillemets doubles `"`** : empêchent l’expansion sauf pour `$`.

#### 4️⃣ Redirections
- `<` : redirige l'entrée standard (`stdin`).
- `>` : redirige la sortie standard (`stdout`).
- `>>` : redirige la sortie en **mode append**.
- `<<` : **Heredoc**, lit l'entrée jusqu'à un **délimiteur** donné (ne doit pas être enregistré dans l’historique).

#### 5️⃣ Gestion des pipes (`|`)
- Le **pipe** connecte la sortie d’une commande à l’entrée de la suivante.

#### 6️⃣ Variables d’environnement
- Expansion des **variables d’environnement** (`$HOME`, `$USER`, etc.).
- Gestion de `$?` qui représente **le statut de sortie de la dernière commande exécutée**.

#### 7️⃣ Gestion des touches spéciales
| **Commande** | **Effet attendu** |
|-------------|----------------|
| `Ctrl + C` | Affiche un **nouveau prompt** sur une nouvelle ligne |
| `Ctrl + D` | **Quitte** le shell |
| `Ctrl + \` | **Ne fait rien** (ignore le signal) |

#### 8️⃣ Implémentation des builtins
Ton **Minishell** doit inclure les **builtins** suivants :
| **Builtin** | **Description** |
|------------|----------------|
| `echo [-n]` | Affiche un message avec ou sans retour à la ligne |
| `cd [path]` | Change le répertoire courant |
| `pwd` | Affiche le répertoire courant |
| `export` | Définit une variable d'environnement |
| `unset` | Supprime une variable d'environnement |
| `env` | Affiche les variables d'environnement |
| `exit` | Quitte le shell |

---

## 🎯 Règles supplémentaires
- La fonction `readline()` **peut provoquer des fuites mémoire** (ce n'est pas un problème).
- **Ton propre code ne doit avoir aucune fuite mémoire**.
- Tu dois **respecter strictement le sujet** : tout comportement non demandé **n'est pas requis**.
- En cas de doute, **référence-toi à Bash**.

---

## ✨ Partie Bonus
Si tu as terminé la partie obligatoire **parfaitement**, tu peux ajouter des fonctionnalités bonus :

### **Bonus demandés :**
1️⃣ **Opérateurs logiques (`&&`, `||`)**  
   - Permettent d’exécuter des commandes conditionnellement :
     - `cmd1 && cmd2` : `cmd2` s’exécute **seulement si** `cmd1` réussit.
     - `cmd1 || cmd2` : `cmd2` s’exécute **seulement si** `cmd1` échoue.
   - Supporte les **parenthèses pour la priorité**.

2️⃣ **Wildcards (`*`)**  
   - Permet d'utiliser `*` pour lister des fichiers (`ls *.c`).
   - Fonctionne **dans le répertoire courant**.

---

## 🎯 Conditions pour que le bonus soit évalué
- **Le projet obligatoire doit être parfaitement fonctionnel**.  
  > Si une seule exigence de la partie obligatoire manque ou ne fonctionne pas, la partie bonus **ne sera pas évaluée**.

---

## 🚀 Conclusion
Minishell est un **projet fondamental** pour comprendre la **gestion des processus**, la **redirection de flux** et la **manipulation des entrées/sorties**
