bool compareStrings(const std::string& str1, const std::string& str2) {
    // Compare strings based on their lengths
    if (str1.length() == str2.length()) {
        return str1 < str2;
    } else {
        return str1.length() < str2.length();
    }
}


vector<string> bigSorting(vector<string> unsorted) {
    
    // Sort the vector of strings using the custom comparison function
    sort(unsorted.begin(), unsorted.end(), compareStrings);

    // Return the sorted vector of strings
    return unsorted;
}
