import huffman_codec as CODEC

codec = CODEC.Huffman_Codec()

codec.load_codes('test.xhu.codes.json')
codec.extract_file('test.xhu', 'reconstructed.txt')
