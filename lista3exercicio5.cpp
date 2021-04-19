//binarySearch
#include<iostream>
#include<vector>

int binarySearch(int A[], int l, int r, int k) {
   if (l <= r) {
      int m = ((l + r)/2);
      if (k == A[m]){
      return m ;
      }
      if (k < A[m]){
      return binarySearch(A, l, m - 1, k);
      }
      if (k > A[m]){
      return binarySearch(A, m + 1, r, k);
      }
   }
   return -1;
}
int main() {
   system("cls");
   int A[] = {3, 14, 27, 31, 39, 42, 55, 70, 74, 81, 85, 93, 98};
   int n = 13;
   int k = 27;
   for (int i = 0; i < n; ++i)
   {
      std::cout << A[i] << ' ';
   }
   std::cout << std::endl;
   int index = binarySearch (A, 0, n, k);
   if(index == -1)
   std::cout << "O numero " << k << " nao esta no array";
   else
   std::cout << "O numero " << k << " esta na posicao: " << index + 1;
   return 0;
}