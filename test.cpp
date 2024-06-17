if(k <= maxi){
    vector<ll> p;
    ll diff = maxi - k;
    for(ll i=n; i>=1; i--){
        if(i - 1 <= diff){
            p.push_back(i - diff);
            diff -= (i - 1);
        } else {
            p.push_back(i);
        }
    }
    if(diff > 0){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(auto it=p.rbegin(); it!=p.rend(); ++it)
            cout << *it << " ";
        cout << "\n";
    }
}