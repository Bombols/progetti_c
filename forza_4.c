#include<stdio.h>
#include<stdlib.h>
const int r = 6;
const int c = 6;
int Inserimento (char array[r][c], int c, char p){
    int i=5;
    while(i>=0){
        if(array[i][c]=='l'){
            array[i][c]=p;
            return i;
        }
        i--;
    }
    printf("colonna piena\n");
    return 0;        
}

void stampa(char array[r][c]){
    for(int i=0 ; i<r; i++){
        for(int j=0; j<c; j++){
            char c=array[i][j];
            printf("%c", c);
            printf(" ");
        }
        printf("\n");
    }
}

int Colonna(char array[r][c], int rig, int col, char g){
    int nc=0;
    for(int i=rig; i>=0; i--){
        if(array[i][col]!=g)
            break;
        else
        {
            nc+=1;
        }
    }
    nc--;
    if(nc<4)
        return 1;
    return 0;
}

int Riga(char array[r][c], int rig, int col, char g){
    int nr=0;
    for(int i=col; i<r; i++){
        if(array[rig][i]!=g)
            break;
        else
        {
            nr+=1;
        }
    }
    for(int i=col; i>=0; i--){
        if(array[rig][i]!=g)
            break;
        else{
            nr+=1;
        }
    }
    nr--;
    if(nr<4)
        return 1;
    return 0;
}

int Diagonale(char array[r][c], int rig, int col, char g){
    int nd1=0;
    int nd2=0;
    int nr=rig;
    int nc=col;
    while (nr<r || nc<c) {
        
        if(array[nr][nc]!=g)
            break;
        else {
            nr+=1;
            nc+=1;
            nd1+=1;
        }
    }
    nr=rig;
    nc=col;
    while (nr>=0 || nc>=0) {
       
        if(array[nr][nc]!=g)
            break;
        else {
            nr-=1;
            nc-=1;
            nd1+=1;
        }
    }
    nd1--;
    nr=rig;
    nc=col;
    while (nr>=0 || nc<c) {
       
        if(array[nr][nc]!=g)
            break;
        else {
            nr-=1;
            nc+=1;
            nd2+=1;
        }
    }
    nr=rig;
    nc=col;
    while (nr<c || nc>=0) {
       
        if(array[nr][nc]!=g)
            break;
        else {
            nr+=1;
            nc-=1;
            nd2+=1;
        }
    }
    nd2--;
    if (nd1 || nd2<4)
        return 1;
    return 0;
}

int main(int argc, char** argv){
    char forza [r][c];
    int cont;
    for(int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            forza [i][j]='l';
        }
    }
    stampa(forza);
    printf("Giocatore 1 Rosso, Giocatore 2 Verde\n");
    for(;;){
        printf("Giocatore 1 inserisci numero di colonna compresa fra 0 e 5:\n");
        int n;
        int max=scanf("%d", &n);
        if(n>=7 || n<0){
            printf("Numero colonna non valida!\n");
        }
        else {
            int riga=Inserimento(forza, n, 'R');
            if(!Colonna(forza, riga, n, 'R')){
                printf("Giocatore 1 hai vinto!\n");
                return 0;
            }
            if(!Riga(forza, riga, n, 'R')){
                stampa(forza);
                printf("Giocatore 1 hai vinto!\n");
                return 0;
            }
            if(!Diagonale(forza, riga, n, 'R')){
                stampa(forza);
                printf("Giocatore 1 hai vinto!\n");
                return 0;
            }
        }
        stampa(forza);
        printf("Giocatore 2 inserisci numero di colonna compresa fra 0 e 5:\n");
        max=scanf("%d", &n);
        if(n>=7 || n<0){
          printf("Numero colonna non valida!\n");
        }
        else {
            int riga=Inserimento(forza, n, 'V');
            if(!Colonna(forza, riga, n, 'V')){
                printf("Giocatore 1 hai vinto!");
                return 0;
            }
            if(!Riga(forza, riga, n, 'V')){
                stampa(forza);
                printf("Giocatore 2 hai vinto!\n");
                return 0;
            }
            if(!Diagonale(forza, riga, n, 'V')){
                stampa(forza);
                printf("Giocatore 2 hai vinto!\n");
                return 0;
            }
        }
        stampa(forza);
    }
    return 0;
}