#include <iostream>

using namespace std;

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por valor
//    - A segunda deve ser passada por referência 
//    - A terceira deve ser passada "por referência" usando apontadores (passagem "por referência" disponível em C)
//    A função deverá somar 1 ao valor de cada uma das 3 variáveis e retornar.

void func0(int valor, int &referencia, int *referenciaPonteiro){
    valor ++;
    referencia++;
    (*referenciaPonteiro)++;
}


int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int valorInt;
    cin >> valorInt;    
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* intPonteiro = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamVetor; 
    cin >> tamVetor;
    int *vetor = new int[tamVetor];
    for(int i = 0; i < tamVetor; i++){
        cin >> vetor[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &valorInt << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << valorInt << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &intPonteiro << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << intPonteiro << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &vetor << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vetor << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vetor[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    intPonteiro = &valorInt;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << intPonteiro << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *intPonteiro << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *intPonteiro = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << valorInt << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    intPonteiro = vetor;

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << intPonteiro << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *intPonteiro << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    intPonteiro = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    cout << (intPonteiro == vetor ? 'S' : 'N') << endl;

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << intPonteiro << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *intPonteiro << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(int i = 0; i < tamVetor; i++){
        intPonteiro[i] *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for(int i = 0; i < tamVetor; i++){
        cout << vetor[i];
        if(i == tamVetor-1)
            cout << endl;
        else
            cout << " ";
    }

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for(int i = 0; i < tamVetor; i++){
        cout << *(vetor+i);
        if(i == tamVetor-1)
            cout << endl;
        else
            cout << " ";
    }

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for(int i = 0; i < tamVetor; i++){
        cout << *(intPonteiro+i);
        if(i == tamVetor-1)
            cout << endl;
        else
            cout << " ";
    }

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    intPonteiro = &(vetor[tamVetor-1]);

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << intPonteiro << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *intPonteiro << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **ponteiroPonteiroInt = &intPonteiro;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << ponteiroPonteiroInt << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &ponteiroPonteiroInt << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *ponteiroPonteiroInt << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **ponteiroPonteiroInt << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int int1, int2, int3;
    cin >> int1 >> int2 >> int3;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    func0(int1, int2, &int3);
    
    // 37) Imprima o valor das 3 variáveis criadas em (35)
    cout << int1 << " " << int2 << " " << int3 << endl;
    
    return 0;
}