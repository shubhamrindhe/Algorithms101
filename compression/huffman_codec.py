import json

class Huffman_Codec:
	def _init_(self):
		self.codes = {}
		self.keys = {}
		self.key_frequency_table = {}
		self.tree = None
	
	@staticmethod
	def new_node(frequency = 0, key = None, zero = None, one = None ):
		return { 'frequency': frequency, 'key': key, '0': zero, '1': one }

	@staticmethod	
	def merge_nodes(node_zero, node_one):
		return Huffman_Codec.new_node(node_zero['frequency'] + node_one['frequency'], None, node_zero, node_one)
		
	def analyse_file(self, filename):
		self.key_frequency_table = {}
		with open(filename) as input_file:
			character = input_file.read(1)
			while character != '':
				if self.key_frequency_table.get(character):
					self.key_frequency_table[character] = self.key_frequency_table[character] + 1
				else:
					self.key_frequency_table[character] = 1
				character = input_file.read(1)
			return self.key_frequency_table
			
	def analyse_string(self, string):
		self.key_frequency_table = {}
		for character in string:
			if self.key_frequency_table.get(character):
				self.key_frequency_table[character] = self.key_frequency_table[character] + 1
			else:
				self.key_frequency_table[character] = 1
		return self.key_frequency_table
				
	def generate_tree(self):
		nodes = sorted([Huffman_Codec.new_node(frequency, key, None, None) for key, frequency in self.key_frequency_table.items()], key = lambda node:node['frequency'])
		tree = None
		while nodes:
			node_0 = node_1 = None
			if len(nodes) > 1:
				node_1 = nodes.pop(0)
				node_0 = nodes.pop(0)
			else:
				break;
			tree = Huffman_Codec.merge_nodes(node_0, node_1)
			insert_idx = -1
			for idx,node in enumerate(nodes):
				if node['frequency'] > tree['frequency']:
					insert_idx = idx
					break
			nodes.insert(insert_idx if insert_idx!=-1 else len(nodes) - 1, tree)
		self.tree = nodes.pop()
		return self.tree;
		
	def crawler(self, root, currentcode = ''):
		if not root:
			return 
		if root['key'] != None:
			self.codes[root['key']] = currentcode
			return 
		self.crawler(root['0'], currentcode+'0')
		self.crawler(root['1'], currentcode+'1')

	def generate_codes(self):
		self.codes = {}
		self.crawler(self.tree)
		return self.codes
	
	def generate_keys(self):
		self.keys = {}
		for key, code in self.codes.items():
			self.keys[code] = key
		print(self.keys)
		
	def encode(self, string):
		encoded_string = ""
		for character in string:
			encoded_string += self.codes[character]
		return encoded_string
		
	def decode(self, encoded_data):
		code = ""
		decoded_string = ""
		for bit in encoded_data:
			code += bit
			if code in self.keys:
				decoded_string += self.keys[code]
				code = ""
		print(len(decoded_string)*8)
		return decoded_string
		
	def compress(self, encoded_string, b_filename):
		extra_bit_count = 8 - len(encoded_string) % 8
		extra_code = ''
		for i in range(extra_bit_count):
			extra_code += '0'
		encoded_string += extra_code
		encoded_string += "{0:08b}".format(extra_bit_count)
		b = bytearray()
		for i in range(0, len(encoded_string), 8):
			byte = encoded_string[i:i+8]
			b.append(int(byte, 2))
		with open(b_filename, 'wb') as o_file:
			o_file.write(bytes(b))
		
	@staticmethod
	def remove_extra_bits(encoded_string):
		extra_bit_count_byte = encoded_string[-8:]
		extra_bit_count = int(extra_bit_count_byte,2)
		return encoded_string[:-1*(8+extra_bit_count)]
			
	def extract(self, filename, outputfilename):
		with open(filename, 'rb') as b_file, open(outputfilename, 'w') as o_file:
			bit_string = ''
			byte = b_file.read(1)
			while byte != b'':
				byte_ord = ord(byte)
				bits = bin(byte_ord)[2:].rjust(8,'0')
				bit_string += bits
				byte = b_file.read(1)
			o_text = self.decode(Huffman_Codec.remove_extra_bits(bit_string))
			o_file.write(o_text)
		

codec = Huffman_Codec()

f = open('huffman_coding.py', 'r')

#string = "abcdefghijklmnopqrstuvwxyz"
string = f.read()

print(codec.analyse_string(string))
print(codec.generate_tree())
print(codec.generate_codes())
print(codec.generate_keys())

e = codec.encode(string)
print(e)
print(codec.decode(e))

codec.compress(e, 'test.bin')
codec.extract('test.bin', 'test.py')


#print(codec.analyse_file('otext.txt'),Huffman_Codec.new_node())


# testing static methods
'''
node_a = Huffman_Codec.new_node(10,'A',None,None)
node_b = Huffman_Codec.new_node(20,'B',None,None)
print(node_a,node_b)
print(Huffman_Codec.merge_nodes(node_a, node_b))
'''