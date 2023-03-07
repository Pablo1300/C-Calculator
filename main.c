#include <stdio.h>
#include <math.h>

#define MULTIPLICADOR 10

//-----------------------------------
//Prototipo funciones
//-----------------------------------
void suma (int *sumando1, int *sumando2);
void resta (int *minuendo, int *sustraendo);
void multiplicacion (int *multiplicando, int *multiplicador);
void division (int *dividendo, int *divisor);

//-----------------------------------
//Función main
//-----------------------------------
int main() {

    //-----------------------------------
    //Variables
    //-----------------------------------
    int num_menu, num1, num2;

    //-----------------------------------
    //Menú
    //-----------------------------------
    printf("\n");
    printf("\tC A L C U L A D O R A\t\n");

    do{
        printf("*****************************\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicación\n");
        printf("4. División\n");
        printf("0. Salir\n");
        printf("*****************************\n\n");

        printf("Escribe el número de la operación deseas realizar: ");
        scanf("%d", &num_menu);

        switch (num_menu) {
            case 1:
                suma(&num1, &num2);
                break;
            case 2:
                resta(&num1, &num2);
                break;
            case 3:
                multiplicacion(&num1, &num2);
                break;
            case 4:
                division(&num1, &num2);
                break;
            case 0:
                printf("Saliendo...");
                break;
            default:
                printf("Esta opción no está disponible\n\n");

        }
    }while (num_menu != 0);

    return 0;
}

//-----------------------------------
//Cuerpo funciones
//-----------------------------------

//-----------------------------------
//Función suma
//-----------------------------------
void suma (int *sumando1, int *sumando2){

   //Declaración de variables
   int resultado_suma, diferencia_digitos_sumandos, diferencia_digitos_sumMayorResultado, i;
   int digitos_sumando1 = 0;
   int digitos_sumando2 = 0;
   int digitos_resultado = 0;

   //Solicitud de los dos sumandos
   printf("Introduce el primer sumando: ");
   scanf("%d", sumando1);
   printf("Introduce el segundo sumando: ");
   scanf("%d", sumando2);
   printf("\n");

   //Cálculo del resultado de la suma
   resultado_suma = *sumando1 + *sumando2;

   //Contamos los dígitos de ambos sumandos y del resultado, y hacemos la comprobaciones y ajustes necesarios si alguno
   //es negativo
    if (*sumando1 != 0) {
        if (*sumando1 < 0){
            digitos_sumando1++;
        }
        for (i = 1; *sumando1 / i != 0; i *= MULTIPLICADOR) {
            digitos_sumando1++;
        }
    }
    else{
        digitos_sumando1++;
    }

    if (*sumando2 != 0) {
        if (*sumando2 < 0){
            digitos_sumando2++;
        }
        for (i = 1; *sumando2 / i != 0; i *= MULTIPLICADOR) {
            digitos_sumando2++;
        }
    }
    else {
        digitos_sumando2++;
    }

    if (resultado_suma != 0) {
        if (resultado_suma < 0){
            digitos_resultado++;
        }
        for (i = 1; resultado_suma / i != 0; i *= MULTIPLICADOR) {
            digitos_resultado++;
        }
    }
    else{
        digitos_resultado++;
    }

    //Si el primer sumando tiene más dígitos que el segundo:
    if (digitos_sumando1 > digitos_sumando2){
        diferencia_digitos_sumandos = digitos_sumando1 - digitos_sumando2;
        diferencia_digitos_sumMayorResultado = digitos_resultado - digitos_sumando1;

        printf("   %d\n", *sumando1);
        printf("+  ");

        for (i = diferencia_digitos_sumandos; i >= 1; i--) {
           printf(" ");
        }
        printf("%d\n", *sumando2);
    }

    //Si el segundo sumando tiene más dígitos que el primero:
    else if(digitos_sumando1 < digitos_sumando2){
        diferencia_digitos_sumandos = digitos_sumando2 - digitos_sumando1;
        diferencia_digitos_sumMayorResultado = digitos_resultado - digitos_sumando2;

        printf("   ");

        for (i = diferencia_digitos_sumandos; i >= 1; i--) {
            printf(" ");
        }
        printf("%d\n", *sumando1);
        printf("+  %d\n", *sumando2);
    }

    //Si ambos sumandos tienen la misma cantidad de dígitos:
    else{
        diferencia_digitos_sumMayorResultado = digitos_resultado - digitos_sumando1;

        printf("   %d\n", *sumando1);
        printf("+  %d\n", *sumando2);
    }

    //Una vez colocados correctamente ambos sumandos, colocamos el resultado de la suma:
    printf("---------------\n");
    printf("  ");
    if (diferencia_digitos_sumMayorResultado == 0) {
        printf(" ");
    }
    else if (diferencia_digitos_sumMayorResultado < 0) {
        if(digitos_sumando2 >= digitos_sumando1) {
            for (i = digitos_resultado; i <= digitos_sumando2; i++) {
                printf(" ");
            }
        } else {
            for (i = digitos_resultado; i <= digitos_sumando1; i++) {
                printf(" ");
            }
        }
    }
    printf("%d\n\n", resultado_suma);
}

