import json

with open('data/shapelets.json') as f:
    data = json.load(f)

array = [x["shapelet"] for x in data["shapelets"]]

with open('data/shapelets_parsed.csv', 'w') as f:
    f.writelines(["%s\n" % ','.join(map(str, x))  for x in array])

