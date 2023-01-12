void states(int s0, int s1, int b0, int b1, int* n0, int* n1, int* o0, int* o1) {
    // from kmap
    *n0 = ((!s1) & b0)| (s0 & b1);
    *n1= ((!s0) & (!s1) & b1) | (s1 & (!b0) & (!b1));
    *o0 = s0;
    *o1 = s1;
}
