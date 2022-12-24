#include <unistd.h>


//HELPER FUNCTIONS
//I can consider them like atomic operations
//                        2 + 2
//                         ==
//                    ft_swap(p, p1)
//The name of the function becomes a new operator that i can use in my programs, basically.


void    ft_puts(char *str)
{
    // man 3 puts
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}
 


//Video ->https://youtu.be/fzrxiJbkk4M
void    ft_swap(char **p, char **p1)
{
    //Swap 2 pointers
    //Function take the address of a ptr
    char     *tmp;

    tmp = *p, *p = *p1; *p1 = tmp;    
}


//Video -> //TODO
int     ft_strcmp(char *s, char *s1)
{
    while (*s == *s1 && *s1)
    {
        ++s;
        ++s1;
    }
    return *s - *s1;
}



//BUBBLE SORT ALGORITHM
//video ->https://youtu.be/Q1pMTdmgBAM
void    ft_sort(char **argv, int args)
{
    
        /*
         * INPUTS that the function sees
         * 
         * argv---->[0]-->[hello\0]
         *             [1]-->[world\0]
                    [2]-->[damn\0]
         *
         * args = 3;
        */

    int        j;
    int     k;
    int        len;

    len = args;

    //Bubble implementation 🧼
    // len(elements) - 1 algos, to get order
    while (len - 1)
    {
        // k is always the str after j
        j = 0;
        k = 1;
            
            //k is max len - 1
        while (k < len)
        {
            //i treat strings like "atomic numbers"
            //thx to the ft_strcmp function
            if (ft_strcmp(argv[j], argv[k]) > 0)        
                ft_swap(&argv[j], &argv[k]);
            ++j;
            ++k;
        }

        //at every iteration a bubble rise up 🧼
        //i have to check 1 slot less ar every algo
        --len;
    }

}



int     main()
{;
    
    char *argv[4];
    char *s = "./a.out";
    char *s1 = "hello";
    char *s2 = "world";
    char *s3 = "damn";
    *argv = s;
    *argv = s;
    *(argv + 1) = s1;
    *(argv + 2) = s2;
    *(argv + 3) = s3;
              //👀       👀
    ft_sort(argv + 1, 3);//TODO

    int i = 1;
    //write all the params
    while (argv[i])
    {
        ft_puts(*(argv + i));    
        ++i;
    }
}
