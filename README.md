# Repository for my competitive programming templates.

* template.cpp - Default template for problems' solutions. 
* c_mint.cpp - Template featuring modular int struct, which allows to operate on integers in given modulo ring (fully tested).
* c_math.cpp - Template featuring precomputed values of common functions like 2^x or x!, eratosthenes sieves for prime testing, aswell as factorization or   extracting numbers' divisors, standalone functions for computing big binomials, factorization, getting divisors and prime testing (including Rho Pollard   algorithm). Requires c_mint.cpp to work (fully tested).
* c_utils.cpp - Template featuring commonly used functions to convert between types (int to string, string to int) and functions that allow counting and     summing up number's digits (fully tested).
* c_dsu.cpp - Template featuring disjoint set union data structure which allows for merging sets of values and asking for given set's representant in         almost constant time (fully tested).
* c_sparse.cpp - Template featuring sparse table data structure which allows to perform segment queries on immutable array using any associative function     in logarithmic time (even constant if function is idempotent) (fully tested).
* c_fenwick.cpp - Template featuring fenwick tree data structure which allows to ask for prefix sums on array, aswell as updating single elements in         logarithmic time (fully tested).

(All templates do not free memory due to contests' strict time limits)
