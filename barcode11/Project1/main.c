#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 150

int findMax(int width_arr[], int m_sensor_num);
int findMin(int width_arr[], int m_sensor_num);
double checkWidth(int width_arr[], int m_sensor_num); // check wide and narrow
int isAvl(char* code, const char* encode_code[]); // to check whether it is available or not
void reverse(char code_arr[], int code_length); // re-check code
void code2dec(const char* encode_code[], char decode_code[], char output_character[]); // store
char* decode(int width_arr[], char decode_width[], int m_sensor_num, const char* encode_code[], char output_character[]); //return string i.e char pointer

int main(void) {
    const char* code11[12] = {
        "10001", // 0
        "11000", // 1
        "00101", // 2
        "01001", // 3
        "01100", // 4
        "10010", // 5
        "00011", // 6
        "10100", // 7
        "10000", // 8
        "00001", // 9
        "00100", // -
        "00110"  // start/stop
    };

    int m = 0, input_width[SIZE] = { 0 }, case_no = 1; // size input, store input, test case to print
    char decode_width[SIZE] = { 0 }, output_character[SIZE] = { 0 }; // store 011101010...

    FILE* cfPtr = NULL;

    if (cfPtr = fopen("test.txt", "r")) {
        while (!feof(cfPtr)) {
            for (int i = 0; i < SIZE; i++)
                input_width[i] = 0; // initialize
            fscanf(cfPtr, "%d", &m);

            if (m > 0 && m <= SIZE) {
                for (int i = 0; i < m; i++)
                    fscanf(cfPtr, "%d", &input_width[i]); // scan file

                printf("%s %d%s %s\n", "Case", case_no, ":", decode(input_width, decode_width, m, code11, output_character)); //output
                case_no++;
            }
            else
                break;
        }
        fclose(cfPtr);
    }
    else
        puts("File could not be opened.");

    return 0;
}

