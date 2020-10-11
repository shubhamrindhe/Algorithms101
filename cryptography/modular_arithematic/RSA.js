
export class RSA {
	
	constructor (p, q) {
		this.p = p;
		this.q = q;
		this.n = p*q;
		this.phi_n = (p-1)*(q-1);
		
		this.e = null;
		this.d = null;
	}
	
} 