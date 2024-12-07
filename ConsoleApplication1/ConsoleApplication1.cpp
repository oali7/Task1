#include <stdio.h>

int set_bit(int number, int position)
{
    return number | (1 << position);
}

int clear_bit(int number, int position)
{
    return number & ~(1 << position);
}

int toggle_bit(int number, int position) noexcept
{
    return number ^ (1 << position);
}

int read_bit(int number, int position)
{
    return (number >> position) & 1;
}

int main() {
    int number, position, operation;

    printf("Menu for Bit Manipulation:\n");
    printf("1. Set a Bit\n");
    printf("2. Clear a Bit\n");
    printf("3. Toggle a Bit\n");
    printf("4. Read a Bit\n");

    printf("Enter an integer number: ");
    scanf("%d", &number);

    printf("Enter the bit position (starting from 0): ");
    scanf("%d", &position);

    if (position < 0 || position >= 32) {
        printf("Invalid bit position. Please enter a position between 0 and 31.\n");
        return 1;  
    }
    printf("Select an operation (1-4): ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
        number = set_bit(number, position);
        printf("After setting bit at position %d: %d\n", position, number);
        break;
    case 2:
        number = clear_bit(number, position);
        printf("After clearing bit at position %d: %d\n", position, number);
        break;
    case 3:
        number = toggle_bit(number, position);
        printf("After toggling bit at position %d: %d\n", position, number);
        break;
    case 4:
        printf("The bit at position %d is: %d\n", position, read_bit(number, position));
        break;
    default:
        printf("Invalid operation selection. Please choose a valid option (1-4).\n");
        break;
    }

    return 0;
}
