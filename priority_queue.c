include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[20];
    int priority;
};

struct Patient pq[MAX];
int size = 0;

// Add patient
void addPatient(char name[], int priority) {
    int i = size++;
    strcpy(pq[i].name, name);
    pq[i].priority = priority;

    // Arrange based on priority (lowest first)
    while (i > 0 && pq[i].priority < pq[i - 1].priority) {
        struct Patient temp = pq[i];
        pq[i] = pq[i - 1];
        pq[i - 1] = temp;
        i--;
    }
}

// Treat next patient
void treatPatient() {
    if (size == 0) {
        printf("No patients\n");
        return;
    }

    printf("Treating: %s (Priority: %d)\n", pq[0].name, pq[0].priority);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

int main() {
    // Initial patients
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("Treatment Order:\n");

    // Treat first 2 patients
    treatPatient();
    treatPatient();

    // Add new emergency patient
    addPatient("P7", 1);
    printf("Added Emergency Patient P7\n");

    // Continue treatment
    while (size > 0) {
        treatPatient();
    }

    return 0;
}