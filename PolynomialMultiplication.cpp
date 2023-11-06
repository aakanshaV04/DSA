#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createTerm(int coeff, int exp) {
    struct Node* term = (struct Node*)malloc(sizeof(struct Node));
    term->coeff = coeff;
    term->exp = exp;
    term->next = NULL;
    return term;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    struct Node* p1 = poly1;
    while (p1 != NULL) {
        struct Node* p2 = poly2;
        while (p2 != NULL) {
            int newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;

            struct Node* temp = result;
            while (temp != NULL) {
                if (temp->exp == newExp) {
                    temp->coeff += newCoeff;
                    break;
                }
                temp = temp->next;
            }

            if (temp == NULL) {
                struct Node* term = createTerm(newCoeff, newExp);
                term->next = result;
                result = term;
            }

            p2 = p2->next;
        }
        p1 = p1->next;
    }

    return result;
}

void displayPolynomial(struct Node* p) {
    while (p != NULL) {
        printf("%dx^%d (Address : %p)", p->coeff, p->exp,p->next);
        if (p->next != NULL) {
            printf(" + ");
        }
        p = p->next;
    }
}

struct Node* createPolynomial(int numTerms) {
    struct Node* poly = NULL;
    printf("Enter the terms:\n");
    for(int i = 0; i < numTerms; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        struct Node* term = createTerm(coeff, exp);
        term->next = poly;
        poly = term;
    }
    return poly;
}

int main() {
    int n1, n2;

    printf("Enter the number of terms in polynomial A: ");
    scanf("%d", &n1);
    struct Node* polyA = createPolynomial(n1);

    printf("Enter the number of terms in polynomial B: ");
    scanf("%d", &n2);
    struct Node* polyB = createPolynomial(n2);

    struct Node* result = multiplyPolynomials(polyA, polyB);

    printf("Polynomial A: ");
    displayPolynomial(polyA);
    printf("\n");

    printf("Polynomial B: ");
    displayPolynomial(polyB);
    printf("\n");

    printf("Resultant Polynomial after multiplication: ");
    displayPolynomial(result);
    printf("\n");

    // Free allocated memory for the linked lists
    // ... (rest of the memory deallocation code remains unchanged)

    return 0;
}
