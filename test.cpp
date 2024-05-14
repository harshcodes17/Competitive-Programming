    for (int i = n - 1; i >= 0; --i) {
        if (i + k >= n) {
            dp[i] = max(energy[i], 0);
        } else {
            dp[i] = max(0, energy[i] + dp[i + k]);
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}