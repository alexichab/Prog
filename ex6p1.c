#include <stdio.h>
#include <math.h>

int main()
{
    int pow3 = 0;
    int logic[5];
    for (int i = 22; i < 47; i++)
    {
        int j = (int)pow(i, 3);
        for (int c = 4; c >= 0; c--)
        {
            logic[c] = j % 10;
            j /= 10;
        }

        if ((logic[0] + logic[1] + logic[2] + logic[3] + logic[4]) == i)
        {
            int flag = 1;
            for (int q = 0; q < 5; q++)
            {
                for (int w = 0; w < 5; w++)
                {
                    if (q != w && logic[q] == logic[w])
                    {
                        flag = 0;
                    }
                }
            }
            if (flag == 1)
            {
                pow3 = (int)pow(i, 3);
                break;
            }
        }
    }

    printf("\n(%d + %d + %d + %d + %d)^3 = %d\n", logic[0], logic[1], logic[2], logic[3], logic[4], pow3);
}