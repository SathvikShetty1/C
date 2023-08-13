#include <stdio.h>
#include <stdbool.h>

int main() {
    int incomingStream[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3;
    int queue[frames], occupied = 0, pagefault = 0;

    printf("Page\tFrame1\tFrame2\tFrame3\n");
    for (int i = 0; i < n; i++) {
        printf("%d:\t\t", incomingStream[i]);
        bool hit = false;
        
        for (int j = 0; j < occupied; j++) {
            if (incomingStream[i] == queue[j]) {
                hit = true;
                break;
            }
        } 
        if (!hit) {
            if (occupied < frames) {
                queue[occupied++] = incomingStream[i];
                pagefault++;
            } else {
                for (int j = 0; j < occupied - 1; j++)
                    queue[j] = queue[j + 1];
                queue[occupied - 1] = incomingStream[i];
                pagefault++;
            }
        }
        for (int j = 0; j < occupied; j++) {
            printf("%d\t\t", queue[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pagefault);
    return 0;
}
/*

Page	Frame1	Frame2	Frame3
1:		1		
3:		1		3		
0:		1		3		0		
3:		1		3		0		
5:		3		0		5		
6:		0		5		6		
3:		5		6		3		
Total Page Faults: 6 */


  
