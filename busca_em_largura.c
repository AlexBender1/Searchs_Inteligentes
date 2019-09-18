#include <stdio.h>
#include <stdlib.h>

#define TR 1 //"Terra Rica"
#define NA 2 //"Nova Aurora"
#define AM 3 //"Amaporã"
#define MR 4 //"Mirador"
#define SAC 5 //"Santo Antônio do Caiuá"
#define SJC 6 //"São João do Caiuá"
#define PR 7 //"Paranavaí"
#define PDN 8 //"Paraíso do Norte"
#define IN 9 //"Inajá"
#define CDS 10 //"Cruzeiro do Sul"
#define UF 11 //"Uniflor"
#define NE 12 //"Nova Esperança"
#define FR 13 //"Floraí"
#define CL 14 //"Colorado"
#define MG 15 //"Mandaguaçu"
#define SI 16 //"Santo Inácio"
#define SF 17 //"Santa Fé"
#define IG 18 //"Iguaraçu"
#define CNS 19 //"Centenário do Sul"
#define GR 20 //"Guaraci"
#define AG 21 //"Astorga"
#define PC 22 //"Porecatu"
#define FP 23 //"Florestópolis"
#define NumVertices 22
#define NArestas 7

int tamFila = 0;

struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node_t;

void fnInicia(node_t *FILA){
    FILA->prox = NULL;
    tamFila = 0;
}

