#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  
  int MAX_N;
  cin >> MAX_N;

 
  vector<bool> is_prime(MAX_N + 1,  true);
  for (int i = 2; i*i <= MAX_N; ++i) {
    if (is_prime[i]) {
      for (int j = i*i; j <= MAX_N; j += i) is_prime[j] = false;
    }
  }
  vector<int> prime;
  for (int i = 2; i <= MAX_N; ++i) if (is_prime[i]) prime.push_back(i);

 
  vector<ll> sum(prime.size() + 1, 0);
  for (int i = 0; i < prime.size(); ++i) sum[i + 1] = sum[i] + prime[i];

 
  int n_queries;  
  cin >> n_queries;
  for (int z = 1; z <= n_queries; ++z) {
    int n;
    cin >> n;

  
    bool found = false;
    for (int i = 0; i < prime.size() and prime[i] <= n and not found; ++i) {

      
      
      int ini = i, fin = int(prime.size()) - 1;
      while (ini <= fin) {
        int mid = (ini + fin)/2;
        int value = sum[mid + 1] - sum[i];
        if (value <= n) ini = mid + 1;
        else fin = mid - 1;
      }

      
      int candidate = ini - 1;
      if (candidate >= i and sum[candidate + 1] - sum[i] == n) {
        found = true;
        cout << n << " =";
        for (int j = i; j <= candidate; ++j) {
          cout << " ";
          if (j > i) cout << "+ ";
          cout << prime[j];
        }
        cout << endl;
      }
    }

    if (not found) cout << "No solution" << endl;
  }
}
