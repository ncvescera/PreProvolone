#include <stdio.h>
#include <stdlib.h>

int* rialloca(int* corrente, int dimCorrente);
int inserisciNumeri(int** p, int dim);
void ordina(int* p, int elementi);
void stampa(int* c, int elementi);

int main(int argc, char** argv) {
    int* p;
    int dim=2;
    int nElementi;
    p=(int*)malloc(dim*sizeof(int));
    
    nElementi=inserisciNumeri(&p,dim);
    ordina(p,nElementi);
    stampa(p,nElementi);
    
    free(p);
    return (EXIT_SUCCESS);
}
int inserisciNumeri(int** p, int dim){
    int i;
    int inserito=-1;
    
    i=0;
    while(inserito!=0){
        printf("Inserisci un numero (0 per terminare): ");
        scanf("%d",&inserito);
        if(inserito){
            if(i==dim){
                *p=rialloca(*p,dim);
                dim*=2;
            }
            (*p)[i++]=inserito;
            
        }
    }
    return i;
  
}
int* rialloca(int* corrente, int dimCorrente){
    int* nuovoPuntatore=NULL;
    int nuovaDimensione=dimCorrente*2;
    int i;
    
    nuovoPuntatore=(int*)malloc(nuovaDimensione*sizeof(int));
    for(i=0;i<dimCorrente;i++){
        nuovoPuntatore[i]=corrente[i];
    }
    
    free(corrente);
    return nuovoPuntatore;
}
void ordina(int* p, int elementi){
    int i,j;
    int temp;
    
    for(i=0;i<elementi-1;i++){
        for(j=0;j<elementi-1;j++){
            if(p[j]>p[j+1]){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void stampa(int* c, int elementi){
    int i;
    FILE *puntafile;
    
    puntafile=fopen("numeri.txt","w");
    if(puntafile==NULL){
        puts("Errore! Impossibile aprire il file.\n");
        exit(1);
    }
        
    for(i=0;i<elementi;i++){
        fprintf(puntafile,"%d\n",c[i]);
    }
    
    puts("Operazione andata a buon fine");
    fclose(puntafile);
}

