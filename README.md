# Investigating Mobility in Spatial Biodiversity Models through Recurrence Quantification Analysis

Data generation for the project "Investigating Mobility in Spatial Biodiversity Models through Recurrence Quantification Analysis".
This directory works in parallel with the **RQA analysis** allocated in a different directory (https://github.com/m-palmero/recurrences_RPS_models).

# Code Description

The present code simulates a canonical population dynamics systems of three cyclically competing species: the spatial May-Leonard Rock-Paper-Scissors. The virtual ecosystem contains N^2 square regular sites with periodic boundary conditions. Individuals of each species occupies one particular sites. They are able to interact with its four nearest neighbours in three forms: reproducing, competing or exchanging places. The time evolution occurs stochastically, with active individuals, its action and the passive individual being all chosen randomly. At the end the abundance time series and the final state of the system are recorded.

# Key Parameters

For executing the algorithm one must specify the lattice size **Nx**, the number of time generations **NG** present in the `rps.h` file.

# Compilation and Execution

You can execute the code simply running the `makefile`.

- Clean existing files from dat/ and plt/
```
make clean
```

- Compilation and Execution

```
./run.sh
```

# Data Processing

For this project, both the abundance time series and final states are of interest. But for the RPA only the time series is necessary.
For generating the figures of the simulations go to `plt` and:

- Abundance

```
gnuplot dst.plt && pdflatex #.tex
```

- Final State

```
gnuplot rps.plt
```

# Authors

Matheus Palmero
Matheus Bongestab
