import json
import time
import sys

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
	
	@staticmethod
	def stringify_byte(_):
		return bin(ord(_))[2:].rjust(8, '0')

	@staticmethod
	def generate_extra_bits(extra_bit_count):
		extra_code = '0' * extra_bit_count
		return extra_code + "{0:08b}".format(extra_bit_count)
	
	@staticmethod
	def remove_extra_bits(encoded_string):
		return encoded_string[: -1 * (8 + int(encoded_string[-8:], 2))]
		
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
		nodes = sorted( [Huffman_Codec.new_node(frequency, key, None, None) for key, frequency in self.key_frequency_table.items()], key = lambda node:node['frequency'] )
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
			nodes.insert(insert_idx if insert_idx != -1 else len(nodes) - 1, tree)
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
		self.keys = { code: key for key, code in self.codes.items() }

	def encode(self, string):
		encoded_string = ''
		for character in string:
			encoded_string += self.codes[character]
		return encoded_string
		
	def decode(self, encoded_data):
		code = ''
		decoded_string = ''
		for bit in encoded_data:
			code += bit
			if code in self.keys:
				decoded_string += self.keys[code]
				code = ''
		return decoded_string
		
	def compress(self, encoded_string, b_filename):
		'''
		extra_bit_count = 8 - len(encoded_string) % 8
		extra_code = ''
		for i in range(extra_bit_count):
			extra_code += '0'
		encoded_string += extra_code
		encoded_string += "{0:08b}".format(extra_bit_count)
		'''
		encoded_string += Huffman_Codec.generate_extra_bits(8 - len(encoded_string) % 8) 
		b = bytearray()
		for i in range(0, len(encoded_string), 8):
			byte = encoded_string[i:i+8]
			b.append(int(byte, 2))
		with open(b_filename, 'wb') as o_file:
			o_file.write(bytes(b))
		
	def compress_file(self, i_filename, b_filename):
		with open(i_filename, 'r') as i_file, open(b_filename, 'wb') as b_file:
			code = ''
			bytes = bytearray()
			character = i_file.read(1)
			while True:
				code += self.codes[character]
				while len(code) >= 8:
					bytes.append(int(code[:8], 2))
					code = code[8:]
					b_file.write(bytes)
					bytes = bytearray()
				character = i_file.read(1)
				if character == '':
					# we are in the endgame now.
					'''
					extra_code_len = 8 - len(code) % 8
					extra_code = ''
					for i in range(extra_code_len):
						extra_code += '0'
					code += extra_code + '{0:08b}'.format(extra_code_len)
					'''
					code += Huffman_Codec.generate_extra_bits(8 - len(code) % 8)
					bytes = bytearray()
					for i in range(0, len(code), 8):
						byte = code[i:i+8]
						bytes.append(int(byte, 2))
					b_file.write(bytes)
					break
			b_file.close()

	def analyse_codes(self):
		codes_list = []
		max_code = 0
		for key, code in self.codes.items():
			if len(code) > max_code:
				max_code = len(code)
		return max_code
	
	def extract(self, filename, outputfilename):
		with open(filename, 'rb') as b_file, open(outputfilename, 'w') as o_file:
			bit_string = ''
			byte = b_file.read(1)
			while byte != b'':
				bits = Huffman_Codec.stringify_byte(byte)
				bit_string += bits
				byte = b_file.read(1)
			o_text = self.decode(Huffman_Codec.remove_extra_bits(bit_string))
			o_file.write(o_text)
	
	def extract_file(self, b_filename, o_filename):
		with open(b_filename, 'rb') as b_file, open(o_filename, 'w') as o_file:
			max_code = self.analyse_codes()
			byte_queue_size, bitcode_queue_size = 2, max_code
			bq = []
			Bq = [ b_file.read(1) for unused in range(byte_queue_size) ]
			code = ''
			while Bq:
				if code in self.keys:
					o_file.write(self.keys[code])
					code = ''
				if len(bq) < bitcode_queue_size:
					next_byte = b_file.read(1)
					if next_byte != b'':
						Bq.append(next_byte)
						byte = Bq.pop(0)
						bits = Huffman_Codec.stringify_byte(byte)
						'''
						for bit in bits:
							bq.append(bit)
						'''
						bq += [bit for bit in bits]
					else:
						# we are in the endgame now.
						while bq:
							code += bq.pop(0)
						final_bytes = []
						while Bq:
							final_bytes.append(Bq.pop(0))
						for byte in final_bytes:
							bits = Huffman_Codec.stringify_byte(byte)
							code += bits
						o_file.write(self.decode(Huffman_Codec.remove_extra_bits(code)))
						o_file.close()
						break
				code += bq.pop(0)
			print("\n\n\t mission accomplished!")
		return
		
	def write_codes(self):
		code_str = json.dumps(self.codes, separators=(',', ':'))
		print(code_str)
	
		

		

codec = Huffman_Codec()

f = open('otext.txt', 'r')

#string = "abcdefghijklmnopqrstuvwxyz"
string = f.read()

print(codec.analyse_file('otext.txt'))
print(codec.generate_tree())
print(codec.generate_codes())
print(codec.generate_keys())

codec.compress_file('otext.txt', 'test.bin')
codec.analyse_codes()
codec.extract_file('test.bin', 'test.json')
codec.write_codes()
'''
codec.compress(e, 'test1.bin')
codec.extract('test1.bin', 'test1.py')
'''

#print(codec.analyse_file('otext.txt'),Huffman_Codec.new_node())


# testing static methods
'''
node_a = Huffman_Codec.new_node(10,'A',None,None)
node_b = Huffman_Codec.new_node(20,'B',None,None)
print(node_a,node_b)
print(Huffman_Codec.merge_nodes(node_a, node_b))
'''