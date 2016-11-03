// Work by Lin, Tzu-Heng
// W42, 2014011054
// Dept. of Electronic Engineering, Tsinghua University
// DSP Course Work


/********************************************************************/
// Decimate in Time/Frequency, Fast Fourier Transform
// 2-based DIT-FFT, 2-based DIF-FFT
// Usage:
	// make ./fft
	// ./fft [N_max] [validate_or_evaluate] [dft_dit_dif]

	// Validate: To output result of N=2^k point DFT/DIT/DIF to validate the result:
		// DFT:
			// ./fft 8 1 1
			// ./fft 16 1 1
		// DIT-FFT:
			// ./fft 16 1 2
		// DIF-FFT:
			// ./fft 16 1 3
		// All:
			// ./fft 16 1 4

	// Evaluate Performance: To output the run time of DFT/DIT/DIF to execute N = 2^{ (10), (11), ..., (10+N_max-1) }
		// DFT:
			// ./fft 6 0 1	# Calc 2^{10~15}
			// ./fft 7 0 1	# Calc 2^{10~16}
		// DIT-FFT:
			// ./fft 7 0 2
		// DIF-FFT:
			// ./fft 7 0 3
		// All:
			// ./fft 7 0 4

// included several .h
# include "complex.h"	// definition of struct complex, Calculation of WN[]
# include "dft.h"		// DFT
# include "dit_fft.h"	// DIT-FFT
# include "dif_fft.h"	// DIF-FFT
# include "validate_n_evaluate.h"	// validate_result(), evaluate_performance()

int main(int argc, char ** argv) 
{

	cout << "\n\nLin, Tzu-Heng's Work, 2014011054, W42" << endl;
	cout << "Dept. of Electronic Enigeering, Tsinghua University" << endl << endl;
	cout << "Starting, This project is to calc DFT in Original-DFT / DIT-FFT / DIF-FFT..." << endl; 
	cout << "\tFor Usage, Please see 'fft.cpp' " << endl << endl;


	// Get argv
		int N_max = atoi(argv[1]); // length of input sequence
			// input 7 to run 2^{10,11,12,13,14,15,16}
			// input 6 to run 2^{10,11,12,13,14,15}
		int validate_or_evaluate = atoi(argv[2]); // 1 for validate, 0 for ignore
		int dft_dit_dif = atoi(argv[3]); // 1:DFT, 2:DIT, 3:DIF, 4:To compute everything for validation

	// Initialize
	// Setup input sequence
		complex* input_seq = new complex[N_max];
		input_seq[0] = complex(1,0);
		input_seq[1] = complex(1,0);
		// input_seq[2] = complex(1,0);
		// input_seq[3] = complex(1,0);
		// input_seq[4] = complex(1,0);
		// input_seq[5] = complex(1,0);
		// input_seq[6] = complex(1,0);
		// input_seq[7] = complex(1,0);
		// input_seq[8] = complex(1,0);
		// input_seq[9] = complex(1,0);
		// input_seq[10] = complex(1,0);
		// input_seq[11] = complex(1,0);
		// input_seq[12] = complex(1,0);
		// input_seq[13] = complex(1,0);
		// input_seq[14] = complex(1,0);
		// input_seq[15] = complex(1,0);


	// For validation of the result
		if (validate_or_evaluate == 1) {
			validate_result(input_seq, N_max, dft_dit_dif);
			return 0;
		}

	// For compare the performance(run time) of DFT/DIT/DIF
		else if (validate_or_evaluate == 0) {
			evaluate_performance(input_seq, N_max, dft_dit_dif);
			return 0;
		}

	// end
	    return 0;

}














