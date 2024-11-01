//Remove an element:

#include <stdio.h>

int removeElement(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != key) {
            arr[count++] = arr[i];
        }
    }
    return count;  // Number of elements not equal to key
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    n = removeElement(arr, n, key);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//Remove duplicates from a sorted array:

#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;

    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    
    return j;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//Best time to buy and sell a commodity:

#include <stdio.h>

void bestDaysToBuySell(int prices[], int n) {
    if (n < 2) {
        printf("Not enough data\n");
        return;
    }

    int minPrice = prices[0], minDay = 0, maxProfit = 0, buyDay = 0, sellDay = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
            minDay = i;
        }
        int profit = prices[i] - minPrice;
        if (profit > maxProfit) {
            maxProfit = profit;
            buyDay = minDay;
            sellDay = i;
        }
    }

    printf("Buy on day %d and sell on day %d for maximum profit.\n", buyDay + 1, sellDay + 1);
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    bestDaysToBuySell(prices, n);

    return 0;
}

//Merging the strings:

#include <stdio.h>
#include <stdlib.h>

void mergeStrings(FILE *f1, FILE *f2, FILE *f3) {
    char ch1, ch2;

    while (((ch1 = fgetc(f1)) != EOF) || ((ch2 = fgetc(f2)) != EOF)) {
        if (ch1 != EOF) fputc(ch1, f3);
        if (ch2 != EOF) fputc(ch2, f3);
    }
}

int main() {
    FILE *f1 = fopen("file1.txt", "r");
    FILE *f2 = fopen("file2.txt", "r");
    FILE *f3 = fopen("file3.txt", "w");

    if (f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    mergeStrings(f1, f2, f3);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("Strings merged into file3.txt\n");
    return 0;
}

//String reversal:

#include <stdio.h>
#include <string.h>

void reverseWords(char str[]) {
    char temp[1000];
    int j = 0, k = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',') {
            continue;
        }
        temp[j++] = str[i];
    }
    temp[j] = '\0';
    for (int i = j - 1; i >= 0; i--) {
        printf("%c", temp[i]);
    }
}

int main() {
    char str[] = "Hello, world.";
    reverseWords(str);
    return 0;
}

//Move all zeros to the end:

#include <stdio.h>

void moveZerosToEnd(int arr[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j++] = arr[i];
        }
    }
    while (j < n) {
        arr[j++] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZerosToEnd(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}



//Is substring:

#include <stdio.h>
#include <string.h>

int isSubstring(char *str1, char *str2) {
    return strstr(str1, str2) != NULL;
}

int main() {
    char str1[] = "hello world";
    char str2[] = "world";
    if (isSubstring(str1, str2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}


//Is subsequence:

#include <stdio.h>

int isSubsequence(char *str1, char *str2) {
    int i = 0, j = 0;
    while (str1[i] && str2[j]) {
        if (str1[i] == str2[j]) {
            j++;
        }
        i++;
    }
    return str2[j] == '\0';
}

int main() {
    char str1[] = "abcde";
    char str2[] = "ace";
    if (isSubsequence(str1, str2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}


//Maximum value subarray:

#include <stdio.h>

int maxSubArraySum(int arr[], int n) {
    int maxSoFar = arr[0], currMax = arr[0];

    for (int i = 1; i < n; i++) {
        currMax = (arr[i] > currMax + arr[i]) ? arr[i] : currMax + arr[i];
        maxSoFar = (currMax > maxSoFar) ? currMax : maxSoFar;
    }
    return maxSoFar;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, n);
    printf("Maximum sum: %d\n", maxSum);

    return 0;
}

//Single occurrence of a number:

#include <stdio.h>

int findSingle(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= arr[i];
    }
    return res;
}

int main() {
    int arr[] = {2, 3, 5, 4, 5, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Element that occurs only once: %d\n", findSingle(arr, n));

    return 0;
}
