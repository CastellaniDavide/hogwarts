// Includes
#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#endif // DEBUG

// Struct
struct scala {
  int da, a;
  int tda, ta;
  bool usata = false;
};

// Variabiles
int maxT = INT_MIN;
vector <scala> scale;
set <int> posizioni = {0};

bool mySort(const scala& a, const scala& b)
{
    return a.tda < b.tda;
}

int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]) {
  for (size_t i = 0; i < M; ++i) {
    scala tmp5;
    tmp5.da = A[i];
    tmp5.a = B[i];
    tmp5.tda = inizio[i];
    tmp5.ta = fine[i];
    scale.push_back(tmp5);
    
    if (inizio[i] > maxT)
      maxT = inizio[i];
  }
  sort(scale.begin(), scale.end(), mySort);

#ifdef DEBUG
  cout << "maxT: " << maxT << endl;

  cout << "scale: " << endl;
  for (size_t i = 0; i < M; ++i) {
    cout << i << ") " << scale[i].da << "\t" << scale[i].a << "\t" << scale[i].tda << "\t" << scale[i].ta << endl;
  }
#endif // DEBUG

  for (size_t i = 0; i < maxT + 1; ++i) {
    set <int> copy (posizioni);

    for (size_t j = 0; j < M; ++j) {
      if (!scale[j].usata && scale[j].tda <= i && scale[j].ta > i && copy.find(scale[j].da) != copy.end()) {
        if (scale[j].a == N - 1) {
          return i;
        }

        posizioni.insert(scale[j].a);
        scale[j].usata = true;
      }
    }
  }

  return -1;
}
