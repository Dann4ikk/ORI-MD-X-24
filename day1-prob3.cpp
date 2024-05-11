#include <bits/stdc++.h>

using namespace std;

int main()
{
  ifstream fin("./input.txt");
  ofstream fout("./output.txt");

  int n, m, k;

  fin >> n >> m >> k;

  if (k > m)
  {
    fout << "Imposibil" << endl;
    return 0;
  }

  int requiredWorkingHours = 0;

  for (int i = 0; i < n; i++)
  {
    int currentWorkingHours;
    fin >> currentWorkingHours;
    requiredWorkingHours += currentWorkingHours;
  }

  int avalaibleWorkers[m];
  int availableWorkingHours = 0;

  for (int i = 0; i < m; i++)
  {
    fin >> avalaibleWorkers[i];
    availableWorkingHours += avalaibleWorkers[i];
  }

  if (availableWorkingHours < requiredWorkingHours)
  {
    fout << "Imposibil" << endl;
    return 0;
  }

  bool chart[m][availableWorkingHours];

  for (int y = 0; y < m; y++)
  {
    chart[y][0] = true;
  }

  for (int x = 0; x < availableWorkingHours; x++)
  {
    int el = avalaibleWorkers[0];

    if (el == x)
    {
      chart[0][x] = true;
      continue;
    }
    chart[0][x] = false;
  }

  int minExcessHours = availableWorkingHours - requiredWorkingHours;

  for (int y = 1; y < m; y++)
  {
    for (int x = 1; x < availableWorkingHours; x++)
    {
      int el = avalaibleWorkers[y];

      chart[y][x] = el == x || chart[y - 1][x] || chart[y - 1][x - el];

      if (x == requiredWorkingHours && chart[y][x])
      {
        fout << 0 << endl;
        return 0;
      }

      if (x > requiredWorkingHours && chart[y][x])
      {
        minExcessHours = min(minExcessHours, x - requiredWorkingHours);
      }
    }
  }

  fout << minExcessHours << endl;
}
