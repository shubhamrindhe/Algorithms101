
class PlayfairCipher:
	#@constant
	def alphabet_str():
		return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	def __init__(self,key,ignore='J'):
		self.key = key
		self.square = []
		for e in self.key.upper():
			if e not in self.square:
				self.square.append(e)
		alphabet = PlayfairCipher.alphabet_str() 
		for e in alphabet.upper():
			if e not in self.square and e is not ignore:
				self.square.append(e)
		self.matrix = []
		for e in range(5):
			self.matrix.append('')
		self.matrix[0]=self.square[0:5]
		self.matrix[1]=self.square[5:10]
		self.matrix[2]=self.square[10:15]
		self.matrix[3]=self.square[15:20]
		self.matrix[4]=self.square[20:25]

	def render_matrix(self):
		for i in self.matrix:
			print(i)

	def message_to_digraphs(self,message_original):
		message=[]
		for e in message_original:
			message.append(e.upper())
		for unused in range(len(message)):
			if " " in message:
				message.remove(" ")
		i=0
		for e in range(len(message)//2):
			if message[i]==message[i+1]:
				message.insert(i+1,'X')
			i=i+2
		if len(message)%2==1:
			message.append("X")
		i=0
		new=[]
		for x in range(1,len(message)//2+1):
			new.append(message[i:i+2])
			i=i+2
		return new
		
	def find_position(self,letter):
		x=y=0
		for i in range(5):
			for j in range(5):
				if self.matrix[i][j]==letter:
					x=i
					y=j
		return x,y


	def encrypt(self,message):
		message = self.message_to_digraphs(message)
		cipher=[]
		for e in message:
			r1,c1 = self.find_position(e[0])
			r2,c2 = self.find_position(e[1])
			
			if r1==r2: #same_row
				if c1==4:
					c1=-1
				if c2==4:
					c2=-1
				cipher.append(self.matrix[r1][c1+1])
				cipher.append(self.matrix[r1][c2+1])		
			elif c1==c2: #same_column next element in matrix
				if r1==4:
					r1=-1;
				if r2==4:
					r2=-1;
				cipher.append(self.matrix[r1+1][c1])
				cipher.append(self.matrix[r2+1][c2])
			else: #rectangle -same row opposite column
				cipher.append(self.matrix[r1][c2])
				cipher.append(self.matrix[r2][c1])

			output=""
			for e in cipher:
				output+=e
		return output

	def cipher_to_digraphs(self,cipher):
		i=0
		new=[]
		for x in range(len(cipher)//2):
			new.append(cipher[i:i+2])
			i=i+2
		return new


	def decrypt(self,cipher):	
		cipher=self.cipher_to_digraphs(cipher)
		plaintext=[]
		msg = ""
		for e in cipher:
			r1,c1=self.find_position(e[0])
			r2,c2=self.find_position(e[1])
			if r1==r2:
				if c1==4:
					c1=-1
				if c2==4:
					c2=-1
				plaintext.append(self.matrix[r1][c1-1])
				plaintext.append(self.matrix[r1][c2-1])
			elif c1==c2:
				if r1==4:
					r1=-1;
				if r2==4:
					r2=-1;
				plaintext.append(self.matrix[r1-1][c1])
				plaintext.append(self.matrix[r2-1][c2])
			else:
				plaintext.append(self.matrix[r1][c2])
				plaintext.append(self.matrix[r2][c1])
		for unused in range(len(plaintext)):
			if "X" in plaintext:
				plaintext.remove("X")
	
		output=""
		for e in plaintext:
			output+=e
		return output

		
key = "playfairexample"
pf = PlayfairCipher(key)
pf.render_matrix()
cip = pf.encrypt("Hide the gold in the tree stump")
print(cip)
print(pf.decrypt(cip))