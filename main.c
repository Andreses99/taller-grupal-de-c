#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>

int Uw,Fll;
char aux;

int falling(char number[10]){
    for (int i =0;i<strlen(number);i++){
        for (int j =0;j<strlen(number)-1;j++){
            if (number[j]>number[j+1]){
                aux=number[j];
                number[j]=number[j+1];
                number[j+1]=aux;
            }
        }
    }
    Fll=atoi(number);
    return Fll;
}
int Upward(char number[10]){
    for (int i =0;i<strlen(number);i++){
        for (int j =0;j<strlen(number)-1;j++){
            if (number[j]<number[j+1]){
                aux=number[j];
                number[j]=number[j+1];
                number[j+1]=aux;
            }
        }
    }
    Uw=atoi(number);
    return Uw;
}
int numberMagic(char number[10]) {
    return Upward(number)-falling(number);
}

void numPrimos(int num){
    int cont;
    int numPrim;

    for (int i = num; i>0 ; --i) {
        numPrim=1;
        cont=2;
        while (cont<=(i/2)){
            if (i % cont==0) {
                numPrim = 0;

            }
            cont++;
        }
        if (numPrim) {
            printf("%d-", i);

        }

    }

}

void numEgolatra(double num) {

    double sum=0;
    double tamanho = sizeof(num)-1;
    char numString [sizeof(num)];
    sprintf(numString, "%d", num);


    if (num>0 & num<10){
        printf("\n el numero %d es Egolatra", num);
    }
    else {
        for (int i = 0; i < tamanho; i++) {
            int cifraActual = numString[i] - '0';
            //  printf("\n %d-",cifraActual);
            int elevar = pow(cifraActual, tamanho);
            //printf(" \n %d - %d", cifraActual, tamanho);
            sum = sum + (elevar);
            // printf("%d *",sum);
        }

        if (sum == num) {
            printf("\n el numero %d es Egolatra", num);
        } else {
            printf(" \n EL NUMERO %d NO ES EGOLATRA", num);
        }
    }
}

int prueba() {

    int cont = 0;
    int tamanho ;
    int sumatoria = 0;
    char prue[] = {"OOXXOXXOOO"};
    tamanho = sizeof(prue);
    int sumar[sizeof(prue)];
    for (int i = 0; i <= tamanho; ++i) {
        cont++;
        if (prue[i] == 'O') {

            sumar[i] = cont;
        } else if (prue[i] == 'X') {
            cont = 0;
            sumar[i] = cont;
        }
    }
    for (int j = 0; j <=tamanho-2; ++j) {

        printf("%d ", sumar[j]);
        sumatoria = sumatoria + sumar[j];

    }
    return sumatoria;

}

double CalImc(float peso, float altura) {
    return peso/(altura*altura);
}


int main() {
    int opt = 0;
    bool continuar = true;

    while (continuar) {

        printf("\n\n\t-*-*-*-*-*-*-* BIENVENIDOS -*-*-*-*-*-*-*-*-*\n\n");

        printf("1) Encontrar los numeros primos descendentemente. \n");
        printf("2) Verificar si el numero es egolatra o no.\n");
        printf("3) Numero Magico\n");
        printf("4)IMC \n");
        printf("5).............\n");
        printf("6)....................\n");
        printf("7) Ver el resultado de la prueba ya registrada. \n");
        printf("8) Salir del programa \n");
        printf("Que desea hacer? \n");
        scanf("%d", &opt);

        switch (opt) {

            case 1:
                printf("\tEjercicio 1\n");
                printf("Digite un numero\n");
                int numPrim;
                scanf("%d", &numPrim);
                if (numPrim > 0) {
                    numPrimos(numPrim);
                } else {
                    printf("Error tiene que elegir un numero mayor a 1\n");
                }
                break;

            case 2:
                printf("\tEjercicio 2 \n");
                printf("Digite un numero para saber si es egolatra o no \n");
                double num;
                scanf("%d", &num);
                numEgolatra(num);

                break;

            case 3:
                
                printf("Bienvenido al Programa de Numeros Magicos \n");
                printf("Digite un numero: \n");
                char number[10];
                scanf("%s", number);
                int nb;
                nb = atoi(number);
                if(nb>0 && nb <100000){
                    if (nb == numberMagic(number)) {
                        printf("El numero %i es un numero magico\n",nb);
                    }
                    else {
                        printf("El numero %i no es un numero magico\n",nb);
                    }
                } else{
                    printf("Caracter introducido es incorrecto");
                }
                break;

            case 4:
                 printf("¿Es usted Hombre o Mujer?\n");
                printf("Escribe h para hombre y m para mujer\n");
                char genero;
                scanf("%s", &genero);
                if( genero =='h' || genero =='m') {
                    printf("Digite su peso?\n");
                    float peso, altura;
                    if (scanf("%f", &peso) != 1) {
                        printf("solo se puede ingresar numeros ejemplo 53");
                        continuar = false;
                    } else {
                        printf("Digite su altura \n");
                        if (scanf("%f", &altura) != 1) {
                            printf("solo se puede ingresar numeros ejemplo 1.60");
                            continuar = false;
                        } else {
                            switch (genero) {
                                case 'h':
                                    if (CalImc(peso, altura) <= 17) {
                                        printf("Desnutricion");
                                    } else if (CalImc(peso, altura) > 17 && CalImc(peso, altura) < 20) {
                                        printf("Bajo peso");
                                    } else if (CalImc(peso, altura) >= 20 && CalImc(peso, altura) < 25) {
                                        printf("Normal");
                                    } else if (CalImc(peso, altura) >= 25 && CalImc(peso, altura) < 30) {
                                        printf("Sobrepeso");
                                    } else if (CalImc(peso, altura) >= 30 && CalImc(peso, altura) < 35) {
                                        printf("Obesidad");
                                    } else if (CalImc(peso, altura) >= 35 && CalImc(peso, altura) <= 40) {
                                        printf("Obesidad Marcada");
                                    } else if (CalImc(peso, altura) > 40) {
                                        printf("Obesidad Morbida ");
                                    }
                                    break;
                                case 'm':
                                    if (CalImc(peso, altura) <= 16) {
                                        printf("Desnutricion");
                                    } else if (CalImc(peso, altura) > 16 && CalImc(peso, altura) < 20) {
                                        printf("Bajo peso");
                                    } else if (CalImc(peso, altura) >= 20 && CalImc(peso, altura) < 24) {
                                        printf("Normal");
                                    } else if (CalImc(peso, altura) >= 24 && CalImc(peso, altura) < 29) {
                                        printf("Sobrepeso");
                                    } else if (CalImc(peso, altura) >= 29 && CalImc(peso, altura) < 34) {
                                        printf("Obesidad");
                                    } else if (CalImc(peso, altura) >= 34 && CalImc(peso, altura) <= 39) {
                                        printf("Obesidad Marcada");
                                    } else if (CalImc(peso, altura) > 39) {
                                        printf("Obesidad Morbida ");
                                    }
                                    break;
                                default:
                                    printf("Error %s no es valido por favor ingresa de nuevo", genero);
                                    break;
                            }
                        }
                    }
                    break;

                    case 5:
                        printf("\tEjercicio 5 \n");

                    break;

                    case 6:
                        printf("\tEjercicio 6\n ");

                    break;

                    case 7:

                        printf("\tEjercicio 7\n ");
                    printf("\nla suma dio! %d \n", prueba());


                    break;

                    case 8:
                        printf("\tPrograma terminado que tenga buen dia \n");
                    continuar = false;


                    break;
                    default:
                        puts("Error");
                    continuar = false;

                }

        }

    }
    return 0;
}
