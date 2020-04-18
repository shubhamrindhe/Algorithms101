
function encrypt_string(data, key) {
	var cipher = '';
	const _key_codes_ = [];
	
	if (typeof key == "number") {
		_key_codes_.push(key);
	} else if (typeof key == "string") {
		for (var i=0; i < key.length; ++i) {
			_key_codes_.push( key.charCodeAt(i) );
		}
	}
	
	for (var idx = 0; idx < data.length; ++idx) {
		cipher += String.fromCharCode( data.charCodeAt(idx) ^ _key_codes_[ idx % _key_codes_.length ] );
	}
	
	return cipher;
}

function encrypt_bytes(data, key) {
	var cipher = [];
	const _key_codes_ = [];
	
	if (typeof key == "number") {
		_key_codes_.push(key);
	} else if (typeof key == "string") {
		for (var i=0; i < key.length; ++i) {
			_key_codes_.push( key.charCodeAt(i) );
		}
	}
	
	for (var idx = 0; idx < data.length; ++idx) {
		cipher.push( data[idx] ^ _key_codes_[ idx % _key_codes_.length ] );
	}
	
	return cipher;
}
