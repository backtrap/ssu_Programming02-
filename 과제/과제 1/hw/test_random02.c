#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

    srand(time(NULL));  // 랜덤 시드는 한 번만 설정

    // n1 ~ n10 설정
    n1 = rand() % 10;
    
    do { n2 = rand() % 10; } while (n2 == n1);
    do { n3 = rand() % 10; } while (n3 == n2 || n3 == n1);
    do { n4 = rand() % 10; } while (n4 == n3 || n4 == n2 || n4 == n1);
    do { n5 = rand() % 10; } while (n5 == n4 || n5 == n3 || n5 == n2 || n5 == n1);
    do { n6 = rand() % 10; } while (n6 == n5 || n6 == n4 || n6 == n3 || n6 == n2 || n6 == n1);
    do { n7 = rand() % 10; } while (n7 == n6 || n7 == n5 || n7 == n4 || n7 == n3 || n7 == n2 || n7 == n1);
    do { n8 = rand() % 10; } while (n8 == n7 || n8 == n6 || n8 == n5 || n8 == n4 || n8 == n3 || n8 == n2 || n8 == n1);
    do { n9 = rand() % 10; } while (n9 == n8 || n9 == n7 || n9 == n6 || n9 == n5 || n9 == n4 || n9 == n3 || n9 == n2 || n9 == n1);
    do { n10 = rand() % 10; } while (n10 == n9 || n10 == n8 || n10 == n7 || n10 == n6 || n10 == n5 || n10 == n4 || n10 == n3 || n10 == n2 || n10 == n1);

    // k1 ~ k10 설정
    k1 = rand() % 10;

    do { k2 = rand() % 10; } while (k2 == k1);
    do { k3 = rand() % 10; } while (k3 == k2 || k3 == k1);
    do { k4 = rand() % 10; } while (k4 == k3 || k4 == k2 || k4 == k1);
    do { k5 = rand() % 10; } while (k5 == k4 || k5 == k3 || k5 == k2 || k5 == k1);
    do { k6 = rand() % 10; } while (k6 == k5 || k6 == k4 || k6 == k3 || k6 == k2 || k6 == k1);
    do { k7 = rand() % 10; } while (k7 == k6 || k7 == k5 || k7 == k4 || k7 == k3 || k7 == k2 || k7 == k1);
    do { k8 = rand() % 10; } while (k8 == k7 || k8 == k6 || k8 == k5 || k8 == k4 || k8 == k3 || k8 == k2 || k8 == k1);
    do { k9 = rand() % 10; } while (k9 == k8 || k9 == k7 || k9 == k6 || k9 == k5 || k9 == k4 || k9 == k3 || k9 == k2 || k9 == k1);
    do { k10 = rand() % 10; } while (k10 == k9 || k10 == k8 || k10 == k7 || k10 == k6 || k10 == k5 || k10 == k4 || k10 == k3 || k10 == k2 || k10 == k1);

    // 결과 출력
    printf("n1 ~ n10: %d %d %d %d %d %d %d %d %d %d\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10);
    printf("k1 ~ k10: %d %d %d %d %d %d %d %d %d %d\n", k1, k2, k3, k4, k5, k6, k7, k8, k9, k10);

    return 0;
}
