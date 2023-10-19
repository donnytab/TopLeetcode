int hIndex(int *citations, int citationsSize) {
    int n = citationsSize, tot = 0;
    int counter[n + 1];
    memset(counter, 0, sizeof(counter));
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n) {
            counter[n]++;
        } else {
            counter[citations[i]]++;
        }
    }
    for (int i = n; i >= 0; i--) {
        tot += counter[i];
        if (tot >= i) {
            return i;
        }
    }
    return 0;
}
