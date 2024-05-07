#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the contents of a file and save to a new file
void encrypt(const char *input_path, const char *output_path, int key) {
    FILE *input_file = fopen(input_path, "r");
    FILE *output_file = fopen(output_path, "w");
    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        // Encrypt the character and write it to the output file
        fputc(((ch + key) % 256), output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

// Function to decrypt the contents of a file and save to a new file
void decrypt(const char *input_path, const char *output_path, int key) {
    FILE *input_file = fopen(input_path, "r");
    FILE *output_file = fopen(output_path, "w");
    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        // Decrypt the character and write it to the output file
        fputc(((ch - key ) % 256), output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char input_path[260], output_path[260];
    int key;
    char choice;

    // Get the file name from the user
    printf("Enter the name of the input file: ");
    scanf("%259s", input_path);

    // Get the output file name from the user
    printf("Enter the name of the output file: ");
    scanf("%259s", output_path);

    // Get the key from the user
    printf("Enter the encryption key (number): ");
    scanf("%d", &key);

    // Get the user's choice for encryption or decryption
    printf("Do you want to (E)ncrypt or (D)ecrypt the file? Enter E or D: ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        // Encrypt the file
        encrypt(input_path, output_path, key);
        printf("File encrypted successfully and saved to %s.\n", output_path);
    } else if (choice == 'D' || choice == 'd') {
        // Decrypt the file
        decrypt(input_path, output_path, key);
        printf("File decrypted successfully and saved to %s.\n", output_path);
    } else {
        printf("Invalid choice. Please enter E or D.\n");
    }

    return 0;
}

