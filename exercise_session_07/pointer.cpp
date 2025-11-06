#include <iostream>
#include <iomanip>

int main() {
    int** M = new int*[2];
    M[0] = new int[5]{0,1,2,3,4};
    M[1] = new int[5]{5,6,7,8,9};

    std::cout << "a) type(M) = int** (pointer to pointer to int)\n";
    std::cout << "b) *M is int* (M[0]); **M is int (M[0][0])\n";
    std::cout << "c) M[1][3]=" << M[1][3]
              << ", *(M[0]+1)=" << *(M[0]+1)
              << ", *((*(M+1))+3)=" << *((*(M+1))+3) << "\n";

    std::cout << "d) M[0] and M[1] not guaranteed adjacent; *(M[0]+5)==M[1][0] is not guaranteed.\n";

    std::cout << "M[0]: ";
    for (int i=0;i<5;++i) std::cout << M[0][i] << (i==4?'\n':' ');
    std::cout << "M[1]: ";
    for (int i=0;i<5;++i) std::cout << M[1][i] << (i==4?'\n':' ');

    // Allocate M2
    int** M2 = new int*[2];
    M2[0] = new int[5];
    M2[1] = new int[5];

    // Transform using pointer arithmetic only (no bracket indexing) 
    // M2[0] = [9,8,7,6,5]  == reverse of M[1]
    // M2[1] = [4,3,2,1,0]  == reverse of M[0]
    for (int r = 0; r < 2; ++r) {
        for (int c = 0; c < 5; ++c) {
            *(*(M2 + r) + c) = *(*(M + (1 - r)) + (4 - c));
        }
    }

    std::cout << "M2[0]: ";
    for (int i=0;i<5;++i) std::cout << M2[0][i] << (i==4?'\n':' ');
    std::cout << "M2[1]: ";
    for (int i=0;i<5;++i) std::cout << M2[1][i] << (i==4?'\n':' ');

    delete[] M[0]; delete[] M[1]; delete[] M;
    delete[] M2[0]; delete[] M2[1]; delete[] M2;
    return 0;
}

