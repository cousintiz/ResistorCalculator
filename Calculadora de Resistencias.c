#include <stdio.h>
#include <stdbool.h>

    void serie (int n);
    void paralelo (int n);
    void TrianguloEstrela (int n);
    void EstrelaTriangulo (int n);

int main(){

    int op = -1, n = -1;
    bool cont = true;
    

   while (cont == true){   

        while(op <= 0){
            printf("\n========= CALCULADORA DE RESISTENCIAS =========");
            printf("\n[1] Resistencias em Serie");
            printf("\n[2] Resistencias em Paralelo");
            printf("\n[3] Converter de Associacao Triangulo para Estrela");
            printf("\n[4] Converter de Associacao Estrela para Triangulo");
            printf("\n[5] Sair!");
            printf("\nIndique a opcao desejada:");
            scanf("%d", &op);

             if (op <= 0){
                    puts("Erro! Introduza uma das opcoes acima");
                }

        }

             if (op == 5){
                    cont == false;
                    return 1;
                }

            while (n <= 0){

                printf("\nIntroduza o numero de resistencias do circuito:");
                scanf("%d", &n);

                    if (n <= 0){ 
                    printf("\nErr0! O numero de resistencias tem que ser Positivo e maior que zero.");  
                    }       
            }

                        switch (op){

                                    case 1:
                                            serie(n);
                                        break;

                                    case 2:
                                            paralelo(n);
                                        break;

                                    case 3:
                                            TrianguloEstrela(n);
                                        break;

                                    case 4:
                                            EstrelaTriangulo(n);
                                        break;

                        }
                        op = -1;
                            
    }
                         
 return 0;
}


     void serie (int n){

        int i;
        float r, req;
             req = 0;

            for(i = 1; i <= n; i++){

                printf("\nIntroduza a %d Resistencia:", i);
                scanf("%f", &r);

                req = req + r;
            }
        printf("\nA Resistencia equivalente e: %.2f Ohms", req);
        
    }

                void paralelo (int n){

                int i;
                float r, req;
                    req = 0.0;

                    for(i = 1; i <= n; i++){

                        printf("\nIntroduza a %d Resistencia:", i);
                        scanf("%f", &r);

                        req = req + (1/r);
                    }

                    req = (1/req);

                printf("\nA Resistencia equivalente e: %.2f Ohms", req);
            }
  
                void TrianguloEstrela (int n){

                    int i;
                    float r[n], ra, rb, rc;
                    
                        
                        for(i = 0; i < n; i++){

                            printf("\nIntroduza a %d Resistencia:", i+1);
                            scanf("%f", &r[i]);
                        }

                        ra = (r[0]*r[1] + r[0]*r[2] + r[2]*r[1]) / r[1];
                        rb = (r[0]*r[1] + r[0]*r[2] + r[2]*r[1]) / r[0];
                        rc = (r[0]*r[1] + r[0]*r[2] + r[2]*r[1]) / r[2];

                         printf("\nRa = %.2f Ohms", ra);
                         printf("\nRb = %.2f Ohms", rb);
                         printf("\nRc = %.2f Ohms", rc);

                }

                void EstrelaTriangulo (int n){

                    int i;
                    float r[n], r1, r2, r3;
                    
                        
                        for(i = 0; i < n; i++){

                            printf("\nIntroduza a %d Resistencia:", i+1);
                            scanf("%f", &r[i]);

                        }

                        r1 = (r[1]*r[2]) / (r[0] + r[1] + r[2]);
                        r2 = (r[0]*r[2]) / (r[0] + r[1] + r[2]);
                        r3 = (r[0]*r[1]) / (r[0] + r[1] + r[2]);

                         printf("\nRa = %.2f Ohms", r1);
                         printf("\nRb = %.2f Ohms", r2);
                         printf("\nRc = %.2f Ohms", r3);

                }
                