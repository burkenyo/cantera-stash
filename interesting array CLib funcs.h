// int*
int sim1D3_newSim1D(int domainsLen, const int* domains)
int sim1D3_setTimeStep(int handle, double stepsize, int n, const int* tsteps)
int sol3_newInterface(const char* infile, const char* name, int adjacentLen, const int* adjacent)
int reactornet3_new(int reactorsLen, const int* reactors)

// not get or set
int domain3_grid(int handle, int bufLen, double* buf)
int sim1D3_eval(int handle, int j, int xLen, double* x, int rLen, double* r, double rdt, int count)
int thermo3_chemPotentials(int handle, int muLen, double* mu)
int thermo3_electroChemPotentials(int handle, int muLen, double* mu)
int rdiag3_findMajor(int handle, double threshold, int lda, int aLen, double* a)
int func13_new_advanced(const char* func1Type, int paramsLen, const double* params)

// const double*, not set
int trans3_getMolarFluxes(int handle, int state1Len, const double* state1, int state2Len, const double* state2, double delta, int cfluxesLen, double* cfluxes);
int trans3_getMassFluxes(int handle, int state1Len, const double* state1, int state2Len, const double* state2, double delta, int mfluxesLen, double* mfluxes);
int func13_new_advanced(const char* func1Type, int paramsLen, const double* params);

// (non-const) double*, not get
int domain3_grid(int handle, int bufLen, double* buf);
int flow3_setFixedTempProfile(int handle, int zfixedLen, double* zfixed, int tfixedLen, double* tfixed);
int sim1D3_eval(int handle, int j, int xLen, double* x, int rLen, double* r, double rdt, int count);
int thermo3_chemPotentials(int handle, int muLen, double* mu);
int thermo3_electroChemPotentials(int handle, int muLen, double* mu);
int rdiag3_findMajor(int handle, double threshold, int lda, int aLen, double* a);

// const double*, get
int trans3_getMolarFluxes(int handle, int state1Len, const double* state1, int state2Len, const double* state2, double delta, int cfluxesLen, double* cfluxes);
int trans3_getMassFluxes(int handle, int state1Len, const double* state1, int state2Len, const double* state2, double delta, int mfluxesLen, double* mfluxes);

// (non-const) double*, set
int flow3_setFixedTempProfile(int handle, int zfixedLen, double* zfixed, int tfixedLen, double* tfixed);
