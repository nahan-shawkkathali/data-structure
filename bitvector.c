#include <stdio.h>
#include <ctype.h>

char univ_set[26] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z'
};

char set1[26], set2[26];
int bit_vec1[26], bit_vec2[26], result[26];

void initializeset()
{
    for(int i = 0; i < 26; i++)
    {
        bit_vec1[i] = 0;
        bit_vec2[i] = 0;
        result[i] = 0;
    }
}

void bitVector(char ary[], int num, int bit[])
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            char c = tolower(ary[i]);
            if (c == univ_set[j])
                bit[j] = 1;
        }
    }
}

void setUnion(int bit1[26], int bit2[26])
{
    for(int i = 0; i < 26; i++)
        result[i] = bit1[i] | bit2[i];
}

void setintersection(int bit1[26], int bit2[26])
{
    for(int i = 0; i < 26; i++)
        result[i] = bit1[i] & bit2[i];
}

void setComplement(int bit[26])
{
    for(int i = 0; i < 26; i++)
        result[i] = (bit[i] == 0) ? 1 : 0;
}

void setDifference(int bit1[26], int bit2[26])
{
    int temp[26];

    // compute complement of bit2 into temp[]
    for(int i = 0; i < 26; i++)
        temp[i] = (bit2[i] == 0) ? 1 : 0;

    // intersection of bit1 and temp into result[]
    for(int i = 0; i < 26; i++)
        result[i] = bit1[i] & temp[i];
}

void printSet(int bit[])
{
    printf("{ ");
    for(int i = 0; i < 26; i++)
    {
        if(bit[i] == 1)
            printf("%c ", univ_set[i]);
    }
    printf("}\n");
}

void printBitVector(int bit[])
{
    for(int i = 0; i < 26; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

int main()
{
    int num1, num2;
    int choice;

    initializeset();

    printf("Enter number of elements in Set1: ");
    scanf("%d", &num1);
    printf("Enter set1 elements: ");
    for(int i = 0; i < num1; i++)
        scanf(" %c", &set1[i]);

    printf("Enter number of elements in Set2 : ");
    scanf("%d", &num2);
    printf("Enter set 2 elements: ");
    for(int i = 0; i < num2; i++)
        scanf(" %c", &set2[i]);

    bitVector(set1, num1, bit_vec1);
    bitVector(set2, num2, bit_vec2);

    while(1)
    {
        printf("\n------ MENU ------\n");
        printf("1. Display Bit Vectors\n");
        printf("2. Union\n");
        printf("3. Intersection\n");
        printf("4. Complement of Set1\n");
        printf("5. Complement of Set2\n");
        printf("6. Set Difference (Set1 - Set2)\n");
        printf("7. Exit\n");
        printf("-------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Bit Vector of Set 1:\n");
                printBitVector(bit_vec1);
                printf("Bit Vector of Set 2:\n");
                printBitVector(bit_vec2);
                break;

            case 2:
                setUnion(bit_vec1, bit_vec2);
                printf("Union = ");
                printSet(result);
                break;

            case 3:
                setintersection(bit_vec1, bit_vec2);
                printf("Intersection = ");
                printSet(result);
                break;

            case 4:
                setComplement(bit_vec1);
                printf("Complement of Set1 = ");
                printSet(result);
                break;

            case 5:
                setComplement(bit_vec2);
                printf("Complement of Set2 = ");
                printSet(result);
                break;

            case 6:
                setDifference(bit_vec1, bit_vec2);
                printf("Set Difference (Set1 - Set2) = ");
                printSet(result);
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

