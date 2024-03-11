# Constrained Differential Dynamic Programming (CDDP) solver in C++



## Requirements
* Eigen (Linear Algebra Library in CPP)
    
    https://formulae.brew.sh/formula/eigen
```bash
sudo apt-get install libeigen3-dev # For Ubuntu
brew install eigen # For macOS

```

* OSQP 
```bash
conda install -c conda-forge osqp
conda install -c conda-forge osqp-eigen
```


## Installation
```bash
git clone https://github.com/astomodynamics/CDDP-cpp 
mkdir build
cd build
cmake ..
make
```

## References

* Tassa, Yuval, Nicolas Mansard, and Emo Todorov. "Control-limited differential dynamic programming." Robotics and Automation (ICRA), 2014 IEEE International Conference on. IEEE, 2014.
* Li, Weiwei, and Emanuel Todorov. "Iterative linear quadratic regulator design for nonlinear biological movement systems." ICINCO (1). 2004.
* https://github.com/kazuotani14/iLQR?tab=readme-ov-file
