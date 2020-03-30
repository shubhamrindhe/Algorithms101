import json

def savior(fname,data):
	file = open(fname, 'w')
	json.dump(data, file,default=lambda o: o.__dict__, indent = 2)
	file.close()

def frequency_table(string):
	freq_table = {}
	for character in string:
		if freq_table.get(character):
			freq_table[character] = freq_table[character] + 1
		else:
			freq_table[character] = 1
	return freq_table

def new_node(frequency = 0, key = None, zero = None, one = None ):
	return  { 'f': frequency, 'k': key, '0': zero, '1': one }
	
def merge_nodes(node_zero, node_one):
	return new_node(node_zero['f'] + node_one['f'], None, node_zero, node_one)

def huffman_tree(string):
	data = frequency_table(string)
	nodes = sorted( [new_node(data[key], key, None, None) for key in data], key = lambda i:i['f'] )
	tree = None
	while nodes:
		node_0 = node_1 = None
		if len(nodes) > 1:
			node_1 = nodes.pop(0)
			node_0 = nodes.pop(0)
		else:
			break;
		tree = merge_nodes(node_0, node_1)
		insert_idx = -1
		for idx,node in enumerate(nodes):
			if node['f'] > tree['f']:
				insert_idx = idx
				break
		nodes.insert(insert_idx if insert_idx!=-1 else len(nodes) - 1, tree)
	return nodes.pop();

codes = {}
def tree_crawler(root, code = ''):
	if not root:
		return 
	if root['k'] != None:
		codes[code] = root['k']
		return 
	tree_crawler(root['0'], code+'0')
	tree_crawler(root['1'], code+'1')

def huffman_code_map(string):
	code_dict = {}
	tree = huffman_tree(string);
	savior('tree.json',tree)
	tree_crawler(tree)
	return codes
	
def encode(string):
	codes = huffman_code_map(string)
	key_codes = {}
	for code in codes:
		key_codes[codes[code]] = code
	encoded_string = ""
	for character in string:
		encoded_string += key_codes[character]
	print("\n\n\n\n\n", encoded_string, len(encoded_string) / 8)
	return encoded_string
	
def decode(data, codes):
	code = ""
	decoded_string = ""
	for bit in data:
		code += bit
		if code in codes:
			decoded_string += codes[code]
			code = ""
	print(decoded_string, len(decoded_string)*8)
	return decoded_string

def write_binary(coded_data):
	extra_bit_count = 8 - len(coded_data) % 8
	extra_code = ''
	for i in range(extra_bit_count):
		extra_code += '0'
	coded_data += extra_code
	coded_data += "{0:08b}".format(extra_bit_count)
	print(coded_data)
	#file = open('com.xhu','bw')
	

#string = "abcdefghijklmnopqrstuvwxyz"
string = "aaaabbbccd"
print(string,frequency_table(string))

print(" tree ",huffman_tree(string))

huffman_code_map(string);
savior('codes.json',codes)
encoded_string = encode(string)
print("\n\n\n",len(decode(encoded_string,codes)) / (len(string)*8) * 100, "% Compression")

print("\n\n\n")
write_binary("1111")


'''
mnist = open('mnist_train.json')
codes = {}
print(" \n\n\n\n\n\n ",huffman_code_map(mnist.read()))
print("\n\n\n",len(decode(encode(mnist.read()),codes)) / (len(string)*8) * 100, "% Compression")
savior('codes.json',codes)
'''

'''
print(merge_nodes(new_node(1,'a',0,1),new_node(2,'b',0,1)))


a = [0,1,2,3,4,5]
print(a)
print(a.pop(0))
print(a)
print(a.pop(2))
print(a)

while a:
	print("da",a.pop())

print('\n\n\n')
s = [{ 'x' : 3}, { 'x' : 2}, { 'x' : 1}, { 'x' : 0}]
print(s)
print(sorted(s, key = lambda i:i['x']))
print(s)
print('\n\n\n')
'''