#include <iostream>
#include <fstream>

using namespace std;

void findLocation() {
    ifstream cin("a.in");
    ofstream cout("a.out");

    int i, n, target, a[1000000];
    cin >> n >> target;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l, r, mid;
    l = 0;
    r = n - 1;
    while (l < r) {
        mid = (l + r) >> 1;
        if (a[mid] < target) {
            l = mid + 1;

        } else {
            r = mid;
        }
    }
    if (a[r] == target) {
        cout << "position=" << r << ", number=" << a[r] << endl;
    } else {
        cout << -1 << endl;
    }
}

int generate_rand(int n, int m) {
    int temp = rand() % (n + 1);
    while (temp == m || temp == 0) {
        temp = rand() % (n + 1);
    }
    return temp;
}

void gift() {

    ifstream cin("a2.in");
    ofstream cout("a2.out");

    int n;
    cin >> n;
    srand((unsigned) time(NULL));
    for (int i = 0; i < n; i++) {
        cout << "i=" << i + 1 << ", j=" << generate_rand(n, i + 1) << endl;
    }

}

int main() {

    findLocation();

    gift();

    return 0;
}