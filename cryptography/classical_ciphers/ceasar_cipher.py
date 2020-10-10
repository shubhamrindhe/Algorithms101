
def encrypt(plaintext, key):
	cipher = []
	for character in plaintext.upper().replace(" ",""):
		plain_ord = ord(character) - ord('A')
		cipher_ord = (plain_ord + key) % 26
		cipher.append(chr(cipher_ord + ord('A')))
	return "".join(cipher)

def decrypt(ciphertext, key):		
	return encrypt(ciphertext, 26 - key) 



test_key = 22
c = encrypt("aaahello worldzzz", test_key)
print(c)
p = decrypt(c, test_key)
print(p)
