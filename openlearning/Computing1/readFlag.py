#!/usr/bin/python
# Billy Chia
# Dec 27, 2012
# readFlag.py
# Code to read an ascii picture point by point
# take the coordinates for each type of charcter
# and generate c code to generate the original 
# run python readFlag.py > pixelTests.h

filename = "BeiyangFleetFlag.txt"
d = {}
row = 0
col = 0
MOST_USED_CHAR = ','

with open(filename) as f:
  while True:
    c = f.read(1)
    if not c:
      break # EOF

    if c != "\n":
        col += 1
    else:
        col = 0
        row += 1 

    if not c in d:
        d[c] = { row: [col] }
    else:
        if row in d[c]:
            d[c][row] += [col]
        else:
           d[c][row] = [col]

for pix in d:
    if pix != '\n' and pix != MOST_USED_CHAR:
        func = d[pix]
        count = 0
        print "int is%s (int col, int row) {" % ord(pix)
        print "\treturn ("

        for c in func:
            count += 1
            lastC = len(func) == count

            for e in func[c]:
                lastE = func[c].index(e) == len(func[c]) - 1
                barbar = (lastC and lastE) and ");" or "||"
                print "\t\t(row == %s && col == %s) %s" % (c, e, barbar)

        print "}\n"

