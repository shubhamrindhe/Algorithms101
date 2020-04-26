
class Stegosaurus {

	constructor (LSB_r = 2, LSB_g = 2, LSB_b = 2) {
		
		this.LSB = {
			r : LSB_r,
			g : LSB_g,
			b : LSB_b
		};
		
		this.data_element_size = 8;
		
	}
	
	embed() {
		
	}
	
	extract(img_data) {
		var data = [];
		
		var data_size = 8;
		var bits = [];
		var i=0;
		while (i < img_data.data.length) {		
			bits = bits.concat( extract_bits_from_byte(img_data.data[i], this.LSB.r).toString(2).ljust(this.LSB.r,'0').split('') );
			bits = bits.concat( extract_bits_from_byte(img_data.data[i+1], this.LSB.g).toString(2).ljust(this.LSB.g,'0').split('') );
			bits = bits.concat( extract_bits_from_byte(img_data.data[i+2], this.LSB.b).toString(2).ljust(this.LSB.b,'0').split('') );
			
			if ( bits.length > this.data_element_size ) {
				var data_frag = bits.slice(0, this.data_element_size);
				bits = bits.slice(this.data_element_size);
				
				var x = parseInt(data_frag.join(''), 2);
				if (x) {
					data.push( x.toString(2).ljust(8, '0') );
				} else {
					break;
				}
			}
				
			i += 4;
		}
		
		return data;
	}
}