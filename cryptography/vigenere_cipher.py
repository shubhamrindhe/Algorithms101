
def encrypt(plaintext, key):
	cipher = []
	key = key.upper()
	key_size = len(key)
	for index,character in enumerate(plaintext.upper().replace(" ","")):
		key_idx = index % key_size
		shift = ord(key[key_idx]) - ord('A')
		plain_ord = ord(character) - ord('A')
		cipher_ord = (plain_ord + shift) % 26
		cipher.append(chr(cipher_ord + ord('A')))
	return "".join(cipher)

def decrypt(ciphertext, key):
	plain = []
	key = key.upper()
	key_size = len(key)
	for index,character in enumerate(ciphertext.upper().replace(" ","")):
		key_idx = index % key_size
		shift = ord(key[key_idx]) - ord('A')
		cipher_ord = ord(character) - ord('A')
		plain_ord = (cipher_ord + 26 - shift) % 26
		plain.append(chr(plain_ord + ord('A')))
	return "".join(plain)


test_key = "shubham"
c = encrypt("aaahello worldzzz", test_key)
print(c)

p = decrypt(c, test_key)
print(p)
