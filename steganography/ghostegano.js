String.prototype.ljust = function (length, _char_) {
	var fill = [];
	while ( fill.length + this.length < length) {
		fill[fill.length] = _char_;
	}
	return fill.join('') + this; 
}
	
String.prototype.rjust = function (length, _char_) {
	var fill = [];
	while ( fill.length + this.length < length) {
		fill[fill.length] = _char_;
	}
	return this + fill.join(''); 
}

function getDataURL (img_data, compression_format = 'image/png', quality = 1) {
	var HTML_canvas = document.createElement('canvas');
	HTML_canvas.width = img_data.width;
	HTML_canvas.height = img_data.height;
	var context = HTML_canvas.getContext('2d');
	context.putImageData(img_data,0,0);
	return HTML_canvas.toDataURL(compression_format, quality);
}

function savePNG (img_data) {
	/*
	var HTML_canvas = document.createElement('canvas');
	HTML_canvas.width = img_data.width;
	HTML_canvas.height = img_data.height;
	var context = HTML_canvas.getContext('2d');
	context.putImageData(img_data,0,0);
	*/

	var anchor = document.createElement('a');
	anchor.download = 'img.png';
	anchor.href = getDataURL(img_data);//HTML_canvas.toDataURL('image/png',1);
	document.body.appendChild(anchor);
	anchor.click();
}

function encode_string (data) {
	_bytes_ = [];
	for (var i=0; i<data.length; ++i) {
		var _ = data.charCodeAt(i).toString(2).ljust(8,'0');
		_bytes_.push(_);
	}
	return _bytes_;
}

function decode_string (data) {
	decoded_string = '';
	for (var i=0; i<data.length; ++i) {
		decoded_string += String.fromCharCode(parseInt(data[i], 2));
	}
	return decoded_string;
}
		
function split_byte_string (byte_string) {
	if (byte_string.length == 8) {
		return byte_string.match(/.{1,2}/g);
	} else {
		return null;
	}
}

function embed_bits_to_byte(_byte_, _bits_) {
	if (_byte_ < 0 || _byte_ > 255) {
		return null; 
	} else {		
		var data = parseInt(_bits_ , 2);
		var mask = 0b11111111;
		for (var i=0;i<_bits_.length;++i) {
			mask -= Math.pow(2,i);
		}
		return (( _byte_ & mask ) | data );
	}
}
		
function extract_bits_from_byte(_byte_ , bit_count) {
	if (_byte_ < 0 || _byte_ > 255) {
		return null; 
	} else {		
		var mask = 0b00000000;
		for (var i=0;i<bit_count;++i) {
			mask += Math.pow(2,i)
		}
		return _byte_ & mask;
	}
}


function embed_data_in_image (img_data, data) {
	/*
	for(var i=0 ; i<img_data.data.length;++i){	
		img_data.data[i] = i % 4 == 3 ? 255 :0;
	}
	*/
			
	var code = encode_string(data);
	console.log('code : ',code,decode_string(code));
	var pixel_idx = 0, j=0;
	for (pixel_idx=0, j=0; pixel_idx < img_data.data.length && j <= code.length; pixel_idx+=4,++j) {
		var sliced_byte = split_byte_string(( j==code.length ? '00000000' : code[j] ));
		/*
		var sliced_byte;
		if (j==code.length) {
			sliced_byte = split_byte_string('00000000');
		} else {
			sliced_byte = split_byte_string(code[j]);
		}
		*/
		img_data.data[pixel_idx]   = embed_bits_to_byte(img_data.data[pixel_idx],   sliced_byte[0]);
		img_data.data[pixel_idx+1] = embed_bits_to_byte(img_data.data[pixel_idx+1], sliced_byte[1]);
		img_data.data[pixel_idx+2] = embed_bits_to_byte(img_data.data[pixel_idx+2], sliced_byte[2]);
		img_data.data[pixel_idx+3] = embed_bits_to_byte(img_data.data[pixel_idx+3], sliced_byte[3]);
	}
	extract_data_from_img(img_data);

	//savePNG(img_data);
	
	return img_data;
}
		
function extract_data_from_img(img_data) {
	data = [];
	for (var i=0; i < img_data.data.length; i+=4) {
		bits = [];
				
		bits.push(extract_bits_from_byte(img_data.data[i], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+1], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+2], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+3], 2));
			
		console.log(bits);
			
		var _byte_ = 0b00000000;
		bits.forEach (function (e,i,l) {
			_byte_ = (_byte_ << 2) | e;
		});
		
		/*
		_byte_ = (_byte_ << 2) | bits[0];
		_byte_ = (_byte_ << 2) | bits[1];
		_byte_ = (_byte_ << 2) | bits[2];
		_byte_ = (_byte_ << 2) | bits[3];
		*/
		
		if (!_byte_) {
			break;
		}
				
		data.push(_byte_.toString(2).ljust(8, '0'));
	}
	console.log("cjschab",decode_string(data));
	return data;
}
