#include <iostream>
#include <vector>
using namespace std;

int Arr[3][3] = {
    (0, 0, 0),
    (0, 0, 0),
    (0, 0, 0)
};
int N = 3;
void func(int(*arr)[3], int val)
{
    long i;
    for (i = 0; i < N; i++) arr[i][i] = val;
}

void func2(int(*arr)[3], int val)
{
    int* Aptr = &arr[0][0];
    do
    {
        *Aptr = val;
        Aptr += (N + 1);
    } while (Aptr != &arr[N][N]);
}

int main()
{
    func2(Arr, 1);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%ld ,", Arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}