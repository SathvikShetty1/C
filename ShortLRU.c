#include <stdio.h>

int main() {
    int in[] = {1,3,0,3,5,6,3}, n=sizeof(in)/sizeof(in[0]), f=3, q[f], o=0, p=0;
    printf("Page\t");
    for (int i=0;i<f;i++) printf("Frame%d\t",i+1);
    printf("\n");
    for (int i=0;i<n;i++) {
        printf("%d:\t\t",in[i]);
        int h=0;
        for (int j=0;j<o;j++) if (in[i]==q[j]) {h=1; break;}
        if (!h) {
            if (o<f) q[o++]=in[i], p++;
            else {
                for (int j=0;j<o-1;j++) q[j]=q[j+1];
                q[o-1]=in[i], p++;
            }
        }
        for (int j=0;j<o;j++) printf("%d\t\t",q[j]);
        printf("\n");
    }
    printf("Total Page Faults: %d\n",p);
    return 0;
}
