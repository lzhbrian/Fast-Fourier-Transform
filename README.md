# Fast-Fourier-Transform

An Implementation of *__Fast Fourier Transform__*



## Info:

* Work by __Brian Lin, Tzu-Heng__
  * W42, 2014011054
  * Dept. of Electronic Engineering, Tsinghua University
  * DSP Course Work


* Decimate in Time/Frequency, Fast Fourier Transform
  * __2-base DIT-FFT__, __2-base DIF-FFT__ & the __Original DFT__ method

  * You can change the __`[input sequence]`__ in the __`main()`__ function of __`fft.cpp`__.

  * Usage:

    ```sh
    make ./fft
    ./fft [N_max] [validate_or_evaluate] [dft_dit_dif]
    ```

* There are two modes. 
  * __Mode 1__: Output the result of DFT *using three methods respectively*.
  * __Mode 2__: Evaluate the performance of *three algorithms respectively*.




## Usage:

* __Model 1: Output__
  * To output result of __N=2^k__ point __DFT / DIT-FFT / DIF-FFT__:

    ```sh
    # DFT:
    	./fft 8 1 1	# Calc a 8-point sequence
    	./fft 16 1 1	# Calc a 16-point sequence
    # DIT-FFT:
    	./fft 16 1 2
    # DIF-FFT:
    	./fft 16 1 3
    # All:
    	./fft 16 1 4
    ```

* __Mode 2: Evaluate Performance__
  * To output the run time of __DFT / DIT-FFT / DIF-FFT__
    * executing __N = 2^{ (10), (11), ..., (10+N_max-1) }__ respectively.

    ```sh
    # DFT:
    	./fft 4 0 1	# Calc 2^{10~13}
    	./fft 6 0 1	# Calc 2^{10~15}
    	./fft 7 0 1	# Calc 2^{10~16}
    # DIT-FFT:
    	./fft 7 0 2
    # DIF-FFT:
    	./fft 7 0 3
    # All:
    	./fft 7 0 4
    ```



## Output Result:

* __Model 1: Output__

  * The result of command __`./fft 8 1 4`__ may look like this:

    ```
    Lin, Tzu-Heng's Work, 2014011054, W42
    Dept. of Electronic Enigeering, Tsinghua University

    Starting, This project is to calc DFT in Original-DFT / DIT-FFT / DIF-FFT...
    	For Usage, Please see 'fft.cpp' 

    Calculating DFT...
    	X[0] = 2 + j*0
    	X[1] = 1.70711 + j*-0.707107
    	X[2] = 1 + j*-1
    	X[3] = 0.292893 + j*-0.707107
    	X[4] = 1.33227e-15 + j*-5.35898e-08
    	X[5] = 0.292893 + j*0.707107
    	X[6] = 1 + j*1
    	X[7] = 1.70711 + j*0.707107
    Calculating DIT-FFT...
    	X[0] = 2 + j*0
    	X[1] = 1.70711 + j*-0.707107
    	X[2] = 1 + j*-1
    	X[3] = 0.292893 + j*-0.707107
    	X[4] = 0 + j*0
    	X[5] = 0.292893 + j*0.707107
    	X[6] = 1 + j*1
    	X[7] = 1.70711 + j*0.707107
    Calculating DIF-FFT...
    	X[0] = 2 + j*0
    	X[1] = 1.70711 + j*-0.707107
    	X[2] = 1 + j*-1
    	X[3] = 0.292893 + j*-0.707107
    	X[4] = 0 + j*0
    	X[5] = 0.292893 + j*0.707107
    	X[6] = 1 + j*1
    	X[7] = 1.70711 + j*0.707107
    ```

* __Model 2: Output__

  * The result of command __`./fft 7 0 4`__ may look like this:

    ```
    Lin, Tzu-Heng's Work, 2014011054, W42
    Dept. of Electronic Enigeering, Tsinghua University

    This project is to calc DFT in Original-DFT / DIT-FFT / DIF-FFT...
    	For Usage, Please see 'fft.cpp' 

    Calculating DIT-FFT...
    N = 1024	Run time = 2 ms
    N = 2048	Run time = 6 ms
    N = 4096	Run time = 14 ms
    N = 8192	Run time = 24 ms
    N = 16384	Run time = 53 ms
    N = 32768	Run time = 106 ms
    N = 65536	Run time = 200 ms
    Calculating DIF-FFT...
    N = 1024	Run time = 1 ms
    N = 2048	Run time = 3 ms
    N = 4096	Run time = 7 ms
    N = 8192	Run time = 16 ms
    N = 16384	Run time = 39 ms
    N = 32768	Run time = 79 ms
    N = 65536	Run time = 154 ms
    Calculating DFT...
    N = 1024	Run time = 38 ms
    N = 2048	Run time = 180 ms
    N = 4096	Run time = 771 ms
    N = 8192	Run time = 2948 ms
    N = 16384	Run time = 12811 ms
    N = 32768	Run time = 61836 ms
    N = 65536	Run time = 356046 ms
    ```