//-----------------------------------
//Función resta
//-----------------------------------
void resta (int *minuendo, int *sustraendo){

    //Declaración de variables
    int resultado_resta, diferencia_digitos, diferencia_digitos_numMayorResultado, i;
    int digitos_minuendo = 0;
    int digitos_sustraendo = 0;
    int digitos_resultado = 0;

    //Solicitud del minuendo y sustraendo
    printf("Introduce el minuendo: ");
    scanf("%d", minuendo);
    printf("Introduce el segundo sustraendo: ");
    scanf("%d", sustraendo);
    printf("\n");

    //Cálculo del resultado de la resta
    resultado_resta = *minuendo - *sustraendo;

    //Contamos los dígitos del minuendo, sustraendo y resultado y hacemos las comprobaciones y ajustes necesarios si
    //alguno es negativo :
    if (*minuendo != 0) {
        if (*minuendo < 0){
            digitos_minuendo++;
        }
        for (i = 1; *minuendo / i != 0; i *= MULTIPLICADOR) {
            digitos_minuendo++;
        }
    }
    else{
        digitos_minuendo++;
    }

    if (*sustraendo != 0) {
        if (*sustraendo < 0){
            digitos_sustraendo++;
        }
        for (i = 1; *sustraendo / i != 0; i *= MULTIPLICADOR) {
            digitos_sustraendo++;
        }
    }
    else {
        digitos_sustraendo++;
    }

    if (resultado_resta != 0) {
        if (resultado_resta < 0){
            digitos_resultado++;
        }
        for (i = 1; resultado_resta / i != 0; i *= MULTIPLICADOR) {
            digitos_resultado++;
        }
    }
    else{
        digitos_resultado++;
    }

    //Si el minuendo tiene más dígitos que el sustraendo:
    if (digitos_minuendo > digitos_sustraendo){
        diferencia_digitos = digitos_minuendo - digitos_sustraendo;
        diferencia_digitos_numMayorResultado = digitos_resultado - digitos_minuendo;

        printf("   %d\n", *minuendo);
        printf("-  ");

        for (i = diferencia_digitos; i > 0; i--){
            printf(" ");
        }
        printf("%d\n", *sustraendo);
    }

    //Si el sustraendo tiene más dígitos que el minuendo:
    else if(digitos_minuendo < digitos_sustraendo){
        diferencia_digitos = digitos_sustraendo - digitos_minuendo;
        diferencia_digitos_numMayorResultado = digitos_resultado - digitos_sustraendo;

        printf("   ");
        for (i = diferencia_digitos; i > 0; i--) {
            printf(" ");
        }
        printf("%d\n", *minuendo);
        printf("-  %d\n", *sustraendo);
    }

    //Si el minuendo y el sustraendo tienen la misma cantidad de dígitos:
    else{
        diferencia_digitos_numMayorResultado = digitos_resultado - digitos_minuendo;

        printf("   %d\n", *minuendo);
        printf("-  %d\n", *sustraendo);
    }

    //Una vez colocados correctamente el minuendo y sustraendo, colocamos el resultado de la resta:
    printf("---------------\n");
    printf("  ");
    if (diferencia_digitos_numMayorResultado == 0) {
        printf(" ");
    }
    else if (diferencia_digitos_numMayorResultado < 0) {
        if(digitos_minuendo >= digitos_sustraendo) {
            for (i = digitos_resultado; i <= digitos_minuendo; i++) {
                printf(" ");
            }
        } else {
            for (i = digitos_resultado; i <= digitos_sustraendo; i++) {
                printf(" ");
            }
        }
    }
    printf("%d\n\n", resultado_resta);
}

