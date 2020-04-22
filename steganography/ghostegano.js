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

function get_img_data(img) {
	var HTML_canvas = document.createElement('canvas');
	HTML_canvas.width = img.width;
	HTML_canvas.height = img.height;
	var context = HTML_canvas.getContext('2d');
	context.drawImage(img,0,0,img.width,img.height);
	return context.getImageData(0,0,context.canvas.width,context.canvas.height);
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
	var _bytes_ = [];
	for (var i=0; i<data.length; ++i) {
		var _ = data.charCodeAt(i).toString(2).ljust(8,'0');
		_bytes_.push(_);
	}
	return _bytes_;
}

function decode_string (data) {
	var decoded_string = '';
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


function embed_data_in_image_data (img_data, data) {
	var code = encode_string(data);
	var pixel_idx = 0, j=0;
	/*
	for (pixel_idx=0, j=0; pixel_idx < img_data.data.length && j <= code.length; pixel_idx+=4,++j) {
		var sliced_byte = split_byte_string(( j==code.length ? '00000000' : code[j] ));
		img_data.data[pixel_idx]   = embed_bits_to_byte(img_data.data[pixel_idx],   sliced_byte[0]);
		img_data.data[pixel_idx+1] = embed_bits_to_byte(img_data.data[pixel_idx+1], sliced_byte[1]);
		img_data.data[pixel_idx+2] = embed_bits_to_byte(img_data.data[pixel_idx+2], sliced_byte[2] + sliced_byte[3]);
		//img_data.data[pixel_idx+3] = embed_bits_to_byte(img_data.data[pixel_idx+3], sliced_byte[3]);
	}
	*/
	
	code.push('00000000');
	var bit_queue = [];
	
	while (code.length != 0) {
		bit_queue = bit_queue.concat( code.shift().split('') );
	}
	
	while (true) {
		
		if (pixel_idx < img_data.data.length) {
			
		} else {
			break;
		}
		
		if (bit_queue.length == 0) {
			break;
		}
		
		img_data.data[pixel_idx]   = embed_bits_to_byte(img_data.data[pixel_idx], bit_queue.shift() + bit_queue.shift());
		img_data.data[pixel_idx+1] = embed_bits_to_byte(img_data.data[pixel_idx+1], bit_queue.shift() + bit_queue.shift());
		img_data.data[pixel_idx+2] = embed_bits_to_byte(img_data.data[pixel_idx+2], bit_queue.shift() + bit_queue.shift() + bit_queue.shift() + bit_queue.shift());
		
		pixel_idx+=4;
		++j;
	}
	
	return img_data;
}
		
function extract_data_from_img_data(img_data) {
	var data = [];
	/*
	for (var i=0; i < img_data.data.length; i+=4) {
		var bits = [];
				
		bits.push(extract_bits_from_byte(img_data.data[i], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+1], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+2], 4));
		//bits.push(extract_bits_from_byte(img_data.data[i+3], 2));
		//var _byte_ = bits.reduce(function (accumulator, current_value) {return (accumulator << 2) | current_value; });
		
		var _byte_;
		_byte_ = bits[0];
		_byte_ = (_byte_ << 2) | bits[1];
		_byte_ = (_byte_ << 4) | bits[2];
		
		if (!_byte_) {
			console.log("break", i, bits);
			break;
		}
		
		data.push(_byte_.toString(2).ljust(8, '0'));
	}
	*/
	
	var i=0;
	while (i < img_data.data.length) {
		var bits = [];
				
		bits.push(extract_bits_from_byte(img_data.data[i], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+1], 2));
		bits.push(extract_bits_from_byte(img_data.data[i+2], 4));
		//bits.push(extract_bits_from_byte(img_data.data[i+3], 2));
		//var _byte_ = bits.reduce(function (accumulator, current_value) {return (accumulator << 2) | current_value; });
		
		var _byte_;
		_byte_ = bits[0];
		_byte_ = (_byte_ << 2) | bits[1];
		_byte_ = (_byte_ << 4) | bits[2];
		
		if (!_byte_) {
			console.log("break", i, bits);
			break;
		}
		
		data.push(_byte_.toString(2).ljust(8, '0'));
		
		i += 4;
	}
	
	return data;
}

function extract_text_from_img_data(img_data) {
	const data = extract_data_from_img_data(img_data);
	console.log(data);
	return decode_string(data);
}