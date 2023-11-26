#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    for (int i =0; i<10; i++) {
        printf("%d ", rand());
    }
    return 0;
}