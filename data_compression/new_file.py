import json

filename = "anton.json"
with open(filename, 'r') as codes_file, open('num_arr,json','w') as out:
	num_arr = json.loads(codes_file.read())
	print(num_arr)
	out.write(json.dumps(num_arr, separators=(',', ':')))
	out.close()