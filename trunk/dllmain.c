/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int isValid(int arr[], int pos) {
    // check if gives pos is valid in arr

    // checking arrays
    int v_tmp[10] = {};
    int h_tmp[10] = {};
    int tmp[10] = {};
    
    int k, nv, nh;
    int i, j, sub_y, sub_x, n;
    
    int x,y;
    
    // 2d coords
    y = pos/9;
    x = pos%9;

    // check vertical & horizontal
    for (k=0; k<9; k++) {
        nv = arr[(k*9)+x];
        nh = arr[(y*9)+k];

        // duplicates?
        if (v_tmp[nv] || h_tmp[nh]) return 0;

        // remember
        if (nv) v_tmp[nv] = 1;
        if (nh) h_tmp[nh] = 1;

    }
    // check sub-square (3x3)
    sub_y = (y/3)*3;
    sub_x = (x/3)*3;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            n = arr[(i*9)+(sub_y*9)+sub_x+j];
            if (tmp[n]) return 0;
            if (n) tmp[n] = 1;
        }
    }

    return 1;
}

int nextZero(int arr[]) {
    // find next 0
    int i=0;
    for (i=0; i<81; i++) {
        if (arr[i] == 0) return i;
    }
    
    // none found
    return -1;
}
    
DLLIMPORT int solveBrute(int arr[]) {
    int i, sol;
    
    int pos = nextZero(arr);

    if (pos < 0) return 1; // done!

    for (i=1; i<10; i++) {
        arr[pos] = i;

        if (isValid(arr, pos)) {
            sol = solveBrute(arr);
            if (sol) return sol;
        }
    }
    arr[pos] = 0; // reset!
    return 0;
}


BOOL APIENTRY DllMain (HINSTANCE hInst ,
                       DWORD reason,
                       LPVOID reserved)
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
