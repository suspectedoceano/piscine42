#include "naruto.h"

#define N 8

void binSasukeOk(uint8_t digits, char *v)
{
    while (true) 
	{
		//1° Print the string
        p("%s\n", v);

        //2° Find the rightmost digit that can be incremented
        int idx;

        for (idx = (digits - 1); idx >= 0; --idx)
        {
            if ('0' == v[idx])
            {
                v[idx]++;
                break;
            }
			// 🧊 refresh value 🧊
            v[idx] = '0';
        }

        //3° If no digit can be incremented, we are done
        if (idx < 0) break;
     }
}

/*
 * CALLOC
 * + 1 for the '\0' sentinel value
 * e.g.->  [__________\0];
 * 
 * Then Initialize the array with '0' chars 
 * 		and terminate with '\0'
 */
void binSasuke(uint8_t digits) {
    char *v;

    v = calloc(digits + 1, sizeof *v);
    if (NULL == v) {
        perror("Calloc failed");
        return;
    }

    for (uint8_t i = 0; i < digits; ++i)
        v[i] = '0';

    binSasukeOk(digits, v);
    free(v);
}

int main() {
    binSasuke(N);
    return 0;
}

