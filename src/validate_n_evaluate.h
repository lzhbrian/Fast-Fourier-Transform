// Work by Lin, Tzu-Heng
// W42, 2014011054
// Dept. of Electronic Engineering, Tsinghua University
// DSP Course Work


void validate_result(complex input_seq[], int N, int dft_dit_dif);
void evaluate_performance(complex input_seq[], int N_max, int dft_dit_dif);

/********************************************************************/
// To validate the result of a point N sequence using DFT/DIT/DIF
	// complex input_seq[]
	// int N
	// int dft_dit_dif:    
		// 1:DFT, 2:DIT, 3:DIF, 4:To compute everything for validation
void validate_result(complex input_seq[], int N, int dft_dit_dif) {


	// DFT
	if (dft_dit_dif == 1 || dft_dit_dif == 4)
	{
		cout << "Calculating DFT..." << endl;

		// DFT
		complex* DFTed_seq = new complex[N];
		DFTed_seq = DFT(input_seq, N);

		// Validate
		cout << "\n\tValidating..." << endl;
		for (int i = 0; i < N; ++i) {
			cout << "\tX[" << i << "] = " << DFTed_seq[i].re << " + j*" << DFTed_seq[i].im << endl;
		}

		delete[] DFTed_seq;
	}

	// DIT-FFT
	if (dft_dit_dif == 2 || dft_dit_dif == 4)
	{
		cout << "Calculating DIT-FFT..." << endl;

		 // DIT_FFT
		complex* DIT_FFTed_seq = new complex[N];
		DIT_FFTed_seq = DIT_FFT_reordered(input_seq, N);

		// Validate
		cout << "\n\tValidating..." << endl;
		for (int i = 0; i < N; ++i) {
			cout << "\tX[" << i << "] = " << DIT_FFTed_seq[i].re << " + j*" << DIT_FFTed_seq[i].im << endl;
		}
		
		delete[] DIT_FFTed_seq;
	}

	// DIF-FFT
	if (dft_dit_dif == 3 || dft_dit_dif == 4)
	{
		cout << "Calculating DIF-FFT..." << endl;

		 // DIT_FFT
		complex* DIF_FFTed_seq = new complex[N];
		DIF_FFTed_seq = DIF_FFT_reordered(input_seq, N);

		// Validate
		cout << "\n\tValidating..." << endl;
		for (int i = 0; i < N; ++i) {
			cout << "\tX[" << i << "] = " << DIF_FFTed_seq[i].re << " + j*" << DIF_FFTed_seq[i].im << endl;
		}

		delete[] DIF_FFTed_seq;
	}
}


// For compare the performance(run time) of DFT/DIT/DIF
	// complex input_seq[]
	// int N_max:
		// compare with N = 2^{ (10), (11), ..., (10+N_max-1) }
	// int dft_dit_dif:    
		// 1:DFT, 2:DIT, 3:DIF, 4:To compute everything for validation
void evaluate_performance(complex input_seq[], int N_max, int dft_dit_dif) {

	time_t first, second; // For calc of run time
	int N[7] = {1024, 2048, 4096, 8192, 16384, 32768, 65536};
		// 2 ^ {10,11,12,13,14,15,16}

	// DIT-FFT
		if (dft_dit_dif == 2 || dft_dit_dif == 4)
		{
			cout << "Calculating DIT-FFT..." << endl;

			for (int i = 0; i < N_max; ++i)
			{
				first = clock(); // start time
				int N_ins = N[i];
				cout << "N = " << N_ins << "... \t";

				// DIT_FFT
				complex* DIT_FFTed_seq = new complex[N_ins];
				DIT_FFTed_seq = DIT_FFT_reordered(input_seq, N_ins);

				delete[] DIT_FFTed_seq;

				second = clock(); //end time
				cout << "Run time = " << (second-first)/1000 << " ms\n";
			}
		}

	// DIF-FFT
		if (dft_dit_dif == 3 || dft_dit_dif == 4)
		{
			cout << "Calculating DIF-FFT..." << endl;
			for (int i = 0; i < N_max; ++i)
			{
				first = clock(); // start time
				int N_ins = N[i];
				cout << "N = " << N_ins << "... \t";

				// DIF
				complex* DIF_FFTed_seq = new complex[N_ins];
				DIF_FFTed_seq = DIF_FFT_reordered(input_seq, N_ins);

				delete[] DIF_FFTed_seq;
				
				second = clock(); //end time
				cout << "Run time = " << (second-first)/1000 << " ms\n";
			}
		}


	// DFT
		if (dft_dit_dif == 1 || dft_dit_dif == 4)
		{
			cout << "Calculating DFT..." << endl;
			for (int i = 0; i < N_max; ++i)
			{
				first = clock(); // start time
				int N_ins = N[i];
				cout << "N = " << N_ins << "... \t";

				// DFT
				complex* DFTed_seq = new complex[N_ins];
				DFTed_seq = DFT(input_seq, N_ins);

				delete[] DFTed_seq;

				second = clock(); //end time
				cout << "Run time = " << (second-first)/1000 << " ms\n";
			}
		}
}

