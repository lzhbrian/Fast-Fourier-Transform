// Work by Lin, Tzu-Heng
// W42, 2014011054
// Dept. of Electronic Engineering, Tsinghua University
// DSP Course Work


complex* DIT_FFT_reordered(complex input_seq[], int N);
complex* DIT_FFT(complex input_seq[], int N, complex WN[], int recur_time_count);

/********************************************************************/
// DIT-FFT
	// input_seq[]: 
	// N: size of input_seq
		// Must be a 2^k integer
complex* DIT_FFT_reordered(complex input_seq[], int N) {
	
	// Initialize
	complex* reordered_seq = new complex[N];
	
	// Calc WN
	complex* WN = new complex[N];
	WN = Calc_WN(N);

	// Reorder
	reordered_seq = reorder_seq(input_seq, N);
	// Calc DIF-FFT
	reordered_seq = DIT_FFT(reordered_seq, N, WN, 0);

	return reordered_seq;
}
complex* DIT_FFT(complex input_seq[], int N, complex WN[], int recur_time_count) {

	// cout << "\tDIF_FFT executed!\n"; // for validation
	// output seq
	complex* return_seq = new complex[N];

	if ( N != 2 ) {

		int k = pow(2,recur_time_count);

		// Split input_seq into 2
		complex* first_half_input_seq = new complex[N/2];
		complex* second_half_input_seq = new complex[N/2];
		for (int i = 0; i < N/2; ++i) {
			first_half_input_seq[i] = input_seq[i];
		}
		for (int i = 0; i < N/2; ++i) {
			second_half_input_seq[i] = input_seq[i+N/2];
		}


		// DFT
		complex* DFTed_first_half_seq = new complex[N/2];
		DFTed_first_half_seq = DIT_FFT(first_half_input_seq, N/2, WN, recur_time_count+1);
		complex* DFTed_second_half_seq = new complex[N/2];
		DFTed_second_half_seq = DIT_FFT(second_half_input_seq, N/2, WN, recur_time_count+1);


		// Calc
		complex* output_first_half_seq = new complex[N/2];
		complex* output_second_half_seq = new complex[N/2];
		for (int i = 0; i < N/2; ++i) {
			output_first_half_seq[i] = ComplexAdd(DFTed_first_half_seq[i], ComplexMul(DFTed_second_half_seq[i], WN[i*k]) ) ;
		}
		for (int i = 0; i < N/2; ++i) {
			output_second_half_seq[i] = ComplexAdd(DFTed_first_half_seq[i], ComplexMul( ReverseComplex(DFTed_second_half_seq[i]), WN[i*k] ) );
		}


		// Append [output_first_half_seq] & [output_second_half_seq]
		return_seq = append_seq(output_first_half_seq, output_second_half_seq, N/2);
		return return_seq;

	} else if ( N == 2 ) { // Smallest Butterfly Unit

		// cout << "\tDIT_FFT N==2 triggered!\n"; // for validation
		return_seq[0] = ComplexAdd(input_seq[0], ComplexMul(input_seq[1], WN[0]) );
		return_seq[1] = ComplexAdd(input_seq[0], ComplexMul( ReverseComplex(input_seq[1]), WN[0] ) );
		return return_seq;
	
	}

	// return [return_seq] # unordered
	return return_seq;
}
/********************************************************************/