void fnPush(node_t *FILA, int V){
    node_t *novo = (node_t *) malloc(sizeof(node_t));
    novo->prox = NULL;
    novo->num = V;

    if(tamFila == 0){
        FILA->prox = novo;
    } else{
        node_t *tmp = FILA->prox;

        while(tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }

    ++tamFila;
}

node_t *fnPop(node_t *Fila){
    if(Fila->prox == NULL){
        printf("Fila ja esta vazia\n");
        return NULL;
    } else {
        node_t *tmp = Fila->prox;
        Fila->prox = tmp->prox;
        --tamFila;
        return tmp;
    }
}

void fnIniMat(int grafo[][NArestas]){
    int i=0;
    //Ligados a Terra Rica
    grafo[i][0] = NA;
    grafo[i][1] = SAC;
    i++;
    //Ligados a Nova Aurora
    grafo[i][0] = TR;
    grafo[i][1] = AM;
    grafo[i][2] = PR;
    i++;
    //Ligados a amaporã
    grafo[i][0] = NA;
    grafo[i][1] = MR;
    grafo[i][2] = PR;
    i++;
    //Ligados a mirador
    grafo[i][0] = AM;
    grafo[i][1] = PDN;
    i++;
    //Ligados a Santo Antônio do Caiuá
    grafo[i][0] = TR;
    grafo[i][1] = SJC;
    grafo[i][2] = IN;
    i++;
    //Ligados a São João do Caiuá
    grafo[i][0] = SAC;
    grafo[i][1] = PR;
    grafo[i][2] = IN;
    grafo[i][3] = CDS;
    i++;

    //Ligadoas a paranavaí
    grafo[i][0] = SJC;
    grafo[i][1] = NA;
    grafo[i][2] = AM;
    grafo[i][3] = PDN;
    grafo[i][4] = NE;
    i++;

    //"Paraíso do Norte"    
    grafo[i][0] = MR;
    grafo[i][1] = FR;
    grafo[i][2] = PR;
    grafo[i][3] = NE;
    grafo[i][4] = AM;
    i++;

    //"Inajá"
    grafo[i][0] = SAC;
    grafo[i][1] = CL;
    grafo[i][2] = SJC;
    grafo[i][3] = CDS;
    grafo[i][4] = SI;
    i++;

    //"Cruzeiro do Sul"
    grafo[i][0] = IN;
    grafo[i][1] = CL;
    grafo[i][2] = SJC;
    grafo[i][3] = UF;
    i++;

    // "Uniflor"
    grafo[i][0] = CDS;
    grafo[i][1] = NE;
    i++;

    //"Nova Esperança"
    grafo[i][0] = UF;
    grafo[i][1] = PR;
    grafo[i][2] = FR;
    grafo[i][3] = MG;
    grafo[i][4] = PDN;
    i++;
          
    //"Floraí"
    grafo[i][0] = PDN;
    grafo[i][1] = NE;
    grafo[i][2] = MG;
    i++;

    //"Colorado"
    grafo[i][0] = IN;
    grafo[i][1] = CDS;
    grafo[i][2] = MG;
    grafo[i][3] = SI;
    grafo[i][4] = NE;
    grafo[i][5] = CNS;
    grafo[i][6] = GR;
    grafo[i][7] = SF;
    i++;

    //"Mandaguaçu"
    grafo[i][0] = FR;
    grafo[i][1] = CL;
    grafo[i][2] = SF;
    grafo[i][3] = IG;
    grafo[i][4] = NE;
    grafo[i][5] = AG;
    i++;
    
    //"Santo Inácio"
    grafo[i][0] = CL;
    grafo[i][1] = CNS;
    i++;
    
    //"Santa Fé"
    grafo[i][0] = CL;
    grafo[i][1] = MG;
    grafo[i][2] = IG;
    grafo[i][3] = GR;
    i++;
    
    //"Iguaraçu"
    grafo[i][0] = SF;
    grafo[i][1] = MG;
    grafo[i][2] = AG;
    i++;

    //"Centenário do Sul"
    grafo[i][0] = CL;
    grafo[i][1] = SI;
    grafo[i][2] = PC;
    grafo[i][3] = FP;
    i++;

    //"Guaraci"               :["Colorado","Santa Fé","Florestópolis"     ],
    grafo[i][0] = CL;
    grafo[i][1] = SF;
    grafo[i][2] = FP;
    i++;
    
    //"Astorga"               :["Mandaguaçu","Iguaraçu","Florestópolis"   ],
    grafo[i][0] = MG;
    grafo[i][1] = IG;
    grafo[i][2] = FP;
    i++;

    //"Porecatu"              :["Centenário do Sul", "Florestópolis"      ],
    grafo[i][0] = CNS;
    grafo[i][1] = FP;
    i++;

    //"Florestópolis"         :["Astorga","Guaraci","Centenário do Sul", "Porecatu"]
    grafo[i][0] = AG;
    grafo[i][1] = GR;
    grafo[i][2] = CNS;
    grafo[i][3] = PC;
    i++;

}

int fnBuscaEmLargura(int mat[][NArestas], int *visitados){
    node_t *Fila = (node_t *) malloc(sizeof(node_t));
    node_t *ret;
    int i = 0, j = 0, w = 0, flagF = 0;

    fnInicia(Fila);

    fnPush(Fila, 8);
    visitados[8] = 1;

    while (tamFila > 0){
        ret = fnPop(Fila);
        printf("ret: %d. \n", ret->num);
        flagF = 0;
        j = 0;
        while (flagF == 0){   
            w = mat[(ret->num) - 1][j];
            if ( w > 22 || w <= 0){
                flagF = 1;
            } else {
                if( w == 22 ){
                    visitados[w] = 1;
                    while (tamFila > 0){
                        ret = fnPop(Fila);
                    }
                    flagF = 1;
                } else if ( visitados[w] == 0){
                    visitados[w] = 1;
                    fnPush(Fila, w);
                }
                j++;                
            }
        }
    }
    

    return 0;
}

int decodeNome(int codigo){
    int var;
    switch (codigo){
        case 1:
            printf("Terra Rica .\n");
        break;
        case 2:
            printf("Nova Aurora .\n");
        break;
        case 3:
            printf("Amaporã .\n");
        break;
        case 4:
            printf("Mirador .\n");
        break;
        case 5:
            printf("Santo Antônio do Caiuá .\n");
        break;
        case 6:
            printf("São João do Caiuá .\n");
        break;
        case 7:
            printf("Paranavaí .\n");
        break;
        case 8:
            printf("Paraíso do Norte .\n");
        break;
        case 9:
            printf("Inajá .\n");
        break;
        case 10:
            printf("Cruzeiro do Sul .\n");
        break;
        case 11:
            printf("Uniflor .\n");
        break;
        case 12:
            printf("Nova Esperança .\n");
        break;
        case 13:
            printf("Floraí .\n");
        break;
        case 14:
            printf("Colorado .\n");
        break;
        case 15:
            printf("Mandaguaçu .\n");
        break;
        case 16:
            printf("Santo Inácio .\n");
        break;
        case 17:
            printf("Iguaraçu .\n");
        break;
        case 18:
            printf("Centenário do Sul .\n");
        break;
        case 19:
            printf("Guaraci .\n");
        break;
        case 20:
            printf("Astorga .\n");
        break;
        case 21:
            printf("Porecatu .\n");
        break;
        case 22:
            printf("Florestópolis .\n");
        break;

        default:
            var = -1;
            break;
    }

    return 0;
}


int fnShowResp(int *visitados){
    int i = 0;
    int ret;
    for (i = 0; i < NumVertices; ++i){
        
        if( visitados[i] == 1){
            printf("Cidade visitada: ");
            ret = decodeNome(i);
        }
    }
    
    return 0;
}


int main(void){  
    int mat[NumVertices][7];
    int visitados[NumVertices];
    int ret, i; 

    for ( i = 0; i < NumVertices; i++){
        visitados[i] = 0;
    }

    fnIniMat(mat);
    ret = fnBuscaEmLargura(mat, visitados);

    fnShowResp(visitados);
    return 0;
}