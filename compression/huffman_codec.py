import json

class Huffman_Codec:
	def _init_(self):
		self.codes = {}
		self.keys = {}
		self.key_frequency_table = {}
		self.tree = {}
		
	def kowalski_analysis(self, string):
		self.key_frequency_table = {}
		for character in string:
			if self.key_frequency_table.get(character):
				self.key_frequency_table[character] = self.key_frequency_table[character] + 1
			else:
				self.key_frequency_table[character] = 1
		return self.key_frequency_table