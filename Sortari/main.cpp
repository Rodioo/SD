#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector <int> num;

void bubbleSort(int n, int nMax)
{
    num.clear();
    for(int i = 0; i < n; ++i)
        num.push_back(rand() % nMax + 1);
    clock_t start = clock();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if(num[j] > num[j + 1])
            swap(num[j], num[j + 1]);
    clock_t sfarsit = clock();
    double secunde = double(sfarsit - start) / CLOCKS_PER_SEC;
    if (is_sorted(num.begin(), num.end()))
        cout << "Sortarea a fost ok, iar bubblesort-ul a durat " << secunde <<" secunde." << endl;
    else
        cout << "Sortarea nu este corecta." << endl;
}

void countSort(int n, int nMax)
{
    num.clear();
    for(int i = 0; i < n; ++i)
        num.push_back(rand() % nMax + 1);
    clock_t start = clock();
    int maxim = num[0];
    for(int i = 1; i < n; ++i)
        if (num[i] > maxim)
            maxim = num[i];
    vector <int> freq;
    vector <int> ans(n);
    for(int i = 0; i <= maxim; ++i)
        freq.push_back(0);
    for(int i = 0; i < n; ++i)
        freq[num[i]]++;
    for(int i = 1; i <= maxim; ++i)
        freq[i] += freq[i - 1];
    for(int i = 0; i < n; ++i)
    {
        ans[freq[num[i]] - 1] = num[i];
        freq[num[i]]--;
    }
    for(int i = 0; i < n; ++i)
        num[i] = ans[i];
    clock_t sfarsit = clock();
    double secunde = double(sfarsit - start) / CLOCKS_PER_SEC;
    if (is_sorted(num.begin(), num.end()))
        cout << "Sortarea a fost ok, iar countsort-ul a durat " << secunde <<" secunde." << endl;
    else
        cout << "Sortarea nu este corecta." << endl;
}

void imperaMerge(vector <int>& v, int stanga, int mijloc, int dreapta)
{
    int lungimeStanga = mijloc - stanga + 1;
    int lungimeDreapta = dreapta - mijloc;
    int  i = 0, j = 0, k = stanga;
    vector <int> v1 (v.begin() + stanga, v.begin() +  stanga + lungimeStanga);
    vector <int> v2 (v.begin() + mijloc + 1, v.begin() + mijloc + 1 + lungimeDreapta);
    while(i < lungimeStanga && j < lungimeDreapta)
    {
        if(v1[i]<=v2[j])
        {
            v[k] = v1[i];
            i++;
        }
        else
        {
            v[k] = v2[j];
            j++;
        }
        k++;
    }
    while(i < lungimeStanga)
    {
        v[k] = v1[i];
        k++;
        i++;
    }
    while(j < lungimeDreapta)
    {
        v[k] = v2[j];
        k++;
        j++;
    }
}
void mergeSort(vector <int>& v, int stanga, int dreapta)
{
    if(stanga >= dreapta)
        return;
    int mijloc = stanga + (dreapta - stanga) / 2;
    mergeSort(v, stanga, mijloc);
    mergeSort(v, mijloc + 1, dreapta);
    imperaMerge(v, stanga, mijloc, dreapta);

}

int medianaDin3(int a, int b, int c) {
    if ((a > b) xor (a > c))
        return a;
    else if ((b < a) xor (b < c))
        return b;
    else
        return c;
}

