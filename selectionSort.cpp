#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " arquivo_entrada.in" << endl;
        return 1;
    }

    ifstream entrada(argv[1]);
    if (!entrada) {
        cerr << "Erro ao abrir o arquivo: " << argv[1] << endl;
        return 1;
    }

    int n;
    entrada >> n;
    vector<int> original(n);
    for (int i = 0; i < n; ++i)
        entrada >> original[i];

    entrada.close();

    vector<int> v1 = original;
    vector<int> v2 = original;

    // Tempo Selection Sort
    auto t1 = high_resolution_clock::now();
    selectionSort(v1);
    auto t2 = high_resolution_clock::now();
    auto duracaoSelection = duration_cast<microseconds>(t2 - t1);

    // Tempo Insertion Sort
    auto t3 = high_resolution_clock::now();
    insertionSort(v2);
    auto t4 = high_resolution_clock::now();
    auto duracaoInsertion = duration_cast<microseconds>(t4 - t3);

    // Exibir resultados
    cout << "Arquivo: " << argv[1] << endl;
    cout << "Tempo Selection Sort: " << duracaoSelection.count() << " microssegundos" << endl;
    cout << "Tempo Insertion Sort: " << duracaoInsertion.count() << " microssegundos" << endl;

    if (duracaoSelection < duracaoInsertion)
        cout << "Resultado: Selection Sort foi mais rápido." << endl;
    else if (duracaoInsertion < duracaoSelection)
        cout << "Resultado: Insertion Sort foi mais rápido." << endl;
    else
        cout << "Resultado: Ambos tiveram o mesmo tempo." << endl;

    cout << "-----------------------------" << endl;

    return 0;
}
