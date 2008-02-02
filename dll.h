#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */


int nextZero(int arr[]);
int isValid(int arr[], int pos);
DLLIMPORT int solveBrute(int arr[]);

#endif /* _DLL_H_ */
