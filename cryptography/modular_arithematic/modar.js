
export function extended_euclidean_recursive(r1, r2, s1 = 1, s2 = 0, t1 = 0, t2 = 1) {
	if (r1 < r2) {
		const temp = r1;
		r1 = r2;
		r2 = temp;
	}
	
	if (!r2) {
		return {
			gcd : r1,
			t : t1,
			s : s1
		};
	}
	
	const r = r1 % r2;
	const q = Math.floor(r1 / r2);
	const s = s1 - q*s2;
	const t = t1 - q*t2;
	
	console.log(q, r1, r2, r, s1, s2, s, t1, t2, t);
	
	return extended_euclidean_recursive(r2, r, s2, s, t2, t);
}

export function extended_euclidean(r1, r2) {
	var s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	
	if (r1 < r2) {
		const t = r1;
		r1 = r2;
		r2 = t;
	}

	while (r2) {
		const r = r1 % r2;
		const q = Math.floor(r1 / r2);
		const s = s1 - q*s2;
		const t = t1 - q*t2;
		
		r1 = r2;
		s1 = s2;
		t1 = t2;
		
		r2 = r;
		s2 = s;
		t2 = t;
	}
	
	return {
		gcd : r1,
		t : r1 == 1 ? t1 : null,
		s : s1
	};
}

export function fast_exponentiation(base, exp, mod) {
	const bits = exp.toString(2).split('');
	
	/*
	const reducer = function (remainder, currentBit) { 
		return ( currentBit == '1' ? remainder * base : remainder ) % mod;
	};
	var r = bits.reduce(reducer, 1);
	*/

	var remainder = 1;
	while (bits.length) {
		remainder = ( Math.pow(remainder, 2) * ( bits.shift() == '1' ? base : 1 ) ) % mod;
	}

	return remainder;
}

