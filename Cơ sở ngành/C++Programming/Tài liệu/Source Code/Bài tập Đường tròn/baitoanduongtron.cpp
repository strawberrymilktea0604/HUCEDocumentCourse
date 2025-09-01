#include<iostream>
#include<algorithm>
using namespace std;
struct point{
   int x, y;
};
int minRadius(int k, point points[], int n) {
   int dist[n];
   for (int i = 0; i < n; i++)
   dist[i] = points[i].x * points[i].x + points[i].y * points[i].y;
   // Sorting the distance
   sort(dist, dist + n);
   return dist[k - 1];
}
int main() {
   int k = 8;
   point points[] = {{0, 0}, {200, 300}, {200, 0}, {200, 200}, {0, 200}, {100, 300}, {300, 100}, {100, 0}};
   int n = sizeof(points)/sizeof(points[0]);
   cout << "Minimum radius: " << minRadius(k, points, n) << endl;
}
