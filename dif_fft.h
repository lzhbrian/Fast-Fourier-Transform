// Work by Lin, Tzu-Heng
// W42, 2014011054
// Dept. of Electronic Engineering, Tsinghua University
// DSP Course Work


complex* DIF_FFT_reordered(complex input_seq[], int N);
complex* DIF_FFT(complex input_seq[], int N, complex WN[], int recur_time_count);

/********************************************************************/
// DIF-FFT
	// input_seq[]: 
	// N: size of input_seq
		// Must be a 2^k integer
complex* DIF_FFT_reordered(complex input_seq[], int N) {
	
	// Initialize
	complex* reordered_seq = new complex[N];
	
	// Calc WN
	complex* WN = new complex[N];
	WN = Calc_WN(N);

	// Calc DIF-FFT
	reordered_seq = DIF_FFT(input_seq, N, WN, 0);
	// Reorder
	reordered_seq = reorder_seq(reordered_seq, N);

	return reordered_seq;
}
complex* DIF_FFT(complex input_seq[], int N, complex WN[], int recur_time_count) {

	// cout << "\tDIF_FFT executed!\n"; // for validation
	// output seq
	complex* return_seq = new complex[N];

	if ( N != 2 ) {

		complex* first_half_seq = new complex[N/2];
		complex* second_half_seq = new complex[N/2];

		int k = pow(2,recur_time_count);

		// Calc
		for (int i = 0; i < N/2; ++i) {
			first_half_seq[i] = ComplexAdd(input_seq[i], input_seq[i+N/2]) ;
		}
		for (int i = 0; i < N/2; ++i) {
			second_half_seq[i] = ComplexMul( ComplexAdd(input_seq[i], ReverseComplex(input_seq[i+N/2])), WN[i*k] ) ;
		}

		// DFT
		complex* DFTed_first_half_seq = new complex[N/2];
		DFTed_first_half_seq = DIF_FFT(first_half_seq, N/2, WN, recur_time_count+1);
		complex* DFTed_second_half_seq = new complex[N/2];
		DFTed_second_half_seq = DIF_FFT(second_half_seq, N/2, WN, recur_time_count+1);

		// Append [DFTed_first_half_seq] & [DFTed_second_half_seq]
		return_seq = append_seq(DFTed_first_half_seq, DFTed_second_half_seq, N/2);
		return return_seq;

	} else if ( N == 2 ) { // Smallest Butterfly Unit

		// cout << "\tDIF_FFT N==2 triggered!\n"; // for validation
		return_seq[0] = ComplexAdd(input_seq[0], input_seq[1]);
		return_seq[1] = ComplexMul( ComplexAdd(input_seq[0], ReverseComplex(input_seq[1])), WN[0] );
		return return_seq;
	
	}

	// return [return_seq] # unordered
	return return_seq;
}
/********************************************************************/
