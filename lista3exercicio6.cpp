//interpolationSearch
#include<iostream>

int interpolationSearch(int A[], int a, int z, int k) {
   int d, valorRange, iRange, estimate;
   float fraction;
   while(a <= z && k >= A[a] && k <= A[z]) {
      d = k - A[a];
      valorRange = A[z] - A[a];
      fraction = d / valorRange;
      iRange = z - a;
      estimate = a + (fraction * iRange);
      if(A[estimate] == k){
         return estimate;
      }
      if(A[estimate] < k){
         a = estimate + 1;
      }
      else{
         z = estimate - 1;
      }
   }
   return -1;
}
int main() {
   system("cls");
   int n = 13;
   int A[n] {3, 14, 27, 31, 39, 42, 55, 70, 74, 81, 85, 93, 98};
   int k = 31;
   int loc;
   for (int i = 0; i < n; ++i){
      std::cout << A[i] << ' ';
   }
   std::cout << std::endl;
   if((loc = interpolationSearch(A, 0, n-1, k)) >= 0){
      std::cout << "O numero "<< k << " esta na posicao: " <<loc + 1<< std::endl;
   }
   else{
      std::cout << "O numero "<< k << " nao esta no array." << std::endl;
   }
}