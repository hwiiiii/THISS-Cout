// file = 0; split type = patterns; threshold = 100000; total count = 0.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "rmapats.h"

void  hsG_0__0 (struct dummyq_struct * I1297, EBLK  * I1291, U  I686);
void  hsG_0__0 (struct dummyq_struct * I1297, EBLK  * I1291, U  I686)
{
    U  I1555;
    U  I1556;
    U  I1557;
    struct futq * I1558;
    struct dummyq_struct * pQ = I1297;
    I1555 = ((U )vcs_clocks) + I686;
    I1557 = I1555 & ((1 << fHashTableSize) - 1);
    I1291->I728 = (EBLK  *)(-1);
    I1291->I732 = I1555;
    if (I1555 < (U )vcs_clocks) {
        I1556 = ((U  *)&vcs_clocks)[1];
        sched_millenium(pQ, I1291, I1556 + 1, I1555);
    }
    else if ((peblkFutQ1Head != ((void *)0)) && (I686 == 1)) {
        I1291->I734 = (struct eblk *)peblkFutQ1Tail;
        peblkFutQ1Tail->I728 = I1291;
        peblkFutQ1Tail = I1291;
    }
    else if ((I1558 = pQ->I1198[I1557].I746)) {
        I1291->I734 = (struct eblk *)I1558->I745;
        I1558->I745->I728 = (RP )I1291;
        I1558->I745 = (RmaEblk  *)I1291;
    }
    else {
        sched_hsopt(pQ, I1291, I1555);
    }
}
#ifdef __cplusplus
extern "C" {
#endif
void SinitHsimPats(void);
#ifdef __cplusplus
}
#endif
