
class Stegosaurus {

	constructor (LSB_r = 2, LSB_g = 2, LSB_b = 2) {
		
		this.LSB = {
			r : LSB_r,
			g : LSB_g,
			b : LSB_b
		};
		this.data_element_size = 8;
		
	}
	
	static encode_string (data) {
		var _bytes_ = [];
		for (var i=0; i<data.length; ++i) {
			var _ = data.charCodeAt(i).toString(2).ljust(8,'0');
			_bytes_.push(_);
		}
		return _bytes_;
	}

	static decode_string (data) {
		var decoded_string = '';
		for (var i=0; i<data.length; ++i) {
			decoded_string += String.fromCharCode(parseInt(data[i], 2));
		}
		return decoded_string;
	}
	
	static embed_bits_to_LSB(_byte_, _bits_) {
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
	
	static embeding_mask () {
		
	}
	
	static extracting_mask () {
		
	}
			
	static extract_bits_from_LSB(_byte_ , bit_count) {
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
	
	embed_text_in_img_data(img_data, text) {
		return this.embed_data_in_img_data(img_data, Stegosaurus.encode_string(text));	
	}
	
	embed_data_in_img_data(img_data, data) {
		var pixel_idx = 0, j=0;
		data.push('00000000');
		var bit_queue = [];
		
		while (true) {
			
			while ( (bit_queue.length < (this.LSB_r + this.LSB_g + this.LSB_b)) && data.length != 0 ) {
				bit_queue = bit_queue.concat( data.shift().split('') );
			}
			
			if (pixel_idx < img_data.data.length) {
				
			} else {
				break;
			}
			
			if (bit_queue.length == 0) {
				break;
			}
			
			var r_data = '';
			for (var i=0;i<this.LSB.r;++i) {
				r_data += bit_queue.shift();
			}
			
			var g_data = '';
			for (var i=0;i<this.LSB.g;++i) {
				g_data += bit_queue.shift();
			}
			
			var b_data = '';
			for (var i=0;i<this.LSB.b;++i) {
				b_data += bit_queue.shift();
			}
			
			img_data.data[ pixel_idx ] = Stegosaurus.embed_bits_to_LSB(img_data.data[ pixel_idx ], r_data);
			img_data.data[pixel_idx+1] = Stegosaurus.embed_bits_to_LSB(img_data.data[pixel_idx+1], g_data);
			img_data.data[pixel_idx+2] = Stegosaurus.embed_bits_to_LSB(img_data.data[pixel_idx+2], b_data);
			
			pixel_idx+=4;
			++j;
		}
		return img_data;
	}
	
	extract_text_from_img_data(img_data) {
		return Stegosaurus.decode_string(this.extract_data_from_img_data(img_data));
	}
	
	extract_data_from_img_data(img_data) {
		var data = [];
		var bits = [];
		var pixel_idx=0;
		while (pixel_idx < img_data.data.length) {		
			bits = bits.concat( Stegosaurus.extract_bits_from_LSB(img_data.data[ pixel_idx ], this.LSB.r).toString(2).ljust(this.LSB.r,'0').split('') );
			bits = bits.concat( Stegosaurus.extract_bits_from_LSB(img_data.data[pixel_idx+1], this.LSB.g).toString(2).ljust(this.LSB.g,'0').split('') );
			bits = bits.concat( Stegosaurus.extract_bits_from_LSB(img_data.data[pixel_idx+2], this.LSB.b).toString(2).ljust(this.LSB.b,'0').split('') );
			if ( bits.length >= this.data_element_size ) {
				var data_frags = bits.slice(0, this.data_element_size);
				bits = bits.slice(this.data_element_size);
				
				var data_element = parseInt(data_frags.join(''), 2);
				if (data_element) {
					data.push( data_element.toString(2).ljust(8, '0') );
				} else {
					break;
				}
			}		
			pixel_idx += 4;
		}
		return data;
	}
}