#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>

// How many numbers do you want from the sequence
#define N 256/2

// Three arrays used to produce sequence
int add[N/2 + 1];
int drop[N/2];
int sequence[N];

void rodriguez_into_array(void)
{
    int count = 0;
    int count_half = 0;

    // First Step: start add[] with 0
    if (count == 0)
    {
        add[0] = 0;
    }

    for(count_half = 0; count_half < N/2; count_half++)
    {
        // Next Step: fill sequence from add, and fill drop from sequence
        sequence[count] = add[count_half];
        drop[count_half] = sequence[count_half];
        count++;

        // Next Step: fill sequence from drop, and fill next add from drop + 1
        sequence[count] = drop[count_half];
        add[count_half + 1] = drop[count_half] + 1;
        count++;
    }

    // If N is odd, perform one more time
    if (N % 2 == 1)
    {
        sequence[count] = add[count_half];
        drop[count_half] = sequence[count_half];
        count++;
    }
}


// Starts base case at 0
int base_count = 0;
// This will be the number printed
int a = 1;

// Writes the difference of the 8th and the 7th term by taking its occurrence number
void base_sequence(int n)
{
    // First time
    if (base_count == 0)
    {
        a = 1;
    }

    // Comparative value
    int base = pow(2, base_count);

    // True means the nth we are on is a multiple of recursive depth number
    if (n % base == 0)
    {
        a++;
    }

    // If nth is also a multiple of the next base, lets gooo
    if (n % (base * 2) == 0)
    {
         base_count++;

         base_sequence(n);
    }
    else
    {
        base_count = 0;
        return;
    }

    return;
}

// This will be the number to print
int b = 0;
// This will be the last 8th value
int last_value = -1;

int implement_base(int n)
{
    switch (n % 8)
    {
        case 1:
        case 2:
        case 4:
            return last_value + 1;

        case 3:
        case 5:
        case 6:
            return last_value + 2;

        case 7:
            return last_value + 3;

        default:
            base_sequence(n / 8);
            last_value = last_value + 3 - a;
            return last_value;
    }
}

int main(void)
{
    // Writes the sequences to these memories
    rodriguez_into_array();

    // Printing the sequences in order USING MEMORY
    printf("This section represents the sequence in order. After hours of analysis I found that the \n");
    printf("sequence relies on itself to continue, thus requires a history (More info in README):\n");
    for(int i = 0; i < N/2; i++)
    {
        printf("%d ", sequence[i]);
    }
    printf("\n\n");


    // Printing the sequences stacked USING MEMORY
    printf("This section represents the odd steps on the top row and the even steps on the bottom row.\n");
    printf("I've added spaces to hep visualize the clues I picked up on that lead to my discovery:\n");
    for(int i = 0; i < N/2; i++)
    {
        printf("%d ", add[i]);

        if (i % 4 == 2 || i % 4 == 3)
        {
            printf(" ");
        }
    }
    printf("\n");
    for(int i = 0; i < N/2; i++)
    {
        printf("%d ", drop[i]);

        if (i % 4 == 2 || i % 4 == 3)
        {
            printf(" ");
        }
    }
    printf("\n\n");


    // Printing the 8th terms minus the 7th terms USING MEMORY
    printf("This section represents sequence created by taking the difference of each 7th and 8th term.\n");
    printf("I will again use spacing to demonstrate the successful thought-process:\n");
    for(int i = 3; i < N/2; i+=4)
    {  
        if ((add[i] - drop[i]) > 3)
        {
            printf(" %d  ", add[i] - drop[i]);
        }
        else
        {
            printf("%d ", add[i] - drop[i]);
        }
    }
    printf("\n");

    int n;
    // Function relies on inputs being incremental ONLY
    printf("One more final eureka! (and 3 sleepless nights) and I was able to break the code and\n");
    printf("recreate that essential base count above recursively and more importantly without the\n");
    printf("need of a history memory. This final algorithm can create the sequence incrementally.\n");
    printf("Enter a positive integer for the length of the sequence to want and see for yourself.\n\n");
    printf("Enter value: ");
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++)
    {
        
        printf("%d ", implement_base(i));
    }
    printf("\n");
    printf("I give you, our Balanced Binary Tree!\n");

    return 0;
}
