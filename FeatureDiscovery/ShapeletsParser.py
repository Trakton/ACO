import json
import sys

with open(sys.argv[1]) as f:
    data = json.load(f)

array = [x["shapelet"] for x in data["shapelets"]]

with open(sys.argv[2], 'w') as f:
    f.writelines(["%s\n" % ','.join(map(str, x))  for x in array])

