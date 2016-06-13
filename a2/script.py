import sys

if __name__ == "__main__":
    # Open a file
    uniqueCodePages = []
    uniqueDataPages = []
    memBeforeAfter = 0
    algoMem = 0
    inAlgo = 0
    beginMarker = sys.argv[2]
    endMarker = sys.argv[3]
    fo = open(sys.argv[1], "r")
    for line in fo:
        if not line.startswith('=='):
            # check for unique code pages
            if line[0] == 'I':
                if line[3:8] not in uniqueCodePages:
                    uniqueCodePages.append(line[3:8])
            # check for unique data pages
            elif 'S' in line or 'L' in line or 'M' in line:
                if line[3:8] not in uniqueDataPages:
                    uniqueDataPages.append(line[3:8])
            #check for number of memory accesses before and after the markers

            # used in tracing the makeTrace
            if beginMarker < 0 or endMarker < 0:
                memBeforeAfter = 0
                algoMem = 0
                
            else:    
                if beginMarker[2:] in line:
                    inAlgo = 1

                elif endMarker[2:] in line:
                    inAlgo = 0
                
                elif inAlgo == 0:
                    memBeforeAfter += 1
                
                elif inAlgo == 1:
                    algoMem += 1
                    
                
    print('**********', sys.argv[1], '**********')
    print('Number of unique code pages:', len(uniqueCodePages))
    print('Number of unique data pages:', len(uniqueDataPages))
    if beginMarker < 0 or endMarker < 0:
        print('Number of memory accesses before and after the markers: ignored')
        print('Number of memory accesses in algorithm component of the program: ignored')
    else:
        print('Number of memory accesses before and after the markers:', memBeforeAfter)
        print('Number of memory accesses in algorithm component of the program:', algoMem)
