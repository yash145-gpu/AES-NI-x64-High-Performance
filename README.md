 <h2>Highly Optimized Low Latency AES128ECB Implementation and Benchmarking</h2>
 
 ### Pure x86_64 Intel Assembly without any external library 
 ### CPU: Intel Skylake   AVX2, AES-NI
<h2></h2>
</b>

- #### Loops unrolled for better instruction scheduling/Pipeline hits.
- #### 22 keys : stored in 15 vector registers (11 Encryption , 4 Decryption) , 7 Decryption keys in memory.
- #### Cache prefetching for memory keys (1-2 clk cycle access time).
- #### 16 Byte memory alignment for Plaintext & Keys for fast fetching.
- #### 10000 Benchmark iterations for stable low variance results.
</b>
<h2></h2>

- ``Assemble : nasm -felf64 -o aex.o aesdqw.asm``
- ``link     : ld -o aex aex.o``
- ``execute  : ./aex``

##
- Input : File : 16 bytes plain text 'plainVector128'
- Output: File : 16 bytes cipher text in file 'encop'
- STDOUT :
  - Average cycle count for enc+dec
  -  Cipher Text 
  -  Decrypted Text 
  -  Key


 ## Achieved Performance Benchmarks:
 *For Intel Skylake , Cpu clock speed : 2300mhz(max scaling) , Memory : 2133 MT/s* 
#
 - block size : 16 Bytes (Single)
 - Average AES encryption: 10-11 clock cycles
 - Average AES decryption: 10-11 clock cycles
#
- block size : 16 Bytesx4 (Concurrent)
- Average AES encryption: 1-2 clock cycles
- Average AES decryption: 1-2 clock cycles