//-----------------------------------
//Función multiplicación
//-----------------------------------
void multiplicacion (int *multiplicando, int *multiplicador) {

    //Declaración de variables
    int resultado_multiplicacion, diferencia_digitos, ult_cifra_multiplicador, multiplicador_actualizado,
        digitoseparado_multiplicador, resultado_mult_digito, digitos_resultado_mult_digito, i, j, k;
    int digitos_multiplicando = 0;
    int digitos_multiplicador = 0;
    int digitos_resultado = 0;
    int digitos_mult_ult_cifra = 0;

    //Solicitud del multiplicando y multiplicador
    printf("Introduce el multiplicando: ");
    scanf("%d", multiplicando);
    printf("Introduce el segundo multiplicador: ");
    scanf("%d", multiplicador);
    printf("\n");

    resultado_multiplicacion = *multiplicando * *multiplicador;

    //Contamos los dígitos del multiplicando, multiplicador y del resultado, y hacemos las comprobaciones y ajustes
    //necesarios si alguno es negativo
    if (*multiplicando != 0) {
        if (*multiplicando < 0){
            digitos_multiplicando++;
        }
        for (i = 1; *multiplicando / i != 0; i *= MULTIPLICADOR) {
            digitos_multiplicando++;
        }
    } else {
        digitos_multiplicando++;
    }

    if (*multiplicador != 0) {
        if (*multiplicador < 0){
            digitos_multiplicador++;
        }
        for (i = 1; *multiplicador / i != 0; i *= MULTIPLICADOR) {
            digitos_multiplicador++;
        }
    } else {
        digitos_multiplicador++;
    }

    if (resultado_multiplicacion != 0) {
        if (resultado_multiplicacion < 0){
            digitos_resultado++;
        }
        for (i = 1; resultado_multiplicacion / i != 0; i *= MULTIPLICADOR) {
            digitos_resultado++;
        }
    } else {
        digitos_resultado++;
    }

    //Si el multiplicando tiene más dígitos que el multiplicador o los mismos:
    if (digitos_multiplicando >= digitos_multiplicador) {
        diferencia_digitos = digitos_multiplicando - digitos_multiplicador;

        for (i = 1; i <= digitos_multiplicador + 2; i++) {
            printf(" ");
        }
        printf("%d\n", *multiplicando);
        printf("x");
        for (i = diferencia_digitos; i > 0; i--) {
            printf(" ");
        }
        for (i = 1; i < digitos_multiplicador + 2; i++) {
            printf(" ");
        }
        printf("%d\n", *multiplicador);
    }

    //Si el multiplicador tiene más dígitos que el multiplicando:
    else if (digitos_multiplicando < digitos_multiplicador) {
        diferencia_digitos = digitos_multiplicador - digitos_multiplicando;

        for (i = 1; i <= digitos_multiplicando + 2; i++) {
            printf(" ");
        }
        for (i = diferencia_digitos; i > 0; i--) {
            printf(" ");
        }
        printf("%d\n", *multiplicando);
        printf("x");
        for (i = 1; i < digitos_multiplicando + 2; i++) {
            printf(" ");
        }
        printf("%d\n", *multiplicador);
    }

    //Una vez colocados el multiplicando y el multiplicador, realizamos la multiplicación elemento a elemento y
    //colocamos correctamente cada resultado, si el multiplicando es distinto de 0 y el multiplicador tiene más de un
    //dígito:
    if (digitos_multiplicador > 1 && *multiplicando != 0) {
        multiplicador_actualizado = *multiplicador;

        printf("-----------------\n");

        //Para la multiplicación elemento a elemento de todos los dígitos del multiplicador menos el último:
        for (i = 1; i <= digitos_multiplicador - 1; i++) {
            digitoseparado_multiplicador = (multiplicador_actualizado % (int) pow(MULTIPLICADOR, i)) / (int) pow(MULTIPLICADOR, i - 1);
            multiplicador_actualizado = (multiplicador_actualizado / (int) pow(MULTIPLICADOR, i)) * (int) pow(MULTIPLICADOR, i);
            resultado_mult_digito = *multiplicando * digitoseparado_multiplicador;

            digitos_resultado_mult_digito = 0;
            if (resultado_mult_digito < 0){
                digitos_resultado_mult_digito++;
            }
            for (j = 1; resultado_mult_digito / j != 0; j *= MULTIPLICADOR) {
                digitos_resultado_mult_digito++;
            }
            if ((*multiplicador < 0 && *multiplicando < 0 && i == digitos_multiplicador - 1) || (*multiplicador < 0 && i == digitos_multiplicador - 1)){
                break;
            }
            if (digitos_multiplicando >= digitos_multiplicador) {
                if (digitos_resultado_mult_digito > digitos_multiplicando) {
                    for (k = 1; k <= digitos_multiplicador + 2 - i; k++) {
                        printf(" ");
                    }
                } else if (digitos_resultado_mult_digito == digitos_multiplicando) {
                    for (k = 0; k <= digitos_multiplicador + 2 - i; k++) {
                        printf(" ");
                    }
                } else if (resultado_mult_digito == 0) {
                    for (k = 0; k <= diferencia_digitos + digitos_multiplicador * 2 - i + 1; k++) {
                        printf(" ");
                    }
                } else {
                    for (k = 0; k <= digitos_multiplicador + 3 - i; k++) {
                        printf(" ");
                    }
                }
                printf("%d\n", resultado_mult_digito);
            } else {
                if (digitos_resultado_mult_digito > digitos_multiplicando) {
                    for (k = 1; k <= digitos_multiplicando + diferencia_digitos + 2 - i; k++) {
                        printf(" ");
                    }
                } else if (digitos_resultado_mult_digito == digitos_multiplicando) {
                    for (k = 0; k <= digitos_multiplicando + diferencia_digitos + 2 - i; k++) {
                        printf(" ");
                    }
                } else if (resultado_mult_digito == 0) {
                    for (k = 0; k <= diferencia_digitos + digitos_multiplicando * 2 - i + 1; k++) {
                        printf(" ");
                    }
                } else {
                    for (k = 0; k <= digitos_multiplicando + 3 - i; k++) {
                        printf(" ");
                    }
                }
                printf("%d\n", resultado_mult_digito);
            }
        }

        //Para la multiplicación elemento a elemento del último dígito del multiplicador:
        if ((*multiplicador < 0 && *multiplicando < 0) || *multiplicador < 0){
            ult_cifra_multiplicador = *multiplicador / (int) pow(MULTIPLICADOR, digitos_multiplicador - 2);
        } else {
            ult_cifra_multiplicador = *multiplicador / (int) pow(MULTIPLICADOR, digitos_multiplicador - 1);
        }
        resultado_mult_digito = *multiplicando * ult_cifra_multiplicador;
        if (resultado_mult_digito < 0){
            digitos_mult_ult_cifra++;
        }
        for (j = 1; resultado_mult_digito / j != 0; j *= MULTIPLICADOR) {
            digitos_mult_ult_cifra++;
        }
        printf("+");
        if (digitos_multiplicando >= digitos_multiplicador) {
            if (digitos_mult_ult_cifra > digitos_multiplicando) {
                for (k = 1; k <= digitos_multiplicador + 1 - i; k++) {
                    printf(" ");
                }
            } else if (digitos_mult_ult_cifra == digitos_multiplicando) {
                for (k = 0; k <= digitos_multiplicador + 1 - i; k++) {
                    printf(" ");
                }
            } else {
                for (k = 0; k <= digitos_multiplicador + 2 - i; k++) {
                    printf(" ");
                }
            }
            printf("%d\n", resultado_mult_digito);
        } else {
            if (digitos_mult_ult_cifra > digitos_multiplicando) {
                for (k = 1; k <= digitos_multiplicando + diferencia_digitos + 1 - i; k++) {
                    printf(" ");
                }
            } else if (digitos_mult_ult_cifra == digitos_multiplicando) {
                for (k = 0; k <= digitos_multiplicando + diferencia_digitos + 1 - i; k++) {
                    printf(" ");
                }
            } else {
                for (k = 0; k <= digitos_multiplicando + 2 - i; k++) {
                    printf(" ");
                }
            }
            printf("%d\n", resultado_mult_digito);
        }
    }

    //Colocamos el resultado final de la multiplicación:
    printf("-----------------\n");
    if (digitos_multiplicando >= digitos_multiplicador) {
        if (digitos_resultado == digitos_multiplicando) {
            for (i = 1; i <= digitos_multiplicador + 2; i++) {
                printf(" ");
            }
            printf("%d\n\n", resultado_multiplicacion);
        } else if (digitos_resultado > digitos_multiplicando) {
            for (i = 1; i <= digitos_multiplicador + 2 - (digitos_resultado - digitos_multiplicando); i++) {
                printf(" ");
            }
            printf("%d\n\n", resultado_multiplicacion);
        } else if (resultado_multiplicacion == 0){
            for (i = 0; i < digitos_multiplicando * 2 - 1; i++) {
                printf(" ");
            }
            printf("%d\n\n", resultado_multiplicacion);
        }
    } else {
        if (digitos_resultado == digitos_multiplicador ) {
            for (i = 1; i <= digitos_multiplicando + 2; i++) {
                printf(" ");
            }
            printf("%d\n\n", resultado_multiplicacion);
        } else if (digitos_resultado > digitos_multiplicador) {
            for (i = 1; i < digitos_multiplicando + 2 - (digitos_resultado - digitos_multiplicador); i++) {
                printf(" ");
            }
            printf(" %d\n\n", resultado_multiplicacion);
        } else if (resultado_multiplicacion == 0){
            for (i = 0; i < diferencia_digitos + digitos_multiplicando * 2; i++) {
                printf(" ");
            }
            printf(" %d\n\n", resultado_multiplicacion);
        }
    }
}

