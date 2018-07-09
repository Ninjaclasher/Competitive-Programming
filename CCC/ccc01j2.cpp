#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;                       ;;  ;; ;;;; ;;  ;;  ;;;;;;        ;;;;;  ;;;;  ;;;;   ;;;; ;;  ;;
    scanf("%i%i", &n, &m);         ;;  ;; ;;   ;;  ;;  ;;  ;;        ;;  ;; ;;    ;; ;;  ;;   ;; ;;
    for (int x = 0; x < m; x++){   ;;;;;; ;;;; ;;  ;;  ;;  ;;        ;;  ;; ;;;;  ;;;;   ;;;; ;;;;
       if ((n * x) % m == 1){      ;;  ;; ;;   ;;  ;;  ;;  ;;        ;;  ;; ;;    ;; ;;  ;;   ;; ;;
           printf("%i", x);        ;;  ;; ;;;; ;;; ;;; ;;;;;;        ;;;;;  ;;;;  ;;  ;; ;;;; ;;  ;;
           return 0;
       }
   }
   printf("No such integer exists.");
   return 0;
}
