#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

// Estructura para memorización
typedef struct {
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    bool result;
} MemoEntry;

MemoEntry memo[MAX_LEN * MAX_LEN];
int memoSize = 0;

// Función auxiliar para verificar si dos cadenas son anagramas
bool areAnagrams(const char *s1, const char *s2, int len) {
    int count[26] = {0};
    
    for (int i = 0; i < len; i++) {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
}

// Función para buscar en la memorización
bool checkMemo(const char *s1, const char *s2, int len) {
    for (int i = 0; i < memoSize; i++) {
        if (strncmp(memo[i].s1, s1, len) == 0 && 
            strncmp(memo[i].s2, s2, len) == 0) {
            return memo[i].result;
        }
    }
    return -1; // No encontrado
}

// Función para agregar a la memorización
void addToMemo(const char *s1, const char *s2, int len, bool result) {
    if (memoSize < MAX_LEN * MAX_LEN) {
        strncpy(memo[memoSize].s1, s1, len);
        strncpy(memo[memoSize].s2, s2, len);
        memo[memoSize].result = result;
        memoSize++;
    }
}

// Función principal recursiva con memorización
bool isScramble(const char *s1, const char *s2, int len) {
    // Verificar en memorización
    bool memoResult = checkMemo(s1, s2, len);
    if (memoResult != -1) {
        return memoResult;
    }
    
    // Caso base: cadenas idénticas
    if (strncmp(s1, s2, len) == 0) {
        addToMemo(s1, s2, len, true);
        return true;
    }
    
    // Si no son anagramas, no pueden ser scrambled
    if (!areAnagrams(s1, s2, len)) {
        addToMemo(s1, s2, len, false);
        return false;
    }
    
    // Probar todas las posibles divisiones
    for (int i = 1; i < len; i++) {
        // Caso 1: No intercambiar las subcadenas
        if (isScramble(s1, s2, i) && 
            isScramble(s1 + i, s2 + i, len - i)) {
            addToMemo(s1, s2, len, true);
            return true;
        }
        
        // Caso 2: Intercambiar las subcadenas
        if (isScramble(s1, s2 + (len - i), i) && 
            isScramble(s1 + i, s2, len - i)) {
            addToMemo(s1, s2, len, true);
            return true;
        }
    }
    
    addToMemo(s1, s2, len, false);
    return false;
}

// Función de interfaz para el usuario
bool isScrambleString(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 != len2) {
        return false;
    }
    
    memoSize = 0; // Resetear la memorización para cada nueva llamada
    
    return isScramble(s1, s2, len1);
}

// Función para probar los ejemplos
void testScramble() {
    struct TestCase {
        const char *s1;
        const char *s2;
        bool expected;
    };
    
    struct TestCase testCases[] = {
        {"great", "great", true},
        {"abcde", "caebd", false},
        {"a", "a", true},
        {"abc", "bca", true},
        {"abcd", "badc", true},
        {"abcd", "dacb", false}
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        bool result = isScrambleString(testCases[i].s1, testCases[i].s2);
        printf("Test %d: s1 = \"%s\", s2 = \"%s\" -> %s (Expected: %s)\n",
               i + 1,
               testCases[i].s1,
               testCases[i].s2,
               result ? "true" : "false",
               testCases[i].expected ? "true" : "false");
    }
}

int main() {
    testScramble();
    return 0;
}