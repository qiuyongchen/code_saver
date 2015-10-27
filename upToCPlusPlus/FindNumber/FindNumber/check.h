bool check(int number[][1000], int size_, int target) {
    bool found = false;
    for (int i = 0; i < size_; i++) {
        // if the last one of the row that we are scanning
        // is still smaller than the target, there is no need
        // for us to scan it yet.
        if (number[i][size_ - 1] < target) continue;
        for (int j = 0; j < size_; j++) {
            if (number[i][j] == target) found = true;
        }
    }
    return found;
}