int partitieMediana(vector<int> &v, int start, int sfarsit) {
    int pivot = medianaDin3(v[start], v[(start + sfarsit) / 2], v[sfarsit]);
    int i = start, j = sfarsit;
    int aux;
    while(i <= j) {
        while(v[i] < pivot) {
            i++;
        }
        while(v[j] > pivot) {
            j--;
        }
        if(i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    return i;
}

void quicksortMediana(vector<int> &v, int start, int sfarsit) {
    if(start < sfarsit) {
        int pivotIndex = partitieMediana(v, start, sfarsit);
        quicksortMediana(v, start, pivotIndex - 1);
        quicksortMediana(v, pivotIndex, sfarsit);
    }
}

int partitieRandom(vector<int> &v, int start, int sfarsit) {
    srand(time(NULL));
    int index = start + rand() % (sfarsit - start);
    int pivot = v[index];
    int i = start, j = sfarsit;
    int aux;
    while(i <= j) {
        while(v[i] < pivot) {
            i++;
        }
        while(v[j] > pivot) {
            j--;
        }
        if(i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    return i;
}

void quicksortRandom(vector<int> &v, int start, int sfarsit) {
    if(start < sfarsit) {
        int pivotIndex = partitieRandom(v, start, sfarsit);
        quicksortRandom(v, start, pivotIndex - 1);
        quicksortRandom(v, pivotIndex, sfarsit);
    }
}

void countSortForRadixBase10(vector <int> &v, int powerOf10)
{
    const int numOfDigits = 10;
    vector <int> ans(v.size());
    vector <int> freq;
    for(int i = 0; i < numOfDigits; ++i)
        freq.push_back(0);
    for(int i = 0; i < v.size(); ++i)
        freq[(v[i] / powerOf10) % numOfDigits]++;
    for(int i = 1; i < numOfDigits; ++i)
        freq[i] += freq[i - 1];
    for(int i = v.size() - 1; i >= 0; i--)
    {
        ans[freq[(v[i] / powerOf10) % numOfDigits] - 1] = v[i];
        freq[(v[i] / powerOf10) % numOfDigits]--;
    }
    for(int i = 0; i < v.size(); ++i)
        v[i] = ans[i];
}

void radixSortBase10(int n, int nMax)
{
    num.clear();
    for(int i = 0; i < n; ++i)
        num.push_back(rand() % nMax + 1);
    clock_t start = clock();
    int maxim = 0;
    for(int elem: num)
        if (elem > maxim)
            maxim = elem;
    for(int i = 1; maxim / i > 0; i *= 10)
        countSortForRadixBase10(num, i);
    clock_t sfarsit = clock();
    double secunde = (double) (sfarsit - start) / CLOCKS_PER_SEC;
    if (is_sorted(num.begin(), num.end()))
        cout << "Sortarea a fost ok, iar radixsort-ul cu baza 10 a durat " << secunde <<" secunde." << endl;
    else
        cout << "Sortarea nu este corecta." << endl;
}

void countSortForRadixBase2(vector <int> &v, int powerOf2) ///Am folosit operatii pe biti pe principiul ca:
                                                           /// x / 2 = x >> 1; x * 2 = x << 1; x % 2 == x & 1;
{
    const int numOfDigits = 2;
    vector <int> ans(v.size());
    vector <int> freq;
    for(int i = 0; i < numOfDigits; ++i)
        freq.push_back(0);
    for(int i = 0; i < v.size(); ++i)
        freq[(v[i] >> powerOf2) & 1]++;
    for(int i = 1; i < numOfDigits; ++i)
        freq[i] += freq[i - 1];
    for(int i = v.size() - 1; i >= 0; i--)
    {
        ans[freq[(v[i] >> powerOf2) & 1] - 1] = v[i];
        freq[(v[i] >> powerOf2) & 1]--;
    }
    for(int i = 0; i < v.size(); ++i)
        v[i] = ans[i];
}

void radixSortBase2(int n, int nMax)
{
    num.clear();
    for(int i = 0; i < n; ++i)
        num.push_back(rand() % nMax + 1);
    clock_t start = clock();
    int maxim = 0;
    for(int elem: num)
        if (elem > maxim)
            maxim = elem;
    for(int i = 0; maxim >> i > 0; i++)
        countSortForRadixBase2(num, i);
    clock_t sfarsit = clock();
    double secunde = (double) (sfarsit - start) / CLOCKS_PER_SEC;
    if (is_sorted(num.begin(), num.end()))
        cout << "Sortarea a fost ok, iar radixsort-ul cu baza 2 a durat " << secunde <<" secunde." << endl;
    else
        cout << "Sortarea nu este corecta." << endl;
}


int main()
{
int t, n, nMax, nr;
srand(time(NULL));
cout << "Numarul de teste: ";
cin >> t;
for (int i = 0; i < t; ++i)
{
    cout << "Numarul de elemente de sortat: ";
    cin >> n;
    cout << "Valoarea maxima: ";
    cin >> nMax;
    if (n <= 10000000)
    {
        num.clear();
        for(int j = 0; j < n; j++)
            num.push_back(rand() % nMax + 1);
        clock_t start = clock();
        sort(num.begin(), num.end());
        clock_t sfarsit = clock();
        double secunde = double(sfarsit - start) / CLOCKS_PER_SEC;
        cout << "Sort-ul default din C++ a durat " << secunde <<" secunde." << endl;
    }
    else
        cout << "Timpul de executie al sort-ului default este prea mare pentru input-ul dat." << endl;
    if (n <= 10000)
        bubbleSort(n, nMax);    ///Pentru n > 10^4 timpul de executie este prea mare (10 ^ 5 = 30 - 35 de secunde)
    else
        cout << "Timpul de executie al bubblesort-ului este prea mare pentru input-ul dat." << endl;
    if (n <= 100000000)
        countSort(n, nMax);    /// Pentru n > 10^8 timpul de executie este prea mare
    else
        cout << "Timpul de executie al countsort-ului este prea mare pentru input-ul dat." << endl;

    if (n <= 10000000)         /// Pentru n > 10 ^ 7 timpul de executie este prea mare
    {
        num.clear();
        for(int j = 0; j < n; j++)
            num.push_back(rand() % nMax + 1);
        clock_t start = clock();
        mergeSort(num, 0, n - 1);
        clock_t sfarsit = clock();
        double secunde = double(sfarsit - start) / CLOCKS_PER_SEC;
        if (is_sorted(num.begin(), num.end()))
            cout << "Sortarea a fost ok, iar mergesort-ul a durat " << secunde <<" secunde." << endl;
        else
            cout << "Sortarea nu este corecta." << endl;
    }
    else
        cout << "Timpul de executie al mergesort-ului este prea mare pentru input-ul dat." << endl;

    if (n <= 10000000)     ///Pentru n > 10 ^ 8 timpul de executie este prea mare
    {
        num.clear();
        for(int j = 0; j < n; j++)
            num.push_back(rand() % nMax + 1);
        vector <int> num1 = num;
        clock_t start = clock();
        quicksortMediana(num, 0, n - 1);
        clock_t sfarsit = clock();
        double secunde = double(sfarsit - start) / CLOCKS_PER_SEC;
        if (is_sorted(num.begin(), num.end()))
            cout << "Sortarea a fost ok, iar quicksort-ul cu mediana din 3 a durat " << secunde <<" secunde." << endl;
        else
            cout << "Sortarea nu este corecta." << endl;

        start = clock();
        quicksortRandom(num1, 0, n - 1);
        sfarsit = clock();
        secunde = double(sfarsit - start) / CLOCKS_PER_SEC;
        if (is_sorted(num.begin(), num.end()))
            cout << "Sortarea a fost ok, iar quicksort-ul cu pivot random a durat " << secunde <<" secunde." << endl;
        else
            cout << "Sortarea nu este corecta." << endl;
    }
    else
        cout << "Timpul de executie al mergesort-ului este prea mare pentru input-ul dat." << endl;
    if (n <= 10000000)
        radixSortBase10(n, nMax);
    else
        cout << "Timpul de executie al radixsort-ului cu baza 10 este prea mare pentru input-ul dat." << endl;
    if (n <= 10000000)
        radixSortBase2(n, nMax);
    else
        cout << "Timpul de executie al radixsort-ului cu baza 2 este prea mare pentru input-ul dat." << endl;
}


    return 0;
}