char* decode(int width_arr[], char decode_width[], int m_sensor_num, const char* encode_code[], char output_character[]) {
    for (int i = 0; i < m_sensor_num; i++) {
        if (width_arr[i] < 1 || width_arr[i] > 200)
            return "bad code"; // bar widths outside the allowable range
    }
    if (!(m_sensor_num + 1) / 6 > 5)
        return "bad code"; // confirm format input
    if (m_sensor_num % 6 != 5)
        return "bad code"; // confirm format input
        // stop character does not have space at the end

    double wide_width = checkWidth(width_arr, m_sensor_num);
    double narrow_width = wide_width / 2;
    double avg_width = (narrow_width + wide_width) / 2;
    double min_wide_width = wide_width * 0.95;
    double max_wide_width = wide_width * 1.05;
    double min_narrow_width = narrow_width * 0.95;
    double max_narrow_width = narrow_width * 1.05;

    if (!((narrow_width * 2) >= min_wide_width && (narrow_width * 2) <= max_wide_width))
        return "bad code"; // narrow * 2 = wide
    for (int i = 0; i < m_sensor_num; i++) {
        if (width_arr[i] > avg_width) {
            if (!(width_arr[i] >= min_wide_width && width_arr[i] <= max_wide_width))
                return "bad code"; // outside wide range
            else
                continue;
        }
        else {
            if (!(width_arr[i] >= min_narrow_width && width_arr[i] <= max_narrow_width))
                return "bad code"; // outside narrow range
            else
                continue;
        }
    }

    sprintf(decode_width, "%s", "");
    for (int i = 0; i < m_sensor_num; i++) {
        if (width_arr[i] >= min_wide_width && width_arr[i] <= max_wide_width)
            strcat(decode_width, "1"); // wide -> 1
        else
            strcat(decode_width, "0"); // narrow -> 0
    }
    for (int i = 5; i < m_sensor_num; i += 6) {
        if (decode_width[i] != '0')
            return "bad code"; // space ~> narrow
    }

    char temp[SIZE] = { 0 };
    char decode_code[6] = { 0 };

    for (int i = 0; i < strlen(decode_width); i += 6) {
        int counter = 0;
        decode_code[0] = '\0'; // initialize
        for (int j = i; counter < 5; j++, counter++) {
            sprintf(temp, "%c", decode_width[j]);
            strcat(decode_code, temp); // check encoding
        }
        if (!(isAvl(decode_code, encode_code)))
            return "bad code"; // outside CODE-11
    }

    decode_code[0] = '\0';

    for (int i = 0; i < 5; i++) { // check if the 1st five code ~> START, if its not then reverse
        sprintf(temp, "%c", decode_width[i]);
        strcat(decode_code, temp);
    }

    if ((strcmp(decode_code, encode_code[11])) != 0) { // reverse if not START
        reverse(decode_width, strlen(decode_width));
    }

    decode_code[0] = '\0';

    for (int i = 0; i < 5; i++) {
        sprintf(temp, "%c", decode_width[i]);
        strcat(decode_code, temp);
    }

    if ((strcmp(decode_code, encode_code[11])) != 0)
        return "bad code"; // there's no START after reverse

    for (int i = 6; i < strlen(decode_width) - 6; i += 6) {
        int counter = 0;
        decode_code[0] = '\0';
        for (int j = i; counter < 5; j++, counter++) { // every element loop, store 5
            sprintf(temp, "%c", decode_width[j]);
            strcat(decode_code, temp);
        }
        if (strcmp(decode_code, encode_code[11]) == 0)
            return "bad code"; // got START/STOP among
    }

    output_character[0] = '\0';

    for (int i = 6; i < m_sensor_num - 7; i += 6) { // store res, and so on i+=6
        int counter = 0;
        decode_code[0] = '\0';
        for (int j = i; counter < 5; j++, counter++) {
            sprintf(temp, "%c", decode_width[j]);
            strcat(decode_code, temp);
        }
        code2dec(encode_code, decode_code, output_character);
    }

    int C = 0; // check C
    int c_value = output_character[(strlen(output_character) - 2)] - '0';

    for (int i = 1, j = 0; j < strlen(output_character) - 2; j++, i++) {
        int weight = 0;
        if (output_character[j] == '-')
            weight = 10;
        else
            weight = output_character[j] - '0';

        C += ((strlen(output_character) - 2 - i) % 10 + 1) * weight;
    }
    if (C % 11 != c_value)
        return "bad C";

    int K = 0, i = 1; // check K
    int k_value = output_character[(strlen(output_character) - 1)] - '0';

    for (int j = 0; j < strlen(output_character) - 2; j++, i++) {
        int weight = 0;
        if (output_character[j] == '-')
            weight = 10;
        else
            weight = output_character[j] - '0';

        K += ((strlen(output_character) - 2 - i + 1) % 9 + 1) * weight;
    }
    int weight = output_character[strlen(output_character) - 2] - '0';
    K += ((strlen(output_character) - 2 - i + 1) % 9 + 1) * weight;

    if (K % 11 != k_value)
        return "bad K";

    char temp_char[SIZE] = { 0 };
    char output_char[SIZE] = { 0 };

    for (int i = 0; i < strlen(output_character) - 2; i++) {
        sprintf(temp_char, "%c", output_character[i]);
        strcat(output_char, temp_char);
    }

    sprintf(output_character, "%s", output_char);
    return output_character;
}
double checkWidth(int width_arr[], int m_sensor_num) {
    double narrow_width = 0, wide_width = 0;
    double min = findMin(width_arr, m_sensor_num); // call function global min
    double max = findMax(width_arr, m_sensor_num); // call function global max
    double avr = (min + max) / 2; // find global average
    max = 0, min = 999;

    for (int i = 0; i < m_sensor_num; i++) {
        double width = width_arr[i];
        if (width <= avr)
            width *= 2; // *2 in order to check whether it's in the range or not 
        if (width < min)
            min = width; // find min wide
        if (width > max)
            max = width; // find max wide
    }
    return (min + max) / 2.0; // return wide range
}
int isAvl(char* code, const char* encode_code[]) { // check whether code is avl or not
    if (strcmp(code, encode_code[0]) == 0 || strcmp(code, encode_code[1]) == 0 ||
        strcmp(code, encode_code[2]) == 0 || strcmp(code, encode_code[3]) == 0 ||
        strcmp(code, encode_code[4]) == 0 || strcmp(code, encode_code[5]) == 0 ||
        strcmp(code, encode_code[6]) == 0 || strcmp(code, encode_code[7]) == 0 ||
        strcmp(code, encode_code[8]) == 0 || strcmp(code, encode_code[9]) == 0 ||
        strcmp(code, encode_code[10]) == 0 ||
        strcmp(code, encode_code[11]) == 0) {
        return 1;
    }
    else
        return 0;
}
void code2dec(const char* encode_code[], char decode_code[], char output_character[]) {
    if ((strcmp(decode_code, encode_code[0])) == 0)
        strcat(output_character, "0");
    else if ((strcmp(decode_code, encode_code[1])) == 0)
        strcat(output_character, "1");
    else if ((strcmp(decode_code, encode_code[2])) == 0)
        strcat(output_character, "2");
    else if ((strcmp(decode_code, encode_code[3])) == 0)
        strcat(output_character, "3");
    else if ((strcmp(decode_code, encode_code[4])) == 0)
        strcat(output_character, "4");
    else if ((strcmp(decode_code, encode_code[5])) == 0)
        strcat(output_character, "5");
    else if ((strcmp(decode_code, encode_code[6])) == 0)
        strcat(output_character, "6");
    else if ((strcmp(decode_code, encode_code[7])) == 0)
        strcat(output_character, "7");
    else if ((strcmp(decode_code, encode_code[8])) == 0)
        strcat(output_character, "8");
    else if ((strcmp(decode_code, encode_code[9])) == 0)
        strcat(output_character, "9");
    else if ((strcmp(decode_code, encode_code[10])) == 0)
        strcat(output_character, "-");
}
void reverse(char code_arr[], int code_length) {
    char rra_edoc[100] = { 0 }; // result

    for (int i = code_length; i >= 0; i--) {
        char temp[2] = { 0 };
        sprintf(temp, "%c", code_arr[i]);
        strcat(rra_edoc, temp);
    }

    sprintf(code_arr, "%s", ""); // initialize arr
    strcat(code_arr, rra_edoc); // copy result to arr, fill the arr backwards
}
int findMax(int width_arr[], int m_sensor_num) {
    int max = width_arr[0];

    for (int i = 0; i <= m_sensor_num; i++) {
        if (width_arr[i] > max)
            max = width_arr[i];
    }
    return max;
}
int findMin(int width_arr[], int m_sensor_num) {
    int min = width_arr[0];

    for (int i = 0; i < m_sensor_num; i++) {
        if (width_arr[i] < min)
            min = width_arr[i];
    }
    return min;
}