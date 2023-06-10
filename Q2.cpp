unordered_set<int> weights;
    char prev_char = '\0';
    int prev_weight = 0;

    for (char c : s) {
        int weight = c - 'a' + 1;
        if (c == prev_char) {
            prev_weight += weight;
        } else {
            prev_char = c;
            prev_weight = weight;
        }
        weights.insert(prev_weight);
    }

    vector<string> result;
    for (int query : queries) {
        result.push_back(weights.count(query) ? "Yes" : "No");
    }

    return result;
