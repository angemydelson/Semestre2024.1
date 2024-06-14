#include "bits/stdc++.h" 
using namespace std; 

int maximo(int a, int b);  
  
int subsequenciaComum(string str1, string str2, int len1, int len2) {  
    int matriz[len1 + 1][len2 + 1];  
    int idx1, idx2;  
      
    for (idx1 = 0; idx1 <= len1; idx1++) {  
        for (idx2 = 0; idx2 <= len2; idx2++) {  
            if (idx1 == 0 || idx2 == 0)  
                matriz[idx1][idx2] = 0;  
            else if (str1[idx1 - 1] == str2[idx2 - 1])  
                matriz[idx1][idx2] = matriz[idx1 - 1][idx2 - 1] + 1;  
            else
                matriz[idx1][idx2] = maximo(matriz[idx1 - 1][idx2], matriz[idx1][idx2 - 1]);  
        }  
    }  
          
    return matriz[len1][len2];  
}  
  
int maximo(int a, int b) {  
    return (a > b) ? a : b;  
}  

string criaSequencia(vector<string> grade) {
    int passosNum, inicioX, inicioY, linhaAtual, colunaAtual, i;
    string linha, passos, resultado = "";

    cin >> passosNum >> inicioX >> inicioY;
    if (passosNum != 0)
        cin >> passos;

    resultado += grade[inicioX-1][inicioY-1]; 
    linhaAtual = inicioX-1;
    colunaAtual = inicioY-1;

    map<char, pair<int, int>> movimentos = {
        {'N', {-1, 0}},
        {'S', {1, 0}},
        {'E', {0, 1}},
        {'W', {0, -1}}
    };

    for (i = 0; i < passosNum; i++) {
        linhaAtual += movimentos[passos[i]].first;
        colunaAtual += movimentos[passos[i]].second;
        resultado += grade[linhaAtual][colunaAtual];
    }

    return resultado;
}

int main() { 
    int testes, altura, largura, i, msc, casoAtual = 1;
    string linha, sequenciaA, sequenciaB;

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    cin >> testes;
    while (testes--) {
        cin >> altura >> largura;
        vector<string> grade;
        for (i = 0; i < altura; i++) {
            cin >> linha;
            grade.push_back(linha);
        }

        sequenciaA = criaSequencia(grade);
        sequenciaB = criaSequencia(grade);

        msc = subsequenciaComum(sequenciaA, sequenciaB, sequenciaA.size(), sequenciaB.size());
        cout << "Case " << casoAtual << ": ";
        cout << sequenciaA.size() - msc << ' ' << sequenciaB.size() - msc << '\n';
        casoAtual++;
    }

    return 0; 
} 
