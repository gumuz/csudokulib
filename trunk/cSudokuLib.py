# cSudokuLib ctypes-wrapper
#
#
# gumuz.nl

from ctypes import *

try:
    sudokulib = cdll.LoadLibrary('csudokulib.so')
except Exception, e:
    print "Error loading cSudokuLib.dll"
    raise e

def solveBrute(list_of_ints):
    list_of_ints = list_of_ints[:] # working copy
    
    intArray = c_int*len(list_of_ints)
    c_arr = intArray(*list_of_ints)
    
    sudokulib.solveBrute(c_arr)
    
    return list(c_arr)

if __name__ == '__main__':
    print "Brute Force cSudoku Solver -- gumuz.nl"
    print
    
    import time, sys
    
    if len(sys.argv) == 1:
        print "Usage: sudoku.py filename.txt"
        sys.exit()
    
    for filename in sys.argv[1:]:
        start = time.time()
        print "processing", filename        
        puzzles = [ [int(n) for n in p.strip()] \
                    for p in open(filename, 'r')]
        for p in puzzles:
            solveBrute(p)
        print "%s sudoku's solved in %s seconds" % (len(puzzles), round(time.time()-start))
