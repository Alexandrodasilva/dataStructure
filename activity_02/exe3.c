
    #include <stdio.h>

    char vogal(char *nome){
        
        int j,k;
        char a, e, i, o, u, A,E,I,O,U;
        a= 'a', e='e',i='i',o='o',u='u';
        A = 'A', E='E',I='I',O='O',U='U';

        for(j = 0;    j < 50;    j++){
            if(nome[j] == a || nome[j] == A){
                printf("a");
            }
            else if(nome[j] == e || nome[j] == E){
                printf("e");
            }
            else if(nome[j] == i || nome[j] == I){
                printf("i");
            }
            else if(nome[j] == o || nome[j] == O){
                printf("o");
            }
            else if(nome[j] == u || nome[j] == U){
                printf("u");
            }
            i++;
        }
        printf("i=%d", i);
        printf("\n");
        
    }

    int main()
    {
        char nome[50];
        printf("insira uma palavra: ");
        scanf("%s", nome);
        printf("\n");
        vogal(nome);
        return 0;
        
    }
