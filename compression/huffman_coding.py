import json

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
	print(codes)
	
	
def huffman_code_map(string):
	code_dict = {}
	tree = huffman_tree(string);
	print("\n\n\n themap \n",tree_crawler(tree))
	
	
	

string = "huffman"
print(string,frequency_table(string))
print(new_node(12,"xhu",{ '0' : 0 }, { '1' : 1}))
print({ key : key for key in ['a' , 'b']})

print(" tree ",huffman_tree(string))

print(merge_nodes(new_node(1,'a',0,1),new_node(2,'b',0,1)))

huffman_code_map(string);

'''
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