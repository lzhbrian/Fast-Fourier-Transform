# Fast-Fourier-Transform
An Implementation of Fast Fourier Transform

* Info:
  * Work by Lin, Tzu-Heng
  * W42, 2014011054
  * Dept. of Electronic Engineering, Tsinghua University
  * DSP Course Work


* Decimate in Time/Frequency, Fast Fourier Transform
  * 2-based DIT-FFT, 2-based DIF-FFT
  * Usage:

```sh
make ./fft
./fft [N_max] [validate_or_evaluate] [dft_dit_dif]
```


* Validate: To output result of N=2^k point DFT/DIT/DIF to validate the result:

```sh
DFT:
	./fft 8 1 1
	./fft 16 1 1
DIT-FFT:
	./fft 16 1 2
DIF-FFT:
	./fft 16 1 3
All:
	./fft 16 1 4
```

* Evaluate Performance: 
  * To output the run time of DFT/DIT/DIF to execute N = 2^{ (10), (11), ..., (10+N_max-1) }

```sh
DFT:
	./fft 6 0 1	# Calc 2^{10~15}
	./fft 7 0 1	# Calc 2^{10~16}
DIT-FFT:
	./fft 7 0 2
DIF-FFT:
	./fft 7 0 3
All:
	./fft 7 0 4
```