//-----------------------------------
//Función división
//-----------------------------------
void division (int *dividendo, int *divisor) {

    //Declaración de variables
    int cociente, dividendo_actualizado, resto_division_digitos, resto_cifra, sobrante_dividendo, cifra_bajar, digitos_dividendo_prima,
        i, j, k;
    int digitos_dividendo = 0;
    int digitos_divisor = 0;
    int digitos_cociente = 0;
    int digitos_resto_division_digitos = 0;
    int digitos_dividendo_actualizado = 0;
    int digitos_sobrante_dividendo = 0;
    int l = 0;

    //Solicitud del dividendo y divisor
    printf("Introduce el dividendo: ");
    scanf("%d", dividendo);
    //Comprobación para que el divisor sea distinto de 0
    do {
        printf("Introduce el segundo divisor: ");
        scanf("%d", divisor);
    } while (*divisor == 0);
    printf("\n");

    //Calculamos el cociente de la división
    cociente = *dividendo / *divisor;

    //Contamos los dígitos del dividendo, divisor, cociente y resto.
    if (*dividendo != 0) {
        if (*dividendo < 0) {
            digitos_dividendo++;
        }
        for (i = 1; *dividendo / i != 0; i *= MULTIPLICADOR) {
            digitos_dividendo++;
        }
    } else {
        digitos_dividendo++;
    }
    digitos_dividendo_prima = digitos_dividendo;

    if (*divisor != 0) {
        if (*divisor < 0) {
            digitos_divisor++;
        }
        for (i = 1; *divisor / i != 0; i *= MULTIPLICADOR) {
            digitos_divisor++;
        }
    } else {
        digitos_divisor++;
    }

    if (cociente != 0) {
        if (cociente < 0) {
            digitos_cociente++;
        }
        for (i = 1; cociente / i != 0; i *= MULTIPLICADOR) {
            digitos_cociente++;
        }
    } else {
        digitos_cociente++;
    }

    //Colocamos el dividendo y divisor para realizar la división:
    printf("%d  | %d\n", *dividendo, *divisor);
    for (i = 1; i <= digitos_dividendo + 2; i++) {
        printf(" ");
    }
    printf("+-------------\n");

    //Hacemos ajustes y comprobaciones por si el usuario introduce un dividendo o divisor negativos, o ambos:
    if (*dividendo < 0) {
        *dividendo *= -1;
        digitos_dividendo--;
        digitos_resto_division_digitos--;
    }

    if (*divisor < 0) {
        *divisor *= -1;
        digitos_divisor--;
    }

    if (cociente < 0) {
        digitos_cociente--;
    }

    //Si el dividendo es mayor o igual que el divisor realizamos la división como de normal:
    if (*dividendo >= *divisor) {

        //Calculamos y colocamos el primer resultado de la división del dividendo por dígitos, y seguido, en la misma linea
        //colocamos el cociente haciendo que esté justo debajo del divisor:
        dividendo_actualizado = *dividendo / (int) pow(MULTIPLICADOR, digitos_dividendo - digitos_divisor);
        if (dividendo_actualizado < *divisor) {
            dividendo_actualizado = *dividendo;
            dividendo_actualizado =
                    dividendo_actualizado / (int) pow(MULTIPLICADOR, digitos_dividendo - digitos_divisor - 1);
        }
        resto_division_digitos = dividendo_actualizado % *divisor;
        for (i = 1; dividendo_actualizado / i != 0; i *= MULTIPLICADOR) {
            digitos_dividendo_actualizado++;
        }
        if (resto_division_digitos != 0) {
            for (i = 1; resto_division_digitos / i != 0; i *= MULTIPLICADOR) {
                digitos_resto_division_digitos++;
            }
        } else {
            digitos_resto_division_digitos++;
        }
        sobrante_dividendo = *dividendo - (dividendo_actualizado * (int) (pow(MULTIPLICADOR, digitos_dividendo - digitos_dividendo_actualizado)));
        if (sobrante_dividendo != 0) {
            for (i = 1; sobrante_dividendo / i != 0; i *= MULTIPLICADOR) {
                digitos_sobrante_dividendo++;
            }
        } else {
            digitos_sobrante_dividendo++;
        }
        j = 0;
        do {
            j++;
            if (j > digitos_sobrante_dividendo) {
                j--;
                break;
            }
            cifra_bajar = sobrante_dividendo / (int) pow(MULTIPLICADOR, digitos_sobrante_dividendo - j);
        } while (resto_division_digitos * (int) pow(MULTIPLICADOR, j) + cifra_bajar < *divisor);
        for (i = 1; i <= digitos_dividendo_actualizado - digitos_resto_division_digitos; i++) {
            printf(" ");
        }
        resto_cifra = resto_division_digitos * (int) pow(MULTIPLICADOR, j) + cifra_bajar;
        if (digitos_cociente != 1) {
            printf("%d%d", resto_division_digitos, cifra_bajar);
        } else {
            printf("%d", resto_division_digitos);
        }
        for (i = 1; i <= digitos_dividendo - digitos_dividendo_actualizado + 4 - j; i++) {
            printf(" ");
        }
        printf("%d\n", cociente);

        //Calculamos y colocamos los demás resultados de dividir el dividendo por partes:
        for (i = 1; cociente / i != 0; i *= MULTIPLICADOR) {
            if (((cociente / i) * i - ((cociente / (i * MULTIPLICADOR)) * (i * MULTIPLICADOR))) == 0) {
                l++;
            }
        }

        for (i = 1; i < digitos_cociente - l; i++) {
            resto_division_digitos = resto_cifra % *divisor;
            sobrante_dividendo = sobrante_dividendo -
                                 (sobrante_dividendo / (int) pow(MULTIPLICADOR, digitos_sobrante_dividendo - j) *
                                  (int) pow(MULTIPLICADOR, digitos_sobrante_dividendo - j));

            digitos_sobrante_dividendo = 0;
            for (k = 1; sobrante_dividendo / k != 0; k *= MULTIPLICADOR) {
                digitos_sobrante_dividendo++;
            }

            j = 0;
            do {
                j++;
                if (j > digitos_sobrante_dividendo) {
                    j--;
                    break;
                }
                cifra_bajar = sobrante_dividendo / (int) pow(MULTIPLICADOR, digitos_sobrante_dividendo - j);
            } while (resto_division_digitos * (int) pow(MULTIPLICADOR, j) + cifra_bajar < *divisor);
            resto_cifra = resto_division_digitos * (int) pow(MULTIPLICADOR, j) + cifra_bajar;
            if (resto_division_digitos != 0) {
                digitos_resto_division_digitos = 0;
            } else {
                digitos_resto_division_digitos = 1;
            }
            if (resto_cifra != 0) {
                for (k = 1; resto_cifra / k != 0; k *= MULTIPLICADOR) {
                    digitos_resto_division_digitos++;
                }
            } else {
                digitos_resto_division_digitos++;
            }
            for (k = 0; k <= digitos_dividendo_prima - (digitos_sobrante_dividendo - (j - 1)) -
                             digitos_resto_division_digitos; k++) {
                printf(" ");
            }
            if (i < digitos_cociente - l - 1) {
                printf("%d%d\n", resto_division_digitos, cifra_bajar);
            } else if (i == digitos_cociente - l - 1) {
                if ((cociente - ((cociente / MULTIPLICADOR) * MULTIPLICADOR)) == 0) {
                    printf("%d%d\n", resto_division_digitos, cifra_bajar);
                } else {
                    if (resto_division_digitos != 0) {
                        printf("%d\n", resto_division_digitos);
                    } else if (resto_division_digitos < 9 && digitos_divisor > 1) {
                        printf(" %d\n", resto_division_digitos);
                    }
                }
            }
        }
        printf("\n");
    //Si el dividendo es menor que el divisor, el cociente es 0 y el resto es igual al dividendo, por lo que los
    //colocamos manualmente:
    } else {
        if (digitos_dividendo_prima != digitos_dividendo) {
            printf("-%d    %d\n", *dividendo, cociente);
        } else {
            printf("%d    %d\n", *dividendo, cociente);
        }
    }
}