#include <stdio.h>
#include <string.h>

char eclosure[20][20], states[10], sym[3] = "01", st[20][20];
int checkstate(char x[][20], int i, char y) {
    int found = 0;
    for (int a = 0; a < strlen(x[i]); a++) {
        if (x[i][a] == y) {
            found = 1;
            break;
        }
    }
    return (found == 0) ? 1 : 0;
}

int main() {
    int i, nt, k, j;
    char state, state1, state2, input;
    printf("\nEnter the number of states: ");
    scanf("%d", &i);

    printf("\nEnter the number of transitions: ");
    scanf("%d", &nt);

    printf("\nEnter the states: ");
    scanf("%s", states);

    printf("\nEnter the transitions in the format 'state input nextstate' (e.g., 'A0B'):\n");
    for (j = 0; j < nt; j++) {
        scanf("%s", st[j]);
    }

    for (i = 0; i < strlen(states); i++) {
        k = 0;
        printf("\ne-closure of %c is {", states[i]);

        state = states[i];
        eclosure[i][k++] = state;   
        eclosure[i][k++] = ',';   

        
        for (j = 0; j < nt; j++) {
            state1 = st[j][0];      
            input = st[j][1];       
            state2 = st[j][2];      
            if (state == state1 && input == 'e') {
                eclosure[i][k++] = state2;
                eclosure[i][k++] = ',';
                state = state2;
            }
        }

        eclosure[i][k - 1] = '\0';  
        printf("%s}", eclosure[i]); 
        printf("\n");
    }

    return 0;
}
